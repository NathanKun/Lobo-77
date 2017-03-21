#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "header.h"

//button
struct Button b_menu_jouer;
SDL_Rect clips_menu_jouer[ 4 ];
SDL_Surface *b_menu_5_buttons_surface=NULL;

struct Button b_menu_parametre;
SDL_Rect clips_menu_parametre[ 4 ];

struct Button b_menu_regle;
SDL_Rect clips_menu_regle[ 4 ];

struct Button b_menu_statistique;
SDL_Rect clips_menu_statistique[ 4 ];

struct Button b_menu_deconnection;
SDL_Rect clips_menu_deconnection[ 4 ];


struct Button b_left;
SDL_Rect clips_left[ 4 ];
SDL_Surface *b_left_right_surface=NULL;

struct Button b_right;
SDL_Rect clips_right[ 4 ];

//background
SDL_Surface *bg_menu_jouer = NULL;
SDL_Surface *bg_menu_parametre = NULL;
SDL_Surface *bg_menu_regle = NULL;
SDL_Surface *bg_menu_statistique = NULL;

//regles' surface
SDL_Surface *regle_1 = NULL;
SDL_Surface *regle_2 = NULL;
SDL_Surface *regle_3 = NULL;
SDL_Surface *regle_4 = NULL;
SDL_Surface *regle_5 = NULL;
SDL_Surface *regle_6 = NULL;

int show_regle=1;

//statistique
SDL_Surface *msg_win = NULL;
SDL_Surface *msg_lose = NULL;
SDL_Surface *msg_login = NULL;
SDL_Surface *msg_win_times = NULL;
SDL_Surface *msg_lose_times = NULL;
SDL_Surface *msg_login_times = NULL;

//game settings
SDL_Surface *playername = NULL;

SDL_Surface *difficulty = NULL;
SDL_Surface *bg_menu_game_settings = NULL;
SDL_Surface *portrait_player = NULL;

struct Button b_start;
SDL_Surface *b_start_surface = NULL;
SDL_Rect clips_start[ 4 ];

//difficulty buttons
struct Button b_npc_1_e;
struct Button b_npc_1_m;
struct Button b_npc_1_h;
struct Button b_npc_2_e;
struct Button b_npc_2_m;
struct Button b_npc_2_h;
struct Button b_npc_3_e;
struct Button b_npc_3_m;
struct Button b_npc_3_h;
struct Button b_npc_4_e;
struct Button b_npc_4_m;
struct Button b_npc_4_h;
struct Button b_npc_5_e;
struct Button b_npc_5_m;
struct Button b_npc_5_h;
struct Button b_npc_6_e;
struct Button b_npc_6_m;
struct Button b_npc_6_h;
struct Button b_npc_7_e;
struct Button b_npc_7_m;
struct Button b_npc_7_h;
struct Button b_npc_8_e;
struct Button b_npc_8_m;
struct Button b_npc_8_h;


SDL_Rect clips_npc_e[4];
SDL_Rect clips_npc_m[4];
SDL_Rect clips_npc_h[4];

//npc's portrait button
struct Button b_npc_1;
struct Button b_npc_2;
struct Button b_npc_3;
struct Button b_npc_4;
struct Button b_npc_5;
struct Button b_npc_6;
struct Button b_npc_7;
struct Button b_npc_8;

SDL_Surface *b_npc_surface = NULL;

SDL_Rect clips_npc[4];

//difficulty numbers
int easy, normal, hard;

//parametre
struct Button b_sound_on;
SDL_Rect clips_sound_on[4];
struct Button b_effect_on;
SDL_Rect clips_effect_on[4];
struct Button b_sound_off;
SDL_Rect clips_sound_off[4];
struct Button b_effect_off;
SDL_Rect clips_effect_off[4];
SDL_Surface *b_sound_effect_surface = NULL;

SDL_Surface *msg_sound = NULL;
SDL_Surface *msg_effect = NULL;




/** partie l'ecran de menu */
/** les fcts pour initier les buttons */
//menu
void set_button_menu_jouer()
{
    b_menu_jouer.box.x=100;
    b_menu_jouer.box.y=300;
    b_menu_jouer.box.h=100;
    b_menu_jouer.box.w=400;
}

void set_button_menu_parametre()
{
    b_menu_parametre.box.x=524;
    b_menu_parametre.box.y=300;
    b_menu_parametre.box.h=100;
    b_menu_parametre.box.w=400;
}

void set_button_menu_regle()
{
    b_menu_regle.box.x=100;
    b_menu_regle.box.y=450;
    b_menu_regle.box.h=100;
    b_menu_regle.box.w=400;
}

void set_button_menu_statistique()
{
    b_menu_statistique.box.x=524;
    b_menu_statistique.box.y=450;
    b_menu_statistique.box.h=100;
    b_menu_statistique.box.w=400;
}

void set_button_menu_deconnection()
{
    b_menu_deconnection.box.x=312;
    b_menu_deconnection.box.y=600;
    b_menu_deconnection.box.h=100;
    b_menu_deconnection.box.w=400;
}

void set_clips_input_for_button_of_menu ( SDL_Rect clips[  ], int i )
{
    clips[ CLIP_MOUSEOVER ].x = 400*i+i;
    clips[ CLIP_MOUSEOVER ].y = 0;
    clips[ CLIP_MOUSEOVER ].w = 400;
    clips[ CLIP_MOUSEOVER ].h = 100;

    clips[ CLIP_MOUSEOUT ].x = 400*i+i;
    clips[ CLIP_MOUSEOUT ].y = 100;
    clips[ CLIP_MOUSEOUT ].w = 400;
    clips[ CLIP_MOUSEOUT ].h = 100;

    clips[ CLIP_MOUSEDOWN ].x = 400*i+i;
    clips[ CLIP_MOUSEDOWN ].y = 200;
    clips[ CLIP_MOUSEDOWN ].w = 400;
    clips[ CLIP_MOUSEDOWN ].h = 100;

    clips[ CLIP_MOUSEUP ].x = 400*i+i;
    clips[ CLIP_MOUSEUP ].y = 300;
    clips[ CLIP_MOUSEUP ].w = 400;
    clips[ CLIP_MOUSEUP ].h = 100;

    /*
     set_clips_input_for_button_of_menu ( clips_menu_jouer,  0);
     set_clips_input_for_button_of_menu ( clips_menu_parametre,  1);
     set_clips_input_for_button_of_menu ( clips_menu_regle,  2);
     set_clips_input_for_button_of_menu ( clips_menu_statistique,  3);
     set_clips_input_for_button_of_menu ( clips_menu_deconnection,  4);
    */
}

void init_menu_buttons ()
{
    set_button_menu_jouer();
    set_button_menu_parametre();
    set_button_menu_regle();
    set_button_menu_statistique();
    set_button_menu_deconnection();

    set_clips_input_for_button_of_menu ( clips_menu_jouer,  0);
    set_clips_input_for_button_of_menu ( clips_menu_parametre,  1);
    set_clips_input_for_button_of_menu ( clips_menu_regle,  2);
    set_clips_input_for_button_of_menu ( clips_menu_statistique,  3);
    set_clips_input_for_button_of_menu ( clips_menu_deconnection,  4);

    b_menu_5_buttons_surface = N_load_img("pic/button/menu_botton.png");

    bg_menu_parametre = N_load_img("pic/bg/parametre.png");
    bg_menu_statistique = N_load_img("pic/bg/statistique.png");
    bg_menu_regle = N_load_img("pic/bg/regle.png");
}

/** afficher 5 buttons dans le menu */
void menu_show_buttons ()
{
    b_menu_jouer=handle_events(b_menu_jouer, clips_menu_jouer);
    b_menu_parametre=handle_events(b_menu_parametre, clips_menu_parametre);
    b_menu_regle=handle_events(b_menu_regle, clips_menu_regle);
    b_menu_statistique=handle_events(b_menu_statistique, clips_menu_statistique);
    b_menu_deconnection=handle_events(b_menu_deconnection, clips_menu_deconnection);

    show_button(b_menu_jouer, b_menu_5_buttons_surface);
    show_button(b_menu_parametre, b_menu_5_buttons_surface);
    show_button(b_menu_regle, b_menu_5_buttons_surface);
    show_button(b_menu_statistique, b_menu_5_buttons_surface);
    show_button(b_menu_deconnection, b_menu_5_buttons_surface);
}

