//implementation of candlestick class header file
// Will contain the open, close, high and low values of a candlestick
// Purpose to encapsulate the data of a candlestick
#pragma once
#include <string>


class Candlestick{
    public:



        double open;
        double close;
        double high;
        double low;

    Candlestick(
                double o,
                double c,
                double h, 
                double l):
                open(o),
                close(c),
                high(h), 
                low(l) {}
       
                // void print() const; 
};
