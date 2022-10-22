#pragma once
#include <string>


int pick_the_number(std::string parameter,int value); // Функция выбора случайного числа
void read_file(std::string filename); // Функция чтения файла
void write_result(std::string filename, std::string player, int attempts); //Функция записи результата

bool isNumber(const std::string& str); // Функция проверки, является ли введенная запись в консоли - числом

void search_best_score(std::string filename,bool rewrite);