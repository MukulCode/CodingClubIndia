package com.khan.smartlink;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.text.method.LinkMovementMethod;
import android.view.View;
import android.widget.TextView;

public class News extends AppCompatActivity {



    TextView abc;
    TextView bbc;
    TextView google;
    TextView cnn;
    TextView nasa;
    TextView indiatimes;
    TextView timesofindia;
    TextView news24;
    TextView nbc;
    TextView mumbaimirror;
    TextView ndtv;
    TextView indiatoday;
    TextView dna;
    TextView yahoo;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.news);

        abc=(TextView)findViewById(R.id.ABC_News);
        abc.setMovementMethod(LinkMovementMethod.getInstance());

        bbc=(TextView)findViewById(R.id.BBC_News);
        bbc.setMovementMethod(LinkMovementMethod.getInstance());

        google=(TextView)findViewById(R.id.Google_News);
        google.setMovementMethod(LinkMovementMethod.getInstance());


        cnn=(TextView)findViewById(R.id.CNN_News);
        cnn.setMovementMethod(LinkMovementMethod.getInstance());


        nasa=(TextView)findViewById(R.id.NASA_News);
        nasa.setMovementMethod(LinkMovementMethod.getInstance());


        indiatimes=(TextView)findViewById(R.id.India_Times);
        indiatimes.setMovementMethod(LinkMovementMethod.getInstance());


        timesofindia=(TextView)findViewById(R.id.Times_Of_India);
        timesofindia.setMovementMethod(LinkMovementMethod.getInstance());


        news24=(TextView)findViewById(R.id.News_24);
        news24.setMovementMethod(LinkMovementMethod.getInstance());


        nbc=(TextView)findViewById(R.id.NBC_News);
        nbc.setMovementMethod(LinkMovementMethod.getInstance());


        mumbaimirror=(TextView)findViewById(R.id.Mumbai_Mirror);
        mumbaimirror.setMovementMethod(LinkMovementMethod.getInstance());


        ndtv=(TextView)findViewById(R.id.NDTV_News);
        ndtv.setMovementMethod(LinkMovementMethod.getInstance());


        indiatoday=(TextView)findViewById(R.id.India_Today);
        indiatoday.setMovementMethod(LinkMovementMethod.getInstance());


        dna=(TextView)findViewById(R.id.DNA);
        dna.setMovementMethod(LinkMovementMethod.getInstance());

        yahoo=(TextView)findViewById(R.id.Yahoo_News);
        yahoo.setMovementMethod(LinkMovementMethod.getInstance());

    }



    public void ABCClick(View view)
    {
        CallWeb("https://abcnews.go.com/");
    }


    public void BCCClick(View view)
    {
        CallWeb("https://www.bbc.com/news");
    }


    public void googlenewsClick(View view)
    {
        CallWeb("https://news.google.com/");
    }



    public void CNNClick(View view)
    {
        CallWeb("https://edition.cnn.com/");
    }


    public void NASAClick(View view)
    {
        CallWeb("https://www.nasa.gov/news/releases/latest/index.html");
    }

    public void indiatimesClick(View view)
    {
        CallWeb("https://www.indiatimes.com/");
    }

    public void timesofindiaClick(View view)
    {
        CallWeb("https://timesofindia.indiatimes.com/");
    }

    public void NBCClick(View view)
    {
        CallWeb("https://www.nbcnews.com/");
    }

    public void mumbaimirrorClick(View view)
    {
        CallWeb("https://mumbaimirror.indiatimes.com/");
    }

    public void NDTVClick(View view)
    {
        CallWeb("https://www.ndtv.com/");
    }

    public void indiatodayClick(View view)
    {
        CallWeb("https://www.indiatoday.in/");
    }


    public void DNAClick(View view)
    {
        CallWeb("https://www.dnaindia.com/");
    }

    public void news24Click(View view)
    {
        CallWeb("https://www.news24.com/");
    }

    public void YAhooClick(View view)
    {
        CallWeb("https://in.news.yahoo.com/");
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
