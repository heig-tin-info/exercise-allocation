# Exercice d'allocation dynamique

On demande d'écrire un programme qui demande à l'utilisateur de saisir des nombres. A la fin de la saisie, les nombres sont récités dans l'ordre croissants.

Cette opération nécessite donc de stocker tous les nombres dans un tableau.

**Entre chaque version faites un `git commit` de vos changements**

## Programme

Le programme devra fonctionner comme ceci:

```console
$ ./sort 5 <<< "3 4 2 1 5"
1
2
3
4
5
```

**Note:** l'écriture `./a <<< "foo"` est identique à `cat foo | ./a`.

Le nombre d'éléments à lire est le premier argument du programme `sort`. Vous pouvez utliser `atoi`.

## Tri d'un tableau

Pour trier un tableau vous utilserez la fonction `qsort` standard :

```c
int compare(const void* a, const void* b)
{
     int int_a, int_b = *((int*)a), *((int*)b);

     if (int_a == int_b)
        return 0;
     else if (int_a < int_b)
        return -1;
     else
        return 1;
}

qsort(array, sizeof(array)/sizeof(int), sizeof(int), compare)
```

## Implémentation statique

Pour vous faire la main, il est demandé d'écrire un programme qui utilise une solution statique avec un tableau.

```c
int read_number(void) {
    int num;
    int ret;
    do {
       printf("Veuillez saisir un nombre: ");
    while ((ret = scanf("%d", &num) != 1) && ret != EOF);
    return num;
}

int main(void) {
    int tab[100];
}
```

Si le nombre d'éléments saisis est plus grand que le nombre d'éléments maximum de votre tableau statique, vous retournerez une erreur.

## Implémentation avec allocation dynamique

Cette fois-ci vous remplacez `int tab[100]` par de l'allocation dynamique.

## Implémentation avec réallocation dynamique

L'idée est de s'affranchir de passer la taille du tableau en paramètre. Par défaut vous réservez un tableau de 1 élément dynamiquement. A chaque fois que la taille du tableau dynamique est atteinte, vous réallouer avec `realloc` un tableau deux fois plus grand que celui d'origine.

