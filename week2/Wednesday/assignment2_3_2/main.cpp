/*
Exercise 1:
Develop a function to simulate data ingestion. 
This function should generate a list of sensor readings. 
Each reading is an object that includes a timestamp (use integers for simplicity), a sensor ID (string), and a sensor value (float).

Exercise 2:
Implement a function that accepts the sensor data list and a sensor ID as parameters. 
This function should filter out the readings from the specified sensor and return them as a new list.

Exercise 3:
Develop a function that sorts the filtered sensor data based on the timestamp in ascending order. 
This can help in understanding the time series behavior of a particular sensor.

Exercise 4:
Develop a function to detect outliers in sensor readings. 
An outlier can be defined as a value that deviates by more than a fixed amount from the mean sensor value.

Exercise 5:
Develop a function to find the sensor that has the highest frequency of readings. 
This might indicate that this sensor's data is crucial or the equipment it's monitoring is critical.

ex1: std::vector<Sensor_object> data_ingestion_simulator (std::string id, int time, float min, float max);

ex2: std::vector<Sensor_object> data_list (std::vector<Sensor_object> data, std::string id);

ex3: bool data_comp (Sensor_object obj1, Sensor_object obj2); void sorted_data (std::vector<Sensor_object>& data);

ex4: float mean_sensor_value (std::vector<Sensor_object>& data); std::vector<Sensor_object> detect_outlier (std::vector<Sensor_object>& data, float deviation);

ex5: std::string highest_frequency (std::vector<Sensor_object>& data);

void print_data (std::vector<Sensor_object>& data);
*/

#include <iostream>
#include "utils.h"
#include <vector>
#include <random>


//Generates random id for sensor
std::string random_id (int min, int max){

    static bool initDone {false};
    if (!initDone){
        std::srand(time(NULL));
        initDone = true;
    }
    std::string return_id = std::to_string(min + rand() % (( max + 1 ) - min));

    return return_id;
}


int main()
{
    std::vector<Sensor_object> all_data;

    for (int i = 0; i < 7; i++ ) {
        std::vector<Sensor_object> some_data = data_ingestion_simulator(random_id(1,5), i, 0.0f, 100.0f);
        all_data.insert (all_data.end (), some_data.begin(), some_data.end ());
    }
    print_data(all_data);

    sorted_data(all_data);
    std::cout << "Sorted by time: \n";
    print_data(all_data);

    std::cout << "Sensor five: \n";
    std::vector<Sensor_object> number_five = data_list(all_data,"5");    
    print_data(number_five);

    std::cout << "Outliers: \n";
    std::vector<Sensor_object> outliers = detect_outlier(all_data,46.0f);
    print_data(outliers);
    std::cout << "Highest frequency "<< highest_frequency(all_data) << "\n";
    return 0;
}
