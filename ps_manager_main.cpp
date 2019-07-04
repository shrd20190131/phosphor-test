#include <sdbusplus/bus.hpp>
#include <string>
#include <iostream>
#include "config.h"
#include "ps_manager.hpp"

int main(int argc, char**)
{

    auto bus = sdbusplus::bus::new_default();

    // Add sdbusplus ObjectManager.
    sdbusplus::server::manager::manager objManager(bus, PS_OBJPATH);

    //create power supply interface
    auto objPath = std::string(PS_OBJPATH);
    phosphor::ps::manager::PsInit PsManager(bus, objPath);

    bus.request_name(PS_BUSNAME);

    //while (true)
    //{
    //    bus.process_discard();
    //    bus.wait();
    //}

    return (0);
}
