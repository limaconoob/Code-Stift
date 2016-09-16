/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stift.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 01:39:01 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/16 09:59:09 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STIFT_H
# define STIFT_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

# define PROCESS    42
# define TRUE       0
# define FALSE      1

# define MAPP       coucou->mapper
# define MATR       coucou->matrix
# define WIND       coucou->wind
# define MOUS       coucou->mous
# define CURS       coucou->curs
# define SLID       coucou->slide
# define TERM       coucou->term
# define INFO       coucou->info
# define SIZE       (coucou->nb_col * (coucou->size_max + 3)) + 1

# define CPY        ft_strcpy
# define LEN        ft_strlen
# define BZE        ft_bzero

///1
///De
///Fr Définition des types
typedef unsigned char     u8;       //
typedef unsigned short    u16;      //
typedef unsigned long     u32;      //
typedef signed char       s8;       //
typedef signed short      s16;      //
typedef signed long       s32;      //
///1

///2
///De Mousetaste
///Fr Énumération des boutons de souris
typedef enum e_mouse
{ LCK,                              //Bouton Gauche
  MCK,                              //Bouton Molette
  RCK,                              //Bouton Droit
  WUP = 64,                         //Molette vers le Haut
  WDN,                              //Molette vers le Bas
  DDL = 32,                         //DnD Gauche
  DDM,                              //DnD Molette
  DDR,                              //DnD Droite
  } t_mouse;
///2

///3
///De
///Fr Énumération et définitions des touches du clavier
typedef enum e_keys
{ SUPPR = 126,                      //Touche Supprimer
  DEL = 127,                        //Touche Retour-Arrière
  LIN = 68,                         //Touche flèche de Gauche
  REC = 67,                         //Touche flèche de Droite
  UNT = 66,                         //Touche flèche du Bas
  TOP = 65,                         //Touche flèche du Haut
  TAB = 9 } t_keys;                 //Touche Tabulation
#define ESC 27
///3

///3
///De
///Fr Énumération des erreurs du programme
typedef enum e_error
{ Malloc = 0x00,                    //Mémoire dynamique insuffisante
  Option = 0x01,                    //Mauvaise Option
  TermInit = 0x02,                  //Contrôle du terminal compromis

  NoInputFile = 0x04,               //Aucun fichier à éditer transmis
} t_error;
///3

///3
///De
///Fr Énumération des avertissements du programme
typedef enum e_warning
{ MissingFile = 0x00,               //Fichier absent
  Access = 0x01,                    //Fichier interdit d'accès
  TooMuchWindows = 0x02,            //Trop de fenêtres ouvertes en même temps
  TermEdit = 0x04,                  //Tentative d'éditer le terminal
  EmptyName = 0x08,                 //Nom de fichier vide
} t_warning;
///3

/*
///3
///De
///Fr Énumération des réparations du programme
typedef enum e_cure
{  } t_cure;                        //
///3
*/

///3
///De
///Fr Structure contenue dans la matrice du terminal
typedef struct s_tab
{ char c;                           //Caractère à afficher
  char attr[10][8]; } t_tab;        //Attributs du caractère
///3

///3
///De
///Fr Structure d'une fenêtre
typedef struct s_wind
{ int fd;                           //Fd du fichier ouvert dans la fenêtre
  char *name;                       //Nom du fichier ouvert dans la fenêtre
  t_tab **matrix;                   //Matrice de caractères du terminal
  int info[2];                      //Taille de la matrice
  int wind[6];                      //Coordonnées de la fenêtre :
                                    //(0, 1): dans le terminal
                                    //(2, 3): dans la matrice
                                    //(4, 5): taille
  int slide[3];                     //(0, 1): coordonnées du slide dans la matrice
                                    //2: Longueur
} t_wind;
///3

///3
///De
///Fr Structure de définition du terminal
// FEATURE::Terminal en 3D
typedef struct s_term
{ int curs[4];                      //Coordonnées du curseur :
                                    //(0, 1): dans le terminal
                                    //(2, 3): dans la matrice
  int mous[5];                      //Coordonnées de la souris :
                                    //(0, 1): dans le terminal
                                    //(2, 3): dans la matrice
                                    //4: Bouton enfoncé
  int term[2];                      //Taille du terminal
  t_wind **wind;                    //Fenêtres stockées (même celles suspendues)
  int nb_wind;                      //Nombre de fenêtres
  t_tab **matrix;                   //Matrice de caractères du terminal
  int info[2];                      //Taille de la matrice
  char **tab_tri;                   //Tableau de tri des éléments
} t_term;
///3

///3
///De Hallo :)
///Fr Coucou :)
t_term *coucou_init(char **argv);
void free_coucou(t_term *coucou);
///3

int         get_next_line(int fd, char **line);
///3
///De
///Fr Gestion des issues et réparations du programme
void stift_cure(int type, char *prob);
void stift_error(int type, char *prob);
void stift_warning(int type, char *prob);
///3

///3
///De
///Fr Interactions avec le terminal grâce à ioctl(2) et aux caractères
///Fr d'échappements ("\033[...");
void term_init(void);
int term_coord(void);
void go_to(int x, int y);
///3

///3
///De
///Fr
void get_names(char **argv, t_term *coucou);
void remove_file(t_term *coucou, int x, int y);
void command_line(t_term *coucou);
void get_size(int x, int y, t_term *tm);
void free_mapper(t_term *coucou);
void put_result(t_term *coucou);
void do_exit(t_term *coucou);
///3

///3
///De
///Fr Manipulations de la matrice de caractères
t_tab **matrix_init(int *size);
void get_coords(int *coord, int *test, t_term *coucou);
void init_char(char c, t_tab *ceil, char attr[10][8]);
void free_matrix(t_tab **matrix);
///3

///3
///De
///Fr Manipulations de la fenêtre du programme
void wind_init(char **argv, t_term *coucou);
void init_wind(int *wind, t_tab **matrix, t_term *coucou);
void windower(int *wind, t_tab **matrix);
void wind_clear(int *wind, t_tab **matrix);
void wind_line(char *str, int i, int *j, t_tab **matrix);
void slide(t_term *coucou);
///3

///3
///De
///Fr Gestion des événements
int idle(char* buf, t_term *coucou);
int mouse(char *buf, t_term *coucou);
int fleche(char *buf, t_term *coucou);
void select_ret(t_term *coucou, int flag);
void content_use(void (*tab)(char*, t_term*));
void ft_signal(void);
///3

///3
///De
///Fr
void ft_tri(char **tab);
char *ft_concat(char *s1, char *s2, int pot);
///3

#endif
