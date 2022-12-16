//
// Created by Bartek on 27.05.2022.
//

#include "weapon.h"

weapon::weapon(int x) {
    creat();
    debug();
}

void weapon::set_stats(element elem, int damage, int def, int cost, int index, string name, type eqtype) {
    eq_stats itemek;
    itemek.damage = damage;
    itemek.cost = cost;
    itemek.def = def;
    itemek.cost = cost;
    itemek.name = name;
    itemek.element = elem;
    itemek.eqtype = eqtype;
    item.push_back(itemek);

}

void weapon::creat() {
    set_stats(non, 0, 0, 0, 0, "empty", nothing);
    set_stats(fire, 10, 0, 5, 1, "fire sword", sword);
    set_stats(fire, 3, 10, 6, 2, "fire chest plate", chest);
    set_stats(fire, 2, 6, 4, 3, "fire pants", legs);
    set_stats(fire, 0, 4, 2, 4, "fire helmet", head);
    set_stats(fire, 0, 4, 2, 5, "fire shoes", feet);
    set_stats(water, 10, 0, 5, 6, "water sword", sword);
    set_stats(water, 3, 10, 6, 7, "water chest plate", chest);
    set_stats(water, 2, 6, 4, 8, "water pants", legs);
    set_stats(water, 0, 4, 2, 9, "water helmet", head);
    set_stats(water, 0, 4, 2, 10, "water shoes", feet);
    set_stats(earth, 10, 0, 5, 11, "earth sword", sword);
    set_stats(earth, 3, 10, 6, 12, "earth chest plate", chest);
    set_stats(earth, 2, 6, 4, 13, "earth pants", legs);
    set_stats(earth, 0, 4, 2, 14, "earth helmet", head);
    set_stats(earth, 0, 4, 2, 15, "earth shoes", feet);
    set_stats(wind, 10, 0, 5, 16, "wind sword", sword);
    set_stats(wind, 3, 10, 6, 17, "wind chest plate", chest);
    set_stats(wind, 2, 6, 4, 18, "wind pants", legs);
    set_stats(wind, 0, 4, 2, 19, "wind helmet", head);
    set_stats(wind, 0, 4, 2, 20, "wind shoes", feet);

}

int weapon::get_damage(int index) const {
    return item[index].damage;
}

element weapon::get_element(int index) const {
    return item[index].element;
}

int weapon::get_def(int index) const {
    return item[index].def;
}

int weapon::get_cost(int index) const {
    return item[index].cost;
}

void weapon::debug() {
//    for (int i = 0; i < 20; ++i) {
//        cout<< item[i].name <<" obrazenia: "<< item[i].damage << " hp: " << item[i].def << " koszt: " << item[i].cost << " element: " << item[i].element << endl;
//
//    }


}

string weapon::get_name(int index) const {
    return item[index].name;
}

void weapon::display_weapon(int index) {
    cout << item[index].name << " damage: " << item[index].damage << " bonus hp: " << item[index].def << " cost: "
         << item[index].cost << " element: " << item[index].element << endl;

}

int weapon::get_numberofweapons() const {
    cout << item.size();
    return item.size();

}

int weapon::get_type(int index) {
    return item[index].eqtype;
}


