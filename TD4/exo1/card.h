#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

class Card {
protected:
    string cardName;

public:
    Card(const string& name);

    virtual void displayInfo() const = 0;

    virtual ~Card() = default;
};

class PokemonCard : public Card {
private:
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    vector<tuple<int, int, string, int> > attacks;

public:
    PokemonCard(const string& name, const string& type, const string& family, int evolution, int max_hp,
                int attack1Cost, const string& attack1Name,  int attack1Damage,
                int attack2Cost, const string& attack2Name,  int attack2Damage);
    void displayInfo() const override;
    void heal();
};

class EnergyCard : public Card {
private:
    string energyType;
public:
    EnergyCard(const string& type);
    void displayInfo() const override;
};

class TrainerCard : public Card {
private:
    string trainerEffect;
public:
    TrainerCard(const string& name, const string& effect);
    void displayInfo() const override;
    void applyEffect(vector<PokemonCard*>& activePokemons);
};

#endif