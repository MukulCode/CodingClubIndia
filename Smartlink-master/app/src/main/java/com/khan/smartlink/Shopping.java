package com.khan.smartlink;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.text.method.LinkMovementMethod;
import android.view.View;
import android.widget.TextView;

public class Shopping extends AppCompatActivity {

   TextView amazon;
    TextView lenskart;
    TextView grofers;
    TextView spoyl;
    TextView olx;
    TextView bigbasket;
    TextView ajio;
    TextView jabong;
    TextView myntra;
    TextView snapdeal;
    TextView ebay;
    TextView aliexpress;
    TextView flipkart;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.shopping);

        amazon=(TextView)findViewById(R.id.Amazon);
        amazon.setMovementMethod(LinkMovementMethod.getInstance());

        lenskart=(TextView)findViewById(R.id.Lenskart);
        lenskart.setMovementMethod(LinkMovementMethod.getInstance());

        grofers=(TextView)findViewById(R.id.Grofers);
        grofers.setMovementMethod(LinkMovementMethod.getInstance());


        spoyl=(TextView)findViewById(R.id.Spoyl);
        spoyl.setMovementMethod(LinkMovementMethod.getInstance());


        olx=(TextView)findViewById(R.id.OLX);
        olx.setMovementMethod(LinkMovementMethod.getInstance());


        bigbasket=(TextView)findViewById(R.id.bigBasket);
        bigbasket.setMovementMethod(LinkMovementMethod.getInstance());


        ajio=(TextView)findViewById(R.id.Ajio);
        ajio.setMovementMethod(LinkMovementMethod.getInstance());


        jabong=(TextView)findViewById(R.id.Jabong);
        jabong.setMovementMethod(LinkMovementMethod.getInstance());


        myntra=(TextView)findViewById(R.id.Myntra);
        myntra.setMovementMethod(LinkMovementMethod.getInstance());


        snapdeal=(TextView)findViewById(R.id.Snapdeal);
        snapdeal.setMovementMethod(LinkMovementMethod.getInstance());


        ebay=(TextView)findViewById(R.id.eBay);
        ebay.setMovementMethod(LinkMovementMethod.getInstance());


        aliexpress=(TextView)findViewById(R.id.Ali_express);
        aliexpress.setMovementMethod(LinkMovementMethod.getInstance());


        flipkart=(TextView)findViewById(R.id.Flipkart);
        flipkart.setMovementMethod(LinkMovementMethod.getInstance());


    }

    public void FlipkartClick(View view)
    {
        CallWeb("https://www.flipkart.com/");
    }


    public void AjioClick(View view)
    {
        CallWeb("https://www.ajio.com/");
    }


    public void aliexpressClick(View view)
    {
        CallWeb("https://www.aliexpress.com/");
    }



    public void snapdealClick(View view)
    {
        CallWeb("https://www.snapdeal.com/");
    }


    public void ebayClick(View view)
    {
        CallWeb("https://www.ebay.com/");
    }

    public void amazonClick(View view)
    {
        CallWeb("https://www.amazon.in/");
    }

    public void LenskartClick(View view)
    {
        CallWeb("https://www.lenskart.com/");
    }

    public void grofersClick(View view)
    {
        CallWeb("https://grofers.com/");
    }

    public void spoylClick(View view)
    {
        CallWeb("https://www.spoyl.in/");
    }

    public void olxClick(View view)
    {
        CallWeb("https://www.olx.in/");
    }

    public void bigbasketClick(View view)
    {
        CallWeb("https://www.bigbasket.com/");
    }


    public void jabongClick(View view)
    {
        CallWeb("https://www.jabong.com/");
    }

    public void myntraClick(View view)
    {
        CallWeb("https://www.myntra.com/");
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
