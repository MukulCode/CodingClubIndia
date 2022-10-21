import React, { useEffect, useState } from "react";
import './covid.css'
const Covid = () => {
    const [data, setData] = useState([]);
    const getCovidData = async () => {
        try {
            const res = await fetch('https://data.covid19india.org/data.json');
            const actualData = await res.json();
            console.log(actualData.statewise[0]);
            setData(actualData.statewise[0]);
        } catch(err){
            console.log(err);
        }
    }

useEffect(() =>{
    getCovidData();
}, []);
return (
    <>
    <section>
    <h1>🔴 LIVE COVID-19 </h1>
    <h2> COVID-19 TRACKER DETAIL </h2>
    <ul>
        <li className="card 1">
        <div className="card__main">
        <div className="card__inner">
        <p className="card__name"><span>OUR </span>COUNTRY</p>
        <p className="card__total card__small"></p>INDIA</div>
</div>
        </li>
        <li className="card 2">
        <div className="card__main">
        <div className="card__inner">
        <p className="card__name"><span>TOTAL </span>RECOVERED</p>
        <p className="card__total card__small"></p>{data.recovered}</div>
</div>
        </li><li className="card 3">
        <div className="card__main">
        <div className="card__inner">
        <p className="card__name"><span>TOATL </span>CONFIRMED</p>
        <p className="card__total card__small"></p>{data.confirmed}</div>
</div>
        </li><li className="card 4">
        <div className="card__main">
        <div className="card__inner">
        <p className="card__name"><span>TOATL </span>DEATHS</p>
        <p className="card__total card__small"></p>{data.deaths}</div>
</div>
        </li><li className="card 5">
        <div className="card__main">
        <div className="card__inner">
        <p className="card__name"><span>TOATL </span>ACTIVE</p>
        <p className="card__total card__small"></p>{data.active}</div>
</div>
        </li><li className="card 6">
        <div className="card__main">
        <div className="card__inner">
        <p className="card__name"><span>LAST </span>UPDATED</p>
        <p className="card__total card__small"></p>{data.lastupdatedtime}</div>
</div>
        </li>
    </ul>
    </section>
    </>
)
}
export default Covid