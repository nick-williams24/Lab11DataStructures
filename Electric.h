#pragma once
#include "Type.h"

class Electric : public IType {
public:
    Electric() : IType("Electric") {
        fireMod = 1;
        waterMod = 2;
        grassMod = 0.25;
        electricMod = 1;

        m_type = "Electric";
    }

    ~Electric() {}
};