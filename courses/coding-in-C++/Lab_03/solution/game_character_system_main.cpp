#include "game_character_system.hpp"
#include <iostream>

int main()
{
    /* ================= Create Characters ================= */

    Warrior warrior("Aragorn", 120, 2, 50);
    Mage mage("Gandalf", 100, 3, 200);
    Healer healer("Elrond", 90, 2, 150);
    Thief thief("Bilbo", 80, 1, 20);

    /* ================= Store in Array ================= */

    Character *characters[4];

    characters[0] = &warrior;
    characters[1] = &mage;
    characters[2] = &healer;
    characters[3] = &thief;

    /* ================= Test Inventory ================= */

    warrior.getInventory().addItem("Sword");
    warrior.getInventory().addItem("Shield");

    thief.getInventory().addItem("Dagger");

    /* ================= Test Method Chaining ================= */

    warrior
        .damageTaken(20)
        .earnExperience(150);

    mage
        .regenerateMagic(50)
        .earnExperience(300);

    healer
        .heal(30, warrior) // healer heals warrior
        .earnExperience(200);

    thief
        .steal(warrior) // steal item from warrior
        .earnExperience(100);

    /* ================= Test Edge Cases ================= */

    std::cout << "\n=== Edge Cases ===\n";

    // damage > health
    warrior.damageTaken(1000);

    // steal from empty inventory
    thief.steal(mage);

    // healer heals itself
    healer.heal(50, healer);

    healer.displayStatus();

    return 0;
}