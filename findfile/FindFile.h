#pragma once
#include <iostream>
#include <filesystem>


bool FindPath(const std::string file_name, std::filesystem::path path);
void Start(const std::string file_name, std::filesystem::path path);