/** comme le nom */
void reset_buttons ()
{
    b_menu_jouer.pressed = 0;
    b_menu_parametre.pressed = 0;
    b_menu_regle.pressed = 0;
    b_menu_statistique.pressed = 0;
    b_menu_deconnection.pressed = 0;
}

/** changer l'ecran en fct du button appuye */
void menu_button_pressed ()
{
    if ( b_menu_jouer.pressed == 1 )
    {
        switch_menu = 8;
        reset_buttons ();
    }

    if ( b_menu_parametre.pressed == 1 )
    {
        switch_menu = 5;
        reset_buttons ();
    }

    if ( b_menu_regle.pressed == 1 )
    {
        switch_menu = 3;
        reset_buttons ();
    }

    if ( b_menu_statistique.pressed == 1 )
    {
        printf("login times = %d\n", player.stat.login_times);
        switch_menu = 2;

        reset_buttons ();
    }

    if ( b_menu_deconnection.pressed == 1 )
    {
        switch_main = 0;
        switch_welcome_page = 0;
        switch_menu = 0;

        reset_buttons ();
        clean_up_menu_Xed();
    }

}


/** partie l'ecran de regle */
//regle
void set_button_left()
{
    b_left.box.x=50;
    b_left.box.y=334;
    b_left.box.h=100;
    b_left.box.w=100;
}

void set_button_right()
{
    b_right.box.x=874;
    b_right.box.y=334;
    b_right.box.h=100;
    b_right.box.w=100;
}

void set_clips_input_for_button_left_right ( SDL_Rect clips[  ], int i )
{
    clips[ CLIP_MOUSEOVER ].x = 100*i;
    clips[ CLIP_MOUSEOVER ].y = 0;
    clips[ CLIP_MOUSEOVER ].w = 100;
    clips[ CLIP_MOUSEOVER ].h = 100;

    clips[ CLIP_MOUSEOUT ].x = 100*i;
    clips[ CLIP_MOUSEOUT ].y = 100;
    clips[ CLIP_MOUSEOUT ].w = 100;
    clips[ CLIP_MOUSEOUT ].h = 100;

    clips[ CLIP_MOUSEDOWN ].x = 100*i;
    clips[ CLIP_MOUSEDOWN ].y = 200;
    clips[ CLIP_MOUSEDOWN ].w = 100;
    clips[ CLIP_MOUSEDOWN ].h = 100;

    clips[ CLIP_MOUSEUP ].x = 100*i;
    clips[ CLIP_MOUSEUP ].y = 300;
    clips[ CLIP_MOUSEUP ].w = 100;
    clips[ CLIP_MOUSEUP ].h = 100;

    /*
    set_clips_input_for_button_left_right ( clips_b_left, 0);
    set_clips_input_for_button_left_right ( clips_b_right, 1);
    */
}

void init_buttons_left_right ()
{
    set_button_left();
    set_button_right();

    set_clips_input_for_button_left_right ( clips_left, 0);
    set_clips_input_for_button_left_right ( clips_right, 1);

    b_left_right_surface = N_load_img("pic/button/left_right.png");
}

void menu_regles_show_buttons ()
{
    b_left=handle_events(b_left, clips_left);
    b_right=handle_events(b_right, clips_right);

    show_button(b_left, b_left_right_surface);
    show_button(b_right, b_left_right_surface);
}

void menu_regle_init()
{
    regle_1 = N_load_img("pic/regle/1.jpg");
    regle_2 = N_load_img("pic/regle/2.jpg");
    regle_3 = N_load_img("pic/regle/3.jpg");
    regle_4 = N_load_img("pic/regle/4.jpg");
    regle_5 = N_load_img("pic/regle/5.jpg");
    regle_6 = N_load_img("pic/regle/6.jpg");

    set_button_b_back();
}

/** afficher l'image de regle en fct de int show_regle */
void menu_regle_show_regle()
{
    if( show_regle == 1)
        N_apply_surface( 217, 0, regle_1, screen, NULL);
    if( show_regle == 2)
        N_apply_surface( 217, 0, regle_2, screen, NULL);
    if( show_regle == 3)
        N_apply_surface( 217, 0, regle_3, screen, NULL);
    if( show_regle == 4)
        N_apply_surface( 217, 0, regle_4, screen, NULL);
    if( show_regle == 5)
        N_apply_surface( 217, 0, regle_5, screen, NULL);
    if( show_regle == 6)
        N_apply_surface( 217, 0, regle_6, screen, NULL);
}

void menu_regle_clean_up ()
{
    SDL_FreeSurface( regle_1 );
    SDL_FreeSurface( regle_2 );
    SDL_FreeSurface( regle_3 );
    SDL_FreeSurface( regle_4 );
    SDL_FreeSurface( regle_5 );
    SDL_FreeSurface( regle_6 );
}

/** fct principale de l'ecran regle, traiter le button gauche et droit, puis afficher l'image de regle */
void menu_regle()
{
    b_back.pressed = 0;
    N_apply_surface(0, 0, bg_menu_regle, screen, NULL);
    b_back = handle_events(b_back, clips_login);
    show_button(b_back, b_back_surface);
    menu_regles_show_buttons ();

    menu_regle_show_regle();

    if( b_left.pressed == 1 )
    {
        if( show_regle > 1 )
            show_regle--;
    }

    if( b_right.pressed == 1 )
    {
        if( show_regle < 6 )
            show_regle++;
    }

    b_left.pressed = 0;
    b_right.pressed = 0;

    menu_regle_show_regle();

    //printf("show_regle = %d\n", show_regle);

    if( b_back.pressed == 1 )
    {
        switch_menu = 0;
        show_regle = 1;
        menu_regle_clean_up ();
        printf("menu_regle_clean_up\n");
    }
}

void clean_up_menu_Xed()
{
    if( b_menu_5_buttons_surface != NULL )
        SDL_FreeSurface(b_menu_5_buttons_surface);
    if( bg_menu != NULL )
        SDL_FreeSurface(bg_menu);
    if( bg_menu_jouer != NULL )
        SDL_FreeSurface(bg_menu_jouer);
    if( bg_menu_parametre != NULL )
        SDL_FreeSurface(bg_menu_parametre);
    if( bg_menu_regle != NULL )
        SDL_FreeSurface(bg_menu_regle);
    if( bg_menu_statistique != NULL )
        SDL_FreeSurface(bg_menu_statistique);


    if( b_ok_surface != NULL )
        SDL_FreeSurface(b_ok_surface);
    if( b_back_surface != NULL )
        SDL_FreeSurface(b_back_surface);


    if( b_sound_effect_surface != NULL )
        SDL_FreeSurface(b_sound_effect_surface);
    if( msg_effect != NULL )
        SDL_FreeSurface(msg_effect);
    if( msg_sound != NULL )
        SDL_FreeSurface(msg_sound);
}


/** partie l'ecran de menu */
//statistique
void menu_statistique_init ()
{
    //sprintf(str, " %d" , num);
    char win[10], lose[10], login_times[10];
    //itoa(player.stat.win, win, 10);
    //itoa(player.stat.lose, lose, 10);
    //itoa(player.stat.login_times, login_times, 10);
    sprintf(win, "%d", player.stat.win);
    sprintf(lose, "%d", player.stat.lose);
    sprintf(login_times, "%d", player.stat.login_times);
    msg_win = message("Gagner : ", font_l);
    msg_lose = message("Perdre : ", font_l);
    msg_login = message("S'identifier : ", font_l);
    msg_win_times = message(win, font_l);
    msg_lose_times = message(lose, font_l);
    msg_login_times = message(login_times, font_l);

    switch_menu = 6;
    set_button_b_back();
}

