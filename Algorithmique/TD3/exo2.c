// Affiche les éléments d'une liste chaînée dans la console
void afficher(Liste L) {
	if(est_liste_vide(L)) {
		printf("\n");
		return;
	}

	printf("%d ", tete(L));
	afficher(queue(L));
}

// Inverse une liste chaînée
Liste inverser(Liste L1, Liste L2) {
	if(est_liste_vide(L1)) return L2;

	L2 = ajouter(tete(L1), L2);
	inverser(queue(L1), L2);
}

// Vérifie l'égalité entre deux listes, si la deuxième liste a un élément de plus que la première, retourne quand même 1 (pour les palindromes impairs)
int palindrome2(Liste m, Liste n) {
	if(!est_liste_vide(m) && !est_liste_vide(n)) {
		if(tete(m) == tete(n)) {
			palindrome2(queue(m), queue(n));
		} else {
			return 0;
		}
	}
	else if(est_liste_vide(m) && est_liste_vide(n)) {
		return 1;
	}
	else if(est_liste_vide(m) && est_liste_vide(queue(n))) {
		return 1;
	}
	else if(est_liste_vide(m) && !est_liste_vide(queue(n))) {
		return 0;
	}
}

// Divise  une liste en deux en inversant la deuxième partie puis retourne 1 si la liste est un palindrome ou 0 si elle ne l'est pas
int palindrome(Liste L) {
	int compteur, i, j;
	Liste m1;
	Liste m2;
	Liste m;
	Liste n;

	m = L;
	compteur = 0;
	
	// Compte le nombre d'éléments de la chaîne
	while(!est_liste_vide(queue(m))) {
		m = queue(m);
		compteur++;
	}
	printf("compteur %i\n", compteur);

	// Divise la chaîne par deux, si la chaîne est impaire, n aura un élément en plus
	m1 = creer_liste_vide();
	n = creer_liste_vide();
	m = L;
	m2 = m;
	for(j=0; j<(compteur-1)/2; j++) {
		m1 = ajouter(tete(m2), m1);
		m2 = queue(m2);
		compteur++;
	}
	m = creer_liste_vide();
	m = inverser(m1, m);    // Remet dans l'ordre la première partie de la chaîne
	n = inverser(m2, n);	// Inverse la seconde partie de la chaîne
	printf("%s", "m : ");
	afficher(m);
	printf("%s", "n : ");
	afficher(n);
	return palindrome2(m, n);
}