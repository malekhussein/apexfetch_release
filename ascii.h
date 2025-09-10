#ifndef ASCII_H
#define ASCII_H

#include <string>
#include <vector>
#include <utility>

extern const std::string RESET;

std::vector<std::string> read_file_lines(const std::string &path);
void print_two_column(const std::vector<std::string> &logo,
                      const std::vector<std::pair<std::string,std::string>> &info,
                      bool color=true);

#endif
