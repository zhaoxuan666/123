  #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

#define PRO_CNT 1  // 生产者线程个数
#define CON_CNT 2  // 消费者线程个数

pthread_cond_t cond;
pthread_mutex_t mutex;
int num = 0;

// 生产者线程
void *pro(void *arg) {
	int id = *(int*)arg;
	free(arg);
	while ( 1 ){
		pthread_mutex_lock(&mutex);
		printf("%d 生产者线程开始生产第%d产品\n", id, num+1);
		num ++;
		sleep(rand()%3);
		printf("%d 生产者线程生产第%d产品结束\n", id, num);
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
		sleep(rand()%3);
	}
}

// 消费者线程
void *con(void *arg)
{
	int id = *(int*)arg;
	free(arg);

	while ( 1 ){
		pthread_mutex_lock(&mutex);
		while (num <= 0 ) {
			printf("%d消费者线程开始等待消费产品\n", id);
			pthread_cond_wait(&cond, &mutex);
			printf("%d消费者线程等待结束\n", id);
		}
		printf("%d消费者线程开始%d消费产品\n", id, num);
		num --;
		sleep(rand()%3);
		printf("%d消费者线程消费%d产品结束\n", id, num+1);
		pthread_mutex_unlock(&mutex);
		sleep(rand()%3);
	}
}

int main( void )
{
	pthread_t tids[PRO_CNT+CON_CNT];

	srand(getpid());

	pthread_cond_init(&cond, NULL); // 初始化条件变量
	pthread_mutex_init(&mutex, NULL); // 初始化互斥量

	for (int i=0; i<PRO_CNT; i++ ) // 创建生产者线程
	{
		int *p = malloc(sizeof(int));
		*p = i;
		pthread_create(&tids[i], NULL, pro, p);
	}
	
	for (int i=0; i<CON_CNT; i++) { // 创建消费者线程
		int *p = malloc(sizeof(int));
		*p = i;
		pthread_create(&tids[PRO_CNT+i], NULL, con, p);
	}

	for (int i=0; i<PRO_CNT+CON_CNT; i++) // 回收线程
		pthread_join(tids[i], NULL);

	pthread_cond_destroy(&cond);   // 销毁条件变量
	pthread_mutex_destroy(&mutex); // 销毁互斥量
}



