#include <string>
#include <iostream>
#include "Weapon.h"
#include "Character.h"
#include "Item.h"
#include "Monster.h"

using namespace std;

int main()
{
    // WARMUP 1
    /*
    Weapon weapon1 = Weapon("waaaaaaaaa", Sword, 1, 110, 1, 1);
    Weapon weapon2 = Weapon("Not an ax", Staff, 2, 9, 100, 1);

    weapon1.ToString();

    //Character character1 = Character("Jack", "Sparrow");
    //Character character2 = Character("Obi Wan", "Kenobi", "Hello there!", 1000, 100, weapon1, Human, Paladin);

    //character2.Introduce();

    vector<Weapon*> stock;
    stock.push_back(&weapon2);

    Merchant merchant1 = Merchant("Pierre");
    Merchant merchant2 = Merchant("Feuille", "Papeterie", "Vend des feuilles", "Les feuilles s'envolent!", 1000);
    Merchant merchant3 = Merchant("Anvil", "Forge", "La forge", "Ca tape encore et toujours", 1000, stock);

    //character1.UseWeapon(&weapon1, &character2);

    // Achat weapon
    
    character1.Buy(&weapon2, &merchant3);
    character2.Buy(&weapon2, &merchant3);
    cout << "nb stock : " << merchant3.GetNbWeapon() << endl;

    character1.Introduce();
    character2.Introduce();

    // Vente weapon
    //character1.Sell(&merchant3);
    //character2.Sell(&merchant1);
    cout << "nb stock : " << merchant1.GetNbWeapon() << endl;
    //character2.Introduce();
    */


    // WARMUP 2
    Weapon weapon1 = Weapon("waaaaaaaaa", Sword, 1, 110, 1, 1);
    Weapon weapon2 = Weapon("Not an ax", Staff, 2, 9, 30, 1);
    Weapon weapon3 = Weapon("No", Bow, 1.5f, 9, 20, 1);

    Character character1 = Character("Jack Sparrow", "Junk pirate", "Why Fight When You Can Negotiate?", 100, 100, nullptr, 15, Gobelin, Priest);
    Character character2 = Character("Obi-Wan Kenobi", "BBQ master", "Hello there!", 150, 5000, &weapon1, 10, Human, Paladin);

    character1.Introduce();
    cout << endl;
    character2.Introduce();
    cout << endl << endl;

    vector<Weapon*> stock;
    stock.push_back(&weapon2);

    Merchant merchant1 = Merchant("Pierre");
    Merchant merchant2 = Merchant("Feuille", "Papeterie", "Vend des feuilles", "Les feuilles s'envolent!", 1000);
    Merchant merchant3 = Merchant("Anvil", "Forge", "La forge", "Ca tape encore et toujours", 1000, stock);

    // Buy weapon
    cout << "-------------- Buy weapon -------------\n\n";

    character1.Buy(&weapon2, &merchant3);
    cout << endl;
    character2.Buy(&weapon2, &merchant3);
    cout << endl;

    character1.Introduce();
    cout << endl;
    character2.Introduce();
    cout << endl;
    cout << "nb stock : " << merchant3.GetNbWeapon() << endl;

    // Sell weapon
    /*
    cout << "-------------- Sell weapon -------------\n\n";

    character1.Sell(&merchant3);
    cout << endl;
    character2.Sell(&merchant3);
    cout << endl;

    character1.Introduce();
    cout << endl;
    character2.Introduce();
    cout << endl;
    cout << "nb stock : " << merchant3.GetNbWeapon() << endl;
    */

    cout << "\n\n---------------------- Attacks -----------------------\n\n";

    Attack attack1 = Attack("Reverse", &weapon1, 40, Slashing, 1);
    Attack attack2 = Attack("Fire ball", &weapon2, 30, Burning, 2);

    character1.AddAttack(&attack2);
    character2.AddAttack(&attack1);

    Creature creature1 = Creature("Ange", "Come from heaven.", 500, 20);
    Creature creature2 = Creature("Demon", "Come from hell.", 500, 20);

    Item item1 = Item("Sugar", "Not take it too much", 10, 500);
    Item item2 = Item("Watch", "Tic-Tac", 0.78f, 100);

    Monster monster1 = Monster("Godzila", "Big lizard", 500, 15);
    Monster monster2 = Monster("Solen", "Turian", 500, 18);

    monster1.AddItem(&item1);
    monster2.AddItem(&item2);

    monster1.AddAttack(&attack1);
    monster2.AddAttack(&attack2);
}
