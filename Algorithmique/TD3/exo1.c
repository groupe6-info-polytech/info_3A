int trier(Liste L)
{
    int compteur;
    int temp;
    Liste m;

    for(compteur=0; compteur>0; compteur++) {
        m = L;
        while (!est_liste_vide(queue(m))) {
            if(tete(m) > tete(queue(m))) {
                temp = tete(queue(m));
                tete(queue(m)) = tete(m);
                tete(m) = temp;
                compteur++;
            }
            m = queue(m);
        }
    }
}