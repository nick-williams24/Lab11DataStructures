#include "PokemonFactory.h"
#include "Party.h"
#include <iostream>

int main()
{
    std::shared_ptr<Pokemon> p1Poke1 = PokemonFactory::createPokemon("Fire", "HighAttack");
    std::shared_ptr<Pokemon> p1Poke2 = PokemonFactory::createPokemon("Fire", "HighHP");
    std::shared_ptr<Pokemon> p1Poke3 = PokemonFactory::createPokemon("Electric", "Balanced");
    std::shared_ptr<Pokemon> p1Poke4 = PokemonFactory::createPokemon("Electric", "HighDefense");

    std::shared_ptr<Pokemon> p2Poke1 = PokemonFactory::createPokemon("Grass", "Balanced");
    std::shared_ptr<Pokemon> p2Poke2 = PokemonFactory::createPokemon("Grass", "HighDefense");
    std::shared_ptr<Pokemon> p2Poke3 = PokemonFactory::createPokemon("Water", "HighAttack");
    std::shared_ptr<Pokemon> p2Poke4 = PokemonFactory::createPokemon("Water", "HighHP"); 

    Party p1(p1Poke1,p1Poke2,p1Poke3,p1Poke4);
    Party p2(p2Poke1,p2Poke2,p2Poke3,p2Poke4);

    while (!(p1.lostBattle("Party 2")) && !(p2.lostBattle("Party 1")))
    {
        if(p1.isFaster(p2))
        {
            p1.Attack("p1",p2);
            p2.partyStatus();
            p2.printPartyHealth("p2");
            p2.Attack("p2",p1);
            p1.partyStatus();
            p1.printPartyHealth("p1");
        }
        else
        {
            p2.Attack("p2",p1);
            p1.partyStatus();
            p1.printPartyHealth("p1");
            p1.Attack("p1",p2);
            p2.partyStatus();
            p2.printPartyHealth("p2");
        }
    }
    std::cout << "Game over!!!!!!!" << std::endl;
    return 0;
}