void menu_statistique_clean_up()
{
    SDL_FreeSurface(msg_win);
    SDL_FreeSurface(msg_lose);
    SDL_FreeSurface(msg_login);
    SDL_FreeSurface(msg_win_times);
    SDL_FreeSurface(msg_lose_times);
    SDL_FreeSurface(msg_login_times);
}

void menu_statistique()
{
    b_back.pressed = 0;
    N_apply_surface(0, 0, bg_menu_statistique, screen, NULL);
    b_back = handle_events(b_back, clips_login);
    show_button(b_back, b_back_surface);

    N_apply_surface(20, 150, msg_win, screen, NULL);
    N_apply_surface(20,350,  msg_lose, screen, NULL);
    N_apply_surface(20, 550, msg_login, screen, NULL);
    N_apply_surface(820, 150, msg_win_times, screen, NULL);
    N_apply_surface(820, 350, msg_lose_times, screen, NULL);
    N_apply_surface(820, 550, msg_login_times, screen, NULL);


    if( b_back.pressed == 1 )
    {
        menu_statistique_clean_up();
        switch_menu = 0;
    }
}


/** partie l'ecran de game setting */
//game settings
void set_button_b_start()
{
    b_start.box.x = 850;
    b_start.box.y = 74;
    b_start.box.w = 100;
    b_start.box.h = 100;
}

void set_button_b_back_menu_game_settings()
{
    b_back.box.x = 700;
    b_back.box.y = 74;
    b_back.box.w = 100;
    b_back.box.h = 100;
}

void set_clips_start()
{
    clips_start[ CLIP_MOUSEOVER ].x = 0;
    clips_start[ CLIP_MOUSEOVER ].y = 0;
    clips_start[ CLIP_MOUSEOVER ].w = 100;
    clips_start[ CLIP_MOUSEOVER ].h = 100;

    clips_start[ CLIP_MOUSEOUT ].x = 0;
    clips_start[ CLIP_MOUSEOUT ].y = 100;
    clips_start[ CLIP_MOUSEOUT ].w = 100;
    clips_start[ CLIP_MOUSEOUT ].h = 100;

    clips_start[ CLIP_MOUSEDOWN ].x = 0;
    clips_start[ CLIP_MOUSEDOWN ].y = 200;
    clips_start[ CLIP_MOUSEDOWN ].w = 100;
    clips_start[ CLIP_MOUSEDOWN ].h = 100;

    clips_start[ CLIP_MOUSEUP ].x = 0;
    clips_start[ CLIP_MOUSEUP ].y = 300;
    clips_start[ CLIP_MOUSEUP ].w = 100;
    clips_start[ CLIP_MOUSEUP ].h = 100;
}

//for npcs' buttons
struct Button set_button_b_npc_portait( struct Button b, int line, int colon )
{
    //line : 1, 2, 3, 4
    //colon : 0, 1
    b.box.x = 30+512*colon;
    b.box.y = 50+150*line;
    b.box.w = 100;
    b.box.h = 100;

    return b;
}

void set_clips_npc_portrait( )
{
    clips_npc[ CLIP_MOUSEOVER ].x = 0;
    clips_npc[ CLIP_MOUSEOVER ].y = 100;
    clips_npc[ CLIP_MOUSEOVER ].w = 100;
    clips_npc[ CLIP_MOUSEOVER ].h = 100;

    clips_npc[ CLIP_MOUSEOUT ].x = 0;
    clips_npc[ CLIP_MOUSEOUT ].y = 0;
    clips_npc[ CLIP_MOUSEOUT ].w = 100;
    clips_npc[ CLIP_MOUSEOUT ].h = 100;

    clips_npc[ CLIP_MOUSEDOWN ].x = 0;
    clips_npc[ CLIP_MOUSEDOWN ].y = 200;
    clips_npc[ CLIP_MOUSEDOWN ].w = 100;
    clips_npc[ CLIP_MOUSEDOWN ].h = 100;

    clips_npc[ CLIP_MOUSEUP ].x = 0;
    clips_npc[ CLIP_MOUSEUP ].y = 200;
    clips_npc[ CLIP_MOUSEUP ].w = 100;
    clips_npc[ CLIP_MOUSEUP ].h = 100;
}

void set_button_for_all_npc_portrait()
{
    b_npc_1 = set_button_b_npc_portait( b_npc_1, 1, 0 );
    b_npc_2 = set_button_b_npc_portait( b_npc_2, 2, 0 );
    b_npc_3 = set_button_b_npc_portait( b_npc_3, 3, 0 );
    b_npc_4 = set_button_b_npc_portait( b_npc_4, 4, 0 );
    b_npc_5 = set_button_b_npc_portait( b_npc_5, 1, 1 );
    b_npc_6 = set_button_b_npc_portait( b_npc_6, 2, 1 );
    b_npc_7 = set_button_b_npc_portait( b_npc_7, 3, 1 );
    b_npc_8 = set_button_b_npc_portait( b_npc_8, 4, 1 );
}

//for difficultys' buttons
struct Button set_button_b_npc( struct Button b, int line, int colon, int difficulty )
{
    //line : 1, 2, 3, 4
    //colon : 0, 1
    //difficylty : 0, 1, 2
    b.box.x = 137+127*difficulty+512*colon;
    b.box.y = 62+150*line;
    b.box.w = 100;
    b.box.h = 50;

    return b;
}

void set_clips_difficulty(SDL_Rect *clips, int i)
{
    clips[ CLIP_MOUSEOVER ].x = 100*i+i;
    clips[ CLIP_MOUSEOVER ].y = 51;
    clips[ CLIP_MOUSEOVER ].w = 100;
    clips[ CLIP_MOUSEOVER ].h = 50;

    clips[ CLIP_MOUSEOUT ].x = 100*i+i;
    clips[ CLIP_MOUSEOUT ].y = 0;
    clips[ CLIP_MOUSEOUT ].w = 100;
    clips[ CLIP_MOUSEOUT ].h = 50;

    clips[ CLIP_MOUSEDOWN ].x = 100*i+i;
    clips[ CLIP_MOUSEDOWN ].y = 102;
    clips[ CLIP_MOUSEDOWN ].w = 100;
    clips[ CLIP_MOUSEDOWN ].h = 50;

    clips[ CLIP_MOUSEUP ].x = 100*i+i;
    clips[ CLIP_MOUSEUP ].y = 102;
    clips[ CLIP_MOUSEUP ].w = 100;
    clips[ CLIP_MOUSEUP ].h = 50;

}

void set_button_for_all_npc()
{
    set_clips_difficulty( clips_npc_e, 0 );
    set_clips_difficulty( clips_npc_m, 1 );
    set_clips_difficulty( clips_npc_h, 2 );

    b_npc_1_e = set_button_b_npc( b_npc_1_e, 1, 0, 0 );
    b_npc_1_m = set_button_b_npc( b_npc_1_m, 1, 0, 1 );
    b_npc_1_h = set_button_b_npc( b_npc_1_h, 1, 0, 2 );
    b_npc_2_e = set_button_b_npc( b_npc_2_e, 2, 0, 0 );
    b_npc_2_m = set_button_b_npc( b_npc_2_m, 2, 0, 1 );
    b_npc_2_h = set_button_b_npc( b_npc_2_h, 2, 0, 2 );
    b_npc_3_e = set_button_b_npc( b_npc_3_e, 3, 0, 0 );
    b_npc_3_m = set_button_b_npc( b_npc_3_m, 3, 0, 1 );
    b_npc_3_h = set_button_b_npc( b_npc_3_h, 3, 0, 2 );
    b_npc_4_e = set_button_b_npc( b_npc_4_e, 4, 0, 0 );
    b_npc_4_m = set_button_b_npc( b_npc_4_m, 4, 0, 1 );
    b_npc_4_h = set_button_b_npc( b_npc_4_h, 4, 0, 2 );
    b_npc_5_e = set_button_b_npc( b_npc_5_e, 1, 1, 0 );
    b_npc_5_m = set_button_b_npc( b_npc_5_m, 1, 1, 1 );
    b_npc_5_h = set_button_b_npc( b_npc_5_h, 1, 1, 2 );
    b_npc_6_e = set_button_b_npc( b_npc_6_e, 2, 1, 0 );
    b_npc_6_m = set_button_b_npc( b_npc_6_m, 2, 1, 1 );
    b_npc_6_h = set_button_b_npc( b_npc_6_h, 2, 1, 2 );
    b_npc_7_e = set_button_b_npc( b_npc_7_e, 3, 1, 0 );
    b_npc_7_m = set_button_b_npc( b_npc_7_m, 3, 1, 1 );
    b_npc_7_h = set_button_b_npc( b_npc_7_h, 3, 1, 2 );
    b_npc_8_e = set_button_b_npc( b_npc_8_e, 4, 1, 0 );
    b_npc_8_m = set_button_b_npc( b_npc_8_m, 4, 1, 1 );
    b_npc_8_h = set_button_b_npc( b_npc_8_h, 4, 1, 2 );

    b_npc_2_h.clip = &clips_npc_h[CLIP_MOUSEOUT];
    b_npc_2_m.clip = &clips_npc_m[CLIP_MOUSEOUT];
}

