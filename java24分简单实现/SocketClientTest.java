//import java.awt.*;
import java.util.*;
import java.io.*;
import java.net.*;
import java.util.logging.Level;
import java.util.logging.Logger;

import java.awt.event.*;
import java.awt.*;
import javax.swing.*;
public class SocketClientTest {
    JTextArea showArea;
    JTextField msgText;
    JFrame mainJframe;
    JButton sentBtn; 
    JScrollPane JSPane;
    JPanel pane;
     
    private static final String HOST="127.0.0.1";
    private static final int PORT=5209;
    public static int count = 0; 
    
    public static Socket socket = null;
     public static   DataInputStream dis = null;
     public static   InputStream is = null;
     
    private  void test(){
       try{
           showArea.setLineWrap(true);
           
           socket = new Socket(HOST,PORT);
            System.out.println("连接成功！！！");
            is = socket.getInputStream();
            dis = new DataInputStream(is);
           DataOutputStream  out = new DataOutputStream(socket.getOutputStream());
         while(true){
           ShowTable(dis,out);
         }
        }catch(Exception e){
            e.printStackTrace();
        }

      
    }
    private static void Game(DataInputStream dis,DataOutputStream out){
          try{        
          
           
                System.out.println("随机数为:"+dis.readUTF());
                
                out.writeUTF(getMath());
               System.out.println(dis.readUTF());
                out.flush();
            
        }catch(Exception e){
            e.printStackTrace();
        }
    }
     private static void ShowTable(DataInputStream dis,DataOutputStream out){
         System.out.println("\n游戏选 1 ：");
         System.out.println("统计选 2 ：");
         Scanner scanner = new Scanner(System.in);
            int a = scanner.nextInt();
         if(a==1)
         {
             try {
                 for(int i=0;i<5;i++)
                     Game(dis,out);
                 System.out.println("\n得分为："+dis.readInt());
             } catch (IOException ex) {
                 Logger.getLogger(SocketClientTest.class.getName()).log(Level.SEVERE, null, ex);
             }
         }
         else
         {
             TopPeople(count);
         }
     }
     private static void TopPeople(int count){
          System.out.println("\n第一名:"+count);
          System.out.println("第二名:"+count);
          System.out.println("第三名:"+count);
          System.out.println("第四名:"+count);
          System.out.println("第五名:"+count);
          System.out.println("第六名:"+count);
          System.out.println("第七名:"+count);
          System.out.println("第八名:"+count);
          System.out.println("第九名:"+count);
          System.out.println("第十名:"+count);
     }
private static String getMath(){
      Scanner ss= new Scanner(System.in);
      String sc = ss.next();
       return sc;
    }



 




    public static void main(String[] args){

       new SocketClientTest().test();
    }
}