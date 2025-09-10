#include "systeminfo.h"
#include <unistd.h>
#include <sys/utsname.h>
#include <fstream>
#include <sstream>
#include <cstdlib>

std::string read_first_line(const std::string &file){
    std::ifstream f(file);
    std::string line;
    if(f.is_open()) std::getline(f,line);
    return line;
}

std::string get_os(){
    std::ifstream f("/etc/os-release");
    std::string line, name;
    while (std::getline(f,line)){
        if(line.rfind("PRETTY_NAME=",0)==0){
            name = line.substr(12);
            if(!name.empty() && name.front()=='"') name.erase(0,1);
            if(!name.empty() && name.back()=='"') name.pop_back();
            break;
        }
    }
    return name.empty() ? "Unknown" : name;
}

std::string get_kernel(){
    struct utsname u;
    uname(&u);
    return u.release;
}

std::string get_hostname(){
    char buf[256];
    gethostname(buf,sizeof(buf));
    return buf;
}

std::string get_username(){
    if(const char* u = getenv("USER")) return u;
    return "unknown";
}

std::string get_uptime(){
    std::ifstream f("/proc/uptime");
    double secs=0;
    if(f>>secs){
        int days = secs/86400; secs-=days*86400;
        int hrs = secs/3600; secs-=hrs*3600;
        int mins = secs/60;
        std::ostringstream out;
        if(days>0) out << days << "d " << hrs << "h " << mins << "m";
        else if(hrs>0) out << hrs << "h " << mins << "m";
        else out << mins << "m";
        return out.str();
    }
    return "0m";
}

std::pair<std::string,int> get_cpu(){
    std::ifstream f("/proc/cpuinfo"); 
    std::string line, model; 
    int cores=0;
    while(std::getline(f,line)){
        if(line.rfind("model name",0)==0 && model.empty())
            model = line.substr(line.find(":")+2);
        if(line.rfind("processor",0)==0) cores++;
    }
    if(model.empty()) model="Unknown";
    return {model, cores};
}

std::pair<long long,long long> get_memory(){
    std::ifstream f("/proc/meminfo"); 
    std::string line; 
    long long total=0, avail=0;
    while(std::getline(f,line)){
        if(line.rfind("MemTotal:",0)==0) sscanf(line.c_str(),"MemTotal: %lld kB",&total);
        if(line.rfind("MemAvailable:",0)==0) sscanf(line.c_str(),"MemAvailable: %lld kB",&avail);
    }
    long long used = total - avail;
    return {used,total};
}

std::string get_shell(){
    const char* s = getenv("SHELL");
    if(s) return std::string(s).substr(std::string(s).find_last_of('/')+1);
    return "unknown";
}

std::string get_terminal(){
    const char* t = getenv("TERM");
    if(t) return std::string(t);
    return "unknown";
}

int get_packages(){
    std::string out = "0";
    FILE* f = popen("pacman -Qq 2>/dev/null | wc -l","r");
    if(f){
        char buf[32]; 
        if(fgets(buf,sizeof(buf),f)) out=buf;
        pclose(f);
    }
    return std::atoi(out.c_str());
}

std::vector<std::pair<std::string,std::string>> collect_system_info(){
    auto cpu = get_cpu();
    auto mem = get_memory();

    std::vector<std::pair<std::string,std::string>> info = {
        {"OS", get_os()},
        {"Host", get_hostname() + " (" + get_username() + ")"},
        {"Kernel", get_kernel()},
        {"Uptime", get_uptime()},
        {"CPU", cpu.first + " (" + std::to_string(cpu.second) + " cores)"},
        {"Memory", std::to_string(mem.first/1024) + "MiB / " + std::to_string(mem.second/1024) + "MiB"},
        {"Shell", get_shell()},
        {"Terminal", get_terminal()},
        {"Packages", std::to_string(get_packages())}
    };
    return info;
}
