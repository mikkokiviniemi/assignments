#include <iostream>

//Hämmentävä tehtävä en tiedä oliko ihan oikein :D

int func1(){
    int variable = 7;
    return variable;
}

int func2(int variable){
    variable = 3;
    std::cout << "Variable inside func2 " << variable << std::endl;
    return variable;
}

int main()
{

    int var = func1();
    //Prints 7
    std::cout <<"Before func2 "<< var << std::endl;

    //Prints 3
    var = func2(var);

    //Prints 3
    std::cout << "After func2 " << var << std::endl;

    return 0;
}
