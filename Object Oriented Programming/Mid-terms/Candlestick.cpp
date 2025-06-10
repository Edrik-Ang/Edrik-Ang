//implementation of candlestick class
//Will contain the open, close, high and low values of a candlestick 
//Purpose to encapsulate the data of a candlestick
#include <Candlestick.h>
#include <iostream>

Candlestick::Candlestick(
    double o,
    double c,
    double h, 
    double l):
    open(o),
    close(c),
    high(h), 
    low(l) {}


