#include <stdio.h>
#include <string.h>

char erste_zahl [20];
char zweite_zahl [20];
char operator [20];


int main() {
    
    printf("Willkommen im Taschenrechner! Was kann ich rechnen?\n");

    printf("Eingabe der Ersten Zahl:");
    fgets(erste_zahl, sizeof(erste_zahl), stdin);
    erste_zahl[strcspn(erste_zahl, "\n")] = '\0';

    printf("Eingabe der Zweiten Zahl:");
    fgets(zweite_zahl, sizeof(zweite_zahl), stdin);
    zweite_zahl[strcspn(zweite_zahl, "\n")] = '\0';

    printf("Eingabe des Operators:");
    fgets(operator, sizeof(operator), stdin);
    operator[strcspn(operator, "\n")] = '\0';

    printf(erste_zahl);
    printf(operator);
    printf(zweite_zahl);

    return 0;
}