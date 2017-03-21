#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>

/** definition de struct StringInput, utiliser pour recevoir le string vient du clavier */
struct StringInput
{
    //The storage string
    char str[20];

    //The text surface
    SDL_Surface *text;
};
/**
* utilisation
* SDL_Surface * StringInput_handle_input(char str[], SDL_Surface *text, TTF_Font *font);
* puis
* void StringInput_show(SDL_Surface *text, int x, int y);
*/


/** definition de struct Button */
struct Button
{
    SDL_Rect box;
    SDL_Rect* clip;
    //SDL_Rect clips[ 4 ];
    int pressed;
    int over;
    int down;
};
/**
* Un button contient
* struct Button b_xx
* SDL_Rect clips_xx
* SDL_Surface *b_xx_surface

* et fonction set clips
* void set_clips_xx ()

* utilisation:
* set_clips_xx;
* b_xx=handle_events(b_xx, clips_xx);
* show_button(b_xx, b_xx_surface);
*/

/** Definition de stucture Stat */
struct Stat
{
    int win;
    int lose;
    int login_times;
};

/** Definition de stucture Player */
struct Player
{
    char id[20];
    char pw[20];
    struct Stat stat;
    int portrait;
};

extern SDL_Surface *portrait_list[20] ;
extern void init_portrait_list ();


/** Definition de stucture Card */
struct Card
{
    int value; //card with value,  -10 included
    int type;  //0 for value card, 1 for x2, 2 for turn
    int card_number; //from 0 to 55
    long taken; //0 for in the deck, 1 for taken, 2 for played

    SDL_Surface *sf;
};

extern struct Card deck[57];


/** Definition de stucture joueur ( utiliser pendant le jeu ) */
struct Game_player_human
{
    struct Card hand_card[5];
    int coin;
    int x2;
};

/** Definition de stucture joueur ordinateur ( utiliser pendant le jeu ) */
struct Game_player_com
{
    int place; //form 1 to 8
    int diff; //0 for noplayer, 1for e, 2 for m, 3 for h
    struct Card hand_card[5];
    int coin;
    int x2;
};

extern struct Player player;
extern struct Player list[123];

extern int switch_welcome_page;
extern int switch_main;
extern int switch_menu;


