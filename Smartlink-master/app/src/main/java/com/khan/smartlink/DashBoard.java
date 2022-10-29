package com.khan.smartlink;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.TextView;

public class DashBoard extends AppCompatActivity {


    TextView social_box;
    TextView shopping_box;
    TextView news_box;
    TextView du_box;
    TextView learn_box;
    TextView aboutapp;



    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
//        TextView social_box, shopping_box, news_box, du_box, learn_box;



        super.onCreate(savedInstanceState);
        setContentView(R.layout.dash_board);

            social_box = findViewById(R.id.social_box);
            shopping_box = findViewById(R.id.shopping_box);
        news_box = findViewById(R.id.news_box);
            du_box = findViewById(R.id.du_box);
            learn_box = findViewById(R.id.learn_box);
            aboutapp=findViewById(R.id.about);




     social_box.setOnClickListener(new View.OnClickListener() {
         @Override
         public void onClick(View view) {

             Intent intent =new Intent(DashBoard.this,SocialWebsites.class);
             startActivity(intent);

         }
     });

     shopping_box.setOnClickListener(new View.OnClickListener() {
         @Override
         public void onClick(View view) {

             Intent intent =new Intent(DashBoard.this,Shopping.class);
             startActivity(intent);

         }
     });

     news_box.setOnClickListener(new View.OnClickListener() {
         @Override
         public void onClick(View view) {

             Intent intent =new Intent(DashBoard.this,News.class);
             startActivity(intent);

         }
     });

     du_box.setOnClickListener(new View.OnClickListener() {
         @Override
         public void onClick(View view) {

             Intent intent =new Intent(DashBoard.this,Daily_used.class);
             startActivity(intent);

         }
     });

     learn_box.setOnClickListener(new View.OnClickListener() {
         @Override
         public void onClick(View view) {


             Intent intent =new Intent(DashBoard.this,Learning.class);
             startActivity(intent);
         }
     });

     aboutapp.setOnClickListener(new View.OnClickListener() {
         @Override
         public void onClick(View view) {

             Intent intent=new Intent(DashBoard.this,aboutapp.class);
             startActivity(intent);
         }
     });



    }

        //ClickEvents

    public void Social_Click(View v)
    {
        try
        {
            Intent social = new Intent(getApplicationContext(),SocialWebsites.class);
            startActivity(social);
            finish();
        }
        catch(Exception e)
        {

        }
    }
    public void Shopping_Click(View v)
    {
        try
        {

        }
        catch(Exception e)
        {

        }
    }
    public void News_Click(View v)
    {
        try
        {

        }
        catch(Exception e)
        {

        }
    }
    public void DU_Click(View v)
    {
        try
        {

        }
        catch(Exception e)
        {

        }
    }
    public void Learn_Click(View v)
    {
            try
            {

            }
            catch(Exception e)
            {

            }
        }
    }
