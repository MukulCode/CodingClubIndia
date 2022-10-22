package com.khan.smartlink;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.text.method.LinkMovementMethod;
import android.view.View;
import android.widget.TextView;

public class Learning extends AppCompatActivity {


    TextView udemy;
    TextView academicearth;
    TextView codeacademy;
    TextView geeksforgeeks;
    TextView tutorialpoint;
    TextView w3school;
    TextView sololearn;
    TextView courseera;
    TextView khanacademy;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.learning);


        udemy=(TextView)findViewById(R.id.Udemy);
        udemy.setMovementMethod(LinkMovementMethod.getInstance());

        academicearth=(TextView)findViewById(R.id.Academic_earth);
        academicearth.setMovementMethod(LinkMovementMethod.getInstance());

        codeacademy=(TextView)findViewById(R.id.Code_Academy);
        codeacademy.setMovementMethod(LinkMovementMethod.getInstance());


        geeksforgeeks=(TextView)findViewById(R.id.GeeksforGeeks);
        geeksforgeeks.setMovementMethod(LinkMovementMethod.getInstance());


        tutorialpoint=(TextView)findViewById(R.id.Tutorials_point);
        tutorialpoint.setMovementMethod(LinkMovementMethod.getInstance());


        w3school=(TextView)findViewById(R.id.W3School);
        w3school.setMovementMethod(LinkMovementMethod.getInstance());


        sololearn=(TextView)findViewById(R.id.Sololearn);
        sololearn.setMovementMethod(LinkMovementMethod.getInstance());


        courseera=(TextView)findViewById(R.id.Coursera);
        courseera.setMovementMethod(LinkMovementMethod.getInstance());


        khanacademy=(TextView)findViewById(R.id.Khan_Academy);
        khanacademy.setMovementMethod(LinkMovementMethod.getInstance());


    }


    public void udemyClick(View view)
    {
        CallWeb("https://www.udemy.com/");
    }


    public void academicClick(View view)
    {
        CallWeb("https://academicearth.org/");
    }


    public void codeClick(View view)
    {
        CallWeb("https://www.codecademy.com/");
    }



    public void gfgClick(View view)
    {
        CallWeb("https://www.geeksforgeeks.org/");
    }


    public void tutoClick(View view)
    {
        CallWeb("https://www.tutorialspoint.com/index.htm");
    }

    public void w3sClick(View view)
    {
        CallWeb("https://www.w3schools.com/");
    }

    public void soloClick(View view)
    {
        CallWeb("https://www.sololearn.com/");
    }

    public void courseClick(View view)
    {
        CallWeb("https://www.coursera.org/");
    }

    public void khanClick(View view)
    {
        CallWeb("https://www.khanacademy.org/");
    }

    private void CallWeb(String url)
    {

        Intent intent = new Intent();
        intent.setAction(Intent.ACTION_VIEW);
        intent.addCategory(Intent.CATEGORY_BROWSABLE);
        intent.setData(Uri.parse(url));
        startActivity(intent);
    }


}


