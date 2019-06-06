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
    
class Infolog
{
  public:
    void ssdinfo_create_log();
};
    
}//namespace manager
}//namespace log     
}//namespace phosphor
