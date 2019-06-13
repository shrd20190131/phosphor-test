#include <phosphor-logging/elog-errors.hpp>
#include <phosphor-logging/elog.hpp>
#include <phosphor-logging/log.hpp>
#include <com/usi/Ssdarray/Log/error.hpp>
#include "usi_log.hpp"

namespace phosphor
{
namespace jboflog
{
namespace manager
{
    
using namespace phosphor::logging;
using SsdLinkFail = sdbusplus::com::usi::Ssdarray::Log::Error::SsdFailure;
using SsdError = phosphor::logging::com::usi::Ssdarray::Log::SsdFailure::ERROR;
    
void Switchlog::ssd_create_log(std::string& spec, std::string& num){
    std::string ssderror_log;

    if(spec.compare("linkstatus") == 0){
        ssderror_log = "ssd" + num + " link fail";
    }

    if(!errorinfo.empty()){
        log<level::ERR>(ssderror_log.c_str());
        report<SsdLinkFail>(SsdError(ssderror_log.c_str()));
    }
}
    
}//namespace manager
}//namespace log     
}//namespace phosphor
