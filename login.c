#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "header.h"

struct StringInput stringinput_id;
struct StringInput stringinput_pw;
struct StringInput stringinput_pwc;

/** declaration de surface screen, et quelques background */
SDL_Surface *screen=NULL;
SDL_Surface *bg_acceuil=NULL;
SDL_Surface *bg_login=NULL;
SDL_Surface *bg_register=NULL;
SDL_Surface *bg_menu=NULL;

//declare button
struct Button b_login;
SDL_Rect clips_login[ 4 ];
SDL_Surface *b_login_surface=NULL;

struct Button b_register;
SDL_Rect clips_register[ 4 ];
SDL_Surface *b_register_surface=NULL;

struct Button b_ok;
SDL_Surface *b_ok_surface=NULL;

struct Button b_back;
SDL_Surface *b_back_surface=NULL;

struct Button b_input_id;
SDL_Rect clips_input_id[4];
SDL_Surface *b_input_id_surface=NULL;

struct Button b_input_pw;
SDL_Rect clips_input_pw[4];
SDL_Surface *b_input_pw_surface=NULL;

struct Button b_input_pwc;

SDL_Surface *portrait_list[20] ;

void set_clips_login()
{
    //Clip the sprite sheet
    clips_login[ CLIP_MOUSEOVER ].x = 0;
    clips_login[ CLIP_MOUSEOVER ].y = 0;
    clips_login[ CLIP_MOUSEOVER ].w = 100;
    clips_login[ CLIP_MOUSEOVER ].h = 100;

    clips_login[ CLIP_MOUSEOUT ].x = 0;
    clips_login[ CLIP_MOUSEOUT ].y = 100;
    clips_login[ CLIP_MOUSEOUT ].w = 100;
    clips_login[ CLIP_MOUSEOUT ].h = 100;

    clips_login[ CLIP_MOUSEDOWN ].x = 0;
    clips_login[ CLIP_MOUSEDOWN ].y = 200;
    clips_login[ CLIP_MOUSEDOWN ].w = 100;
    clips_login[ CLIP_MOUSEDOWN ].h = 100;

    clips_login[ CLIP_MOUSEUP ].x = 0;
    clips_login[ CLIP_MOUSEUP ].y = 300;
    clips_login[ CLIP_MOUSEUP ].w = 100;
    clips_login[ CLIP_MOUSEUP ].h = 100;
}

void set_button_b_login()
{
    b_login.box.x=700;
    b_login.box.y=50;
    b_login.box.w=100;
    b_login.box.h=100;
}

void set_button_b_register()
{
    b_register.box.x=700;
    b_register.box.y=250;
    b_register.box.w=100;
    b_register.box.h=100;
}

void set_button_b_ok()
{
    b_ok.box.x=900;
    b_ok.box.y=650;
    b_ok.box.w=100;
    b_ok.box.h=100;
}

void set_button_b_back()
{
    b_back.box.x=30;
    b_back.box.y=650;
    b_back.box.w=100;
    b_back.box.h=100;
}

void init_portrait_list ()
{
    int i;
    for(i=0; i<20; i++)
    {
        portrait_list[i] = NULL;
    }
}

int portrait_number = 8;

/** fct charger tous les protraits */
void init_portrait_load_img()
{
    portrait_list[0] = N_load_img("pic/portrait/8.jpg");
    portrait_list[1] = N_load_img("pic/portrait/1.png");
    portrait_list[2] = N_load_img("pic/portrait/2.png");
    portrait_list[3] = N_load_img("pic/portrait/3.png");
    portrait_list[4] = N_load_img("pic/portrait/4.png");
    portrait_list[5] = N_load_img("pic/portrait/5.png");
    portrait_list[6] = N_load_img("pic/portrait/6.png");
    portrait_list[7] = N_load_img("pic/portrait/7.png");
}

/** clean up */
void free_portrait()
{
    int i;
    for(i=0; i<portrait_number; i++)
    {
        SDL_FreeSurface(portrait_list[i]);
    }
}

/** compter nombre de joueur dans le fic */
int count_player()
{
    int i=0;
    FILE* fp=fopen("player.dat","r");
    if(fp == NULL)
        return i;

    struct Player buffer;

    while(!feof(fp))
    {
        fread(&buffer ,sizeof(struct Player),1,fp);
        i++;
    }
    i--;
    fclose(fp);
    return i;
}

