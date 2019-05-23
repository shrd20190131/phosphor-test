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


std::string status(std::string value) const{
    sleep(60);
    return (std::string("ok"));
}

} // namespace manager
} // namespace ps
} // namespace phosphor


