#include "usi_log.hpp"

int main(int argc, char* argv[])
{
    
    phosphor::jboflog::manager::log logmanager;
    logmanager.ssdinfo_create_log();
    
    return 0;
}