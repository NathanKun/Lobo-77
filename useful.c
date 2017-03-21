#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include"header.h"



//Font
SDL_Color textColor = { 0, 0, 0 };

/** fct pour charger une image dans le disque dur, bmp, png, jpg, jpeg... */
SDL_Surface *N_load_img (char file_name[ ])
{
    SDL_Surface *loaded_img = NULL;
    SDL_Surface *optimized_img = NULL;

    loaded_img=IMG_Load(file_name);

    if(loaded_img!=NULL)
    {
        optimized_img=SDL_DisplayFormatAlpha(loaded_img);
        SDL_FreeSurface(loaded_img);
    }
    return optimized_img;
}

/** le meme, mais enlever une couleur ( color key ) */
SDL_Surface *N_load_img_color_key (char file_name[ ],const Uint8 r,const Uint8 g,const Uint8 b)
{
    SDL_Surface *loaded_img = NULL;
    SDL_Surface *optimized_img = NULL;

    loaded_img=IMG_Load(file_name);

    if(loaded_img!=NULL)
    {
        optimized_img=SDL_DisplayFormat(loaded_img);
        SDL_FreeSurface(loaded_img);

        if(optimized_img != NULL)
        {
            Uint32 colorkey = SDL_MapRGB(optimized_img->format,r,g,b);
            SDL_SetColorKey( optimized_img, SDL_SRCCOLORKEY, colorkey );
        }
    }

    return optimized_img;
}


/** fct affichage d'une surface a ( x, y ) d'un screen avec clip */
void N_apply_surface (int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
    SDL_Rect offset;
    offset.x=x;
    offset.y=y;

    SDL_BlitSurface(source, clip, destination, &offset);
}

/** surface pour le ecran au tout debut de ce programme */
SDL_Surface *logo_screen = NULL;
SDL_Surface *logo = NULL;
SDL_Surface *logo_sdl = NULL;


