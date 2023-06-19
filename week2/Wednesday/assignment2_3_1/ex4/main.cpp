/*
Exercise 4:

Create a vector of strings and sort them in lexicographical order. Also, sort them based on the string length.
*/

#include <iostream>
#include <vector>
#include <algorithm>

bool length_comp(std::string str,std::string str2) {
    if(str.length() > str2.length()){
        return true;
    }
    return false;
}

int main()
{
    std::vector<std::string> vec = {"Ooooooasd","Hello","Hi","Moikka","Moro","Öre","Äre","Åre"};

    std::sort(vec.begin(),vec.end());

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n\n";
    std::sort(vec.begin(),vec.end(),length_comp);

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
