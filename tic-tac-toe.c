#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void startTableau(char tableau[3][3]){ //Création de la fonction qui crée le tableau
  for (int i = 0; i < 3; i++) { //Boucle parcourant le lignes du tableau
    for (int j = 0; j < 3; j++) { //Boucle parcourant les colone du tableau
      tableau[i][j] = ' ';
    }
  }

}
void printTableau(char tableau[3][3]) { //Cération de la fonction qui affiche la grille au joueur
  printf(" %c | %c | %c \n", tableau[0][0], tableau[0][1], tableau[0][2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n",  tableau[1][0], tableau[1][1], tableau[1][2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", tableau[2][0], tableau[2][1], tableau[2][2]);
}
void joueurMouvement(char tableau[3][3], char symbole) { //Création de la fonction pour le tour du joueur + empecher la triche
  int lig, col;
  printf("Entrez la ligne (0, 1, 2) et la colonne (0, 1, 2) : ");
  scanf("%d %d", &lig, &col);

  if (tableau[lig][col] == ' ') {
    tableau[lig][col] = symbole;
  } else {
    printf("Case déjà prise ! Essayer a nouveau.\n");
    joueurMouvement(tableau, symbole);
  }
}
void ordiMouvement(char tableau[3][3]) { //création de la fonction pour les mouvements de l'ordinateur
  int lig, col;
    
  do {
    lig = rand() % 3; 
    col = rand() % 3;
  } while (tableau[lig][col] != ' '); //anti triche pour le robot    
  tableau[lig][col] = 'O';
  printf("L'ordinateur joue à la position (%d, %d)\n", lig, col);
}
int checkWin(char tableau[3][3]) { //Création de la fonction qui vérifie si nous avons gagner le jeu 
  for (int i = 0; i < 3; i++) {
    if (tableau[i][0] == tableau[i][1] && tableau[i][1] == tableau[i][2] && tableau[i][0] != ' ') {
      return 1;
    }
  }
  for (int i = 0; i < 3; i++) {
    if (tableau[0][i] == tableau[1][i] && tableau[1][i] == tableau[2][i] && tableau[0][i] != ' ') {
      return 1;
    }
  }
  if (tableau[0][0] == tableau[1][1] && tableau[1][1] == tableau[2][2] && tableau[0][0] != ' ') {
    return 1;
  }
  if (tableau[0][2] == tableau[1][1] && tableau[1][1] ==tableau[2][0] && tableau[0][2] != ' ') {
    return 1;
  }
  return 0;
}
int main() { //jeu
  char tableau[3][3];
  char joueur = 'X';
  int mouvement = 0;

  srand(time(NULL));  // Initialisation du générateur de nombres aléatoires
  startTableau(tableau);

  while (1) {
    printTableau(tableau);    
    if (joueur == 'X') {
      printf("Tour du joueur (X) :\n");
      joueurMouvement(tableau, 'X');
    } else {
      printf("Tour de l'ordinateur (O) :\n");
      ordiMouvement(tableau);
    }
    mouvement++;
    if (checkWin(tableau)) {
      printTableau(tableau);
      printf("Le joueur %c a gagné !\n", joueur);
      break;
    }
    if (mouvement == 9) {
      printTableau(tableau);
      printf("Match nul !\n");
    break;
    }
     joueur = (joueur == 'X') ? 'O' : 'X';
  }

  return 0;
}