void show_button_for_all_npc()
{
//1
    if ( b_npc_1_e.pressed == 0 && b_npc_1_m.pressed == 0 && b_npc_1_h.pressed == 0 )
    {
        b_npc_1_e = handle_events(b_npc_1_e, clips_npc_e);
        b_npc_1_m = handle_events(b_npc_1_m, clips_npc_m);
        b_npc_1_h = handle_events(b_npc_1_h, clips_npc_h);
        b_npc_1.clip = &clips_npc[3];
    }

    if ( b_npc_1_e.pressed == 1 && b_npc_1_m.pressed == 0 && b_npc_1_h.pressed == 0 )
    {
        b_npc_1.pressed = 0;
        b_npc_1_m = handle_events(b_npc_1_m, clips_npc_m);
        b_npc_1_h = handle_events(b_npc_1_h, clips_npc_h);
        b_npc_1 = handle_events( b_npc_1, clips_npc );
        if(b_npc_1_m.pressed == 1)
        {
            b_npc_1_e.pressed = 0;
            b_npc_1_h.pressed = 0;
        }
        if(b_npc_1_h.pressed == 1)
        {
            b_npc_1_m.pressed = 0;
            b_npc_1_e.pressed = 0;
        }
    }

    if ( b_npc_1_m.pressed == 1 && b_npc_1_e.pressed == 0 && b_npc_1_h.pressed == 0 )
    {
        b_npc_1.pressed = 0;
        b_npc_1_e = handle_events(b_npc_1_e, clips_npc_e);
        b_npc_1_h = handle_events(b_npc_1_h, clips_npc_h);
        b_npc_1 = handle_events( b_npc_1, clips_npc );
        if(b_npc_1_e.pressed == 1)
        {
            b_npc_1_m.pressed = 0;
            b_npc_1_h.pressed = 0;
        }
        if(b_npc_1_h.pressed == 1)
        {
            b_npc_1_e.pressed = 0;
            b_npc_1_m.pressed = 0;
        }
    }

    if ( b_npc_1_h.pressed == 1 && b_npc_1_e.pressed == 0 && b_npc_1_m.pressed == 0 )
    {
        b_npc_1.pressed = 0;
        b_npc_1_m = handle_events(b_npc_1_m, clips_npc_m);
        b_npc_1_e = handle_events(b_npc_1_e, clips_npc_e);
        b_npc_1 = handle_events( b_npc_1, clips_npc );
        if(b_npc_1_m.pressed == 1)
        {
            b_npc_1_e.pressed = 0;
            b_npc_1_h.pressed = 0;
        }
        if(b_npc_1_e.pressed == 1)
        {
            b_npc_1_m.pressed = 0;
            b_npc_1_h.pressed = 0;
        }
    }

    if ( b_npc_1.pressed ==1 )
    {
        b_npc_1_e.pressed = 0;
        b_npc_1_m.pressed = 0;
        b_npc_1_h.pressed = 0;
    }

//2
    if ( b_npc_2_e.pressed == 0 && b_npc_2_m.pressed == 0 && b_npc_2_h.pressed == 0 )
    {
        b_npc_2_e = handle_events(b_npc_2_e, clips_npc_e);
        b_npc_2_m = handle_events(b_npc_2_m, clips_npc_m);
        b_npc_2_h = handle_events(b_npc_2_h, clips_npc_h);
        b_npc_2.clip = &clips_npc[3];
    }

    if ( b_npc_2_e.pressed == 1 && b_npc_2_m.pressed == 0 && b_npc_2_h.pressed == 0 )
    {
        b_npc_2.pressed = 0;
        b_npc_2_m = handle_events(b_npc_2_m, clips_npc_m);
        b_npc_2_h = handle_events(b_npc_2_h, clips_npc_h);
        b_npc_2 = handle_events( b_npc_2, clips_npc );
        if(b_npc_2_m.pressed == 1)
        {
            b_npc_2_e.pressed = 0;
            b_npc_2_h.pressed = 0;
        }
        if(b_npc_2_h.pressed == 1)
        {
            b_npc_2_m.pressed = 0;
            b_npc_2_e.pressed = 0;
        }
    }

    if ( b_npc_2_m.pressed == 1 && b_npc_2_e.pressed == 0 && b_npc_2_h.pressed == 0 )
    {
        b_npc_2.pressed = 0;
        b_npc_2_e = handle_events(b_npc_2_e, clips_npc_e);
        b_npc_2_h = handle_events(b_npc_2_h, clips_npc_h);
        b_npc_2 = handle_events( b_npc_2, clips_npc );
        if(b_npc_2_e.pressed == 1)
        {
            b_npc_2_m.pressed = 0;
            b_npc_2_h.pressed = 0;
        }
        if(b_npc_2_h.pressed == 1)
        {
            b_npc_2_e.pressed = 0;
            b_npc_2_m.pressed = 0;
        }
    }

    if ( b_npc_2_h.pressed == 1 && b_npc_2_e.pressed == 0 && b_npc_2_m.pressed == 0 )
    {
        b_npc_2.pressed = 0;
        b_npc_2_m = handle_events(b_npc_2_m, clips_npc_m);
        b_npc_2_e = handle_events(b_npc_2_e, clips_npc_e);
        b_npc_2 = handle_events( b_npc_2, clips_npc );
        if(b_npc_2_m.pressed == 1)
        {
            b_npc_2_e.pressed = 0;
            b_npc_2_h.pressed = 0;
        }
        if(b_npc_2_e.pressed == 1)
        {
            b_npc_2_m.pressed = 0;
            b_npc_2_h.pressed = 0;
        }
    }

    if ( b_npc_2.pressed ==1 )
    {
        b_npc_2_e.pressed = 0;
        b_npc_2_m.pressed = 0;
        b_npc_2_h.pressed = 0;
    }

//3
    if ( b_npc_3_e.pressed == 0 && b_npc_3_m.pressed == 0 && b_npc_3_h.pressed == 0 )
    {
        b_npc_3_e = handle_events(b_npc_3_e, clips_npc_e);
        b_npc_3_m = handle_events(b_npc_3_m, clips_npc_m);
        b_npc_3_h = handle_events(b_npc_3_h, clips_npc_h);
        b_npc_3.clip = &clips_npc[3];
    }

    if ( b_npc_3_e.pressed == 1 && b_npc_3_m.pressed == 0 && b_npc_3_h.pressed == 0 )
    {
        b_npc_3.pressed = 0;
        b_npc_3_m = handle_events(b_npc_3_m, clips_npc_m);
        b_npc_3_h = handle_events(b_npc_3_h, clips_npc_h);
        b_npc_3 = handle_events( b_npc_3, clips_npc );
        if(b_npc_3_m.pressed == 1)
        {
            b_npc_3_e.pressed = 0;
            b_npc_3_h.pressed = 0;
        }
        if(b_npc_3_h.pressed == 1)
        {
            b_npc_3_m.pressed = 0;
            b_npc_3_e.pressed = 0;
        }
    }

    if ( b_npc_3_m.pressed == 1 && b_npc_3_e.pressed == 0 && b_npc_3_h.pressed == 0 )
    {
        b_npc_3.pressed = 0;
        b_npc_3_e = handle_events(b_npc_3_e, clips_npc_e);
        b_npc_3_h = handle_events(b_npc_3_h, clips_npc_h);
        b_npc_3 = handle_events( b_npc_3, clips_npc );
        if(b_npc_3_e.pressed == 1)
        {
            b_npc_3_m.pressed = 0;
            b_npc_3_h.pressed = 0;
        }
        if(b_npc_3_h.pressed == 1)
        {
            b_npc_3_e.pressed = 0;
            b_npc_3_m.pressed = 0;
        }
    }

    if ( b_npc_3_h.pressed == 1 && b_npc_3_e.pressed == 0 && b_npc_3_m.pressed == 0 )
    {
        b_npc_3.pressed = 0;
        b_npc_3_m = handle_events(b_npc_3_m, clips_npc_m);
        b_npc_3_e = handle_events(b_npc_3_e, clips_npc_e);
        b_npc_3 = handle_events( b_npc_3, clips_npc );
        if(b_npc_3_m.pressed == 1)
        {
            b_npc_3_e.pressed = 0;
            b_npc_3_h.pressed = 0;
        }
        if(b_npc_3_e.pressed == 1)
        {
            b_npc_3_m.pressed = 0;
            b_npc_3_h.pressed = 0;
        }
    }

    if ( b_npc_3.pressed ==1 )
    {
        b_npc_3_e.pressed = 0;
        b_npc_3_m.pressed = 0;
        b_npc_3_h.pressed = 0;
    }

//4
    if ( b_npc_4_e.pressed == 0 && b_npc_4_m.pressed == 0 && b_npc_4_h.pressed == 0 )
    {
        b_npc_4_e = handle_events(b_npc_4_e, clips_npc_e);
        b_npc_4_m = handle_events(b_npc_4_m, clips_npc_m);
        b_npc_4_h = handle_events(b_npc_4_h, clips_npc_h);
        b_npc_4.clip = &clips_npc[3];
    }

    if ( b_npc_4_e.pressed == 1 && b_npc_4_m.pressed == 0 && b_npc_4_h.pressed == 0 )
    {
        b_npc_4.pressed = 0;
        b_npc_4_m = handle_events(b_npc_4_m, clips_npc_m);
        b_npc_4_h = handle_events(b_npc_4_h, clips_npc_h);
        b_npc_4 = handle_events( b_npc_4, clips_npc );
        if(b_npc_4_m.pressed == 1)
        {
            b_npc_4_e.pressed = 0;
            b_npc_4_h.pressed = 0;
        }
        if(b_npc_4_h.pressed == 1)
        {
            b_npc_4_m.pressed = 0;
            b_npc_4_e.pressed = 0;
        }
    }

    if ( b_npc_4_m.pressed == 1 && b_npc_4_e.pressed == 0 && b_npc_4_h.pressed == 0 )
    {
        b_npc_4.pressed = 0;
        b_npc_4_e = handle_events(b_npc_4_e, clips_npc_e);
        b_npc_4_h = handle_events(b_npc_4_h, clips_npc_h);
        b_npc_4 = handle_events( b_npc_4, clips_npc );
        if(b_npc_4_e.pressed == 1)
        {
            b_npc_4_m.pressed = 0;
            b_npc_4_h.pressed = 0;
        }
        if(b_npc_4_h.pressed == 1)
        {
            b_npc_4_e.pressed = 0;
            b_npc_4_m.pressed = 0;
        }
    }

    if ( b_npc_4_h.pressed == 1 && b_npc_4_e.pressed == 0 && b_npc_4_m.pressed == 0 )
    {
        b_npc_4.pressed = 0;
        b_npc_4_m = handle_events(b_npc_4_m, clips_npc_m);
        b_npc_4_e = handle_events(b_npc_4_e, clips_npc_e);
        b_npc_4 = handle_events( b_npc_4, clips_npc );
        if(b_npc_4_m.pressed == 1)
        {
            b_npc_4_e.pressed = 0;
            b_npc_4_h.pressed = 0;
        }
        if(b_npc_4_e.pressed == 1)
        {
            b_npc_4_m.pressed = 0;
            b_npc_4_h.pressed = 0;
        }
    }

    if ( b_npc_4.pressed ==1 )
    {
        b_npc_4_e.pressed = 0;
        b_npc_4_m.pressed = 0;
        b_npc_4_h.pressed = 0;
    }

//5
    if ( b_npc_5_e.pressed == 0 && b_npc_5_m.pressed == 0 && b_npc_5_h.pressed == 0 )
    {
        b_npc_5_e = handle_events(b_npc_5_e, clips_npc_e);
        b_npc_5_m = handle_events(b_npc_5_m, clips_npc_m);
        b_npc_5_h = handle_events(b_npc_5_h, clips_npc_h);
        b_npc_5.clip = &clips_npc[3];
    }

    if ( b_npc_5_e.pressed == 1 && b_npc_5_m.pressed == 0 && b_npc_5_h.pressed == 0 )
    {
        b_npc_5.pressed = 0;
        b_npc_5_m = handle_events(b_npc_5_m, clips_npc_m);
        b_npc_5_h = handle_events(b_npc_5_h, clips_npc_h);
        b_npc_5 = handle_events( b_npc_5, clips_npc );
        if(b_npc_5_m.pressed == 1)
        {
            b_npc_5_e.pressed = 0;
            b_npc_5_h.pressed = 0;
        }
        if(b_npc_5_h.pressed == 1)
        {
            b_npc_5_m.pressed = 0;
            b_npc_5_e.pressed = 0;
        }
    }

    if ( b_npc_5_m.pressed == 1 && b_npc_5_e.pressed == 0 && b_npc_5_h.pressed == 0 )
    {
        b_npc_5.pressed = 0;
        b_npc_5_e = handle_events(b_npc_5_e, clips_npc_e);
        b_npc_5_h = handle_events(b_npc_5_h, clips_npc_h);
        b_npc_5 = handle_events( b_npc_5, clips_npc );
        if(b_npc_5_e.pressed == 1)
        {
            b_npc_5_m.pressed = 0;
            b_npc_5_h.pressed = 0;
        }
        if(b_npc_5_h.pressed == 1)
        {
            b_npc_5_e.pressed = 0;
            b_npc_5_m.pressed = 0;
        }
    }

    if ( b_npc_5_h.pressed == 1 && b_npc_5_e.pressed == 0 && b_npc_5_m.pressed == 0 )
    {
        b_npc_5.pressed = 0;
        b_npc_5_m = handle_events(b_npc_5_m, clips_npc_m);
        b_npc_5_e = handle_events(b_npc_5_e, clips_npc_e);
        b_npc_5 = handle_events( b_npc_5, clips_npc );
        if(b_npc_5_m.pressed == 1)
        {
            b_npc_5_e.pressed = 0;
            b_npc_5_h.pressed = 0;
        }
        if(b_npc_5_e.pressed == 1)
        {
            b_npc_5_m.pressed = 0;
            b_npc_5_h.pressed = 0;
        }
    }

    if ( b_npc_5.pressed ==1 )
    {
        b_npc_5_e.pressed = 0;
        b_npc_5_m.pressed = 0;
        b_npc_5_h.pressed = 0;
    }

//6
    if ( b_npc_6_e.pressed == 0 && b_npc_6_m.pressed == 0 && b_npc_6_h.pressed == 0 )
    {
        b_npc_6_e = handle_events(b_npc_6_e, clips_npc_e);
        b_npc_6_m = handle_events(b_npc_6_m, clips_npc_m);
        b_npc_6_h = handle_events(b_npc_6_h, clips_npc_h);
        b_npc_6.clip = &clips_npc[3];
    }

    if ( b_npc_6_e.pressed == 1 && b_npc_6_m.pressed == 0 && b_npc_6_h.pressed == 0 )
    {
        b_npc_6.pressed = 0;
        b_npc_6_m = handle_events(b_npc_6_m, clips_npc_m);
        b_npc_6_h = handle_events(b_npc_6_h, clips_npc_h);
        b_npc_6 = handle_events( b_npc_6, clips_npc );
        if(b_npc_6_m.pressed == 1)
        {
            b_npc_6_e.pressed = 0;
            b_npc_6_h.pressed = 0;
        }
        if(b_npc_6_h.pressed == 1)
        {
            b_npc_6_m.pressed = 0;
            b_npc_6_e.pressed = 0;
        }
    }

    if ( b_npc_6_m.pressed == 1 && b_npc_6_e.pressed == 0 && b_npc_6_h.pressed == 0 )
    {
        b_npc_6.pressed = 0;
        b_npc_6_e = handle_events(b_npc_6_e, clips_npc_e);
        b_npc_6_h = handle_events(b_npc_6_h, clips_npc_h);
        b_npc_6 = handle_events( b_npc_6, clips_npc );
        if(b_npc_6_e.pressed == 1)
        {
            b_npc_6_m.pressed = 0;
            b_npc_6_h.pressed = 0;
        }
        if(b_npc_6_h.pressed == 1)
        {
            b_npc_6_e.pressed = 0;
            b_npc_6_m.pressed = 0;
        }
    }

    if ( b_npc_6_h.pressed == 1 && b_npc_6_e.pressed == 0 && b_npc_6_m.pressed == 0 )
    {
        b_npc_6.pressed = 0;
        b_npc_6_m = handle_events(b_npc_6_m, clips_npc_m);
        b_npc_6_e = handle_events(b_npc_6_e, clips_npc_e);
        b_npc_6 = handle_events( b_npc_6, clips_npc );
        if(b_npc_6_m.pressed == 1)
        {
            b_npc_6_e.pressed = 0;
            b_npc_6_h.pressed = 0;
        }
        if(b_npc_6_e.pressed == 1)
        {
            b_npc_6_m.pressed = 0;
            b_npc_6_h.pressed = 0;
        }
    }

    if ( b_npc_6.pressed ==1 )
    {
        b_npc_6_e.pressed = 0;
        b_npc_6_m.pressed = 0;
        b_npc_6_h.pressed = 0;
    }

//7
    if ( b_npc_7_e.pressed == 0 && b_npc_7_m.pressed == 0 && b_npc_7_h.pressed == 0 )
    {
        b_npc_7_e = handle_events(b_npc_7_e, clips_npc_e);
        b_npc_7_m = handle_events(b_npc_7_m, clips_npc_m);
        b_npc_7_h = handle_events(b_npc_7_h, clips_npc_h);
        b_npc_7.clip = &clips_npc[3];
    }

    if ( b_npc_7_e.pressed == 1 && b_npc_7_m.pressed == 0 && b_npc_7_h.pressed == 0 )
    {
        b_npc_7.pressed = 0;
        b_npc_7_m = handle_events(b_npc_7_m, clips_npc_m);
        b_npc_7_h = handle_events(b_npc_7_h, clips_npc_h);
        b_npc_7 = handle_events( b_npc_7, clips_npc );
        if(b_npc_7_m.pressed == 1)
        {
            b_npc_7_e.pressed = 0;
            b_npc_7_h.pressed = 0;
        }
        if(b_npc_7_h.pressed == 1)
        {
            b_npc_7_m.pressed = 0;
            b_npc_7_e.pressed = 0;
        }
    }

    if ( b_npc_7_m.pressed == 1 && b_npc_7_e.pressed == 0 && b_npc_7_h.pressed == 0 )
    {
        b_npc_7.pressed = 0;
        b_npc_7_e = handle_events(b_npc_7_e, clips_npc_e);
        b_npc_7_h = handle_events(b_npc_7_h, clips_npc_h);
        b_npc_7 = handle_events( b_npc_7, clips_npc );
        if(b_npc_7_e.pressed == 1)
        {
            b_npc_7_m.pressed = 0;
            b_npc_7_h.pressed = 0;
        }
        if(b_npc_7_h.pressed == 1)
        {
            b_npc_7_e.pressed = 0;
            b_npc_7_m.pressed = 0;
        }
    }

    if ( b_npc_7_h.pressed == 1 && b_npc_7_e.pressed == 0 && b_npc_7_m.pressed == 0 )
    {
        b_npc_7.pressed = 0;
        b_npc_7_m = handle_events(b_npc_7_m, clips_npc_m);
        b_npc_7_e = handle_events(b_npc_7_e, clips_npc_e);
        b_npc_7 = handle_events( b_npc_7, clips_npc );
        if(b_npc_7_m.pressed == 1)
        {
            b_npc_7_e.pressed = 0;
            b_npc_7_h.pressed = 0;
        }
        if(b_npc_7_e.pressed == 1)
        {
            b_npc_7_m.pressed = 0;
            b_npc_7_h.pressed = 0;
        }
    }

    if ( b_npc_7.pressed ==1 )
    {
        b_npc_7_e.pressed = 0;
        b_npc_7_m.pressed = 0;
        b_npc_7_h.pressed = 0;
    }

//8
    if ( b_npc_8_e.pressed == 0 && b_npc_8_m.pressed == 0 && b_npc_8_h.pressed == 0 )
    {
        b_npc_8_e = handle_events(b_npc_8_e, clips_npc_e);
        b_npc_8_m = handle_events(b_npc_8_m, clips_npc_m);
        b_npc_8_h = handle_events(b_npc_8_h, clips_npc_h);
        b_npc_8.clip = &clips_npc[3];
    }

    if ( b_npc_8_e.pressed == 1 && b_npc_8_m.pressed == 0 && b_npc_8_h.pressed == 0 )
    {
        b_npc_8.pressed = 0;
        b_npc_8_m = handle_events(b_npc_8_m, clips_npc_m);
        b_npc_8_h = handle_events(b_npc_8_h, clips_npc_h);
        b_npc_8 = handle_events( b_npc_8, clips_npc );
        if(b_npc_8_m.pressed == 1)
        {
            b_npc_8_e.pressed = 0;
            b_npc_8_h.pressed = 0;
        }
        if(b_npc_8_h.pressed == 1)
        {
            b_npc_8_m.pressed = 0;
            b_npc_8_e.pressed = 0;
        }
    }

    if ( b_npc_8_m.pressed == 1 && b_npc_8_e.pressed == 0 && b_npc_8_h.pressed == 0 )
    {
        b_npc_8.pressed = 0;
        b_npc_8_e = handle_events(b_npc_8_e, clips_npc_e);
        b_npc_8_h = handle_events(b_npc_8_h, clips_npc_h);
        b_npc_8 = handle_events( b_npc_8, clips_npc );
        if(b_npc_8_e.pressed == 1)
        {
            b_npc_8_m.pressed = 0;
            b_npc_8_h.pressed = 0;
        }
        if(b_npc_8_h.pressed == 1)
        {
            b_npc_8_e.pressed = 0;
            b_npc_8_m.pressed = 0;
        }
    }

    if ( b_npc_8_h.pressed == 1 && b_npc_8_e.pressed == 0 && b_npc_8_m.pressed == 0 )
    {
        b_npc_8.pressed = 0;
        b_npc_8_m = handle_events(b_npc_8_m, clips_npc_m);
        b_npc_8_e = handle_events(b_npc_8_e, clips_npc_e);
        b_npc_8 = handle_events( b_npc_8, clips_npc );
        if(b_npc_8_m.pressed == 1)
        {
            b_npc_8_e.pressed = 0;
            b_npc_8_h.pressed = 0;
        }
        if(b_npc_8_e.pressed == 1)
        {
            b_npc_8_m.pressed = 0;
            b_npc_8_h.pressed = 0;
        }
    }

    if ( b_npc_8.pressed ==1 )
    {
        b_npc_8_e.pressed = 0;
        b_npc_8_m.pressed = 0;
        b_npc_8_h.pressed = 0;
    }


    show_button(b_npc_1_e, difficulty);
    show_button(b_npc_2_e, difficulty);
    show_button(b_npc_3_e, difficulty);
    show_button(b_npc_4_e, difficulty);
    show_button(b_npc_5_e, difficulty);
    show_button(b_npc_6_e, difficulty);
    show_button(b_npc_7_e, difficulty);
    show_button(b_npc_8_e, difficulty);

    show_button(b_npc_1_m, difficulty);
    show_button(b_npc_2_m, difficulty);
    show_button(b_npc_3_m, difficulty);
    show_button(b_npc_4_m, difficulty);
    show_button(b_npc_5_m, difficulty);
    show_button(b_npc_6_m, difficulty);
    show_button(b_npc_7_m, difficulty);
    show_button(b_npc_8_m, difficulty);

    show_button(b_npc_1_h, difficulty);
    show_button(b_npc_2_h, difficulty);
    show_button(b_npc_3_h, difficulty);
    show_button(b_npc_4_h, difficulty);
    show_button(b_npc_5_h, difficulty);
    show_button(b_npc_6_h, difficulty);
    show_button(b_npc_7_h, difficulty);
    show_button(b_npc_8_h, difficulty);

    show_button(b_npc_1, b_npc_surface);
    show_button(b_npc_2, b_npc_surface);
    show_button(b_npc_3, b_npc_surface);
    show_button(b_npc_4, b_npc_surface);
    show_button(b_npc_5, b_npc_surface);
    show_button(b_npc_6, b_npc_surface);
    show_button(b_npc_7, b_npc_surface);
    show_button(b_npc_8, b_npc_surface);
}

