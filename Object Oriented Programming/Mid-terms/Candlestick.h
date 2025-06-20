//implementation of candlestick class header file
// Will contain the open, close, high and low values of a candlestick
// Purpose to encapsulate the data of a candlestick
#pragma once
#include <string>

class Candlestick{
    public:
        int time_key; //represent the x-axis value, which could be year
        double open,close,high,low; //represent the y-axis values

    Candlestick(
                int x,
                double o,
                double c,
                double h, 
                double l):
                time_key(x),
                open(o),
                close(c),
                high(h), 
                low(l) {} 
};
