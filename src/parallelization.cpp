#include "parallelization.h"

std::string tolower(const std::string &str) {
    std::string lower_str;
    std::transform(std::cbegin(str), std::cend(str),
                   std::back_inserter(lower_str),
                   [](unsigned char ch) { return std::tolower(ch); });
    return lower_str;
};

void count_words(std::istream& stream, Counter& counter, std::mutex& mutex) {
    Counter thread_counter;
    std::for_each(std::istream_iterator<std::string>(stream),
                  std::istream_iterator<std::string>(),
                  [&thread_counter](const std::string &s) { ++thread_counter[tolower(s)]; });

    std::lock_guard lock(mutex);

    if (first_write)
    {
        counter = std::move(thread_counter);
        first_write = false;
    }

    else
    {
        std::for_each(thread_counter.begin(),
                      thread_counter.end(),
                      [&counter](auto& iterator){counter[iterator.first]+=iterator.second;});
    }
    
        
}

void print_topk(std::ostream& stream, const Counter& counter, const size_t k) {
    std::vector<Counter::const_iterator> words;
    words.reserve(counter.size());
    for (auto it = std::cbegin(counter); it != std::cend(counter); ++it) {
        words.push_back(it);
    }

    std::partial_sort(
        std::begin(words), std::begin(words) + k, std::end(words),
        [](auto lhs, auto &rhs) { return lhs->second > rhs->second; });

    std::for_each(
        std::begin(words), std::begin(words) + k,
        [&stream](const Counter::const_iterator &pair) {
            stream << std::setw(4) << pair->second << " " << pair->first
                      << '\n';
        });
}

void open_file(const fs::path& file_name, Counter& dictionary,  std::mutex& mutex){
    std::ifstream input(file_name);
    if (!input.is_open()) {
        std::cerr << "Failed to open file " << file_name << '\n';
        return;
    }
    count_words(input,dictionary,mutex);
    
}