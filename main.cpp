#include "ascii.h"
#include "systeminfo.h"
#include <iostream>

int main(){
    auto logo = read_file_lines("arch.txt");
    if(logo.empty()){
        logo = {
            "       /\\        ",
            "      /  \\   _ __ ",
            "     / /\\ \\ | '_ \\",
            "    / ____ \\| | | |",
            "   /_/    \\_\\_| |_|"
        };
    }

    auto info = collect_system_info();
    print_two_column(logo, info, true);
    return 0;
}
