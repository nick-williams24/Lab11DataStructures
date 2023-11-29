#pragma once

#include "Type.h"
#include "Water.h"
#include "Grass.h"
#include "Fire.h"
#include "Electric.h"

#include "IRole.h"
#include "HighAttack.h"
#include "HighDefense.h"
#include "HighHP.h"
#include "Balanced.h"

#include <memory>

class Pokemon : public IType, public IRole
{
public:
    Pokemon();
    Pokemon(const std::string &type, const std::string &role);

    // IType funcs
    double FireMod() override;
    double WaterMod() override;
    double GrassMod() override;
    double ElectricMod() override;
    std::string GetType() override;

    // IRole funcs
    double GetHP() override;
    int GetAttack() override;
    int GetDefense() override;
    int GetSpeed() override;
    std::string GetRole() override;

    void LoseHP(double attackVal);

    ~Pokemon();

private:
    std::string m_type;
    std::string m_role;
    double m_hp;
    int m_attack;
    int m_defense;
    int m_speed;
    double fireMod;
    double waterMod;
    double grassMod;
    double electricMod;
};

class PokemonFactory
{
public:
    static std::shared_ptr<Pokemon> createPokemon(const std::string &type, const std::string &role);
};