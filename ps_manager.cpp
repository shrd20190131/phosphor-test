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


std::string PsInit::status() const{
    sleep(30);
    return (std::string("ok"));
}

} // namespace manager
} // namespace ps
} // namespace phosphor


