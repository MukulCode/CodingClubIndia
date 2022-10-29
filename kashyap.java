package com.company;


import javax.swing.*;
import java.awt.*;

public class Main {

    public static void main(String[] args)
    {
	 Abc obj=new Abc();

    }
}
class Abc extends JFrame
{JTextField t1,t2;
JLabel l,l1,l2;
JButton b1,b2;
    public Abc(){

       l= new JLabel("hello kashyp");
       l1=new JLabel("shukla");
       t1=new JTextField(15);
       t2=new JTextField(15);
       b1=new JButton("sum");
       b2=new JButton("sub");
      l2=new JLabel("result");
      add(l);
      add(l1);
      add(t1);
      add(t2);
      add(b1);
      add(b2);
      add(l2);
        b1.addActionListener(ae ->
        {
            int num1=Integer.parseInt(t1.getText());
            int num2=Integer.parseInt(t2.getText());
            int value=num1+num2;
            l2.setText(value+"");
        });
        b2.addActionListener(ae ->
        {
            int num1=Integer.parseInt(t1.getText());
            int num2=Integer.parseInt(t2.getText());
            int value=num1-num2;
            l2.setText(value+"");
        });
        setLayout( new FlowLayout());
        setVisible(true);
        setSize(400,400);
        setDefaultCloseOperation(3);
    }
}