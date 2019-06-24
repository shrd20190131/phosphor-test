#include <functional>
#include <sdbusplus/bus.hpp>
#include <com/usi/Ssdarray/Powersupply/server.hpp>
#include <sdbusplus/server/object.hpp>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <map>
#include <variant>

namespace phosphor
{
namespace ps
{
namespace manager
{

using PsInherit = sdbusplus::server::object::object<
    sdbusplus::com::usi::Ssdarray::server::Powersupply>;

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
            //nothting
        }
        std::map<std::string, sdbusplus::message::variant<std::string, std::map<std::string, std::string>>> status() const override;
};

class PsStatus
{
    public:
        std::string get_value(const int& flag);
        std::vector<std::string> get_status(const std::string& psvalue, const int& flag);
        uint32_t startwith(const std::string& str, const std::string& pattern);
};

} // namespace manager
} // namespace ps
} // namespace phosphor
