/**
 * Game LOBO 77
 * Realiser par HE Junyang et CHEN Lichong
 * 2015/04/14
 * Version : 3.0 ( sans net )
 * Systeme : Windows
 */

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "header.h"
#include <time.h>

/** Definition de screen  */
const int WIDTH=1024;
const int HEIGHT=768;
const int BPP=32;
const char CAPTION[ ]="LOBO 77 !!!";
/** definition de FPS */
const int FRAMES_PER_SECOND = 200;


/** definition des evenement de souris */
const int CLIP_MOUSEOVER = 0;
const int CLIP_MOUSEOUT = 1;
const int CLIP_MOUSEDOWN = 2;
const int CLIP_MOUSEUP = 3;

/** delaration des variable pour le switch */
int switch_welcome_page = 0;
int switch_main = 0;
int switch_menu = 0;

/** une solution pour que l'on puisse entre dans le boucle principal meme s'il n'y a pas de evenement */
int no_event_time = 0;
int time_start=  0;
int time_count = 0;
int no_event_time_start = 0;

/** declaration de liste de joueur et le joueur */
struct Player list[123];
struct Player player;

/** variable de gestion d'anime */
int anime = 0;




/** declaration d'evenement */
SDL_Event event;
SDL_Event event_old;

/** declaration des font TTF */
TTF_Font *font_l = NULL;
TTF_Font *font_m = NULL;
TTF_Font *font_s = NULL;

/** declaration de BGM et Effect */
Mix_Music *bgm1 = NULL;
Mix_Chunk *effect_over = NULL;
Mix_Chunk *effect_down = NULL;
Mix_Chunk *effect_hey = NULL;


