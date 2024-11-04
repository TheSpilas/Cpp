#include "card.h"

Card::Card(const string& name) : cardName(name) {}

PokemonCard::PokemonCard(const string& name, const string& type, const string& family, int evolution, int max_hp,
                         int attack1Cost, const string& attack1Name, int attack1Damage,
                         int attack2Cost, const string& attack2Name, int attack2Damage)
    : Card(name), pokemonType(type), familyName(family), evolutionLevel(evolution), maxHP(max_hp), hp(max_hp) {
    attacks.push_back(make_tuple(attack1Cost, attack1Cost, attack1Name, attack1Damage));
    attacks.push_back(make_tuple(attack2Cost, attack2Cost, attack2Name, attack2Damage));
}

void PokemonCard::displayInfo() const {
    cout << "Pokemon Card - Name: " << cardName << ", Type: " << pokemonType << ", Evolution Level: " << evolutionLevel
         << " of the family \"" << familyName << "\", HP: " << maxHP << "\"" << endl;
    cout << "Attacks:" << endl;
    for (size_t i = 0; i < attacks.size(); ++i) {
        const auto& attack = attacks[i];
        cout << "Attack #" << i << ":" << endl;
        cout << "Attack cost: " << get<0>(attack) << endl;
        cout << "Attack current energy storage: " << get<1>(attack) << endl;
        cout << "Attack description: " << get<2>(attack) << endl;
        cout << "Attack damage: " << get<3>(attack) << endl;
    }
}

void PokemonCard::heal() {
    hp = maxHP;
}

EnergyCard::EnergyCard(const string& type) : Card("Energy"), energyType(type) {}

void EnergyCard::displayInfo() const {
    cout << "Card Name: " << cardName << endl;
    cout << "Energy Card - Type: " << energyType << endl;
}

TrainerCard::TrainerCard(const string& name, const string& effect) : Card(name), trainerEffect(effect) {}

void TrainerCard::displayInfo() const {
    cout << "Trainer Card - Name: " << cardName << ", Effect: " << trainerEffect << endl;
}

void TrainerCard::applyEffect(vector<PokemonCard*>& activePokemons) {
    if (trainerEffect == "heal all your action pokemon") {
        for (auto& pokemon : activePokemons) {
            pokemon->heal();
        }
    }
}