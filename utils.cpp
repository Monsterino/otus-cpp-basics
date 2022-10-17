#include "utils.h"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

int pick_the_number(){
    std::srand(std::time(nullptr));
    const int random_value = std::rand() % 100;
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