/** charger le fic dans le tableau */
int charge_file (struct Player list[])
{
    FILE* fp;
    int nb=0;
    if( (fp = fopen("player.dat","r")) )
    {
        while(!feof(fp))
        {
            fread(&list[nb],sizeof(struct Player),1,fp);
            nb++;
        }
        printf("player.dat chargé!\n");
        fclose(fp);
        printf("nombre de joueur = %d\n",nb-1);
    }

    else
    {
        printf("player.dat n'existe pas!\nplayer.dat est créé!\n");
        fp=fopen("player.dat","a");
        fclose(fp);
        printf("nombre de joueur = %d\n",nb);
    }


    return nb-1;
}

/** enregistrer le tb ds le fic */
void save_file( )
{
    int i;
    int nb = count_player();
    FILE* fp = fopen("player.dat","w");
    for(i = 0; i < nb ; i++)
    {
        fwrite( &list[ i ], sizeof(struct Player), 1, fp );
    }
    fclose(fp);
}

/** fct principale pour s'inscrire */
int registation(struct Player list[])
{
    char id[20],pw[20],pwc[20];
    int nb=count_player();
    strcpy(id, stringinput_id.str);
    strcpy(pw, stringinput_pw.str);
    strcpy(pwc, stringinput_pwc.str);

    if(strlen(id) != 0)
    {
        if(strlen(pw) == 0)
        {
            printf("Code doit etre non vide!\n");
            N_apply_surface(100, 434, message("Code doit etre non vide!", font_l), screen, NULL);
            SDL_Flip(screen);
            SDL_Delay(1500);
            return 2;
        }
    }
    else
    {
        printf("identifiant doit etre non vide!\n");
        N_apply_surface(200, 334, message("identifiant doit etre", font_l), screen, NULL);
        N_apply_surface(250, 434, message("non vide!", font_l), screen, NULL);
        SDL_Flip(screen);
        SDL_Delay(1500);
        return 2;
    }

    if(strcmp(pw,pwc) == 0)
    {
        int i;

        for(i=0; i<count_player(); i++)
        {
            if(strcmp(id, list[i].id) == 0)
            {
                printf("identifiant deja existe!\n");
                N_apply_surface(120, 434, message("identifiant deja existe!", font_l), screen, NULL);
                SDL_Flip(screen);
                SDL_Delay(1500);
                return 2;
            }
        }

        strcpy(list[nb].id,id);
        strcpy(list[nb].pw,pw);
        list[nb].portrait = 0;

        printf("S'inscrire reussir!\n");
        N_apply_surface(120, 434, message("S'inscrire reussir!", font_l), screen, NULL);
        SDL_Flip(screen);
        SDL_Delay(1500);

        FILE* fp=fopen("player.dat","w");
        for(i=0; i<nb+1; i++)
        {
            fwrite(&list[i],sizeof(struct Player),1,fp);
            //printf("i = %d\n",i);
        }
        fclose(fp);
        charge_file(list);
        return 1;
    }
    else
    {
        printf("Deux code sont differentes\n");
        N_apply_surface(80, 434, message("Deux code sont differentes", font_l), screen, NULL);
        SDL_Flip(screen);
        SDL_Delay(1500);
        return 2;
    }

}

/** fct principale pour s'identifier */
//reset SDL_Delay for login successful afrer finish this program
struct Player login(struct Player list[])
{
    struct Stat no_stat= {0,0,0};
    struct Player noplayer= {"00000fffff","00000fffff",no_stat};

    char id[20],pw[20];
    int i=0;
    int nb = count_player();
    int counter = 0;

    strcpy(id, stringinput_id.str);
    strcpy(pw, stringinput_pw.str);

