//
// Created by Bartek on 27.05.2022.
//

#ifndef KARCIANKAZALICZENIE_WEPON_H
#define KARCIANKAZALICZENIE_WEPON_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
enum eqoraktion{eqcard, aktioncard};
enum element{fire, water,earth, wind,joker,non};
enum type{sword,head,chest,feet,legs,nothing};
struct eq_stats{
    element element;
    int damage;
    int def;
    int cost;
    int index;

    type eqtype;
    string name;
};

    class weapon {

    public:
        vector<eq_stats> item;
        weapon(int x);
        void set_stats(element elem, int damage, int def, int cost, int index, string name,type eqtype);
        void creat();
        int get_damage(int index) const;
        int get_type(int index);
        int get_def(int index) const;
        int get_cost(int index) const;
        string get_name(int index) const;
        element get_element(int index)  const;
        void display_weapon(int index);
        int get_numberofweapons() const;
        void debug();

    };


#endif //KARCIANKAZALICZENIE_WEPON_H
