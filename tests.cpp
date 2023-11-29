#include <gtest/gtest.h>
#include "PokemonFactory.h"

TEST(ConcreteClasses, PokemonFactory1)
{
    std::shared_ptr<Pokemon> poke = PokemonFactory::createPokemon("Water", "HighAttack");

    ASSERT_EQ(poke->GetType(), "Water");
    ASSERT_EQ(poke->GetRole(), "HighAttack");
}

TEST(ConcreteClasses, PokemonFactory2)
{
    std::shared_ptr<Pokemon> poke = PokemonFactory::createPokemon("Grass", "Balanced");

    ASSERT_EQ(poke->GetHP(), 84);
    ASSERT_EQ(poke->GetAttack(), 83);
    ASSERT_EQ(poke->GetDefense(), 83);
    ASSERT_EQ(poke->GetSpeed(), 3);    
}

TEST(ConcreteClasses, Pokemon1)
{
    Pokemon poke ("Water", "Balanced");

    ASSERT_EQ(poke.GetRole(), "Balanced");
    ASSERT_EQ(poke.GetType(), "Water");
}

TEST(ConcreteClasses, Pokemon2)
{
    Pokemon poke ("Fire", "HighAttack");

    ASSERT_EQ(poke.GetHP(), 100);
    ASSERT_EQ(poke.GetAttack(), 100);
    ASSERT_EQ(poke.GetDefense(), 50);
    ASSERT_EQ(poke.GetSpeed(), 4);

    ASSERT_EQ(poke.FireMod(), 1);
    ASSERT_EQ(poke.WaterMod(), 0.25);
    ASSERT_EQ(poke.GrassMod(), 2);
    ASSERT_EQ(poke.ElectricMod(), 1);
}

TEST(Types, Fire1)
{
    Fire fire;
    ASSERT_EQ(fire.GetType(), "Fire");
}

TEST(Types, Fire2)
{
    Fire fire;
    ASSERT_EQ(fire.FireMod(), 1);
    ASSERT_EQ(fire.WaterMod(), 0.25);
    ASSERT_EQ(fire.GrassMod(), 2);
    ASSERT_EQ(fire.ElectricMod(), 1);
}

TEST(Types, Water1)
{
    Water water;
    ASSERT_EQ(water.GetType(), "Water");
}

TEST(Types, Water2)
{
    Water water;
    ASSERT_EQ(water.FireMod(), 2);
    ASSERT_EQ(water.WaterMod(), 1);
    ASSERT_EQ(water.GrassMod(), 0.25);
    ASSERT_EQ(water.ElectricMod(), 1);
}

TEST(Types, Grass1)
{
    Grass grass;
    ASSERT_EQ(grass.GetType(), "Grass");
}

TEST(Types, Grass2)
{
    Grass grass;
    ASSERT_EQ(grass.FireMod(), 0.25);
    ASSERT_EQ(grass.WaterMod(), 2);
    ASSERT_EQ(grass.GrassMod(), 1);
    ASSERT_EQ(grass.ElectricMod(), 1);
}

TEST(Types, Electric1)
{
    Electric electric;
    ASSERT_EQ(electric.GetType(), "Electric");
}

TEST(Types, Electric2)
{
    Electric electric;
    ASSERT_EQ(electric.FireMod(), 1);
    ASSERT_EQ(electric.WaterMod(), 2);
    ASSERT_EQ(electric.GrassMod(), 0.25);
    ASSERT_EQ(electric.ElectricMod(), 1);
}

TEST(Roles, Balanced1)
{
    Balanced bal;

    ASSERT_EQ(bal.GetRole(), "Balanced");
}

TEST(Roles, Balanced2)
{
    Balanced bal;

    ASSERT_EQ(bal.GetHP(), 84);
    ASSERT_EQ(bal.GetAttack(), 83);
    ASSERT_EQ(bal.GetDefense(), 83);
    ASSERT_EQ(bal.GetSpeed(), 3);
}

TEST(Roles, HighAttack1)
{
    HighAttack HA;

    ASSERT_EQ(HA.GetRole(), "HighAttack");
}

TEST(Roles, HighAttack2)
{
    HighAttack HA;

    ASSERT_EQ(HA.GetHP(), 100);
    ASSERT_EQ(HA.GetAttack(), 100);
    ASSERT_EQ(HA.GetDefense(), 50);
    ASSERT_EQ(HA.GetSpeed(), 4);
}

TEST(Roles, HighDefense1)
{
    HighDefense HD;

    ASSERT_EQ(HD.GetRole(), "HighDefense");
}

TEST(Roles, HighDefense2)
{
    HighDefense HD;

    ASSERT_EQ(HD.GetHP(), 100);
    ASSERT_EQ(HD.GetAttack(), 50);
    ASSERT_EQ(HD.GetDefense(), 100);
    ASSERT_EQ(HD.GetSpeed(), 2);
}

TEST(Roles, HighHP1)
{
    HighHP HHP;

    ASSERT_EQ(HHP.GetRole(), "HighHP");
}

TEST(Roles, HighHP2)
{
    HighHP HHP;

    ASSERT_EQ(HHP.GetHP(), 150);
    ASSERT_EQ(HHP.GetAttack(), 50);
    ASSERT_EQ(HHP.GetDefense(), 50);
    ASSERT_EQ(HHP.GetSpeed(), 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
