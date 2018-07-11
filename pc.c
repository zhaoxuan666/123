  #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

#define PRO_CNT 1  // �������̸߳���
#define CON_CNT 2  // �������̸߳���

pthread_cond_t cond;
pthread_mutex_t mutex;
int num = 0;

// �������߳�


void *pro(void *arg) {
	int id = *(int*)arg;
	free(arg);
	while ( 1 ){
		pthread_mutex_lock(&mutex);
		printf("%d �������߳̿�ʼ������%d��Ʒ\n", id, num+1);
		num ++;
		sleep(rand()%3);
		printf("%d �������߳�������%d��Ʒ����\n", id, num);
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
		sleep(rand()%3);
	}
}

// �������߳�
void *con(void *arg)
{
	int id = *(int*)arg;
	free(arg);

	while ( 1 ){
		pthread_mutex_lock(&mutex);
		while (num <= 0 ) {
			printf("%d�������߳̿�ʼ�ȴ����Ѳ�Ʒ\n", id);
			pthread_cond_wait(&cond, &mutex);
			printf("%d�������̵߳ȴ�����\n", id);
		}
		printf("%d�������߳̿�ʼ%d���Ѳ�Ʒ\n", id, num);
		num --;
		sleep(rand()%3);
		printf("%d�������߳�����%d��Ʒ����\n", id, num+1);
		pthread_mutex_unlock(&mutex);
		sleep(rand()%3);
	}
}

int main( void )
{
	pthread_t tids[PRO_CNT+CON_CNT];

	srand(getpid());

	pthread_cond_init(&cond, NULL); // ��ʼ����������
	pthread_mutex_init(&mutex, NULL); // ��ʼ��������

	for (int i=0; i<PRO_CNT; i++ ) // �����������߳�
	{
		int *p = malloc(sizeof(int));
		*p = i;
		pthread_create(&tids[i], NULL, pro, p);
	}
	
	for (int i=0; i<CON_CNT; i++) { // �����������߳�
		int *p = malloc(sizeof(int));
		*p = i;
		pthread_create(&tids[PRO_CNT+i], NULL, con, p);
	}

	for (int i=0; i<PRO_CNT+CON_CNT; i++) // �����߳�
		pthread_join(tids[i], NULL);

	pthread_cond_destroy(&cond);   // ������������
	pthread_mutex_destroy(&mutex); // ���ٻ�����
}



