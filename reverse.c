#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Main
int main(int argc, char *argv[]) {

    char rivi[50]; //rivin max pituus 50
    char rivit[1000] = "";
    FILE *tiedosto1, *tiedosto2;
    //Tiedoston luku
    if ((tiedosto1 = fopen("input.txt", "r")) == NULL){
        printf("Virhe tiedoston avaamisessa.\n");
        exit(1);
    }
    while ((fgets(rivi, 50, tiedosto1)) != NULL) {
        strrev(rivi);
        rivi[0] = '\n';
        strcat(rivit, rivi);
    }
    fclose(tiedosto1);
    //Luettu tiedosto muutetaan merkkijonoksi, joka käännetään toisinpäin. Tämä merkkijono kirjoitetaan uuteen tiedostoon.
    strrev(rivit);

    if ((tiedosto2 = fopen("output.txt", "w")) == NULL){
        printf("Virhe tiedoston avaamisessa.\n");
        exit(1);
    }
    fprintf(tiedosto2, "%s", rivit);
    fclose(tiedosto2);
    printf("\nKiitos ohjelman käytöstä!");
    return 0;
}