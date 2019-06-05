#include "config.h"
#include <sys/wait.h>
#include <unistd.h>
#include <experimental/filesystem>
#include <phosphor-logging/elog-errors.hpp>
#include <phosphor-logging/elog.hpp>
#include <phosphor-logging/log.hpp>
#include <string>
#include <cstring>
#include <xyz/openbmc_project/Ssdarray/Switch/error.hpp>
#include "usi_log.hpp"

namespace phosphor
{
namespace jboflog
{
namespace manager
{
    
using namespace phosphor::logging;
using namespace sdbusplus::com::usi::Ssdarray::Switch::Error;
namespace Ssdarray = phosphor::logging::xyz::openbmc_project::Ssdarray;
using SsdLinkFail = Ssdarray::Switch::SsdLinkFailure;
namespace fs = std::experimental::filesystem;
    
void log::ssdinfo_create_log{
    
    //log<level::ERR>("Ssd link fail",
    //                        entry("FILENAME=%s", tarFilePath.c_str()));
    //report<SsdLinkFailure>(SsdLinkFail::PATH(tarFilePath.c_str()));
    log<level::ERR>("Ssd link fail");
    report<SsdLinkFailure>();
}
    
}//namespace manager
}//namespace log     
}//namespace phosphor