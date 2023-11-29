#pragma once
#include "Type.h"

class Fire : public IType {
public:
    Fire() : IType("Fire") {
        fireMod = 1;
        waterMod = 0.25;
        grassMod = 2;
        electricMod = 1;

        m_type = "Fire";
    }

    ~Fire() {}
};