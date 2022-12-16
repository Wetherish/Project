//
// Created by Bartek on 05.06.2022.
//

#ifndef PROJEKTZALICZENIE_264396_PT_2022_FIGHTMENAGER_H
#define PROJEKTZALICZENIE_264396_PT_2022_FIGHTMENAGER_H

#include "weapon.h"
#include "Unit.h"
#include "Aktioncards.h"
#include "menumenager.h"

class fightmenager {
    weapon &w;
    Unit &hero;
    Unit &enemy;
    Aktioncards &cards;
    menumenager &menumg;
    vector<int> owneddeck;
    int stun = 0;
public:
    fightmenager(weapon &w1, Unit &hero1, Unit &enemy1, Aktioncards &cards1, menumenager &menumg1);

    void setownedspells();

    int getspell(int index);

    void cast_spel(int index);

    void play();

    void attack_hero();

    void attack_enemy();

    int get_stun() const;

    void dekrementstun();
};


#endif //PROJEKTZALICZENIE_264396_PT_2022_FIGHTMENAGER_H
