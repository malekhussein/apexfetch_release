#include "ascii.h"
#include <iostream>
#include <fstream>
#include <algorithm>

const std::string RESET = "\033[0m";

std::vector<std::string> read_file_lines(const std::string &path){
    std::ifstream f(path);
    std::vector<std::string> lines;
    std::string l;
    while (getline(f, l))
        lines.push_back(l);
    return lines;
}

void print_two_column(const std::vector<std::string> &logo,
                      const std::vector<std::pair<std::string,std::string>> &info,
                      bool color)
{
    size_t max_width = 0;
    for (auto &line : logo)
        if (line.size() > max_width) max_width = line.size();

    size_t total_lines = std::max(logo.size(), info.size());

    for (size_t i = 0; i < total_lines; i++) {
        std::string logo_line = (i < logo.size()) ? logo[i] : std::string(max_width, ' ');
        std::cout << (color ? "\033[1;36m" + logo_line + "\033[0m" : logo_line);

        size_t pad = max_width - logo_line.size() + 4;
        for (size_t p = 0; p < pad; p++) std::cout << " ";

        if (i < info.size()) {
            std::string key = info[i].first;
            std::string val = info[i].second;
            std::cout << (color ? "\033[1m" + key + "\033[0m" : key) << ": " << val;
        }

        std::cout << "\n";
    }
}
