#include "utils.h"

#include <iostream>


int main() {
    std::string filename = "high_scores.txt";
    std::string name;
    int number;
    int counter = 1;

    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::cin >> name;

    int random_number = pick_the_number();
    //int random_number = 52;
    std::cout << "Enter your guess:" << std::endl;
    while(true)
    {
        while (!(std::cin>>number)){
            std::cout << "Not num" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }


        if (random_number < number){
            std::cout << "less than" << std::endl;
            counter++;
            pick_the_number();
        }
        else if (random_number > number){
            std::cout << "more than" << std::endl;
            counter++;
        }
        else{
            std::cout << "you win! attempts = " << counter << std::endl;
            write_result(filename,name,counter);
            std::cout << std::endl << "High scores table:" << std::endl;
            read_file("high_scores.txt");
            break;
        }
    }
    return 0;

}