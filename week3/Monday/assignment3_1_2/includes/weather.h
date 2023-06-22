#ifndef WEATHER_H
#define WEATHER_H

#include <iostream>
#include <vector>
#include <random>
#include <exception>

struct Weather {
    float temperature;
    float humidity;
    float wind_speed;
    float atmospheric_pressure;
    int time;
};

float random_float(float min, float max);

std::vector<Weather> weather_simulator (int hours);

bool valid_data (Weather weather);

void check_data (std::vector<Weather> data);

void print_weather_data (std::vector<Weather> data);

#endif  