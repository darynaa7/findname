#include "FindFile.h"
#include <vector>
#include <thread>
#include <condition_variable>

#define thread_max 7

//std::condition_variable cv;
std::atomic<bool> stop_search = false; 

namespace fs = std::filesystem;
  
bool FindPath(const std::string file_name, fs::path path)
{
    //std::lock_guard<std::mutex> lock(mtx);
    if ( path.filename() == file_name && stop_search == false)
    {
        std::cout << "The path to the file: " << path << "\n";
        stop_search = true;
        //cv.notify_all();
        return true;
    }
    return false;
}

void Start(const std::string file_name, fs::path path)
{
    std::vector<std::thread> find_threads(thread_max);
    for (const auto& p : fs::recursive_directory_iterator(path, fs::directory_options::skip_permission_denied))
    {  
        find_threads.emplace_back(FindPath, file_name, p.path());
        if (stop_search)
        {
            break;
        }
    }
    for (auto& thread : find_threads)
    {
        if (thread.joinable())
        thread.join();
    }
    if (!stop_search) {
        std::cout << "File not found.\n";
    }
}
