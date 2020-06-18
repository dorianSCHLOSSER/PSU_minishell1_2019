/*
** EPITECH PROJECT, 2019
** _MY_H_
** File description:
** return
*/

#ifndef _MY_H_
#define _MY_H_
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

int my_getnbr(char const *str);
int my_putstr(char const *str);
int my_arrlen(char **str);
void my_put_nbr(int nb);
void my_putchar(char c);
int my_strlen(char const *str);
char **my_str_to_word_array(char const *str, char c);
int my_strcmp(char const *s1, char const *s2);
char *my_getenv(char **env, char *elem);
void my_free_array(char **str);
char *my_strcat(char *dest, char *src);
int my_strcmp_mn(char const *s1, char const *s2);
void my_error_global(char **str);
int my_error_setenv(char *str);
char *my_strdup(char const *src);
int my_putstrtwo(char const *str);
int check_access(char *tab, char *str);

typedef struct list_t list_t;
struct list_t
{
    char *env;
    list_t *following;
};

typedef struct eternel_s
{
    char *old_pwd;
} eternel_t;

list_t *my_create_node(char *envp);
list_t *my_create_egal(char *envp, char *str);
list_t *my_params_list(char **envp);
int my_strlen_list(list_t *list);
int access_paths(char **tab, char **str, list_t *list);
void livefre(list_t *list);
list_t *remove_elementfront(list_t *list);
int my_error_set(char **str, list_t *list);
int my_getline(char **str, list_t **list, char *get, eternel_t *eternel);
void my_print_list(list_t *list);
int my_setenv_end(list_t *list, char **str);
int check_getline(char **str, list_t **list);
char **list_to_tab(list_t *list, char **str);
list_t **my_unsetenv(list_t **list, char *str);
int check_cd_env(char **str, list_t *list, char *get, eternel_t *eternel);
int do_cd(list_t *list, char **str, char *get, eternel_t *eternel);
char *for_old_pwd(list_t *list);
char *check_pwd(char *str);
int check_old_pwd(list_t *list);
void my_old_pwd(list_t *list, char *old);
void cd_tir(list_t *list, eternel_t *eternel);
void my_pwd(list_t *list, char *str);
int my_add_end(list_t *list, char *eternel);

#endif
