#include "FindFile.h"
#include <filesystem>
#include <functional> 
#include <vector>
#include <thread>
#define thread_max 8


namespace fs = std::filesystem;

FindFile::FindFile(const std::string& root, const std::string& filename)
	: root(root), file_name(filename), stop_search(false){}
  
bool FindFile::FindPath(const std::string file_name, fs::path path)
{
    //std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::lock_guard<std::mutex> lock(mtx);
    if ( path.filename() == file_name && stop_search == false)
    {
        std::cout << "The path to the file: " << path << "\n";
        stop_search = true;
        return true;
    }
    return false;
}

void FindFile::Start()
{
    std::vector<std::thread> find_threads(thread_max);
    for (const auto& p : fs::recursive_directory_iterator(root, fs::directory_options::skip_permission_denied))
    {
        if (p.is_directory() && !stop_search)
        {
            find_threads.emplace_back(&FindFile::FindPath, this, file_name, p.path());
        }
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
