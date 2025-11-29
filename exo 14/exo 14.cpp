// exo 14.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

int main()
{
    int tableau[10] = { 1, 5, 2, 7, 8, 7, 9, 10, 9, 11 };
    int max = 10;
    int nbrUtilisateur, decalage;                                                     // choix de taille de l'utilisateur.
    char c = ' ';                                                                    // pour savoir si on le fait a gauche ou a droite.

    printf("Bonjour, quel nombre voulez vous votre tableau?\n");
    while (scanf_s("%d", &nbrUtilisateur) != 1)
    {
        printf("ce nombre est ou incorrect veuillez choisir un nombre entre 1 et %d\n", (max));         // boucle pour empecher l'utilisateur de rentrer autre chose qu'un nombre
        while ((getchar()) != '\n');

    }

    while (nbrUtilisateur > max)
    {
        printf("Nombre trop grand, recommencez.\n");                                          // boucle pour empecher l'utilisateur d'utiliser un nombre plus grand que le tableau
        scanf_s("%d", &nbrUtilisateur);
        while ((getchar()) != '\n');
    }
    

    printf("Voici le tableau.\n");

    for (int i = 0; i < nbrUtilisateur; i++)
        printf(" %d |", tableau[i]);

    while ((getchar()) != '\n');
    printf("\nsouhaitez vous faire une rotation a gauche ou a droite?(G/D)\n");

    
    while ((toupper(c = getchar())) != 'G' && (toupper(c)) != 'D')                                         // boucle si l'utilisateur choisis autre chose que g ou d
    {                                                                                                      // on utilise toupper pour prendre en compte les minuscules
        printf("Vous n'avez pas choisi gauche ou droite, recommencez.\n");
        while ((getchar()) != '\n');
    }
    c = toupper(c);                                                                                        // si l'utilisateur a rentré une minuscule, on la change avec la fonction toupper

    printf("De combien de case souhaitez vous decaler?\n");

    while (scanf_s("%d", &decalage) != 1)
    {
        printf("ceci n'est pas un nombre!, recommencez.\n");                                                 // boucle au cas ou il rentre encore autre chose qu'un nombre

        while ((getchar()) != '\n');
    }
    while ((getchar()) != '\n');

    while(decalage > nbrUtilisateur)
    {
        printf("votre nombre surpasse la taille du tableau, recommencez.\n");                                //boucle au cas ou il veut décaler avec un nombre au dessus de la taille du tableau
        scanf_s("%d", &decalage);
        while ((getchar()) != '\n');
    }

    
    
    if (c == 'G') 
    {
        
        for (int d = 0; d < decalage; d++)
        {
            int temp = tableau[0];

            for (int i = 0; i < nbrUtilisateur - 1; i++)                                       // on fait attention a ne pas dépasser le tableau.
                tableau[i] = tableau[i + 1];

            tableau[nbrUtilisateur - 1] = temp;
        }
    }

    if (c == 'D')
    {
        for (int d = 0; d < decalage; d++)
        {
            int temp = tableau[nbrUtilisateur - 1];

            for (int i = nbrUtilisateur - 1; i > 0; i--)
                tableau[i] = tableau[i - 1];

            tableau[0] = temp;
        }
    }

    printf("voici le tableau retourne.\n");
    for (int i = 0; i < nbrUtilisateur; i++)
        printf(" %d |", tableau[i]);

    printf("\nMerci et a bientot.");
    getchar();
    return 0;
}

