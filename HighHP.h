#pragma once
#include "IRole.h"

class HighHP : public IRole {
public:
    HighHP() : IRole("HighHP") 
    {
        m_hp = 150;
        m_attack = 50;
        m_defense = 50;
        m_speed = 1;
    }

    std::string GetRole() override {
        return "HighHP";
    }

    ~HighHP() override {}
};