void menu_game_settings_init()
{
    bg_menu_game_settings = N_load_img("pic/bg/game settings.png");
    b_start_surface = N_load_img("pic/button/start.png");
    portrait_player = N_load_img("pic/portrait/portrait.jpg");
    b_npc_surface = N_load_img("pic/portrait/npc.png");
    difficulty = N_load_img("pic/button/difficulty.jpg");

    playername = message(player.id, font_l);

    set_button_b_start();
    set_clips_start();
    set_button_b_back_menu_game_settings();

    set_button_for_all_npc();
    set_button_for_all_npc_portrait();
    set_clips_npc_portrait();

    switch_menu = 9;
}

/** compter nomber de joueurs de chaque difficulter, pas vraiment utiliser tous ses fonctionnements, juste pour tester */
void menu_game_settings_count_difficulty ()
{
    easy = 0;
    normal = 0;
    hard = 0;

    if ( b_npc_1_e.pressed == 1 )
    {
        easy++;
        com[1].diff = 1;
    }

    if ( b_npc_2_e.pressed == 1 )
    {
        easy++;
        com[2].diff = 1;
    }
    if ( b_npc_3_e.pressed == 1 )
    {
        easy++;
        com[3].diff = 1;
    }
    if ( b_npc_4_e.pressed == 1 )
    {
        easy++;
        com[4].diff = 1;
    }
    if ( b_npc_5_e.pressed == 1 )
    {
        easy++;
        com[5].diff = 1;
    }
    if ( b_npc_6_e.pressed == 1 )
    {
        easy++;
        com[6].diff = 1;
    }
    if ( b_npc_7_e.pressed == 1 )
    {
        easy++;
        com[7].diff = 1;
    }
    if ( b_npc_8_e.pressed == 1 )
    {
        easy++;
        com[0].diff = 1;
    }

    if ( b_npc_1_m.pressed == 1 )
    {
        normal++;
        com[1].diff = 2;
    }
    if ( b_npc_2_m.pressed == 1 )
    {
        normal++;
        com[2].diff = 2;
    }
    if ( b_npc_3_m.pressed == 1 )
    {
        normal++;
        com[3].diff = 2;
    }
    if ( b_npc_4_m.pressed == 1 )
    {
        normal++;
        com[4].diff = 2;
    }
    if ( b_npc_5_m.pressed == 1 )
    {
        normal++;
        com[5].diff = 2;
    }
    if ( b_npc_6_m.pressed == 1 )
    {
        normal++;
        com[6].diff = 2;
    }
    if ( b_npc_7_m.pressed == 1 )
    {
        normal++;
        com[7].diff = 2;
    }
    if ( b_npc_8_m.pressed == 1 )
    {
        normal++;
        com[0].diff = 2;
    }

    if ( b_npc_1_h.pressed == 1 )
    {
        hard++;
        com[1].diff = 3;
    }
    if ( b_npc_2_h.pressed == 1 )
    {
        hard++;
        com[2].diff = 3;
    }
    if ( b_npc_3_h.pressed == 1 )
    {
        hard++;
        com[3].diff = 3;
    }
    if ( b_npc_4_h.pressed == 1 )
    {
        hard++;
        com[4].diff = 3;
    }
    if ( b_npc_5_h.pressed == 1 )
    {
        hard++;
        com[5].diff = 3;
    }
    if ( b_npc_6_h.pressed == 1 )
    {
        hard++;
        com[6].diff = 3;
    }
    if ( b_npc_7_h.pressed == 1 )
    {
        hard++;
        com[7].diff = 3;
    }
    if ( b_npc_8_h.pressed == 1 )
    {
        hard++;
        com[0].diff = 3;
    }

    if( b_npc_1.pressed == 1 )
    {
        com[1].diff = 0;
    }

    if( b_npc_2.pressed == 1 )
    {
        com[2].diff = 0;
    }

    if( b_npc_3.pressed == 1 )
    {
        com[3].diff = 0;
    }

    if( b_npc_4.pressed == 1 )
    {
        com[4].diff = 0;
    }

    if( b_npc_5.pressed == 1 )
    {
        com[5].diff = 0;
    }

    if( b_npc_6.pressed == 1 )
    {
        com[6].diff = 0;
    }

    if( b_npc_7.pressed == 1 )
    {
        com[7].diff = 0;
    }

    if( b_npc_8.pressed == 1 )
    {
        com[0].diff = 0;
    }


}

