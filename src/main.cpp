// Read files and prints top k word by frequency



#include "parallelization.h"

const size_t TOPK = 10;


int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: topk_words [FILES...]\n";
        return EXIT_FAILURE;
    }

    auto start = std::chrono::high_resolution_clock::now();


    std::vector<fs::path> files;

    for (int i = 1; i < argc; ++i) {

        std::vector<fs::path> paths = {fs::current_path().parent_path() / "data" /  argv[i], fs::current_path() / "data" /  argv[i],  argv[i]};

	    for (size_t j = 0; j < 3; j++){
		    if (fs::exists(paths[j])){
                files.push_back(paths[j]);
			    break;
		    }
		    else if (j == 2){
                std::cout << "Файл " << argv[i] << " отсутствует" << std::endl;
		    }
	    }
    }

    if (!files.size()){
        std::cerr << "Отсутствуют файлы для подсчета слов" << std::endl;
        exit(0);
    }

    Counter dict;
    std::vector<std::thread> threads;
    std::mutex mutex;

    for (size_t i = 0; i < files.size(); i++)
    {
        std::thread counter_file{open_file, std::ref(files[i]), std::ref(dict),std::ref(mutex)};
        threads.emplace_back(std::move(counter_file));
    }


for (auto& thread : threads) {							
		thread.join();
	}



    print_topk(std::cout, dict, TOPK);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time is " << elapsed_ms.count() << " us\n";
}

