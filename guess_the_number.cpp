#include "utils.h"
#include <string>
#include <iostream>


int main(int argc, char** argv) {
    std::string filename = "high_scores.txt"; // Имя файла с рекордами
    std::string name;                         // Введенное имя игрока
    int number;                               // Введенное игроком число    
    int counter = 1;                          // Счетчик попыток
    int random_number;                        // Случайно выбранное компьютером число
     
    //если аргументов больше одного, но меньше трех
    if (argc > 1 && argc <= 3){    

        std::string parameter{ argv[1]};  // считываем первый параметр
        if (parameter == "-table"){
            std::cout <<  " You start the program with flag:-table" << std::endl;
            read_file("high_scores.txt"); // Выводим таблицу
            return 0;
        }
        // Если флаг max
        else if (parameter == "-max") 
        {
            std::cout <<  "You start the program with flag: -max" << std::endl;
            if (argc == 3){   // Проверяем на количество аргументов. Если их 3, то все работает, если нет, то выводим ошибку о том, что данный флаг требует еще значения
            
                int max;
                std::string val = argv[2];
                if (isNumber(val)){   // Проверяем, является ли значение для данного параметра числом
                    max = std::stoi(val);
                }
                else{
                    std::cout << "Value must be an integer";
                    return -1;
                }
                
                std::cout <<  "parameter: " << max  << std::endl;
                random_number = pick_the_number(parameter,max);  // Генерируем случайное число
            }
            else {
                std::cout <<  "Wrong usage! The argument '-max' requires value!" << std::endl;
                return -1;
            }
        }
        // Аналогично предыдущему флагу , с той лишь разницей, что значение при флаге level должно быть от 1 до 3
        else if (parameter == "-level") 
        {
            std::cout <<  "You start the program with flag: -level" << std::endl;
            if (argc == 3)
            {
                int max;
                std::string val = argv[2];
                if (isNumber(val)){
                    max = std::stoi(val);
                }
                else{
                    std::cout << "Value must be an integer" << std::endl;
                    return -1;
                }

                std::cout <<  "parameter: " << max  << std::endl;

                if (max > 3 || max < 1){
                    std::cout<< "Min level is 1, max level is 3" << std::endl;
                    return 0;
                }
                random_number = pick_the_number(parameter,max);
            }
            else {
                std::cout <<  "Wrong usage! The argument '-level' requires value!" << std::endl;
                return -1;
            }            
        }
        // Проверка на неверный параметр
        else {
            std::cout <<  "Wrong parameter" << std::endl;
            return -1;
        }
    }
    // Проверка на случай, если параметров нет. Тогда программа будет работать со значениями по умолчанию
    else if (argc == 1){
        random_number = pick_the_number("None",0);
    }
    else if (argc > 1){ 
        std::cout << "So many arguments";
        return -1;
    }
    

    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::cin >> name;

//    int random_number = pick_the_number();
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
        }
        else if (random_number > number){
            std::cout << "more than" << std::endl;
            counter++;
        }
        else{
            std::cout << "you win! attempts = " << counter << std::endl;
            write_result(filename,name,counter);
            search_best_score(filename);  
            std::cout << std::endl << "High scores table:" << std::endl;
            read_file("high_scores.txt");
            break;
        }
    }
    return 0;

}