    if(count_player() == 0)
    {
        printf("Aucun compte de joueur existe, inscrisez vous d'abord!\n");
        N_apply_surface(120, 534, message("Aucun compte existe,", font_l), screen, NULL);
        N_apply_surface(100, 634, message("inscrisez vous d'abord!", font_l), screen, NULL);
        SDL_Flip(screen);
        SDL_Delay(2000);
        return noplayer;
    }
    else
    {
        for(i=0; i<nb; i++)
        {
            //printf("i = %d\n", i);
            if(strcmp(id,list[i].id)==0)
            {
                if(strcmp(pw,list[i].pw)==0)
                {
                    printf("Bienvenue %s\n",list[i].id);
                    N_apply_surface(400, 434, message("Bienvenue", font_l), screen, NULL);
                    N_apply_surface(400, 534, message(id, font_l), screen, NULL);
                    SDL_Flip(screen);

                    //player.time_of_connection++
                    list[i].stat.login_times++;
                    save_file( );

                    SDL_Delay(1000);
                    //SDL_Delay(2500);

                    return list[i];
                }
                else
                {
                    printf("code incorrect!\n");
                    N_apply_surface(300, 534, message("code incorrect!", font_l), screen, NULL);
                    SDL_Flip(screen);
                    SDL_Delay(2000);
                    return noplayer;
                }
            }
            else
            {
                counter++;
                if(counter == nb)
                {
                    printf("indentifiant incorrect!\n");
                    N_apply_surface(100, 534, message("indentifiant incorrect!", font_l), screen, NULL);
                    SDL_Flip(screen);
                    SDL_Delay(2000);
                    return noplayer;
                }

            }
        }
    }
    return noplayer;
}

void set_button_input_id()
{
    b_input_id.box.x=262;
    b_input_id.box.y=134;
    b_input_id.box.h=100;
    b_input_id.box.w=500;
    //b_input_id.clip = &clips_input_id[ CLIP_MOUSEUP ];
}

void set_button_input_pw()
{
    b_input_pw.box.x=262;
    b_input_pw.box.y=334;
    b_input_pw.box.h=100;
    b_input_pw.box.w=500;
}

void set_button_input_pwc()
{
    b_input_pwc.box.x=262;
    b_input_pwc.box.y=534;
    b_input_pwc.box.h=100;
    b_input_pwc.box.w=500;
}

void set_clips_input_id()
{
    //Clip the sprite sheet
    clips_input_id[ CLIP_MOUSEOVER ].x = 0;
    clips_input_id[ CLIP_MOUSEOVER ].y = 200;
    clips_input_id[ CLIP_MOUSEOVER ].w = 500;
    clips_input_id[ CLIP_MOUSEOVER ].h = 100;

    clips_input_id[ CLIP_MOUSEOUT ].x = 0;
    clips_input_id[ CLIP_MOUSEOUT ].y = 200;
    clips_input_id[ CLIP_MOUSEOUT ].w = 500;
    clips_input_id[ CLIP_MOUSEOUT ].h = 100;

    clips_input_id[ CLIP_MOUSEDOWN ].x = 0;
    clips_input_id[ CLIP_MOUSEDOWN ].y = 0;
    clips_input_id[ CLIP_MOUSEDOWN ].w = 500;
    clips_input_id[ CLIP_MOUSEDOWN ].h = 100;

    clips_input_id[ CLIP_MOUSEUP ].x = 0;
    clips_input_id[ CLIP_MOUSEUP ].y = 100;
    clips_input_id[ CLIP_MOUSEUP ].w = 500;
    clips_input_id[ CLIP_MOUSEUP ].h = 100;
}

void set_clips_input_pw()
{
    //Clip the sprite sheet
    clips_input_pw[ CLIP_MOUSEOVER ].x = 0;
    clips_input_pw[ CLIP_MOUSEOVER ].y = 200;
    clips_input_pw[ CLIP_MOUSEOVER ].w = 500;
    clips_input_pw[ CLIP_MOUSEOVER ].h = 100;

    clips_input_pw[ CLIP_MOUSEOUT ].x = 0;
    clips_input_pw[ CLIP_MOUSEOUT ].y = 200;
    clips_input_pw[ CLIP_MOUSEOUT ].w = 500;
    clips_input_pw[ CLIP_MOUSEOUT ].h = 100;

    clips_input_pw[ CLIP_MOUSEDOWN ].x = 0;
    clips_input_pw[ CLIP_MOUSEDOWN ].y = 0;
    clips_input_pw[ CLIP_MOUSEDOWN ].w = 500;
    clips_input_pw[ CLIP_MOUSEDOWN ].h = 100;

    clips_input_pw[ CLIP_MOUSEUP ].x = 0;
    clips_input_pw[ CLIP_MOUSEUP ].y = 100;
    clips_input_pw[ CLIP_MOUSEUP ].w = 500;
    clips_input_pw[ CLIP_MOUSEUP ].h = 100;
}

