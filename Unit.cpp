//
// Created by Bartek on 02.05.2022.
//

#include "Unit.h"

Unit::Unit(int hp, int damage, int gold, string name) {
this -> hp = hp;
this -> damage = damage;
this -> gold = gold;
this -> name = name;
d_dmg = damage;
d_hp = hp;
    cout<<"damage: "<<get_damage()<<endl;

}

string Unit::get_name() const
{
return name;
}

int Unit::get_gold() const {
    return gold;
}
int Unit::get_hp() const {
    return hp;
}


void Unit::increase_gold(int PlusGold) {
    gold += PlusGold;
}

void Unit::decrease_gold(int MinusGold) {
    gold -= MinusGold;
}

void Unit::increase_hp(int PlusHp) {
    hp += PlusHp;
}

void Unit::decrease_hp(int MinusHp) {
    hp -= MinusHp;
}

void Unit::decrease_damage(int MinusDamage) {
    damage -= MinusDamage;
}

void Unit::increase_damage(int PlusDamage) {
    damage += PlusDamage;
}

int Unit::get_damage() const {
    return damage;
}

void Unit::set_hp(int hpp) {
hp = hpp;
}
int Unit::get_default_hp() {
    return d_hp;
}

int Unit::get_default_dmg() {
    return d_dmg;
}

void Unit::set_dmg(int hpp) {
   damage = hpp;
}
