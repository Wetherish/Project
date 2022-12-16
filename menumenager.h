//
// Created by Bartek on 30.05.2022.
//

#ifndef PROJEKTZALICZENIE_264396_PT_2022_MENUMENAGER_H
#define PROJEKTZALICZENIE_264396_PT_2022_MENUMENAGER_H
#include "weapon.h"
#include "Unit.h"
#include "Aktioncards.h"


class menumenager {

    weapon &w;
    Unit &hero;
    Aktioncards &cards;

    struct buff{
        bool has_buff;
        int how_big;
    };
    int buffsize = 0;
    buff emblem;

int listofweapon[7];
int owned[11];
int listofcards[5];

public:
    menumenager(weapon &weapon1, Unit &unit, Aktioncards &cards1);

    void generate_list();
    void generate_action_card();

    void buy_card_eq(int index);
    void buy_card_aktion(int index);

    void sell_eq(int index);
    void sell_cards(int index);

    void clear_eq();

    int get_bonus_eqHP();
    int get_bonus_eqDMG();

    int get_owned_spell(int x) const;
    void element_bonus_hp();
    void element_bonus_damage();

    int get_count_fire();
    int get_count_earth();
    int get_count_wind();
    int get_count_water();

    int get_index_weapon_list(int posiotion);
    int get_index_cards_list(int position);
    int get_owned_cards(int posiotion);

    void used_card(int index);

    int get_owned(int position);
    void set_owned(int index, int i);


};


#endif //PROJEKTZALICZENIE_264396_PT_2022_MENUMENAGER_H