/** fct initiation, init sdl, ttf, mix, afficher les logos, puis afficher le screen principal du programme  */
int init(const int WIDTH, const int HEIGHT,const  int BPP, const char CAPTION[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
        return 1;

    logo_screen=SDL_SetVideoMode(557, 412, BPP, SDL_SWSURFACE|SDL_NOFRAME);
    SDL_WM_SetCaption(CAPTION,NULL);
    SDL_WM_SetIcon(N_load_img("pic/logo/logo.png"),NULL);
    logo = N_load_img("pic/logo/code_monkey.png");
    logo_sdl = N_load_img("pic/logo/SDL.jpg");
    SDL_FillRect( logo_screen, NULL, SDL_MapRGB( logo_screen->format, 0xFF, 0xFF, 0xFF ));
    N_apply_surface( 50, 73, logo_sdl, logo_screen, NULL );
    SDL_Flip(logo_screen);
    SDL_Delay(2500);
    N_apply_surface( 0, 0, logo, logo_screen, NULL );
    SDL_Flip(logo_screen);
    SDL_Delay(2500);
    SDL_FreeSurface(logo);
    SDL_FreeSurface(logo_sdl);
    //the second screen cannot be centered in windows, so quit and reinit
    SDL_Quit();
    if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
        return 1;
    putenv("SDL_VIDEO_CENTERED=1");
    screen=SDL_SetVideoMode(WIDTH, HEIGHT, BPP, SDL_SWSURFACE);
    if(screen==NULL)
        return 1;
    SDL_WM_SetCaption(CAPTION,NULL);
    SDL_WM_SetIcon(N_load_img("pic/logo/logo.png"),NULL);
    //for win32
    //SDL_WM_SetIcon(N_load_img("pic/logo/icon.png"),NULL);

    //init font
    if( TTF_Init() == -1 )
    {
        return 1;
    }

    font_l = TTF_OpenFont( "font/font.ttf", 70 );
    if( font_l == NULL )
        return 1;

    font_m = TTF_OpenFont( "font/font.ttf", 50 );
    if( font_m == NULL )
        return 1;

    font_s = TTF_OpenFont( "font/font.ttf", 30 );
    if( font_s == NULL )
        return 1;

    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
        //if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 256 ) == -1 )
        return 1;

//mixer    Mix_Init( MIX_INIT_MP3 );

    return 0;
}

/** fct pour initier le premier ecran ( init les buttons, charger les images et les sons) */
void welcome_page_init()
{
    set_clips_login();
    set_button_b_login();
    set_button_b_register();
    set_button_b_ok();
    set_button_b_back();

    b_login_surface = N_load_img("pic/button/login.png");
    b_register_surface = N_load_img("pic/button/register.png");
    b_ok_surface = N_load_img("pic/button/ok.png");
    b_back_surface = N_load_img("pic/button/back.png");
    bg_acceuil=N_load_img("pic/bg/acceuil.png");

    if ( bgm1 == NULL )
        bgm1 = Mix_LoadMUS( "sound/bgm_1.mp3" );
    effect_over = Mix_LoadWAV("sound/effect/over.wav");
    effect_down = Mix_LoadWAV("sound/effect/down.wav");
    effect_hey = Mix_LoadWAV("sound/effect/hey.wav");
}

/** fct retourner le clip pour un button en fonction de la position de la souris et etat du button de la souris */
struct Button handle_events(struct Button b, SDL_Rect clips[])
{
    int x = 0, y = 0;
    b.down = 0;
    //b.pressed = 0;
    //printf("b.pressed = %d", b.pressed);
    if((event.motion.x>0) && (event.motion.x<1024) && (event.motion.y<768) && (event.motion.y>0))
    {
        if( event.type == SDL_MOUSEMOTION )
        {

            x = event.motion.x;
            y = event.motion.y;

            if( ( x > b.box.x ) && ( x < b.box.x + b.box.w ) && ( y > b.box.y ) && ( y < b.box.y + b.box.h ) )
            {
                b.clip = &clips[ CLIP_MOUSEOVER ];
                if( same_event_or_not_for_sound_effect_for_button () == 0 )
                {
                    b.over = 1;
                }
            }
            else
            {
                b.clip = &clips[ CLIP_MOUSEOUT ];
                b.over = 0;
            }
        }

        if( event.type == SDL_MOUSEBUTTONDOWN )
        {
            if( event.button.button == SDL_BUTTON_LEFT )
            {
                x = event.button.x;
                y = event.button.y;

                if( ( x > b.box.x ) && ( x < b.box.x + b.box.w ) && ( y > b.box.y ) && ( y < b.box.y + b.box.h ) )
                {
                    b.clip = &clips[ CLIP_MOUSEDOWN ];
                    b.down = 1;
                }
                else
                {
                    b.clip = &clips[ CLIP_MOUSEOUT ];
                }
                b.over = 0;
            }

            if( event.button.button == SDL_BUTTON_RIGHT || event.button.button == SDL_BUTTON_MIDDLE || event.button.button == SDL_BUTTON_WHEELDOWN || event.button.button == SDL_BUTTON_WHEELUP)
            {
                if( ( x > b.box.x ) && ( x < b.box.x + b.box.w ) && ( y > b.box.y ) && ( y < b.box.y + b.box.h ) )
                    b.clip = &clips[ CLIP_MOUSEOVER ];
                else
                    b.clip = &clips[ CLIP_MOUSEOUT ];
            }
        }

        if( event.type == SDL_MOUSEBUTTONUP )
        {
            if( event.button.button == SDL_BUTTON_LEFT )
            {
                x = event.button.x;
                y = event.button.y;
                if( ( x > b.box.x ) && ( x < b.box.x + b.box.w ) && ( y > b.box.y ) && ( y < b.box.y + b.box.h ) )
                {
                    if( same_event_or_not_for_button () == 0 )
                    {
                        b.clip = &clips[ CLIP_MOUSEUP ];
                        b.pressed = 1;
                    }
                }
                else
                    b.clip = &clips[ CLIP_MOUSEOUT ];
            }

            if( event.button.button == SDL_BUTTON_RIGHT || event.button.button == SDL_BUTTON_MIDDLE || event.button.button == SDL_BUTTON_WHEELDOWN || event.button.button == SDL_BUTTON_WHEELUP)
            {
                if( ( x > b.box.x ) && ( x < b.box.x + b.box.w ) && ( y > b.box.y ) && ( y < b.box.y + b.box.h ) )
                    b.clip = &clips[ CLIP_MOUSEOVER ];
                else
                    b.clip = &clips[ CLIP_MOUSEOUT ];
            }
            b.over = 0;
        }
    }

    else
        b.clip = &clips[ CLIP_MOUSEOUT ];

    //printf("b.pressed = %d",b.pressed);
    if( b_effect_on.pressed == 1 )
    {
        /*if( b.over == 1 )
        {
            Mix_PlayChannel ( -1, effect_over, 0 );
            b.over = 2;
        }*/
        if( b.pressed == 1 )
        {
            Mix_PlayChannel ( -1, effect_down, 0 ) ;
        }
    }


    return b;
}

/** fct affichage du button */
void show_button(struct Button b, SDL_Surface *surface)
{
    N_apply_surface( b.box.x, b.box.y, surface, screen, b.clip );
}

/** fct transformer une chaine de caratere a une surface */
SDL_Surface *message(char m[ ], TTF_Font *font)
{
    SDL_Surface *msg;
    msg = TTF_RenderText_Solid( font, m, textColor );
    if( msg == NULL )
    {
        return NULL;
    }
    return msg;
}

/** une solution d'un probleme rencontre */
/** difficile a decrire */
int same_event_or_not_for_input ()  //999 for yes, 0 for no
{
    if ( event.type == event_old.type )
    {
        if ( event.type == SDL_KEYDOWN )
        {
            if ( event.key.keysym.sym == event_old.key.keysym.sym )
            {
                //if ( event.key.keysym.sym == SDLK_BACKSPACE )
                //   return 0;
                //    else
                //   {
                //printf("same event detected!  SDL_KEYDOWN  same sym\n");
                return 999;
                //   }
            }
            return 0;
        }
        return 0;
    }
    return 0;
}

/** de meme */
int same_event_or_not_for_button () //888 for yes, 0 for no
{
    if ( event.type == event_old.type )
    {
        if ( event.type == SDL_MOUSEBUTTONUP )
        {
            if ( event.button.button == event_old.button.button )
            {
                if ( event.button.button == SDL_BUTTON_LEFT )
                {
                    //printf("same event detected!  -  SDL_MOUSEBUTTONUP  SDL_BUTTON_LEFT \n");
                    return 888;
                }
                else
                {
                    return 0;
                }
            }
            return 0;
        }
        return 0;
    }
    return 0;
}

/** cela j'ai pas bien reussir, fct est abondonnee, mais je l'ai garder quand meme */
int same_event_or_not_for_sound_effect_for_button () //10086 for yes, 0 for no
{
    if ( event.type == event_old.type )
    {
        if ( event.type == SDL_MOUSEMOTION )
        {
            if ( event.motion.x == event_old.motion.x )
            {
                if ( event.motion.y == event_old.motion.y )
                {
                    return 10086;
                }
                else
                {
                    return 0;
                }
            }
            return 0;
        }
        return 0;
    }
    return 0;
}









