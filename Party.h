#pragma once
#include "PokemonFactory.h"
#include <random>
#include <iostream>
#include <algorithm>

class Party
{
public:
    Party(std::shared_ptr<Pokemon> pokemon1, std::shared_ptr<Pokemon> pokemon2, std::shared_ptr<Pokemon> pokemon3, std::shared_ptr<Pokemon> pokemon4)
    {
        poke1 = std::move(pokemon1);
        poke2 = std::move(pokemon2);
        poke3 = std::move(pokemon3);
        poke4 = std::move(pokemon4);

        formation.push_back(poke1);
        formation.push_back(poke2);
        formation.push_back(poke3);
        formation.push_back(poke4);
    }
    ~Party() {}
    void Attack(std::string party_name,Party receiving_party)
    {
        if (formation.size() == 0 | receiving_party.getNumAlive() == 0)
        {
            return;
        }
        std::cout << party_name <<"'s Pokemon is attacking" << std::endl;
        int attack_val = formation[pokemon_to_attack]->GetAttack() * ThreeSidedDie();
        receiving_party.Receive(attack_val, formation[pokemon_to_attack]);
        
        pokemon_to_attack++;
        if(pokemon_to_attack > formation.size()-1)
        {
            pokemon_to_attack = 0;
        }
    }
    void Receive(double attack_val1, std::shared_ptr<Pokemon> attacking_pokemon)
    {
        std::cout << "Party is getting attacked" << std::endl;
        double fireMod = attacking_pokemon->FireMod();
        double grassMod = attacking_pokemon->GrassMod();
        double waterMod = attacking_pokemon->WaterMod();
        double electricMod = attacking_pokemon->ElectricMod();
        for (int i = 0; i < formation.size(); i++)
        {
            if (formation[i]->GetType() == "Fire")
            {
                int attack = attack_val1 * fireMod - formation[i]->GetDefense();
                if (attack < 0)
                {
                    attack = 0;
                }
                formation[i]->LoseHP(attack);
            }
            if (formation[i]->GetType() == "Grass")
            {
                int attack = attack_val1 * grassMod - formation[i]->GetDefense();
                if (attack < 0)
                {
                    attack = 0;
                }
                formation[i]->LoseHP(attack);
            }
            if (formation[i]->GetType() == "Electric")
            {
                int attack = attack_val1 * electricMod - formation[i]->GetDefense();
                if (attack < 0)
                {
                    attack = 0;
                }
                formation[i]->LoseHP(attack);
            }
            if (formation[i]->GetType() == "Water")
            {
                int attack = attack_val1 * waterMod - formation[i]->GetDefense();
                if (attack < 0)
                {
                    attack = 0;
                }
                formation[i]->LoseHP(attack);
            }
            
        }
    }
    void printPartyHealth(std::string party_name)
    {
        
        std::cout << party_name << "'s Party Health" << std::endl;
        for (int i = 0; i < formation.size(); i++)
        {
            if (formation.size() == 0)
            {
                return;
            }
            std::cout << formation[i]->GetHP() << std::endl;
        }
    }
    bool isDead(std::shared_ptr<Pokemon> poke)
    {
        if (poke->GetHP() <= 0)
        {
            std::cout << "A Pokemon has Fainted!" << std::endl;
            formation.erase(std::find(formation.begin(), formation.end(), poke));
            pokemon_to_attack --;
            if (pokemon_to_attack < 0)
            {
                pokemon_to_attack = 0;
            }
            return true;
        }
        return false;
    }

    void partyStatus()
    {
        for(int i = 0; i < formation.size(); i++)
        {
            if(isDead(formation[i]))
            {
                i--;
            }
        }
    }

    int getNumAlive()
    {
        return formation.size();
    }

    bool lostBattle(std::string party_name)
    {
        if(formation.size() == 0)
        {
            std::cout << party_name << " has won!" << std::endl;
            return true;
        }
        return false;
    }

    bool isFaster(Party receiving_party)
    {
        if (getAttackingPokemon()->GetSpeed() < receiving_party.getAttackingPokemon()->GetSpeed())
        {
            return false;
        }
        return true;
    }

    std::shared_ptr<Pokemon> getAttackingPokemon()
    {
        return formation[pokemon_to_attack];
    }

    int getAttackingPokemonIndex()
    {
        return pokemon_to_attack;
    }

    double ThreeSidedDie()
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist3(1, 3); // distribution in range [1, 3]
        double retval;
        if (dist3(rng) == 1)
        {
            retval = 0.8;
        } 
        else if (dist3(rng) == 2)
        {
            retval = 1;
        }
        else 
        {
            retval = 1.2;
        }
        return retval;
    }


private:
    int pokemon_to_attack = 0;
    std::vector<std::shared_ptr<Pokemon>> formation;
    std::shared_ptr<Pokemon> poke1;
    std::shared_ptr<Pokemon> poke2;
    std::shared_ptr<Pokemon> poke3;
    std::shared_ptr<Pokemon> poke4;
};