import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.Arrays;
/**
*�����
*����������
*/
public class SocketServerTest {
    private static final int PORT = 5209;
    public static void test(){
        System.out.println("�ȴ��ͻ��˽������ӣ�����");
        ServerSocket server = null;
        Socket socket = null;
         DataOutputStream out = null;
        try {
            server = new ServerSocket(PORT);
            socket = server.accept();
            out = new DataOutputStream(socket.getOutputStream());
            
            while(true)
        {
            int c=selectm(socket,out);//�����Լ��ĺ���
            out.writeInt(c);        
            out.flush();
        }
        } catch (Exception e) {
            e.printStackTrace();
        }
            
            
        
    }
    private static int selectm(Socket socket,DataOutputStream out){
         
        
        InputStream is = null;
          DataInputStream dis = null;
          int count=0;
       
        try{
           
          //  while(true){
            for(int i=0;i<5;i++){
                Thread.sleep(1000);
                out.writeUTF(getRandomStr());        
                out.flush();
                
                is = socket.getInputStream();
                dis = new DataInputStream(is);
                String jisuan=dis.readUTF();
                System.out.println("������ַ���Ϊ:"+jisuan);
                double JiGuo=calcBracket(jisuan);
                System.out.println("���Ϊ:"+ JiGuo);
             /*    PrintWriter pw = new PrintWriter(out);
                     pw.write("��ӭ��½");
                     pw.flush();
                */
                if(JiGuo!=24)
                {
                    
                     out.writeUTF("����");        
                     out.flush();
                     // continue;
                }
                else
                {
                    out.writeUTF("����");        
                    out.flush();
                    ++count;
                }
              
            //    Thread.sleep(60000);
            }
        }catch(Exception e){
            e.printStackTrace();
        }
        
        return count;
    }
    
//��ȡ1-9�����ֵ
    private static String getRandomStr(){
        String str = "";
       
       int x = (int) (Math.random()*9+1);
       int y = (int) (Math.random()*9+1);
        int z = (int) (Math.random()*9+1);
        int m = (int) (Math.random()*9+1);
        str = " x:"+x+" y:"+y+" z:"+z+" m:"+m;
       // str=x+y+z;
        return str;
    }

   //������
    public static double calcBracket(String exp){
        //������������ſ�ʼ����,exp�������ֵ�(���ڲ������
        int lastIndexOf = exp.lastIndexOf('(');
        //���ֽ��
        if (lastIndexOf != -1) {
            //��
            //1.�������ڲ����ű��ʽ��ֵ,�Ҷ�Ӧ��������
            int rightIndexOf = exp.indexOf(')', lastIndexOf);
            double d = calc(exp.substring(lastIndexOf+1,rightIndexOf));
            //2.��������ƴ��
            exp = exp.substring(0, lastIndexOf)+d+exp.substring(rightIndexOf+1);
            return calcBracket(exp);
        }else {
            //û��
            //û�����ŵı��ʽ
            return calc(exp);
        }
    }

    /**
     * 
     * @param exp �������ŵ�������ʽ
     * @return
     */
    public static double calc(String exp){
        //1.�ѱ�ʾ������-�Ż���@��
       // exp = fu2At(exp);
        //2.���ֵķ���
        List<Double> numbers;
        numbers = splitNumExp(exp);
        //3.������ķ���
        List<Character> ops = splitOpfromExp(exp);
        //4.�ȳ˳�
        for (int i = 0; i < ops.size(); i++) {
            //�ж�,������Ƿ��ǳ˳�
            char op = ops.get(i);
            //��,ȡ��,����
            if (op == '*' || op == '/') {
                //ȡ����,����
                ops.remove(i);//�����������ǰ˳���ƶ�
                //����
                //������������ȡ����Ӧ���������������
                double d1 = numbers.remove(i);
                double d2 = numbers.remove(i);

                if (op == '*') {
                    d1 *= d2;
                }else {
                    d1 /= d2;
                }

                //����������������������i��λ��
                numbers.add(i, d1);//ԭ��iλ��(����)�����������������˳��
                i--;
            }
        }
        //5.��Ӽ�
        while (!ops.isEmpty() ) {
            char op = ops.remove(0);
            double d1 = numbers.remove(0);
            double d2 = numbers.remove(0);
            //����
            if (op == '+') {
                d1 += d2;
            } else {
                d1 -= d2;
            }
            //�����������뵽����������0��λ��
            numbers.add(0, d1);
        }
        //6.�����еĵ�һ�����ݾ��ǽ��
        return numbers.get(0);
    }

    /**
     * �ӱ��ʽ�з�����ʽ�������
     * @param exp
     * @return
     */
    private static List<Character> splitOpfromExp(String exp) {
        List<Character> ops = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(exp, "1234567890.@");
        while (st.hasMoreTokens()) {
            char c = st.nextElement().toString().trim().charAt(0);
            ops.add(c);
        }
        return ops;
    }

    /**
     * ���������
     * @param exp
     * @return
     */
    private static List<Double> splitNumExp(String exp) {
        List<Double> numbers = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(exp, "+-*/");
        while (st.hasMoreTokens()) {
            String numStr = st.nextElement().toString().trim();
            if (numStr.charAt(0) == '@') {
                numStr = "-" + numStr.substring(1);
            }
            numbers.add(Double.parseDouble(numStr));
        }
        return numbers;
    }
    
    public static void main(String[] args){
        new SocketServerTest().test();
    }
}