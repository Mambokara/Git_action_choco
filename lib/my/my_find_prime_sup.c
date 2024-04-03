/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** Program made to fin the nearest superior
** or equal prime number as the number given as parameter
*/
int find_prime(int nb)
{
    int i = 2;

    if ((nb % 2 == 0 && nb != 2) || nb <= 1){
        return 0;
    }
    while (nb % i != 0 && i <= nb / 2){
        i++;
    }
    if (nb % i != 0 || i == 2){
        return 1;
    } else {
        return 0;
    }
}

int my_find_prime_sup(int nb)
{
    int nb_sup = nb + 1;

    if (find_prime(nb) == 1){
        return nb;
    }
    while (find_prime(nb_sup) == 0){
        find_prime(nb_sup);
        nb_sup++;
    }
    return nb_sup;
}
