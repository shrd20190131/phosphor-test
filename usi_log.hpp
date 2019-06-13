#pragma once

#include <unistd.h>
#include <string>
#include <cstring>
#include <sdbusplus/server.hpp>
#include <sdbusplus/bus.hpp>

namespace phosphor
{
namespace jboflog
{
namespace manager
{
    
class Createlog
{
  public:
    void ssd_create_log(std::string& spec, std::string& num);
    void cable_create_log(std::string& spec, std::string& num);
    void fan_create_log(std::string& spec, std::string& num);
};

}//namespace manager
}//namespace log     
}//namespace phosphor
