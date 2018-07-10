import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.Arrays;
/**
*服务端
*负责发送数据
*/
public class SocketServerTest {
    private static final int PORT = 5209;
    public static void test(){
        System.out.println("等待客户端进行连接！！！");
        ServerSocket server = null;
        Socket socket = null;
         DataOutputStream out = null;
        try {
            server = new ServerSocket(PORT);
            socket = server.accept();
            out = new DataOutputStream(socket.getOutputStream());
            
            while(true)
        {
            int c=selectm(socket,out);//调用自己的函数
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
                System.out.println("随机数字符串为:"+jisuan);
                double JiGuo=calcBracket(jisuan);
                System.out.println("结果为:"+ JiGuo);
             /*    PrintWriter pw = new PrintWriter(out);
                     pw.write("欢迎登陆");
                     pw.flush();
                */
                if(JiGuo!=24)
                {
                    
                     out.writeUTF("错了");        
                     out.flush();
                     // continue;
                }
                else
                {
                    out.writeUTF("对了");        
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
    
//获取1-9的随机值
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

   //计算器
    public static double calcBracket(String exp){
        //从最里面的括号开始运算,exp中最后出现的(最内层的括号
        int lastIndexOf = exp.lastIndexOf('(');
        //两种结果
        if (lastIndexOf != -1) {
            //有
            //1.计算最内层括号表达式的值,找对应的右括号
            int rightIndexOf = exp.indexOf(')', lastIndexOf);
            double d = calc(exp.substring(lastIndexOf+1,rightIndexOf));
            //2.把运算结果拼接
            exp = exp.substring(0, lastIndexOf)+d+exp.substring(rightIndexOf+1);
            return calcBracket(exp);
        }else {
            //没有
            //没有括号的表达式
            return calc(exp);
        }
    }

    /**
     * 
     * @param exp 不带括号的四则表达式
     * @return
     */
    public static double calc(String exp){
        //1.把表示负数的-号换成@号
       // exp = fu2At(exp);
        //2.数字的分类
        List<Double> numbers;
        numbers = splitNumExp(exp);
        //3.运算符的分离
        List<Character> ops = splitOpfromExp(exp);
        //4.先乘除
        for (int i = 0; i < ops.size(); i++) {
            //判断,运算符是否是乘除
            char op = ops.get(i);
            //是,取出,运算
            if (op == '*' || op == '/') {
                //取出来,运算
                ops.remove(i);//后面的数据往前顺序移动
                //运算
                //从数字容器中取出对应运算符的两个数字
                double d1 = numbers.remove(i);
                double d2 = numbers.remove(i);

                if (op == '*') {
                    d1 *= d2;
                }else {
                    d1 /= d2;
                }

                //把运算结果放入数字容器中i的位置
                numbers.add(i, d1);//原来i位置(包括)后面的数据依次往后顺移
                i--;
            }
        }
        //5.后加减
        while (!ops.isEmpty() ) {
            char op = ops.remove(0);
            double d1 = numbers.remove(0);
            double d2 = numbers.remove(0);
            //运算
            if (op == '+') {
                d1 += d2;
            } else {
                d1 -= d2;
            }
            //把运算结果插入到数字容器中0的位置
            numbers.add(0, d1);
        }
        //6.容器中的第一个数据就是结果
        return numbers.get(0);
    }

    /**
     * 从表达式中分离表达式和运算符
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
     * 分离出数字
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