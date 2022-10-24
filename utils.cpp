#include "utils.h"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <limits>

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
    o_file << std::endl << player << " " << attempts ;
    o_file.close();
}

bool isNumber(const std::string& str)
{
    return std::all_of(str.begin(), str.end(), [](const char& ch) { return isdigit(ch); });
}

void search_best_score(std::string filename, bool rewrite){
    std::ifstream o_file{filename}; //Открытый файл
    std::string player; // Имя игрока
    std::string result;
    std::vector<std::string> names; // Список всех игроков из таблицы 
    std::vector<int> results;  // Список всех результатов из таблицы
    int min_result;

// Загружаем в вектор имена из таблицы
    while (true){
      o_file >> player;
      o_file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      if(o_file.fail()){
        break;
      }
      names.push_back(player);
    }

// Сортируем имена и удаляем дубликаты
  sort( names.begin(), names.end() );
  names.erase( unique( names.begin(), names.end() ), names.end());

  o_file.clear();
  o_file.seekg(0, std::ios_base::beg);
  //o_file.close();
  //o_file.open(fileName);
    
// Проходим по всем элементам вектора с именами и ищем в нашем файле все игры для каждого игрока
  unsigned int names_size = names.size();

    // Вывод заполненного вектора на экран
    for (int i = 0; i < names_size; i++) {
      std::vector<int> tmp_results;
      while (!o_file.eof()){
        //if(o_file.fail()){
        //  break;
        //}
        o_file >> player;
        o_file >> result;
        if (player == names[i]){
          tmp_results.push_back(std::stoi(result));
        }

        }
      o_file.clear();
      o_file.seekg(0, std::ios_base::beg);
      
      if (unsigned int results_size = tmp_results.size() >1 ){
        min_result = *std::min_element(tmp_results.begin(),tmp_results.end());
      }
      else if (results_size = tmp_results.size() == 1){
        min_result = tmp_results[0];
      }
      results.push_back(min_result);
    }
    o_file.close();
    //На выходе этого блока мы имеем два вектора, содержащие имена игроков с их лучшим значением

    //Заново открываем файл и перезаписываем данные

    std::cout << std::endl << "High scores table:" << std::endl;
    if (rewrite){
    std::ofstream open_file{filename};
    for (int i = 0; i < names_size; i++) {
      if (i==names_size-1){
        open_file << names[i] << " " << results[i];
      }
      else{
        open_file << names[i] << " " << results[i] << std::endl;
      }
    }
    open_file.close();
    }
    

    for (int i = 0; i < names_size; i++) {
      std::cout << "Player: " << names[i] << " Attempts: " << results[i] << std::endl;
    }
    

}