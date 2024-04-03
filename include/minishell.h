/*
** EPITECH PROJECT, 2023
** corentinbergaentzle
** File description:
** bsprintf
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_
    #define _GNU_SOURCE

typedef struct minishell_s {
    char **env;
}minishell_t;

int launch_terminal(int argc, char **argv, char **env);
char **get_env(char **env);
char **split(char *read, char *separator);
int change_directory(minishell_t *mysh, char **infos);
void display_env(minishell_t *mysh);
int execute_function(char **infos, int nb_words, minishell_t *mysh);
int count_words(char *str);
void free_array(char **array);
char *my_strdupe(char *str);
char *get_absolute(char *src, char **env);
char **spliter(char *src, char *separator);
int count_paths(char *str);
int get_position(char **env);
int get_oldpos(char **env);
char *get_pos(char **env);
char *get_home(char **env);
void set_oldpwd(minishell_t *mysh);
void set_newpwd(minishell_t *mysh);
int my_unsetenv(char *name, minishell_t *mysh);
char **my_setenv(char *name, char *string, minishell_t *mysh);
int get_env_pos(char *name, char **env);
int check_exec(char **infos, minishell_t *mysh);
int check_env(char **infos, minishell_t *mysh);
char *add_enter(char *read);
int make_setenv(char **infos, minishell_t *mysh);
int exitter(char **infos);
char **copy_env(char **tmp_env, char **env);
int my_setenv_empty(char *name, minishell_t *mysh);
void replace_env(char *string, char **env, int pos);
char **add_env(minishell_t *mysh, char *string);
int launch_isatty(char **infos, size_t len, minishell_t *mysh, int val);
int launch_not_isatty(char **infos, minishell_t *mysh, int val, size_t len);
int check_file_dir(char **infos);

#endif /* !MINISHELL_H_ */
