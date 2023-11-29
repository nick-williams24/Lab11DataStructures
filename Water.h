#pragma once
#include "Type.h"

class Water : public IType {
public:
    Water() : IType("Water") {
        fireMod = 2;
        waterMod = 1;
        grassMod = 0.25;
        electricMod = 1;

        m_type = "Water";
    }

    ~Water() {}
};
