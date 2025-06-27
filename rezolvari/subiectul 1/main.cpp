#include <iostream>
#include <string>
#include <string.h>
#include "Weather.h"
#include "Region.h"

int main(){

    //testing
    float temps[4] = {27.5, 29.3, 34.5, 36};
    float temps2[4] = {23, 22.4, 21.3, 20.1};
    
    Weather w1("27/06/2025", temps, 4, "Really hot", (char*)"Bucharest");
    Weather w2("28/06/2025", temps2, 4, "Sunny", (char*)"Brasov");

    Weather w3 = w1;

    Region region;
    region.addWeather(w1);
    region.addWeather(w2);
    region.addWeather(w3);

    region.displayWeather();

    return 0;
}