//functions
//main.c and useful.c
extern int init(const int WIDTH, const int HEIGHT,const  int BPP, const char CAPTION[ ]);
extern SDL_Surface *N_load_img (char file_name[ ]);
extern SDL_Surface *N_load_img_color_key (char file_name[ ],const Uint8 r,const Uint8 g,const Uint8 b);
extern void N_apply_surface (int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
extern struct Button handle_events(struct Button b, SDL_Rect clips[]);
extern void show_button(struct Button b, SDL_Surface *surface);
extern void set_clips_login();
extern void set_clips_register();
extern void welcome_page_init();
extern SDL_Surface *message(char m[], TTF_Font *font);
extern struct Player login(struct Player list[]);
extern void login_page_init();
extern void stringinput_init();
extern void input_pw();
extern void input_id();
extern void clean_up_login_successful();
extern void clean_up_welcome_page_Xed();
extern struct Button handle_events(struct Button b, SDL_Rect clips[]);

extern int welcome_page_case_1(int switch_welcome_page);
extern int welcome_page_case_2(int switch_welcome_page);
extern int welcome_page_case_3(int switch_welcome_page);
extern int welcome_page_case_4(int switch_welcome_page);
extern int welcome_page_case_5(int switch_welcome_page, struct Player player);
extern int welcome_page_case_6(int switch_welcome_page);
extern int welcome_page_case_8(int switch_welcome_page);
extern int welcome_page_case_9(int switch_welcome_page);
extern int welcome_page_case_10(int switch_welcome_page);
extern int welcome_page_case_12(int switch_welcome_page);

extern int same_event_or_not_for_input ();
extern int same_event_or_not_for_sound_effect_for_button ();
extern void set_button_b_back();

//input_for_keyboard.c
extern SDL_Surface * StringInput_handle_input(char str[], SDL_Surface *text, TTF_Font *font);
extern void StringInput_show(SDL_Surface *text, int x, int y);
extern SDL_Surface * StringInput_handle_input_pw(char str[], SDL_Surface *text, TTF_Font *font);
extern int same_event_or_not_for_button ();

//login.c
extern int charge_file (struct Player list[]);
extern void register_page_init();
extern int registation(struct Player list[]);
extern int count_player();
extern void init_portrait_load_img();
extern void set_button_b_login();
extern void set_button_b_register();
extern void set_button_b_ok();

//menu.c
extern void init_menu_buttons ();
extern void menu_show_buttons ();
extern void menu_button_pressed ();
extern void menu_statistique();
extern void menu_regle_init();
extern void init_buttons_left_right ();
extern void menu_regle();
extern void menu_parametre();
extern void clean_up_menu_Xed();
extern void menu_statistique_init ();
extern void menu_game_settings_init();
extern void menu_game_settings ();
extern struct Button b_sound_on;
extern struct Button b_effect_on;
extern struct Button b_sound_off;
extern struct Button b_effect_off;
extern struct Button b_left;
extern struct Button b_right;
extern void menu_parametre_init();
extern void menu_regles_show_buttons ();

//game.c
extern void game_start_init();
extern void game();
extern void anime_give_card ();
extern void game_new_turn_flash ();

//define mouse event for button
extern const int CLIP_MOUSEOVER;
extern const int CLIP_MOUSEOUT;
extern const int CLIP_MOUSEDOWN;
extern const int CLIP_MOUSEUP;

//variable
extern SDL_Surface *screen;
extern SDL_Surface *bg_acceuil;
extern SDL_Surface *bg_login;
extern SDL_Surface *bg_register;
extern SDL_Surface *bg_menu;
extern SDL_Surface *b_ok_surface;
extern SDL_Surface *b_back_surface;
extern SDL_Surface *b_register_surface;
extern SDL_Surface *b_login_surface;
extern SDL_Surface *b_input_id_surface;
extern SDL_Surface *b_input_pw_surface;

extern int entered;

extern SDL_Rect clips_login[ 4 ];
extern SDL_Rect clips_register[ 4 ];

extern SDL_Event event;
extern SDL_Event event_old;


extern TTF_Font *font_l;
extern TTF_Font *font_m;
extern TTF_Font *font_s;

extern struct Button b_login;
extern struct Button b_register;
extern struct Button b_ok;
extern struct Button b_back;

extern SDL_Surface *screen;
extern SDL_Surface *bg_login;
extern SDL_Surface *bg_register;

extern TTF_Font *font_l;
extern TTF_Font *font_m;
extern TTF_Font *font_s;

//BGM
extern Mix_Music *bgm1;
extern Mix_Chunk *effect_over;
extern Mix_Chunk *effect_down;
extern Mix_Chunk *effect_hey;

//login.c
extern struct Button b_login;
extern SDL_Rect clips_login[ 4 ];
extern SDL_Surface *b_login_surface;

extern struct Button b_register;
extern SDL_Rect clips_register[ 4 ];
extern SDL_Surface *b_register_surface;

extern struct Button b_ok;
extern SDL_Surface *b_ok_surface;

extern struct Button b_back;
extern SDL_Surface *b_back_surface;

extern struct Button b_input_pwc;

extern SDL_Surface *b_input_id_surface;
extern struct Button b_input_id;
extern SDL_Rect clips_input_id[4];

extern SDL_Surface *b_input_pw_surface;
extern struct Button b_input_pw;
extern SDL_Rect clips_input_pw[4];

extern struct Button b_input_pwc;


extern SDL_Surface *portrait_player;

//menu.c
extern int show_regle;
extern int no_event_time;

//game.c
extern struct Game_player_com com[8];

extern int anime;



