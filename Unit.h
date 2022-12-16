//
// Created by Bartek on 02.05.2022.
//
#include <iostream>
#include <string>
#include <vector>
#ifndef KARCIANKAZALICZENIE_UNIT_H
#define KARCIANKAZALICZENIE_UNIT_H

using namespace std;



class Unit {
    string name;
    int hp;
    int damage;
    int gold;
    int d_hp;
    int d_dmg;
public:
    Unit(int hp, int damage, int gold, string name);

    string get_name() const;
    int get_hp() const;
    int get_gold() const;
    int get_damage() const;

    void increase_gold(int PlusGold);
    void decrease_gold(int MinusGold);

    void decrease_hp(int MinusHp);
    void increase_hp(int PlusHp);

    void decrease_damage(int MinusDamage);
    void increase_damage(int PlusDamage);

    int get_default_hp();
    int get_default_dmg();
    void set_hp(int hpp);
    void set_dmg(int hpp);
};


#endif //KARCIANKAZALICZENIE_UNIT_H
