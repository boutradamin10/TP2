#include <stdio.h>
#include <string.h>

typedef struct Module {
  char nom[50];
  float td;
  float tp;
  float quiz;
  float CC;
  float exam;
  float moyenne;
} Module;

float calculerMoyenneModule(Module module) {
  return (module.td + module.tp + module.quiz + module.CC + module.exam) / 5;
}

void afficherModule(Module module) {
  printf("Module name: %s\n", module.nom);
  printf("grade td: %.2f\n", module.td);
  printf("grade tp: %.2f\n", module.tp);
  printf("grade quiz: %.2f\n", module.quiz);
  printf("grade CC: %.2f\n", module.CC);
  printf("grade exam: %.2f\n", module.exam);
  printf("an average: %.2f\n", module.moyenne);
}

int estEchoueModule(Module module) {
  return module.moyenne < 10;
}

float calculerMoyenneGenerale(Module modules[], int nbModules) {
  float sommeMoyennes = 0;
  for (int i = 0; i < nbModules; i++) {
    sommeMoyennes += modules[i].moyenne;
  }
  return sommeMoyennes / nbModules;
}

void afficherModules(Module modules[], int nbModules) {
  for (int i = 0; i < nbModules; i++) {
    afficherModule(modules[i]);
  }
}

int main() {
  Module semester1[7];
  Module semester2[7];

  const char* nomsModules[] = {
    "Algorithmique",
    "Analyse",
    "Système d'exploitation",
    "Logique mathématique",
    "Probabilité",
    "Algèbre",
    "English"
  };

  printf("Enter data for first semester:\n");
  for (int i = 0; i < 7; i++) {
    strcpy(semester1[i].nom, nomsModules[i]);
    printf("Enter the material information %d (%s):\n", i + 1, semester1[i].nom);
    printf(" td: ");
    scanf("%f", &semester1[i].td);
    printf(" tp: ");
    scanf("%f", &semester1[i].tp);
    printf(" quiz: ");
    scanf("%f", &semester1[i].quiz);
    printf(" CC: ");
    scanf("%f", &semester1[i].CC);
    printf(" exam: ");
    scanf("%f", &semester1[i].exam);
    semester1[i].moyenne = calculerMoyenneModule(semester1[i]);
  }

  printf("\nEnter data for second semester:\n");
  for (int i = 0; i < 7; i++) {
    strcpy(semester2[i].nom, nomsModules[i]);
    printf("Enter the material information %d (%s):\n", i + 1, semester2[i].nom);
    printf(" td: ");
    scanf("%f", &semester2[i].td);
    printf(" tp: ");
    scanf("%f", &semester2[i].tp);
    printf(" quiz: ");
    scanf("%f", &semester2[i].quiz);
    printf(" CC: ");
    scanf("%f", &semester2[i].CC);
    printf(" exam: ");
    scanf("%f", &semester2[i].exam);
    semester2[i].moyenne = calculerMoyenneModule(semester2[i]);
  }

  printf("\nFirst Semester Modules:\n");
  afficherModules(semester1, 7);

  printf("\nSecond Semester Modules:\n");
  afficherModules(semester2, 7);

  float moyenneGenerale1 = calculerMoyenneGenerale(semester1, 7);
  float moyenneGenerale2 = calculerMoyenneGenerale(semester2, 7);
  float moyenneGenerale = (moyenneGenerale1 + moyenneGenerale2) / 2;
  printf("\nOverall average for both semesters: %.2f\n", moyenneGenerale);

  int nbModulesEchoues1 = 0;
  int nbModulesEchoues2 = 0;
  for (int i = 0; i < 7; i++) {
    if (estEchoueModule(semester1[i])) {
      nbModulesEchoues1++;
    }
    if (estEchoueModule(semester2[i])) {
      nbModulesEchoues2++;
    }
  }
   if (moyenneGenerale >= 10) {
      printf(" The student moves to the next year.\n");
    } else {
    printf("\nThe student needs to take a makeup exam or repeat the year.\n");
    }


  return 0;
}

