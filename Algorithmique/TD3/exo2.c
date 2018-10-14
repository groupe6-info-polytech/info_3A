int palindrome2(Liste m, Liste n) {
    printf("%i %i\n", tete(m), tete(n));
    if(!est_liste_vide(m) && !est_liste_vide(n)) {
        if(tete(m) == tete(n)) {
            if(est_liste_vide(queue(m)) && est_liste_vide(queue(n))) return 1;
            else palindrome2(queue(m), queue(n));
        }
    } 
    else if(est_liste_vide(m) && est_liste_vide(n)) return 1;
    else if(est_liste_vide(m) && est_liste_vide(queue(n)))
        return 1;
    else return 0;
}

int palindrome(Liste L) {
    int compteur, i, j;
    Liste m2;
    Liste m = L;
    Liste n  = creer_liste_vide();
    compteur = 0;
    while(!est_liste_vide(queue(m))) {
        m = queue(m);
        compteur++;
    }
    m = L;
    for(j=compteur; j>=compteur/2; j=j-1) {
        m2 = m;
        for(i=0; i<=j-1; i++) {
            if(est_liste_vide(m2)) {
            } else {
                m2 = queue(m2);
            }
        }
        ajouter(tete(m2), n);
    }
    
    printf("tête m %i\n", tete(m));
    printf("tête n %i\n", tete(n));
    return palindrome2(m, n);
}