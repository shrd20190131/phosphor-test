#include "usi_log.hpp"

int main(int argc, char* argv[])
{
    
    phosphor::jboflog::manager::Infolog infolog_manager;
    infolog_manager.ssdinfo_create_log();
    
    return 0;
}