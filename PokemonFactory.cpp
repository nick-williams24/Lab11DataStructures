#include "PokemonFactory.h"
#include <iostream>

Pokemon::Pokemon()
{
}

Pokemon::Pokemon(const std::string& type, const std::string& role)
    : m_type(type), m_role(role), m_hp(0), m_attack(0), m_defense(0)
{
    if (type == "Water")
    {
        Water waterType;
        waterMod = waterType.WaterMod();
        fireMod = waterType.FireMod();
        grassMod = waterType.GrassMod();
        electricMod = waterType.ElectricMod();
    }
    else if (type == "Grass")
    {
        Grass grassType;
        waterMod = grassType.WaterMod();
        fireMod = grassType.FireMod();
        grassMod = grassType.GrassMod();
        electricMod = grassType.ElectricMod();
    }
    else if (type == "Fire")
    {
        Fire fireType;
        waterMod = fireType.WaterMod();
        fireMod = fireType.FireMod();
        grassMod = fireType.GrassMod();
        electricMod = fireType.ElectricMod();
    }
    else
    {
        Electric electricType;
        waterMod = electricType.WaterMod();
        fireMod = electricType.FireMod();
        grassMod = electricType.GrassMod();
        electricMod = electricType.ElectricMod();
    }

    if (role == "HighAttack")
    {
        HighAttack highAttackRole;
        m_hp = highAttackRole.GetHP();
        m_attack = highAttackRole.GetAttack();
        m_defense = highAttackRole.GetDefense();
        m_speed = highAttackRole.GetSpeed();
    }
    else if (role == "HighDefense")
    {
        HighDefense highDefenseRole;
        m_hp = highDefenseRole.GetHP();
        m_attack = highDefenseRole.GetAttack();
        m_defense = highDefenseRole.GetDefense();
        m_speed = highDefenseRole.GetSpeed();
    }
    else if (role == "HighHP")
    {
        HighHP highHPRole;
        m_hp = highHPRole.GetHP();
        m_attack = highHPRole.GetAttack();
        m_defense = highHPRole.GetDefense();
        m_speed = highHPRole.GetSpeed();
    }
    else
    {
        Balanced balancedRole;
        m_hp = balancedRole.GetHP();
        m_attack = balancedRole.GetAttack();
        m_defense = balancedRole.GetDefense();
        m_speed = balancedRole.GetSpeed();
    }
}

double Pokemon::FireMod()
{
    return fireMod;
}

double Pokemon::WaterMod()
{
    return waterMod;
}

double Pokemon::GrassMod()
{
    return grassMod;
}

double Pokemon::ElectricMod()
{
    return electricMod;
}

std::string Pokemon::GetType()
{
    return m_type;
}

double Pokemon::GetHP()
{
    return m_hp;
}

int Pokemon::GetAttack()
{
    return m_attack;
}

int Pokemon::GetDefense()
{
    return m_defense;
}

int Pokemon::GetSpeed()
{
    return m_speed;
}

std::string Pokemon::GetRole()
{
    return m_role;
}

void Pokemon::LoseHP(double attackVal)
{
    m_hp = m_hp - attackVal;
}

Pokemon::~Pokemon()
{
}

std::shared_ptr<Pokemon> PokemonFactory::createPokemon(const std::string &type, const std::string &role)
{
    return std::make_shared<Pokemon>(type, role);
}
