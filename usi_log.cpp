#include <phosphor-logging/elog-errors.hpp>
#include <phosphor-logging/elog.hpp>
#include <phosphor-logging/log.hpp>
#include <com/usi/Ssdarray/Switch/error.hpp>
#include "usi_log.hpp"

namespace phosphor
{
namespace jboflog
{
namespace manager
{
    
using namespace phosphor::logging;
using SsdLinkFail = sdbusplus::com::usi::Ssdarray::Switch::Error::SsdLinkFailure;
using FAIL = com::usi::Ssdarray::Switch::FAIL;
    
void Infolog::ssdinfo_create_log(){
    
    log<level::ERR>("Ssd link fail");
    report<SsdLinkFailure>(FAIL("Ssd link fail"));
}
    
}//namespace manager
}//namespace log     
}//namespace phosphor
