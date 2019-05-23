#include <functional>
#include <sdbusplus/bus.hpp>
#include <com/usi/Ssdarray/Test/server.hpp>
#include <sdbusplus/server/object.hpp>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>

namespace phosphor
{
namespace ps
{
namespace manager
{

using PsInherit = sdbusplus::server::object::object<
    sdbusplus::com::usi::Ssdarray::server::Test>;

/** @class SSDInit
 *  @brief OpenBMC BMC SSD management implementation.
 *  @details A concrete implementation for xyz.openbmc_project.Switch.Ssd
 *  DBus API.
 */
class PsInit: public PsInherit
{
    public:
        /** @brief Constructs SSD  Manager
         *
         * @param[in] bus       - The Dbus bus object
         * @param[in] busName   - The Dbus name to own
         * @param[in] objPath   - The Dbus object path
         */
        PsInit() = delete;
        ~PsInit() = default;
        PsInit(const PsInit&) = delete;
        PsInit& operator=(const PsInit&) = delete;
        PsInit(PsInit&&) = delete;
        PsInit& operator=(PsInit&&) = delete;

        PsInit(sdbusplus::bus::bus& bus, const std::string& objPath):PsInherit(bus, objPath.c_str())
        {
            //
        }
        std::string status(std::string value) override;
};

} // namespace manager
} // namespace ps
} // namespace phosphor
