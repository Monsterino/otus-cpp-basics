#include "utils.h"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <algorithm>

int pick_the_number(std::string parameter,int value){
    std::srand(std::time(nullptr));
    int random_value;
    if (parameter == "-max"){
      random_value = std::rand() % value;
    }
    else if (parameter == "-level"){

      switch (value)
      {
      case 1:
        random_value = std::rand() % 10;
        break;
      case 2:
        random_value = std::rand() % 50;
        break;
      case 3:
        random_value = std::rand() % 100;
        break;
      default:
        break;
      }
    }
    else if (parameter == "None")
    {
      random_value = std::rand() % 100;
    }
    else{
      std::cout<< "Unknown parameter" << std::endl;
    }
    
    return random_value;
}

void read_file(std::string filename){
    std::ifstream o_file{filename};

    std::string player;
    int attempts;
    while (true){
      o_file >> player;
      o_file >> attempts;
      if(o_file.fail()){
        break;
      }
      std::cout << "Player: " << player << " Attempts: " << attempts << std::endl;
    }
    o_file.close();
}

void write_result(std::string filename, std::string player, int attempts){
    std::ofstream o_file{filename, std::ios_base::app};
    o_file << player << " " << attempts << std::endl;
    o_file.close();
}

bool isNumber(const std::string& str)
{
    return std::all_of(str.begin(), str.end(), [](const char& ch) { return isdigit(ch); });
}