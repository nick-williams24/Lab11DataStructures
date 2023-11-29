
#pragma once
#include <string>

class IRole {
public:
    IRole();
    IRole(const std::string& role);
    virtual ~IRole();

    virtual double GetHP();
    virtual int GetAttack();
    virtual int GetDefense();
    virtual int GetSpeed();
    virtual std::string GetRole();

protected:
    int m_attack;
    int m_defense;
    int m_speed;
    double m_hp;
    std::string m_role;
};
