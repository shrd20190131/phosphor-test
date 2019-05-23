#include <iostream>
#include <fstream>
#include <cstring>
#include "ps_manager.hpp"

namespace phosphor
{
namespace ps
{
namespace manager
{


std::string PsInit::status(std::string value){
    sleep(5);
    return (std::string("ok"));
}

} // namespace manager
} // namespace ps
} // namespace phosphor


