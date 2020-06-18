/*
** EPITECH PROJECT, 2020
** my_pronpt
** File description:
** return
*/

#include "../lib/my/my.h"

char **take_paths(char **tab, char **envp)
{
    char *strt = my_getenv(envp, "PATH");
    if (my_getenv(envp, "PATH") == NULL) return (NULL);
    if (strt[0] == '\0') return (NULL);
    tab = my_str_to_word_array(strt, ':');
    for (int i = 0 ; tab[i] ; i++) {
        for (int j = 0 ; tab[i][j] ; j++) {
            if (tab[i][j + 1] == '\0') {
                tab[i][j + 1] = '/';
                j += 2;
                tab[i][j] = '\0';
            }
        }
    }
    free(strt);
    return (tab);
}

int access_paths(char **tab, char **str, list_t *list)
{
    int i = 0;
    int index = 1;
    char **envp = list_to_tab(list, envp);
    tab = take_paths(tab, envp);
    if (tab == NULL) {
        my_error_global(str);
        return (84);
    }
    for (; tab[i] && (access(my_strcat(tab[i], str[0]), X_OK) != 0) ; i++);
    if (check_access(tab[i], str[0]) == 0)
        index = fork();
    if (access(my_strcat(tab[i], str[0]), X_OK) != 0) tab[i] = NULL;
    if (index == 0 && check_access(tab[i], str[0]) == 0)
        execve(my_strcat(tab[i], str[0]), str, envp);
    wait(NULL);
    my_free_array(tab);
    return (0);
}

char *remove_elem(char *str, char c)
{
    if (my_strlen(str) == 1) {
        free(str);
        return (NULL);
    }
    char *strp = malloc(sizeof(char) * my_strlen(str) + 1);
    int j = 0;
    for (int i = 0 ; str[i] ; i++) {
        if (str[i] != c) {
            strp[j] = str[i];
            j++;
        }
    }
    strp[j] = '\0';
    free(str);
    return (strp);
}

int check_space(char *buffer)
{
    for (int i = 0 ; buffer[i] ; i++) {
        if (buffer[i] != ' ' && buffer[i] != '\t') return (0);
    }
    return (1);
}

int my_getline(char **str, list_t **list, char *get, eternel_t *eternel)
{
    char *buffer = NULL;
    size_t bufsize = 256;
    char **tab = NULL;
    my_putstr("~~ ");
    if (getline(&buffer, &bufsize, stdin) == -1) {
        livefre(*list);
        my_putstr("exit\n");
        exit(0);
    }
    buffer = remove_elem(buffer, '\n');
    if (buffer == NULL) return (0);
    str = my_str_to_word_array(buffer, ' ');
    if (check_space(buffer) == 1) return (0);
    if (check_getline(str, list) == 0) return (0);
    if (check_cd_env(str, *list, get, eternel) == 0) return (0);
    if ((access_paths(tab, str, *list)) == 84) return (0);
    my_free_array(str);
}