#pragma once
#include <string>

//Candlestick class stores data for a single candlestick in a financial chart.
class Candlestick{
    public:
    //time key identify the candle bucket
    //E.g 1980 for yearly, 1980-01 for monthly or 1980-01-01 for daily.
    // 
        std::string time_key;

        double open;
        double close;
        double high;
        double low;

    Candlestick(const std::string& key,
                double o,
                double c,
                double h, 
                double l):
                time_key(key),
                open(o),
                close(c),
                high(h), 
                low(l) {}
       
    private:
};