void login_page_init()
{
    bg_login=N_load_img("pic/bg/login.png");
    N_apply_surface(0,0,bg_login,screen,NULL);
    N_apply_surface(100,134,message("id: ", font_l),screen,NULL);
    N_apply_surface(100,334,message("pw: ",font_l),screen,NULL);
    set_button_input_id();
    set_clips_input_id();
    set_button_input_pw();
    set_clips_input_pw();
    b_input_id_surface = N_load_img("pic/button/input.png");
    b_input_pw_surface = N_load_img("pic/button/input.png");;
    b_input_pw.clip = &clips_input_pw[ CLIP_MOUSEOVER ];
    b_input_id.clip = &clips_input_id[ CLIP_MOUSEUP ];
    //N_apply_surface(262, 334, b_input_pw_surface, screen, &clips_input_pw[ CLIP_MOUSEDOWN ]);
    //N_apply_surface(262, 134, b_input_id_surface, screen, &clips_input_id[ CLIP_MOUSEDOWN ]);
}

void register_page_init()
{
    bg_register = N_load_img("pic/bg/register.png");
    N_apply_surface(0, 0, bg_register, screen, NULL);


    N_apply_surface(100,130,message("id: ", font_l),screen,NULL);
    N_apply_surface(100,330,message("pw: ",font_l),screen,NULL);
    N_apply_surface(100,530,message("pwc: ",font_l),screen,NULL);
    set_button_input_id();
    set_clips_input_id();
    set_button_input_pw();
    set_clips_input_pw();
    set_button_input_pwc();
    b_input_id_surface = N_load_img("pic/button/input.png");
    b_input_pw_surface = N_load_img("pic/button/input.png");;

    b_input_pwc.clip = &clips_input_pw[ CLIP_MOUSEOVER ];
    b_input_pw.clip = &clips_input_pw[ CLIP_MOUSEOVER ];
    b_input_id.clip = &clips_input_id[ CLIP_MOUSEUP];
}

void stringinput_init()
{
    int i;
    for(i=0; i<20; i++)
    {
        stringinput_id.str[i]='\0';
        stringinput_pw.str[i]='\0';
        stringinput_pwc.str[i]='\0';
    }

    stringinput_id.text = NULL;
    stringinput_pw.text = NULL;
    stringinput_pwc.text = NULL;

    SDL_EnableUNICODE( SDL_ENABLE );
}

/** fct pour gerer input */
void input_id()
{
    //if ( no_event_time < 150)
    if ( same_event_or_not_for_input() == 0 )
        stringinput_id.text = StringInput_handle_input(stringinput_id.str, stringinput_id.text, font_l);

    StringInput_show(stringinput_id.text, 262, 134);
    StringInput_show(stringinput_pw.text, 262, 354);
    StringInput_show(stringinput_pwc.text, 262, 554);
}

void input_pw()
{
    //if ( no_event_time < 150)
    if ( same_event_or_not_for_input() == 0 )
        stringinput_pw.text = StringInput_handle_input_pw(stringinput_pw.str, stringinput_pw.text, font_l);

    StringInput_show(stringinput_id.text, 262, 134);
    StringInput_show(stringinput_pw.text, 262, 354);
    StringInput_show(stringinput_pwc.text, 262, 554);
}

void input_pwc()
{
    //if ( no_event_time < 150)
    if ( same_event_or_not_for_input() == 0 )
        stringinput_pwc.text = StringInput_handle_input_pw(stringinput_pwc.str, stringinput_pwc.text, font_l);

    StringInput_show(stringinput_id.text, 262, 134);
    StringInput_show(stringinput_pw.text, 262, 354);
    StringInput_show(stringinput_pwc.text, 262, 554);
}


/** tous les cas pour ecran acceuil, ecran identifier et ecran s'inscrire */
/** comentaire dans fct main */
int welcome_page_case_1(int switch_welcome_page)
{
    b_login.pressed = 0;
    b_register.pressed = 0;

    b_login=handle_events(b_login, clips_login);
    b_register=handle_events(b_register, clips_login);

    show_button(b_login, b_login_surface);
    show_button(b_register, b_register_surface);

    if( b_login.pressed == 1)
    {
        switch_welcome_page = 2;
    }

    if( b_register.pressed == 1)
    {
        switch_welcome_page = 7;
    }

    return switch_welcome_page;
}

int welcome_page_case_2(int switch_welcome_page)
{
    login_page_init();
    stringinput_init();
    switch_welcome_page = 3;
    return switch_welcome_page;
}

