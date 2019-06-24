#include <iostream>
#include <fstream>
#include <cstring>
#include "usi_log.hpp"

namespace phosphor
{
namespace ps
{
namespace manager
{

uint32_t PsStatus::startwith(const std::string& str, const std::string& pattern){
    return (str.find(pattern) == 0 ? 1 : 0);
}

std::string PsStatus::get_value(const int& flag){
    FILE *fp = NULL;
    std::string ps;
    char buf[50];
    std::string cmd;

    //get ps status
    if(flag == 1){
        cmd = "i2cget -y 14 0x58 0x79 w";
    }
    else{
        cmd = "i2cget -y 17 0x59 0x79 w";
    }
    fp = popen(cmd.c_str(), "r");
    if(fp){
        while(NULL != fgets(buf, sizeof(buf), fp)){
            if (buf[strlen(buf) - 1] == '\n'){
                buf[strlen(buf) - 1] = '\0';
            }
            ps = buf;
            //std::cout << "ps:" << ps << std::endl;
        }
        pclose(fp);
    }

    return (ps);
}

std::vector<std::string> PsStatus::get_status(const std::string& psvalue, const int& flag){
    std::vector<std::string> status;

    auto value = std::stoul(psvalue, 0, 16);
    //psa status
    if(flag == 1){
        auto psavalue_2 = (value >> 2) & 0x01;
        if(psavalue_2 == 1){
            status.push_back(std::string("A temperature fault or warning has occurred"));
        }
        auto psavalue_3 = (value >> 3) & 0x01;
        if(psavalue_3 == 1){
            status.push_back(std::string("An input under voltage fault has occurred"));
        }
        auto psavalue_4 = (value >> 4) & 0x01;
        if(psavalue_4 == 1){
            status.push_back(std::string("An output overcurrent fault has occurred"));
        }
        auto psavalue_5 = (value >> 5) & 0x01;
        if(psavalue_5 == 1){
            status.push_back(std::string("An output overvoltage fault has occurred"));
        }
        auto psavalue_6 = (value >> 6) & 0x01;
        if(psavalue_6 == 1){
            status.push_back(std::string("Output not being provided power or not being enabled"));
        }
    }
    //psb status
    else{
        auto psavalue_10 = (value >> 10) & 0x01;
        if(psavalue_10 == 1){
            status.push_back(std::string("A fan or airflow fault or warning has occurred"));
        }
        auto psavalue_11 = (value >> 11) & 0x01;
        if(psavalue_11 == 1){
            status.push_back(std::string("The POWER_GOOD signal is negated"));
        }
        auto psavalue_13 = (value >> 13) & 0x01;
        if(psavalue_13 == 1){
            status.push_back(std::string("An input voltage, input current, or input power fault,"
                    "or warning has occurred"));
        }
        auto psavalue_14 = (value >> 14) & 0x01;
        if(psavalue_14 == 1){
            status.push_back(std::string("An output current or output power fault"
                    "or warning has occurred"));
        }
        auto psavalue_15 = (value >> 15) & 0x01;
        if(psavalue_15 == 1){
            status.push_back(std::string("An output voltage fault or warning has occurred"));
        }
    }

    return (status);
}

std::map<std::string, sdbusplus::message::variant<std::string, std::map<std::string, std::string>>> PsInit::status() const{
    std::map<std::string, sdbusplus::message::variant<std::string, std::map<std::string, std::string>>> status;
    sdbusplus::message::variant<std::string> none_flag = "Read fail";
    sdbusplus::message::variant<std::string> ok_flag = "Ok";
    sdbusplus::message::variant<std::map<std::string, std::string>> psa_error_temp;
    sdbusplus::message::variant<std::map<std::string, std::string>> psb_error_temp;
    std::map<std::string, std::string> error;

    PsStatus psstatuscall;
    //auto psa_getvalue = psstatuscall.get_value(1);
    //status["PSA"] = sdbusplus::message::variant_ns::get<std::string>(none_flag);
    error["Error1"] = "The POWER_GOOD signal is negated";
    error["Error2"] = "A temperature fault or warning has occurred";
    status["PSA"] = sdbusplus::message::variant_ns::get<std::map<std::string, std::string>>(error);
    status["PSB"] = sdbusplus::message::variant_ns::get<std::string>(none_flag);

/*
    if(!psstatuscall.startwith(psa_getvalue, std::string("0x"))){

    }
    else{
        auto psa_getstatus = psstatuscall.get_status(psa_getvalue, 1);
        if(psa_getstatus.size() == 0){
            status["PSA"] = sdbusplus::message::variant_ns::get<std::string>(ok_flag);
        }
        else{
            for(unsigned int i = 0; i < psa_getstatus.size(); i++){
                auto psa_error_num = "Error" + std::to_string(i+1);
                error[psa_error_num] = psa_getstatus[i];
            }
            psa_error_temp = error;
            error.clear();
            status["PSA"] = sdbusplus::message::variant_ns::get<std::map<std::string, std::string>>(psa_error_temp);
        }
    }
    auto psb_getvalue =  psstatuscall.get_value(2);
    if(!psstatuscall.startwith(psb_getvalue, std::string("0x"))){
        status["PSB"] = sdbusplus::message::variant_ns::get<std::string>(none_flag);
    }
    else{
        auto psb_getstatus = psstatuscall.get_status(psb_getvalue, 2);
        if(psb_getstatus.size() == 0){
            status["PSB"] = sdbusplus::message::variant_ns::get<std::string>(ok_flag);
        }
        else{
            for(unsigned int j = 0; j < psb_getstatus.size(); j++){
                auto psb_error_num = "Error" + std::to_string(j+1);
                error[psb_error_num] = psb_getstatus[j];
            }
            psb_error_temp = error;
            error.clear();
            status["PSB"] = sdbusplus::message::variant_ns::get<std::map<std::string, std::string>>(psb_error_temp);
        }
    }
*/
    return (status);
}

} // namespace manager
} // namespace ps
} // namespace phosphor


