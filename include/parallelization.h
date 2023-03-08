#pragma once

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <chrono>
#include <string>
#include <thread>
#include <mutex>
#include <filesystem>

namespace fs = std::filesystem;


static bool first_write = true;

using Counter = std::map<std::string, std::size_t>;

std::string tolower(const std::string &str);

void count_words(std::istream& stream, Counter& counter, std::mutex& mutex);

void print_topk(std::ostream& stream, const Counter&, const size_t k);

void open_file(const fs::path& file_name, Counter& dictionary,  std::mutex& mutex);
