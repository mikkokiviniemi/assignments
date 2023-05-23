#include <iostream>

/*

You are offered a job at a company that pays salary as follows. 
The first day you earn 1 euro. and for the following days the salary always doubles from the last day. 
Write a program that calculates how long you need to work to have earned 10 million euros. 

*/

int days(){

    int days = 1;
    int salary = 1;

    while(salary < 1000000){

        salary = salary * 2;
        days = days + 1;

    }

    return days;

}

int main()
{
    
    std::cout<<days()<<std::endl;
    

    return 0;
}
