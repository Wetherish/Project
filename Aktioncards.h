//
// Created by Bartek on 03.06.2022.
//
#include <vector>
#include <string>
#include "iostream"
#ifndef PROJEKTZALICZENIE_264396_PT_2022_AKTIONCARDS_H
#define PROJEKTZALICZENIE_264396_PT_2022_AKTIONCARDS_H
using namespace std;


enum action{buff, nerf};
struct cards {
    int bonusdamage;
    int minusdamage;
    int freeztime;
    int cost;
    int minushp;
    int bonushp;
    bool empty ;

    string name;
    action bn;

};

class Aktioncards {
    vector<cards>deck1;
public:
    explicit Aktioncards(int x);
    void create();
    void setstats(int bonusdamage, int minusdamage, int freeztime,int cost ,int minushp, int bonushp, string name, action bn, bool empty);
    int get_bonusdamage(int index) const;
    int get_minusdamage(int index) const;
    int get_bonushp(int index) const;
    int get_minushp(int index) const;
    int get_cardtype(int index);
    int get_stuntime(int index) const;
    int get_cost(int index) const;
    bool isempty(int index) const;
    string get_name(int index) const;
    void display_card(int index);
    int get_decksize();

};


#endif //PROJEKTZALICZENIE_264396_PT_2022_AKTIONCARDS_H