void menu_game_settings ()
{
    N_apply_surface( 0, 0, bg_menu_game_settings, screen, NULL );
    N_apply_surface( 262, 50, portrait_list[player.portrait], screen, NULL );
    //printf("player.portrait = %d\n",player.portrait);

    b_back.pressed = 0;
    b_start.pressed = 0;

    b_start = handle_events(b_start, clips_start);
    show_button(b_start, b_start_surface);

    b_back = handle_events(b_back, clips_start);
    show_button(b_back, b_back_surface);

    show_button_for_all_npc();//portrait included

    N_apply_surface(400, 70, playername, screen, NULL);

    menu_game_settings_count_difficulty();
    //printf("e%d\nn%d\nh%d\n", easy, normal, hard);

    if( b_back.pressed == 1)
        switch_menu = 0;

    if( b_start.pressed == 1 )
    {
        if( easy+normal+hard >0 )
            switch_menu = 10;
        else
        {
            SDL_Surface *msg = message("Un joueur d'ordinateur minimum", font_l);
            N_apply_surface(10, 400, msg, screen, NULL);
            SDL_Flip(screen);
            SDL_Delay(2000);
        }
    }
}


/** partie ecran de parametre */
//parameter
void set_clips_sound_on( )
{
    clips_sound_on[ CLIP_MOUSEOVER ].x = 0;
    clips_sound_on[ CLIP_MOUSEOVER ].y = 100;
    clips_sound_on[ CLIP_MOUSEOVER ].w = 100;
    clips_sound_on[ CLIP_MOUSEOVER ].h = 100;

    clips_sound_on[ CLIP_MOUSEOUT ].x = 0;
    clips_sound_on[ CLIP_MOUSEOUT ].y = 300;
    clips_sound_on[ CLIP_MOUSEOUT ].w = 100;
    clips_sound_on[ CLIP_MOUSEOUT ].h = 100;

    clips_sound_on[ CLIP_MOUSEDOWN ].x = 0;
    clips_sound_on[ CLIP_MOUSEDOWN ].y = 0;
    clips_sound_on[ CLIP_MOUSEDOWN ].w = 100;
    clips_sound_on[ CLIP_MOUSEDOWN ].h = 100;

    clips_sound_on[ CLIP_MOUSEUP ].x = 0;
    clips_sound_on[ CLIP_MOUSEUP ].y = 0;
    clips_sound_on[ CLIP_MOUSEUP ].w = 100;
    clips_sound_on[ CLIP_MOUSEUP ].h = 100;
}

