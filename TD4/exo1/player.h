#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.h"

using namespace std;

class Player {
private:
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;

public:
    Player(const string& name);

    void addCardToBench(Card* card);
    void activatePokemonCard(int index);
    void attachEnergyCard(int benchIndex, int actionIndex);
    void displayBench() const;
    void displayAction() const;
    void attack(int attackerIndex, int attackIndex, Player& opponent, int targetIndex);
    void useTrainer(int index);
};

#endif