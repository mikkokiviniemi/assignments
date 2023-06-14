#include "utils.h"

float rand_float(float min, float max) {
    std::random_device random_device;
    std::mt19937 mt(random_device());
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(mt);
}

//Develop a function to simulate data ingestion. 
//This function should generate a list of sensor readings. 
std::vector<Sensor_object> data_ingestion_simulator (std::string id, int time, float min, float max) {
    std::vector<Sensor_object> new_ingestion;

    for (int i = 0; i < time; i++) {
        Sensor_object new_object = {id,i,rand_float(min,max)};
        new_ingestion.push_back(new_object);
    }

    return new_ingestion;
}

//Implement a function that accepts the sensor data list and a sensor ID as parameters. 
//This function should filter out the readings from the specified sensor and return them as a new list.
std::vector<Sensor_object> data_list (std::vector<Sensor_object> data, std::string id) {
    std::vector<Sensor_object> data_return;

    for (auto& object : data) {
        if (object.id == id) {
            data_return.push_back(object);
        }
    }

    return data_return;
}

//Data timestamp comparator
bool data_comp (Sensor_object obj1, Sensor_object obj2) {
    return obj1.timestamp < obj2.timestamp;
}

//Develop a function that sorts the filtered sensor data based on the timestamp in ascending order. 
//This can help in understanding the time series behavior of a particular sensor.
void sorted_data (std::vector<Sensor_object>& data) {
    std::sort(data.begin(), data.end(),data_comp);
}

float mean_sensor_value (std::vector<Sensor_object>& data) {
    float sum = 0.0f;
    int size = data.size();

    for (auto& object : data) {
        sum += object.value;
    }

    return sum/size;
}

//Develop a function to detect outliers in sensor readings. 
//An outlier can be defined as a value that deviates by more than a fixed amount from the mean sensor value.
std::vector<Sensor_object> detect_outlier (std::vector<Sensor_object>& data, float deviation) {
    std::vector<Sensor_object> outliers;

    float mean = mean_sensor_value(data);
    
    for (auto& object : data) {
        if (object.value > mean + deviation || object.value < mean - deviation) {
            outliers.push_back(object);
        } 
    }
    return outliers;
}

//Develop a function to find the sensor that has the highest frequency of readings. 
//This might indicate that this sensor's data is crucial or the equipment it's monitoring is critical.
std::string highest_frequency (std::vector<Sensor_object>& data) {
    int highest_frequency = 0;
    std::string highest;

    for (auto& object : data) {
        int current_frequency = 0;
        std::string current_id = object.id;
        for (auto& object : data) {
            if (object.id == current_id) {
                ++current_frequency;
            }
        }
        if (current_frequency > highest_frequency) {
            highest_frequency = current_frequency;
            highest = current_id;
        }
    }

    return highest;
}

//Prints data "[Sensor n] 0.000 time:n"
void print_data (std::vector<Sensor_object>& data) {
    for(auto& object : data) {
        std::cout << "[Sensor " << object.id << "] " << std::setw(10) << std::fixed << object.value << " time: " << object.timestamp << "\n";
    }
}