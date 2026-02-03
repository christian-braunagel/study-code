/*
 * File: chars_and_pointers.c
 * Description: This program should support the understanding of how strings and pointers work together
 */

#include <stdio.h>

/**
 * @brief change the second letter of the string to c
 *
 * @param[out]  str String pointer to be modified
 */
void change_char(char str[])
{
    *(str + 1) = 'c';
    printf("%s\n", str);
    return;
}

int main()
{

    char proverb[] = "Curly bird catches the worm"; // Zeichenkette ist intern char * (siehe auch Zeile darunter)
    char *p_proverb = proverb;

    char proverb2[] = "AAtions speak louder than words";

    printf("%s\n", proverb);
    // printf("%s\n", *p_proverb); // Segmentation fault: *p_proverb ist der Inhalt des Zeigers = C; da ein Zeiger auf Integer in printf("%s") erwartet wird, wird C als Adresse interpretiert und darauf zugegriffen
    printf("%s\n", p_proverb); // Das ist korrekt

    *p_proverb = 'E';       // Inhalt des Pointers ändern; dazu muss der Typ passen; hier char
    *(p_proverb + 1) = 'a'; // Pointer arithmetik

    printf("%s\n", proverb);

    // change_char("literal"); // würde ein Segmentation Fault erzeugen, da in function der Inhalt angepasst werden soll aber es sich um einen Stringliteral handelt, der auf dem statischen Speichersegment liegt, der nur readonly ist
    change_char(proverb2); // korrekt: Pointer übergeben oder eben char [] denn char [] ist intern char *

    return 0;
}
