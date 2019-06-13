#include "usi_log.hpp"
#include <iostream>

void print_usage(void)
{
    std::cout << "Example : phsophor-switch-log-manager -c xx -t xx -n xx"  << std::endl;
    std::cout << "[-c <x>] : ssd/cable/fan"  << std::endl;
    std::cout << "[-t <x>] : linkstatus/status/linkspeed/....."  << std::endl;
    std::cout << "[-n <x>] : id number"  << std::endl;
}

//phosphor-switch-log-manager -c xx -t xx -n xx
int main(int argc, char* argv[])
{
    int option;
    std::string log_type;
    std::string log_type_spec;
    std::string log_type_spec_num;
    int flag = 0;

    phosphor::jboflog::manager::Switchlog switchlog_manager;

    while((option = getopt(argc, argv, "c:t:n:")) != -1){
        flag += 1;
        switch(option){
            case 'c':
                    log_type = optarg;
                    break;
            case 't':
                    log_type_spec = optarg;
                    break;
            case 'n':
                    log_type_spec_num = optarg;
                    break;
            case 'h':
            case '?':
                print_usage();
                return (0);
        }
    }
    
    if(flag == 3){
        if(log_type.compare("ssd") == 0){
            switchlog_manager.ssd_create_log(log_type_spec, log_type_spec_num);
        }
        else if(log_type.compare("cable") == 0){
            switchlog_manager.cable_create_log(log_type_spec, log_type_spec_num);
        }
    }
    else{
        print_usage();
    }

    return (0);
}
