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
    
class Switchlog
{
  public:
    void ssd_create_log(std::string& spec, std::string& num);
};

}//namespace manager
}//namespace log     
}//namespace phosphor
