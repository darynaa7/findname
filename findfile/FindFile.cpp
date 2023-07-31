#include "FindFile.h"
#include <filesystem>
#include <functional> 
#include<vector>
#include<thread>


namespace fs = std::filesystem;

FindFile::FindFile(const std::string& root, const std::string& filename)
	: root(root), file_name(filename), stop_search(false){}
  
bool FindFile::FindPath(const std::string file_name, std::filesystem::path path)
{
    for (const auto& p : fs::recursive_directory_iterator(path, fs::directory_options::skip_permission_denied))
    {
        std::lock_guard<std::mutex> lock(mtx);
        if (p.is_regular_file() && p.path().filename() == file_name)
        {
            std::cout << "The path to the file: " << p.path() << "\n";
            stop_search = true;
            return true;
        }
        if (stop_search)
        {
            return false;
        }
    }
    std::cout << "File doesn't exist in this directory:\n";
    return false;
}

void FindFile::Start()
{
    std::vector<std::thread> findthreads;
    int max = 8;
    for (int i = 0; i < max; i++)
    {
        findthreads.emplace_back(std::bind(&FindFile::FindPath, this, file_name, root));
    }
    for (auto& thread : findthreads)
    {
        thread.join();
    }
}

