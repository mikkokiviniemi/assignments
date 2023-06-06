#include <iostream>
#include <ctime>

/*
Create a software that can calculate the time difference between a start and end time. 
Think how you can split the program into multiple functions.
*/

//Structure for time
struct Time
{
    int hours;
    int minutes;
    int seconds;

    void print (){
        std::cout << hours << ":" << minutes << ":" << seconds << "\n";
    }

    void populate (){
        std::cout << "Hours: ";
        std::cin >> hours;

        std::cout << "Minutes: ";
        std::cin >> minutes;

        std::cout << "Seconds: ";
        std::cin >> seconds;

        std::cout << std::endl;
    }
};

//Counts difference between start and end. Makes another returns Time.
Time countDifference (Time start, Time end) {
    Time difference;

    int totalStartSeconds = start.hours * 3600 + start.minutes * 60 + start.seconds;
    int totalEndSeconds = end.hours * 3600 + end.minutes * 60 + end.seconds;
    int totalDifferenceSeconds = totalEndSeconds - totalStartSeconds;

    difference.hours = totalDifferenceSeconds / 3600;
    difference.minutes = (totalDifferenceSeconds % 3600) / 60;
    difference.seconds = (totalDifferenceSeconds % 3600) % 60;

    return difference;
}


int main()
{
    Time start;
    Time end;
    Time difference;

    std::cout << "Start time: " << std::endl;
    start.populate();

    std::cout << "End time: " << std::endl;
    end.populate();

    difference = countDifference(start,end);

    std::cout << "Difference: ";
    difference.print();


    return 0;
}
