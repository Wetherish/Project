//
// Created by Bartek on 30.05.2022.
//

#include "menumenager.h"

menumenager::menumenager(weapon &weapon1, Unit &unit, Aktioncards &cards1) : w(weapon1), hero(unit), cards(cards1) {

    !emblem.has_buff;
    emblem.how_big = 0;

    generate_list();
    generate_action_card();
}
void menumenager::generate_action_card() {
    int x = 0;
    int randomcards;
    for (int ctr = 0; ctr < 5; ++ctr) {
        randomcards = rand() % (cards.get_decksize() -2)+1;

        listofcards[x] = randomcards;
//        cards.display_card(randomcards);
//        if (can_buy_card(randomcards))
//            cout<<"can buy "<< ctr <<endl;
//        else
//            cout<<"cant buy"<<endl;
        x++;
    }
}

void menumenager::generate_list() {
    int randomeq;
    int x = 0;
   // cout << "Here you can buy new items. You have: " <<hero.get_gold()<< " coins" << endl;
    for (int ctr = 0; ctr < 7; ++ctr) {
        randomeq = rand() % (w.get_numberofweapons()-1)+1;

        for (int i = 0; i < ctr ; ++i) {
            while(listofweapon[i] == randomeq)
            {
                randomeq = rand() % (w.get_numberofweapons()-6)+1;
            }
        }
        listofweapon[x] = randomeq;
       // w.display_weapon(randomeq);
       // if (can_buy_eq(randomeq))
           // cout<<"can buy "<< ctr <<endl;
        //else
            //cout<<"cant buy"<<endl;
        x++;
    }
}

void menumenager::buy_card_eq(int index) {
    if(hero.get_gold() >= w.get_cost(index)) {
        int check;
        if (w.get_type(index) == sword) {
            check = 0;
        }
        if (w.get_type(index) == head) {
            check = 1;
        }
        if (w.get_type(index) == chest) {
            check = 2;
        }
        if (w.get_type(index) == legs) {
            check = 3;
        }
        if (w.get_type(index) == feet) {
            check = 4;
        }
        if (owned[check] == 0) {
            hero.decrease_gold(w.get_cost(index));
            if (w.get_type(index) == sword) {
                    owned[0] = index;
                hero.increase_damage(w.get_damage(owned[0]));
                hero.increase_hp(w.get_def(owned[0]));

            }
            if (w.get_type(index) == head) {
                    owned[1] = index;
                hero.increase_damage(w.get_damage(owned[1]));
                hero.increase_hp(w.get_def(owned[1]));

            }
            if (w.get_type(index) == chest) {
                    owned[2] = index;
                    hero.increase_damage(w.get_damage(owned[2]));
                hero.increase_hp(w.get_def(owned[2]));

            }
            if (w.get_type(index) == legs) {
                    owned[3] = index;
                hero.increase_damage(w.get_damage(owned[3]));
                hero.increase_hp(w.get_def(owned[3]));

            }
            if (w.get_type(index) == feet) {
                    owned[4] = index;
                hero.increase_damage(w.get_damage(owned[4]));
                hero.increase_hp(w.get_def(owned[4]));

            }
            //cout << "kupiony item: " << w.get_name(index) << " gold: " << hero.get_gold() << endl;
            if(get_count_wind() > emblem.how_big or get_count_earth() > emblem.how_big or get_count_water() > emblem.how_big or get_count_fire() > emblem.how_big)
            {
                emblem.has_buff =false;
                hero.decrease_damage(buffsize);
//                cout << "minus" << buffsize <<endl;
                hero.decrease_hp(buffsize);
//                cout << "minus" << buffsize << endl;

            }
            if(!emblem.has_buff)
            {
                element_bonus_damage();
                element_bonus_hp();
               // emblem.has_buff = true;

            }
        }
    }
}

void menumenager::clear_eq() {
    for (int i = 0; i < 11; ++i) {
        owned[i] = 0;
    }
}

void menumenager::sell_eq(int index) {
    if(w.get_type(owned[index])!= nothing)
    {

       // cout<<"sprzedany item: "<<w.get_name(owned[index]);
        hero.increase_gold(w.get_cost(owned[index]));
        hero.decrease_damage(w.get_damage(owned[index]));
        hero.decrease_hp(w.get_def(owned[index]));
        owned[index] = 0;
        hero.set_hp(get_bonus_eqHP() + hero.get_default_hp());
        hero.set_dmg(get_bonus_eqDMG() + hero.get_default_dmg());

        element_bonus_damage();
        element_bonus_hp();


        }
       // get_buff();
    }

int menumenager::get_count_fire() {
    int ctr = 0;
    for (int numbereq = 0; numbereq < 5; ++numbereq) {
        if(w.get_element(owned[numbereq]) == fire) {
            ctr++;
        }
    }
    return ctr;
}

