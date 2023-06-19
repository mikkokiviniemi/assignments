/*
Modbus communication
Modbus is a communication protocol for connecting electronic devices, 
allowing them to exchange data and be controlled by a central computer.

In this exercise you are going to simulate a simple Modbus communication between one master device and a 10 slave devices. 
All the data will be stored in and read from files.

Exercise 1:
Every device has an unique id, is it master or slave device, 
and each slave device has a data register with the register address and a value for the register.

Start by creating a program that generates the devices and stores them in a file called devices.csv (comma separated values) 
and another file called registers.csv that will store the slave devices id, register address and value.
https://fi.wikipedia.org/wiki/CSVLinks to an external site.

Exercise 2:
Your program will simulate the master device reading a register from a slave device. 
Specify the slave device id, and register number, the program will then read the correct device and register, and print the register value.

Exercise 3:
Simulate the master writing a value into a slave device's register. 
Specify the id, register address and the new value. 
The program should update the value in the "register.txt" file.
*/

#include <iostream>
#include "utils.h"
#include <vector>

int main()
{
    std::vector<Device> devices;
    //std::vector<Device> addition = fill_devices(3);
    //devices.insert(devices.end(),addition.begin(),addition.end());

    devices_registers_from_files(devices,"./data/devices.csv","./data/registers.csv");

    write_address_value(devices,"slave_1",1,"Kirjoitetaan valueen");

    //std::cout << get_address_value(devices,"slave_1",1) << "\n";

    devices_to_file(devices, "./data/devices.csv");
    registers_to_file(devices,"./data/registers.csv");

    return 0;
}
