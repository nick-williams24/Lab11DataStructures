#include "Type.h"

IType::IType()
{
}

IType::IType(const std::string &type)
{
}

IType::~IType()
{
}

double IType::FireMod()
{
    return fireMod;
}

double IType::WaterMod()
{
    return waterMod;
}

double IType::GrassMod()
{
    return grassMod;
}

double IType::ElectricMod()
{
    return electricMod;
}

std::string IType::GetType()
{
    return m_type;
}
