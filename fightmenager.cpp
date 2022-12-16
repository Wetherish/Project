//
// Created by Bartek on 05.06.2022.
//

#include "fightmenager.h"

fightmenager::fightmenager(weapon &w1, Unit &hero1, Unit &enemy1, Aktioncards &cards1, menumenager &menumg1) : w(w1),
                                                                                                               hero(hero1),
                                                                                                               enemy(enemy1),
                                                                                                               cards(cards1),
                                                                                                               menumg(menumg1) {

}


void fightmenager::cast_spel(int index) {
    stun += cards.get_stuntime(menumg.get_owned_spell(index + 5));
    hero.increase_hp(cards.get_bonushp(menumg.get_owned_spell(index + 5)));
    cout << "bonus hp:" << cards.get_bonushp(menumg.get_owned_spell(index + 5)) << endl;
    hero.increase_damage(cards.get_bonusdamage(menumg.get_owned_spell(index + 5)));
    cout << "bonus damage: " << cards.get_bonusdamage(menumg.get_owned_spell(index + 5)) << endl;
    enemy.decrease_damage(cards.get_minusdamage(menumg.get_owned_spell(index + 5)));
    cout << "minus damage: " << cards.get_minusdamage(menumg.get_owned_spell(index + 5)) << endl;
    enemy.decrease_hp(cards.get_minushp(menumg.get_owned_spell(index + 5)));
    cout << "minus hp:" << cards.get_minushp(menumg.get_owned_spell(index + 5)) << endl;
    cout << cards.get_name(menumg.get_owned_spell(index + 5));
    menumg.used_card(index + 5);


}

void fightmenager::attack_hero() {
    if (hero.get_hp() > 0)
        enemy.decrease_hp(hero.get_damage());
}

void fightmenager::attack_enemy() {
    if (enemy.get_hp() > 0)
        hero.decrease_hp(enemy.get_damage());
}

int fightmenager::getspell(int index) {
    return 0;
}

int fightmenager::get_stun() const {
    return stun;

}

void fightmenager::dekrementstun() {
    if (stun > 0)
        stun -= 1;
}


