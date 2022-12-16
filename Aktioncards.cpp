//
// Created by Bartek on 03.06.2022.
//

#include "Aktioncards.h"
using namespace std;
Aktioncards::Aktioncards(int x) {
    create();
}

void Aktioncards::create() {
    setstats(0,0,0,0,0,0,"empty",buff, true);
    setstats(10,0,0,4,0,0,"bonus damage (buff)",buff, false);
    setstats(0,0,0,4,0,10,"heal (buff)",buff, false);
    setstats(5,0,0,4,0,5,"heal and damage (buff)",buff, false);

    setstats(0,0,1,4,0,0,"freeze (nerf)",nerf, false);
    setstats(0,0,0,4,10,0,"hurt (nerf)",nerf, false);
    setstats(0,10,0,4,0,0,"exhaust (nerf)",nerf, false);
    setstats(0,5,0,4,5,0,"exhaust and damage (nerf)",nerf, false);

}



void Aktioncards::setstats(int bonusdamage, int minusdamage, int freeztime, int cost, int minushp, int bonushp, string name, action bn, bool empty) {
    cards karta;
    karta.name = name;
    karta.bonusdamage = bonusdamage;
    karta.minusdamage = minusdamage;
    karta.freeztime = freeztime;
    karta.cost = cost;
    karta.minushp = minushp;
    karta.bonushp = bonushp;
    karta.bn = bn;
    karta.empty = empty;
    deck1.push_back(karta);

}

int Aktioncards::get_bonusdamage(int index) const {
    return deck1[index].bonusdamage;
}

int Aktioncards::get_minusdamage(int index) const {
    return deck1[index].minusdamage;
}

int Aktioncards::get_bonushp(int index) const {
    return deck1[index].bonushp;
}

int Aktioncards::get_minushp(int index) const {
    return deck1[index].minushp;
}

int Aktioncards::get_cardtype(int index) {
    return deck1[index].bn;

}

int Aktioncards::get_stuntime(int index) const {
    return deck1[index].freeztime;
}

int Aktioncards::get_cost(int index) const {
    return deck1[index].cost;
}

string Aktioncards::get_name(int index) const {
    return deck1[index].name;
}

void Aktioncards::display_card(int index) {
   cout << get_name(index)
   << " bonus damage: " << get_bonusdamage(index)
   << " minus damage: " << get_minusdamage(index)
   << " bonus hp: " << get_bonushp(index)
   << " minus hp: " << get_minushp(index)
   << " freez atatak: " << get_stuntime(index)
   << " cost: " << get_cost(index) << endl;

}

int Aktioncards::get_decksize() {
    return deck1.size();
}

bool Aktioncards::isempty(int index) const {
    return deck1[index].empty;
}




// resnik