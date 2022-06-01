#include "embedded/notecom.h"

// programme permettant de lire un fichier texte et d'y saisir des données de différentes manières
// déclaration des fonctions du programme
int read_file(void);
int save_file(char *s);
int edit_file(void);
int clean_file(void);

// fonction principale du programme
// la fonction principale du programme réoriente vers les fonctions secondaires.
// elle permet principalement d'évaluer les arguments passés au moment de l'appel du programme dans
// le terminal, et de réagir en conséquence.
int main(int argc, char *argv[]) {
	// si le nombre d'argument argc est supérieur à 1 ET si la comparaison (strncmp) de argv[1] et
	// la suite de caractères est vraie (true ou 0, alors le programme se dirige vers la fonction
	// adéquate.
    if (argc > 1 && strncmp(argv[1], "-r", 2) == 0) {
        read_file();
    } else if (argc > 1 && strncmp(argv[1], "-s", 2) == 0) {
        save_file(argv[2]);
    } else if (argc > 1 && strncmp(argv[1], "-e", 2) == 0) {
		edit_file();
	} else if (argc > 1 && strncmp(argv[1], "-c", 2) == 0) {
		clean_file();
	} else {
        printf("... pas d'option valable spécifié > fin du programme ...\n");
    }
    return 0;
}

// fonction de lecture du programme
int read_file(void) {
	// définition de 3 variables, une de type FILE avec pointeur, une autre de type char, et une de 
	// type int. 'f' permet de pointer sur le fichier texte, 'c' permet de lire la ligne en cours, 
	// et 'i' va servir de compteur de ligne.
    FILE * f;
    char c;
	int i = 1;

	// ouverture du fichier en mode 'read' (rt)
    f = fopen(FICHIER, "r");
	// tant que 'c' n'a pas atteint la fin du fichier (EOF : End Of File), la boucle continue et lit
	// le caractère suivant. 
	// le compteur de ligne va réagir au symbole \ (back slash), il va incrémenter i de 1, faire un
	// retour à la ligne et afficher le nouveau numéro de ligne.
	printf("  %d \t: ", i);
    while ( (c = fgetc(f)) != EOF ) {
		if (strncmp(&c, "\n", 1) == 0) {
			i++;
			printf("\n  %d \t: ", i);
		} else {
			printf("%c", c);
		}
    }
	printf("\n");
	// fermeture du fichier.
    fclose(f);

    return 0;
}

// fonction de sauvegarde du programme
// cette fonction prend en argument une suite de caractères afin de les écrire dans le fichier
int save_file(char *s) {
	// définition d'un variable 'f' de type FILE avec pointeur, qui pointe sur le fichier à écrire
	// et dans la foulée, ouverture du fichier spécifié en mode ajout ('a' : append)
    FILE * f = fopen(FICHIER, "a");
	// écriture de la suite de caractères
    fwrite(s, 1, strlen(s), f);
	// écriture d'un saut de ligne, afin d'éviter que le suite ne soit directement rajouter à la fin
	// de la ligne précédemment écrite.
    fwrite("\n", 1, 2, f);
	// et fermeture du fichier concerné.
    fclose(f);

    return 0;
}

// fonction d'édition récursive
// cette fonction permet de saisir du texte tant que l'utilisateur ne saisie pas le mot 'stop' dans
// l'invite du programme. l'invite accepte au maximum 2000 caractères.
int edit_file(void) {
	// définition d'une variable 'ligne' de type char de maximum 2000 caractères
	char ligne[2000];
	// définition d'une invite de commande qui permettra d'attribuer une valeur à la variable 'ligne'
	printf("Ncom >>> ");
	fgets(ligne, 2000, stdin);

	// si 'ligne' ne vaut pas "stop": enregistrement de la suite de caractères dans le fichier texte
	// en mode 'ajout', puis la fonction se rappele elle même pour que l'utilisateur puisse continuer
	// à saisir du texte.
	// bien sûr, si 'ligne' vaut "stop", la fonction et le programme s'arrêtent.
	if (strncmp(ligne, "stop", 4) != 0) {
		FILE * f = fopen(FICHIER, "a");
		fwrite(ligne, 1, strlen(ligne), f);
		fclose(f);
		edit_file();
	} else {
		return 0;
	}
	return 0;
}

// fonction permettant de vider le fichier texte.
// elle va ouvrir le fichier en mode 'w' (write) ce qui a pour effet d'écraser le contenu
int clean_file(void) {
	FILE * f;
	f = fopen(FICHIER, "w");
	fwrite("", 1, 0, f);
	fclose(f);
	printf("...le fichier %s a été vidé...\n", FICHIER);
	return 0;
}