/** fct main */
int main(int argc, char** args)
{
    /** centrer l'ecran */
    putenv("SDL_VIDEO_CENTERED=1");

    /** sramdom dans linux, srand dans Windows */
    srand((unsigned)time(NULL));

    /** quit, 0 pour continuer, 1 pour Xed */
    int quit = 0;

    /** pour le son, gerer par buttons dans l'ecran parametre */
    b_sound_on.pressed = 1;
    b_effect_on.pressed = 1;

    /** init SDL */
    if(init(WIDTH,HEIGHT,BPP,CAPTION)==1)
        return 1;

    /** charger le fic */
    charge_file(list);
    /** init et charger les portraits */
    init_portrait_list ();
    init_portrait_load_img();

    /** si non Xed */
    while (quit == 0)
    {

        /** compter le temps depuis le dernier evenement, c-a-d le derniere fois entrer dans le boucle while(SDL_PollEvent( &event ) || no_event_time > 10 ) */
        no_event_time = SDL_GetTicks() - no_event_time_start;
        //printf("no_event_time = %d\n ", no_event_time);

        /** commercer a compter le temps utiliser par ce frame */
        time_start = SDL_GetTicks();

        /** boucle principale du jeu, tous sont dans ce boucle, une seconde entre dans ce boucle FRAMES_PER_SECOND fois */
        while(SDL_PollEvent( &event ) || no_event_time > 10 )
        {
            /** Si appuyer a X */
            if(event.type == SDL_QUIT)
            {
                switch_welcome_page = 999;
                switch_menu = 999;
                quit = 1;
            }

            /** switch principale */
            switch(switch_main)
            {

            /** ecran d'acceuil */
            case 0:

                /** switch, ecran d'acceuil, ecran d'identifier, et ecran de s'incrire */
                switch (switch_welcome_page)
                {
                    //int i;
                    //init
                case 0:
                    welcome_page_init();
                    N_apply_surface(0,0,bg_acceuil,screen,NULL);
                    switch_welcome_page = 1;
                    break;

                    //welcome page
                case 1:
                    switch_welcome_page = welcome_page_case_1(switch_welcome_page);
                    break;

                    //init login
                case 2:
                    switch_welcome_page = welcome_page_case_2(switch_welcome_page);
                    break;

                    //login_enter_id
                case 3:
                    switch_welcome_page = welcome_page_case_3(switch_welcome_page);
                    break;

                    //login_enter_pw
                case 4:
                    switch_welcome_page = welcome_page_case_4(switch_welcome_page);
                    break;

                    //login test
                case 5:
                    player = login(list);
                    switch_welcome_page = welcome_page_case_5(switch_welcome_page, player);
                    break;

                    //login successful, clean up, jump to game menu
                case 6:
                    switch_welcome_page = welcome_page_case_6(switch_welcome_page);
                    switch_main = 1;
                    break;

                    //init register
                case 7:
                    register_page_init();
                    stringinput_init();
                    init_buttons_left_right ();
                    switch_welcome_page = 8;
                    break;

                    //register enter id
                case 8:
                    switch_welcome_page = welcome_page_case_8(switch_welcome_page);
                    break;

                    //register enter pw
                case 9:
                    switch_welcome_page = welcome_page_case_9(switch_welcome_page);
                    break;

                    //register enter pwc
                case 10:
                    switch_welcome_page = welcome_page_case_10(switch_welcome_page);
                    break;

                    //check register
                case 11:
                    if(registation(list) == 1)
                        switch_welcome_page = 12; //register successful and jump to choise portrait
                    else
                        switch_welcome_page = 7;//register failed, jump back to register page
                    break;

                    //register choise portrait
                case 12:
                    switch_welcome_page = welcome_page_case_12(switch_welcome_page);
                    break;

                    //clean up
                case 999:
                    clean_up_welcome_page_Xed();
                    printf("clean_up_welcome_page_Xed\n");
                    break;
                }//welcome page switch

                break;

            /** switch, ecran de menu, de parametre, de regle, de statistique, de parametre du jeu, et de jeu */
                //game menu init
            case 1:
                switch(switch_menu)
                {
                case 0:
                    bg_menu = N_load_img("pic/bg/menu.png");
                    N_apply_surface(0,0, bg_menu, screen, NULL);
                    init_menu_buttons ();
                    switch_menu = 1;
                    break;

                case 1:
                    menu_show_buttons ();
                    menu_button_pressed ();
                    break;

                    //statistique_init
                case 2:
                    menu_statistique_init ();
                    break;

                    //statistique
                case 6:
                    menu_statistique();
                    break;

                    //regle init
                case 3:
                    menu_regle_init();
                    init_buttons_left_right ();
                    switch_menu = 4;
                    break;

                    //regle
                case 4 :
                    menu_regle();
                    break;

                    //parametre_init
                case 5:
                    menu_parametre_init();
                    switch_menu = 7;
                    break;

                    //parametre
                case 7:
                    menu_parametre();
                    break;

                    //game settings init
                case 8:
                    menu_game_settings_init();
                    break;

                    //game settings
                case 9:
                    menu_game_settings ();
                    break;

                    //game start
                case 10:
                    game_start_init ();
                    switch_menu = 11;
                    break;

                case 11:
                    anime = 1;
                    break;

                case 12:
                    game();
                    //SDL_Flip(screen);
                    break;



                case 999:
                    clean_up_menu_Xed();
                    printf("clean_up_menu_Xed\n");
                    break;

                }

                //time = 0;
                break;
            }//main swtich

            /** gerer le BGM */
            if( b_sound_on.pressed == 1 )
            {
                if( Mix_PlayingMusic() == 0 )
                {
                    if( Mix_PlayMusic( bgm1, -1 ) == -1 )
                    {
                        return 1;
                    }
                }
                if( Mix_PausedMusic() == 1 )
                {
                    Mix_ResumeMusic();
                }
            }
            if( b_sound_on.pressed == 0 )
                Mix_PauseMusic();

            /** cet evenement est fini */
            no_event_time = 0;
            /** le temps a fin de cet evenement */
            no_event_time_start = SDL_GetTicks();

            /** enregister cet evenement, une solution d'un probleme */
            event_old = event;
        }//while SDL_PollEventtime_count = SDL_GetTicks() - time_start;

        /** afficher un anime */
        //play anime, frame constant
        if(anime == 1)
        {
            anime_give_card ();
        }
        if(anime == 2)
        {
            game_new_turn_flash();
        }

        /** compter le temps utiliser par cet evenement, puis delay pour stabiliser le FPS */
        if( time_count < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - time_count );
        }
        SDL_Flip( screen );

    }//while quit ==0

    /** clean up */
    Mix_FreeMusic( bgm1 );
    Mix_FreeChunk( effect_down );
    Mix_FreeChunk( effect_over );
    Mix_FreeChunk( effect_hey );
    Mix_CloseAudio();
    TTF_CloseFont( font_l );
    TTF_CloseFont( font_m );
    TTF_CloseFont( font_s );
    TTF_Quit();
    atexit(SDL_Quit);
    //SDL_Quit();

    return 0;
}//main()