void menumenager::element_bonus_hp()
{
    if(get_count_fire() == 3){
        hero.increase_hp(5);
        buffsize = 5;
        emblem.how_big = 3;
    }
    if(get_count_fire() == 4){
        hero.increase_hp(10);
        buffsize = 10;
        emblem.how_big = 4;
    }
    if(get_count_fire() == 5){
        hero.increase_hp(15);
        buffsize = 15;
        emblem.how_big = 5;
    }
    if(get_count_earth() == 3){
        hero.increase_hp(5);
        buffsize = 5;
        emblem.how_big = 3;
    }
    if(get_count_earth() == 4){
        hero.increase_hp(10);
        buffsize = 10;
        emblem.how_big = 4;
    }
    if(get_count_earth() == 5){
        hero.increase_hp(15);
        buffsize = 15;
        emblem.how_big = 5;
    }
    if(get_count_wind() == 3){
        hero.increase_hp(5);
        buffsize = 5;
        emblem.how_big = 3;
    }
    if(get_count_wind() == 4){
        hero.increase_hp(10);
        buffsize = 10;
        emblem.how_big = 4;
    }
    if(get_count_wind() == 5){
        hero.increase_hp(15);
        buffsize = 15;
        emblem.how_big = 5;
    }
    if(get_count_water() == 3){
        hero.increase_hp(5);
        buffsize = 5;
        emblem.how_big = 3;
    }
    if(get_count_water() == 4){
        hero.increase_hp(10);
        buffsize = 10;
        emblem.how_big = 4;
    }
    if(get_count_water() == 5){
        hero.increase_hp(15);
        buffsize = 15;
        emblem.how_big = 5;
    }
}

void menumenager::element_bonus_damage() {
    if(get_count_fire() == 3){
        hero.increase_damage(5);
        cout << "wzrost o: " << 5 << "fire 3" <<endl;
    }
    if(get_count_fire() == 4){
        hero.increase_damage(10);
        cout << "wzrost o: " << 10 << "fire 4" <<endl;
    }
    if(get_count_fire() == 5){
        hero.increase_damage(15);
        cout << "wzrost o: " << 15 << "fire 5" <<endl;
    }
    if(get_count_earth() == 3){
        hero.increase_damage(5);
        cout << "wzrost o: " << 5 << "eart 3" <<endl;
    }
    if(get_count_earth() == 4){
        hero.increase_damage(10);
        cout << "wzrost o: " << 10 << "eart 4"<<endl;
    }
    if(get_count_earth() == 5){
        hero.increase_damage(15);
        cout << "wzrost o: " << 10 << "eart 5"<<endl;
    }
    if(get_count_wind() == 3){
        hero.increase_damage(5);
        cout << "wzrost o: " << 10 << "wind 3"<<endl;
    }
    if(get_count_wind() == 4){
        hero.increase_damage(10);
        cout << "wzrost o: " << 10 << "wind 4"<<endl;
    }
    if(get_count_wind() == 5){
        hero.increase_damage(15);
        cout << "wzrost o: " << 15 << "wind 5"<<endl;
    }
    if(get_count_water() == 3){
        hero.increase_damage(5);
        cout << "wzrost o: " << 5 << "water3"<<endl;
    }
    if(get_count_water() == 4){
        hero.increase_damage(10);
        cout << "wzrost o: " << 10 << "water 4"<<endl;
    }
    if(get_count_water() == 5){
        hero.increase_damage(15);
        cout << "wzrost o: " << 15 << "water 5"<<endl;
    }
}



int menumenager::get_count_earth() {
    int ctr = 0;
    for (int numbereq = 0; numbereq < 5; ++numbereq) {
        if(w.get_element(owned[numbereq]) == earth) {
            ctr++;
        }
    }
    return ctr;}

int menumenager::get_count_wind() {
    int ctr = 0;
    for (int numbereq = 0; numbereq < 5; ++numbereq) {
        if(w.get_element(owned[numbereq]) == wind) {
            ctr++;
        }
    }
    return ctr;
}

int menumenager::get_count_water() {
    int ctr = 0;
    for (int numbereq = 0; numbereq < 5; ++numbereq) {
        if(w.get_element(owned[numbereq]) == water) {
            ctr++;
        }
    }
    return ctr;
}

void menumenager::buy_card_aktion(int index) {
    if(hero.get_gold() >= w.get_cost(index)) {
    int check = 5;
        while(cards.get_name(owned[check] and check < 11) != "empty"){
            check++;

        }
        if(check >= 11)
            return;
        else {
            owned[check] = index;
            hero.decrease_gold(cards.get_cost(index));

        }
    }
}

int menumenager::get_owned_spell(int x) const {
    return owned[x];
}
int menumenager::get_index_weapon_list(int index) {

    return listofweapon[index];
}

int menumenager::get_owned_cards(int posiotion) {
    return owned[posiotion];
}

int menumenager::get_index_cards_list(int position) {
    return listofcards[position];
}


void menumenager::sell_cards(int index) {
    hero.increase_gold(cards.get_cost(owned[index+5]));
    owned[index+5] = 0;

}



void menumenager::used_card(int index) {
    if(index >= 5)
    owned[index] = 0;
}


int menumenager::get_bonus_eqHP() {
    int x = 0;
    for (int i = 0; i < 5; ++i) {
        x = x + w.get_def(owned[i]);

    }
    return x;
}

int menumenager::get_bonus_eqDMG() {
    int x = 0;
    for (int i = 0; i < 5; ++i) {
        x = x + w.get_damage(owned[i]);

    }
    return x;
}

int menumenager::get_owned(int position) {
    return owned[position];
}


void menumenager::set_owned(int index, int i) {
    owned[i] = index;
}
