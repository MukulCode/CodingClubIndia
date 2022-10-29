package com.khan.smartlink;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        try
        {
            Intent dash = new Intent(getApplicationContext(),DashBoard.class);
            startActivity(dash);
            finish();
        }
        catch(Exception e)
        {

        }
    }
}
