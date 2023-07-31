#pragma once
#include <iostream>
#include<filesystem>
#include <mutex>
#include <atomic>


class FindFile
{
private:
	std::string root;
	std::string file_name;
	std::mutex mtx;
	std::atomic<bool> stop_search;
public:
	FindFile(const std::string& root, const std::string& file_name);
	bool FindPath(const std::string file_name, std::filesystem::path path);
	void Start();
};

