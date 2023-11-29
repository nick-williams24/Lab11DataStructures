#pragma once
#include "Type.h"

class Grass : public IType {
public:
    Grass() : IType("Grass") {
        fireMod = 0.25;
        waterMod = 2;
        grassMod = 1;
        electricMod = 1;

        m_type = "Grass";
    }

    ~Grass() {}
};