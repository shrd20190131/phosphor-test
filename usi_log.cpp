#include <phosphor-logging/elog-errors.hpp>
#include <phosphor-logging/elog.hpp>
#include <phosphor-logging/log.hpp>
#include <com/usi/Logging/error.hpp>
#include "usi_log.hpp"

namespace phosphor
{
namespace jboflog
{
namespace manager
{
    
using namespace phosphor::logging;
using SsdFail = sdbusplus::com::usi::Logging::Error::SsdFailure;
using CableFail = sdbusplus::com::usi::Logging::Error::CableFailure;
using FanFail = sdbusplus::com::usi::Logging::Error::FanFailure;
using SsdError = phosphor::logging::com::usi::Logging::SsdFailure::ERROR;
using CableError = phosphor::logging::com::usi::Logging::CableFailure::ERROR;
using FanError = phosphor::logging::com::usi::Logging::FanFailure::ERROR;
    
void Createlog::ssd_create_log(std::string& spec, std::string& num){
    std::string ssderror_log;

    if(spec.compare("linkstatus") == 0){
        ssderror_log = "Ssd" + num + " link fail  |";
    }

    if(!ssderror_log.empty()){
        log<level::ERR>(ssderror_log.c_str());
        report<SsdFail>(SsdError(ssderror_log.c_str()));
    }
}

void Createlog::cable_create_log(std::string& spec, std::string& num){
    std::string cablerror_log;

    if(spec.compare("linkstatus") == 0){
        cablerror_log = "Cable" + num + " link fail  |";
    }

    if(!cablerror_log.empty()){
        log<level::ERR>(cablerror_log.c_str());
        report<CableFail>(CableError(cablerror_log.c_str()));
    }
}

void Createlog::fan_create_log(std::string& spec, std::string& num){
    std::string fanerror_log;

    if(spec.compare("fanspeed") == 0){
        fanerror_log = "Fan" + num + " current speed is lower than the normal setting range  |";
    }

    if(!fanerror_log.empty()){
        log<level::ERR>(fanerror_log.c_str());
        report<FanFail>(FanError(fanerror_log.c_str()));
    }
}

}//namespace manager
}//namespace log     
}//namespace phosphor
