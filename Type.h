
#pragma once
#include <string>

class IType {
public:
    IType();
    IType(const std::string& type);
    virtual ~IType();

    virtual double FireMod();
    virtual double WaterMod();
    virtual double GrassMod();
    virtual double ElectricMod();
    virtual std::string GetType();

protected:
    double fireMod;
    double waterMod;
    double grassMod;
    double electricMod;
    std::string m_type;
};
