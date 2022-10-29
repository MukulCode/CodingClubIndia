package com.khan.smartlink;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.text.method.LinkMovementMethod;
import android.view.View;
import android.widget.TextView;

public class SocialWebsites extends AppCompatActivity {


    TextView Whatsapp;
    TextView instagram;
    TextView twitter;
    TextView pinterest;
    TextView reditt;
    TextView quora;
    TextView youtube;
    TextView telegram;
    TextView skype;
    TextView wikipedia;
    TextView netflix;
    TextView amazaonprime;


    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.social_websites);

        Whatsapp=(TextView)findViewById(R.id.whatsapp);
        Whatsapp.setMovementMethod(LinkMovementMethod.getInstance());

        instagram=(TextView)findViewById(R.id.Instagram);
        instagram.setMovementMethod(LinkMovementMethod.getInstance());

        twitter=(TextView)findViewById(R.id.Twitter);
        twitter.setMovementMethod(LinkMovementMethod.getInstance());


        pinterest=(TextView)findViewById(R.id.Pinterest);
        pinterest.setMovementMethod(LinkMovementMethod.getInstance());


        reditt=(TextView)findViewById(R.id.Reddit);
        reditt.setMovementMethod(LinkMovementMethod.getInstance());


        quora=(TextView)findViewById(R.id.Quora);
        quora.setMovementMethod(LinkMovementMethod.getInstance());


        youtube=(TextView)findViewById(R.id.Youtube);
        youtube.setMovementMethod(LinkMovementMethod.getInstance());


        telegram=(TextView)findViewById(R.id.Telegram);
        telegram.setMovementMethod(LinkMovementMethod.getInstance());


        skype=(TextView)findViewById(R.id.Skype);
        skype.setMovementMethod(LinkMovementMethod.getInstance());


        wikipedia=(TextView)findViewById(R.id.Wkipidea);
        wikipedia.setMovementMethod(LinkMovementMethod.getInstance());


        netflix=(TextView)findViewById(R.id.Netflix);
        netflix.setMovementMethod(LinkMovementMethod.getInstance());


        amazaonprime=(TextView)findViewById(R.id.Amazon_prime);
        amazaonprime.setMovementMethod(LinkMovementMethod.getInstance());


    }


    public void whatsappClick(View view)
    {
        CallWeb("https://web.whatsapp.com/");
    }


    public void instagramClick(View view)
    {
        CallWeb("https://www.instagram.com/");
    }


    public void twitterClick(View view)
    {
        CallWeb("https://twitter.com/login");
    }



    public void pinterestClick(View view)
    {
        CallWeb("https://in.pinterest.com/");
    }


    public void redditClick(View view)
    {
        CallWeb("https://www.reddit.com/");
    }

    public void quoraClick(View view)
    {
        CallWeb("https://www.quora.com/");
    }

    public void youtubeClick(View view)
    {
        CallWeb("https://www.youtube.com/");
    }

    public void telegramClick(View view)
    {
        CallWeb("https://telegram.org/");
    }

    public void skypeClick(View view)
    {
        CallWeb("https://www.skype.com/en/");
    }

    public void wikipediaClick(View view)
    {
        CallWeb("https://www.wikipedia.org/");
    }

    public void netflixClick(View view)
    {
        CallWeb("https://www.netflix.com/in/Login");
    }


    public void amazonprimeClick(View view)
    {
        CallWeb("https://www.primevideo.com/");
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