void set_clips_sound_off( )
{
    clips_sound_off[ CLIP_MOUSEOVER ].x = 0;
    clips_sound_off[ CLIP_MOUSEOVER ].y = 200;
    clips_sound_off[ CLIP_MOUSEOVER ].w = 100;
    clips_sound_off[ CLIP_MOUSEOVER ].h = 100;

    clips_sound_off[ CLIP_MOUSEOUT ].x = 0;
    clips_sound_off[ CLIP_MOUSEOUT ].y = 0;
    clips_sound_off[ CLIP_MOUSEOUT ].w = 100;
    clips_sound_off[ CLIP_MOUSEOUT ].h = 100;

    clips_sound_off[ CLIP_MOUSEDOWN ].x = 0;
    clips_sound_off[ CLIP_MOUSEDOWN ].y = 300;
    clips_sound_off[ CLIP_MOUSEDOWN ].w = 100;
    clips_sound_off[ CLIP_MOUSEDOWN ].h = 100;

    clips_sound_off[ CLIP_MOUSEUP ].x = 0;
    clips_sound_off[ CLIP_MOUSEUP ].y = 300;
    clips_sound_off[ CLIP_MOUSEUP ].w = 100;
    clips_sound_off[ CLIP_MOUSEUP ].h = 100;
}

