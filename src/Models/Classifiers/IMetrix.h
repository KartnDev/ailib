//
// Created by Dmitry on 11.09.2020.
//

#ifndef AILIB_IMETRIX_H
#define AILIB_IMETRIX_H

#include <map>
#include <string>

enum OutputType
{
    console = 100,
    file = 200
};

class IMetrix
{
    virtual void SetMetrixOutputSettings(std::map<std::string, std::string> params) = 0;
    virtual double GetAccuracy() = 0;
    virtual void PrintMetrix(OutputType outputType) = 0;
};


#endif //AILIB_IMETRIX_H
