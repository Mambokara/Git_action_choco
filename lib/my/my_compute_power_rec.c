/*
** EPITECH PROJECT, 2023
** my_compute_power_rec
** File description:
** Program made to recursively give the
** power of the number given in parameter
*/
int my_compute_power_rec(int nb, int p)
{
    int num_pow;

    if (p < 0){
        return 0;
    } else if (p == 0) {
        return 1;
    } else {
        num_pow = nb * my_compute_power_rec(nb, p - 1);
    }
    return (num_pow);
}