void set_clips_effect_on( )
{
    clips_effect_on[ CLIP_MOUSEOVER ].x = 100;
    clips_effect_on[ CLIP_MOUSEOVER ].y = 100;
    clips_effect_on[ CLIP_MOUSEOVER ].w = 100;
    clips_effect_on[ CLIP_MOUSEOVER ].h = 100;

    clips_effect_on[ CLIP_MOUSEOUT ].x = 100;
    clips_effect_on[ CLIP_MOUSEOUT ].y = 300;
    clips_effect_on[ CLIP_MOUSEOUT ].w = 100;
    clips_effect_on[ CLIP_MOUSEOUT ].h = 100;

    clips_effect_on[ CLIP_MOUSEDOWN ].x = 100;
    clips_effect_on[ CLIP_MOUSEDOWN ].y = 0;
    clips_effect_on[ CLIP_MOUSEDOWN ].w = 100;
    clips_effect_on[ CLIP_MOUSEDOWN ].h = 100;

    clips_effect_on[ CLIP_MOUSEUP ].x = 100;
    clips_effect_on[ CLIP_MOUSEUP ].y = 0;
    clips_effect_on[ CLIP_MOUSEUP ].w = 100;
    clips_effect_on[ CLIP_MOUSEUP ].h = 100;
}

void set_clips_effect_off( )
{
    clips_effect_off[ CLIP_MOUSEOVER ].x = 100;
    clips_effect_off[ CLIP_MOUSEOVER ].y = 200;
    clips_effect_off[ CLIP_MOUSEOVER ].w = 100;
    clips_effect_off[ CLIP_MOUSEOVER ].h = 100;

    clips_effect_off[ CLIP_MOUSEOUT ].x = 100;
    clips_effect_off[ CLIP_MOUSEOUT ].y = 0;
    clips_effect_off[ CLIP_MOUSEOUT ].w = 100;
    clips_effect_off[ CLIP_MOUSEOUT ].h = 100;

    clips_effect_off[ CLIP_MOUSEDOWN ].x = 100;
    clips_effect_off[ CLIP_MOUSEDOWN ].y = 300;
    clips_effect_off[ CLIP_MOUSEDOWN ].w = 100;
    clips_effect_off[ CLIP_MOUSEDOWN ].h = 100;

    clips_effect_off[ CLIP_MOUSEUP ].x = 100;
    clips_effect_off[ CLIP_MOUSEUP ].y = 300;
    clips_effect_off[ CLIP_MOUSEUP ].w = 100;
    clips_effect_off[ CLIP_MOUSEUP ].h = 100;
}

void set_button_b_sound_on(  )
{
    b_sound_on.box.x = 400;
    b_sound_on.box.y = 400;
    b_sound_on.box.w = 100;
    b_sound_on.box.h = 100;
}

void set_button_b_sound_off(  )
{
    b_sound_off.box.x = 300;
    b_sound_off.box.y = 400;
    b_sound_off.box.w = 100;
    b_sound_off.box.h = 100;
}

void set_button_b_effect_on(  )
{
    b_effect_on.box.x = 724;
    b_effect_on.box.y = 400;
    b_effect_on.box.w = 100;
    b_effect_on.box.h = 100;
}

void set_button_b_effect_off(  )
{
    b_effect_off.box.x = 624;
    b_effect_off.box.y = 400;
    b_effect_off.box.w = 100;
    b_effect_off.box.h = 100;
}

void menu_parametre_init()
{
    b_sound_effect_surface = N_load_img("pic/button/sound_effect.png");
    set_clips_sound_off( );
    set_clips_effect_off( );
    set_clips_sound_on( );
    set_clips_effect_on( );
    set_button_b_sound_off(  );
    set_button_b_effect_off(  );
    set_button_b_sound_on(  );
    set_button_b_effect_on(  );

    msg_effect = message("effect", font_l);
    msg_sound = message("sound", font_l);
    set_button_b_back();
}

void show_sound_effect_button()
{
    //in init
    //b_sound_on.pressed = 1
    //b_effect_on.pressed = 1
    if( b_sound_on.pressed == 1 )
    {
        b_sound_off.pressed = 0;
        b_sound_off = handle_events( b_sound_off, clips_sound_off );
        show_button( b_sound_off, b_sound_effect_surface );
        if( b_sound_off.pressed == 1 )
            b_sound_on.pressed = 0;

        //printf("\n\non = %d\noff = %d\n", b_sound_on.pressed, b_sound_off.pressed);
    }
    if( b_sound_off.pressed == 1 )
    {
        b_sound_on.pressed = 0;
        b_sound_on = handle_events( b_sound_on, clips_sound_on );
        show_button( b_sound_on, b_sound_effect_surface );
        if( b_sound_on.pressed == 1 )
            b_sound_off.pressed = 0;
    }

    if( b_effect_on.pressed == 1 )
    {
        b_effect_off.pressed = 0;
        b_effect_off = handle_events( b_effect_off, clips_effect_off );
        show_button( b_effect_off, b_sound_effect_surface );
        if( b_effect_off.pressed == 1 )
            b_effect_on.pressed = 0;
    }
    if( b_effect_off.pressed == 1 )
    {
        b_effect_on.pressed = 0;
        b_effect_on = handle_events( b_effect_on, clips_effect_on );
        show_button( b_effect_on, b_sound_effect_surface );
        if( b_effect_on.pressed == 1 )
            b_effect_off.pressed = 0;
    }


}

void menu_parametre()
{
    b_back.pressed = 0;
    N_apply_surface(0, 0, bg_menu_parametre, screen, NULL);
    b_back = handle_events(b_back, clips_login);
    show_button(b_back, b_back_surface);

    N_apply_surface( 305, 300, msg_sound, screen, NULL );
    N_apply_surface( 619, 300, msg_effect, screen, NULL );

    show_sound_effect_button();
    //printf("arfer\non = %d\noff = %d\n", b_sound_on.pressed, b_sound_off.pressed);

    if( b_back.pressed == 1 )
        switch_menu = 0;

}
