#pragma once
#ifndef HIGHATTACK_H
#define HIGHATTACK_H

#include "IRole.h"

class HighAttack : public IRole {
public:
    HighAttack() : IRole("HighAttack") 
    {
        m_hp = 100;
        m_attack = 100;
        m_defense = 50;
        m_speed = 4;
    }

    std::string GetRole() override {
        return "HighAttack";
    }

    ~HighAttack() override {}


};

#endif // HIGHATTACK_H
