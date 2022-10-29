package com.khan.smartlink;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.text.method.LinkMovementMethod;
import android.view.View;
import android.widget.TextView;

public class Daily_used extends AppCompatActivity {



    TextView calculator;
    TextView converter;
    TextView currency;
    TextView timezone;
    TextView map;
    TextView accuweather;
    TextView translator;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.daily_used);

        converter=(TextView)findViewById(R.id.Converter_);
        converter.setMovementMethod(LinkMovementMethod.getInstance());

        calculator=(TextView)findViewById(R.id.Calculator);
        calculator.setMovementMethod(LinkMovementMethod.getInstance());

        currency=(TextView)findViewById(R.id.Currency);
        currency.setMovementMethod(LinkMovementMethod.getInstance());


        timezone=(TextView)findViewById(R.id.Time_Zone);
        timezone.setMovementMethod(LinkMovementMethod.getInstance());


        map=(TextView)findViewById(R.id.Map);
        map.setMovementMethod(LinkMovementMethod.getInstance());


        accuweather=(TextView)findViewById(R.id.AccuWeather);
        accuweather.setMovementMethod(LinkMovementMethod.getInstance());


        translator=(TextView)findViewById(R.id.Translator);
        translator.setMovementMethod(LinkMovementMethod.getInstance());

    }


    public void calcClick(View view)
    {
        CallWeb("https://www.online-calculator.com/");
    }


    public void converterClick(View view)
    {
        CallWeb("https://www.online-convert.com/");
    }


    public void currencyClick(View view)
    {
        CallWeb("https://www.unitconverters.net/currency-converter.html");
    }



    public void timezoneClick(View view)
    {
        CallWeb("https://www.timeanddate.com/time/map/");
    }


    public void mapClick(View view)
    {
        CallWeb("https://maps.google.com");
    }

    public void accuClick(View view)
    {
        CallWeb("https://www.accuweather.com/");
    }

    public void translatorClick(View view)
    {
        CallWeb("https://translate.google.com/");
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
