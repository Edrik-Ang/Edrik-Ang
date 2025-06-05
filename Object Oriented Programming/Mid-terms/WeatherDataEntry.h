#pragma once
#include <string>


//**WeatherDataEntry class is to encapsulate the data of each line read to be later organised. */
//Takes the timestamp and the weather data for each country as parameters.
//The timestamp is a string, while the weather data for each country is a double.
class WeatherDataEntry {
    public:
        WeatherDataEntry(std::string _timestamp,  
                        double _AT,
                        double _BE,
                        double _BG,
                        double _CH,
                        double _CZ,
                        double _DE,
                        double _DK,
                        double _EE,
                        double _ES,
                        double _FI,
                        double _FR,
                        double _GB,
                        double _GR,
                        double _HR,
                        double _HU,
                        double _IE,
                        double _IT,
                        double _LT,
                        double _LU,
                        double _LV,
                        double _NL,
                        double _NO,
                        double _PL,
                        double _PT,
                        double _RO,
                        double _SE,
                        double _SI,
                        double _SK
                         );

        std::string timestamp;
        double AT;
        double BE;
        double BG;
        double CH;
        double CZ;
        double DE;
        double DK;
        double EE;
        double ES;
        double FI;
        double FR;
        double GB;
        double GR;
        double HR;
        double HU;
        double IE;
        double IT;
        double LT;
        double LU;
        double LV;
        double NL;
        double NO;
        double PL;
        double PT;
        double RO;
        double SE;
        double SI;
        double SK;
            


};