#include "player.h"
#include <iostream>

Player::Player(const string& name) : playerName(name) {}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int index) {
    if (index >= 0 && index < benchCards.size()) {
        PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards[index]);
        if (pokemon) {
            actionCards.push_back(pokemon);
            benchCards.erase(benchCards.begin() + index);
        }
    }
}

void Player::attachEnergyCard(int benchIndex, int actionIndex) {
    if (benchIndex >= 0 && benchIndex < benchCards.size() && actionIndex >= 0 && actionIndex < actionCards.size()) {
        EnergyCard* energy = dynamic_cast<EnergyCard*>(benchCards[benchIndex]);
        if (energy) {
            benchCards.erase(benchCards.begin() + benchIndex);
        }
    }
}

void Player::displayBench() const {
    cout << "Bench Cards for " << playerName << ":" << endl;
    for (const auto& card : benchCards) {
        card->displayInfo();
    }
}

void Player::displayAction() const {
    cout << "Action Cards for " << playerName << ":" << endl;
    for (const auto& card : actionCards) {
        card->displayInfo();
    }
}

void Player::attack(int attackerIndex, int attackIndex, Player& opponent, int targetIndex) {
    if (attackerIndex >= 0 && attackerIndex < actionCards.size() && targetIndex >= 0 && targetIndex < opponent.actionCards.size()) {
        PokemonCard* attacker = actionCards[attackerIndex];
        PokemonCard* target = opponent.actionCards[targetIndex];
    }
}

void Player::useTrainer(int index) {
    if (index >= 0 && index < benchCards.size()) {
        TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[index]);
        if (trainer) {
            trainer->applyEffect(actionCards);
            benchCards.erase(benchCards.begin() + index);
        }
    }
}