int welcome_page_case_3(int switch_welcome_page)
{
    entered = 0;

    b_ok.pressed = 0;
    b_ok = handle_events(b_ok, clips_login);
    show_button(b_ok, b_ok_surface);

    b_back.pressed = 0;
    b_back = handle_events(b_back, clips_login);
    show_button(b_back, b_back_surface);

    b_input_id.pressed = 0;
    b_input_pw = handle_events(b_input_pw, clips_input_pw);
    show_button(b_input_pw, b_input_pw_surface);
    show_button(b_input_id, b_input_id_surface);

    input_id();

    if(b_ok.pressed == 1)
        switch_welcome_page = 5;

    if(b_back.pressed == 1)
        switch_welcome_page = 0;

    if(b_input_pw.pressed == 1 || entered == 1 )
    {
        switch_welcome_page = 4;
        b_input_pw.pressed = 1;
    }

    return switch_welcome_page;
}

int welcome_page_case_4(int switch_welcome_page)
{
    entered = 0;

    b_ok.pressed = 0;
    b_ok = handle_events(b_ok, clips_login);
    show_button(b_ok, b_ok_surface);

    b_back.pressed = 0;
    b_back = handle_events(b_back, clips_login);
    show_button(b_back, b_back_surface);

    b_input_pw.pressed = 0;

    b_input_id = handle_events(b_input_id, clips_input_id);
    show_button(b_input_id, b_input_id_surface);
    show_button(b_input_pw, b_input_pw_surface);

    input_pw();

    if(b_ok.pressed == 1 || entered == 1 )
    {
        switch_welcome_page = 5;
    }

    if(b_back.pressed == 1)
        switch_welcome_page = 0;

    if(b_input_id.pressed == 1)
        switch_welcome_page = 3;
    return switch_welcome_page;
}

int welcome_page_case_5(int switch_welcome_page, struct Player player)
{

    if(strcmp(player.id, "00000fffff") == 0)
    {
        if(strcmp(player.pw, "00000fffff") == 0)
            switch_welcome_page = 2;
        else
            switch_welcome_page = 6;
    }
    else
        switch_welcome_page = 6;
    return switch_welcome_page;
}

int welcome_page_case_6(int switch_welcome_page)
{
    //Disable Unicode
    SDL_EnableUNICODE( SDL_DISABLE );

    clean_up_login_successful();
    printf("clean_up_login_successful\n");
    //printf("login successful\n");
    //jump to game menu
    return switch_welcome_page;
}

int welcome_page_case_8(int switch_welcome_page)
{
    entered = 0;

    b_ok.pressed = 0;
    b_ok = handle_events(b_ok, clips_login);
    show_button(b_ok, b_ok_surface);

    b_back.pressed = 0;
    b_back = handle_events(b_back, clips_login);
    show_button(b_back, b_back_surface);

    b_input_pw.pressed = 0;
    b_input_pwc.pressed = 0;

    b_input_pw = handle_events(b_input_pw, clips_input_pw);
    b_input_pwc = handle_events(b_input_pwc, clips_input_pw);

    show_button(b_input_id, b_input_id_surface);
    show_button(b_input_pw, b_input_pw_surface);
    show_button(b_input_pwc, b_input_pw_surface);

    input_id();



    if(b_ok.pressed == 1)
        switch_welcome_page = 11;

    if(b_back.pressed == 1)
        switch_welcome_page = 0;

    if(b_input_pw.pressed == 1 || entered == 1 )
    {
        switch_welcome_page = 9;
        b_input_pw.pressed = 1;
    }
    if(b_input_pwc.pressed == 1)
        switch_welcome_page = 10;

    return switch_welcome_page;
}

int welcome_page_case_9(int switch_welcome_page)
{
    entered = 0;

    b_ok.pressed = 0;
    b_ok = handle_events(b_ok, clips_login);
    show_button(b_ok, b_ok_surface);

    b_back.pressed = 0;
    b_back = handle_events(b_back, clips_login);
    show_button(b_back, b_back_surface);

    b_input_id.pressed = 0;
    b_input_pwc.pressed = 0;

    b_input_id = handle_events(b_input_id, clips_input_id);
    b_input_pwc = handle_events(b_input_pwc, clips_input_pw);

    show_button(b_input_id, b_input_id_surface);
    show_button(b_input_pw, b_input_pw_surface);
    show_button(b_input_pwc, b_input_pw_surface);

    input_pw();

    if(b_ok.pressed == 1)
        switch_welcome_page = 11;

    if(b_back.pressed == 1)
        switch_welcome_page = 0;

    if(b_input_id.pressed == 1)
        switch_welcome_page = 8;

    if(b_input_pwc.pressed == 1 || entered == 1 )
    {
        switch_welcome_page = 10;
        b_input_pwc.pressed = 1;
    }
    return switch_welcome_page;
}

int welcome_page_case_10(int switch_welcome_page)
{
    entered = 0;

    b_ok.pressed = 0;
    b_ok = handle_events(b_ok, clips_login);
    show_button(b_ok, b_ok_surface);

    b_back.pressed = 0;
    b_back = handle_events(b_back, clips_login);
    show_button(b_back, b_back_surface);

    b_input_id.pressed = 0;
    b_input_pw.pressed = 0;

    b_input_id = handle_events(b_input_id, clips_input_id);
    b_input_pw = handle_events(b_input_pw, clips_input_pw);

    show_button(b_input_id, b_input_id_surface);
    show_button(b_input_pw, b_input_pw_surface);
    show_button(b_input_pwc, b_input_pw_surface);

    input_pwc();

    if(b_ok.pressed == 1 || entered == 1 )
    {
        switch_welcome_page = 11;
    }

    if(b_back.pressed == 1)
        switch_welcome_page = 0;

    if(b_input_id.pressed == 1)
        switch_welcome_page = 8;

    if(b_input_pw.pressed == 1)
        switch_welcome_page = 9;
    return switch_welcome_page;
}

int p = 0;

int welcome_page_case_12(int switch_welcome_page)
{
    int i;
    N_apply_surface( 0, 0, bg_register, screen, NULL );
    b_ok.pressed = 0;
    b_ok = handle_events(b_ok, clips_login);
    show_button(b_ok, b_ok_surface);
    /*
        b_back.pressed = 0;
        b_back = handle_events(b_back, clips_login);
        show_button(b_back, b_back_surface);
    */

    menu_regles_show_buttons ();

    if( b_left.pressed == 1 )
    {
        if( p > 0 )
            p--;
        else
            p = portrait_number-1;
    }

    if( b_right.pressed == 1 )
    {
        if( p < portrait_number-1 )
            p++;
        else
            p = 0;
    }

    N_apply_surface( 150, 100, message("Chose your portrait plz", font_l), screen, NULL);
    N_apply_surface( 462, 334, portrait_list[p], screen, NULL );

    b_left.pressed = 0;
    b_right.pressed = 0;


    if(b_ok.pressed == 1)
    {
        for(i = 0; i < count_player() ; i++)
        {
            if(strcmp(stringinput_id.str,list[i].id)==0)
            {
                if(strcmp(stringinput_pw.str,list[i].pw)==0)
                {
                    list[i].portrait = p;
                    save_file();
                }
            }
            printf("i = %d",i);
        }
        switch_welcome_page = 0;
        //printf("player.portrait = %d\n",player.portrait);
    }
    /*
        if(b_back.pressed == 1)
        switch_welcome_page = 8;
    */

    return switch_welcome_page;
}


/** clean up */
void clean_up_welcome_page_Xed()
{
    if( bg_acceuil != NULL )
        SDL_FreeSurface(bg_acceuil);

    if( bg_login != NULL )
        SDL_FreeSurface(bg_login);

    if( bg_register != NULL )
        SDL_FreeSurface(bg_register);

    if( b_login_surface != NULL )
        SDL_FreeSurface(b_login_surface);

    if( b_register_surface != NULL )
        SDL_FreeSurface(b_register_surface);

    if( b_ok_surface!= NULL )
        SDL_FreeSurface(b_ok_surface);

    if( b_back_surface != NULL )
        SDL_FreeSurface(b_back_surface);

    if( b_input_id_surface != NULL )
        SDL_FreeSurface(b_input_id_surface);

    if( b_input_pw_surface != NULL )
        SDL_FreeSurface(b_input_pw_surface);

    free_portrait();
}

void clean_up_login_successful()
{
    SDL_FreeSurface(bg_acceuil);
    SDL_FreeSurface(bg_login);
    if( b_register_surface != NULL )
        SDL_FreeSurface(bg_register);
    SDL_FreeSurface(b_login_surface);
    SDL_FreeSurface(b_register_surface);
    SDL_FreeSurface(b_input_id_surface);
    SDL_FreeSurface(b_input_pw_surface);
}


