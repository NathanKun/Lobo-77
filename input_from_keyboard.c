#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
#include "header.h"

/** definition le type booleen */
#define bool int
#define true 1
#define false 0

/** definition de couleur du text */
extern SDL_Color textColor;

/** fct classique pour afficher un surface */
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

/** variable stocker si l'on a appuye a enter ou pas, 0 pour non, 1 pour oui */
int entered = 0;

/** fct qui change l'evenement de clavier a une chaine de caratere, et puis retourner une surface qui contient la chaine */
SDL_Surface * StringInput_handle_input(char str[], SDL_Surface *text, TTF_Font *font)
{
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Keep a copy of the current version of the string
        char temp[20];
        strcpy(temp, str);
        //printf("temp = %s\n", temp);

        //If the string less than maximum size
        if( strlen(str)< 13)
        {
            //If the key is a space
            if( event.key.keysym.unicode == (Uint16)' ' )
            {
                //Append the character
                //str += (char)event.key.keysym.unicode;
                str[strlen(str)] = (char)event.key.keysym.unicode;
            }
            //If the key is a number
            else if( ( event.key.keysym.unicode >= (Uint16)'0' ) && ( event.key.keysym.unicode <= (Uint16)'9' ) )
            {
                //Append the character
                str[strlen(str)] = (char)event.key.keysym.unicode;
            }
            //If the key is a uppercase letter
            else if( ( event.key.keysym.unicode >= (Uint16)'A' ) && ( event.key.keysym.unicode <= (Uint16)'Z' ) )
            {
                //Append the character
                str[strlen(str)] = (char)event.key.keysym.unicode;
            }
            //If the key is a lowercase letter
            else if( ( event.key.keysym.unicode >= (Uint16)'a' ) && ( event.key.keysym.unicode <= (Uint16)'z' ) )
            {
                //Append the character
                str[strlen(str)] = (char)event.key.keysym.unicode;
            }
        }

        //If backspace was pressed and the string isn't blank
        if( ( event.key.keysym.sym == SDLK_BACKSPACE ) && ( strlen(str) != 0 ) )
        {
            //Remove a character from the end
            str[strlen(str)-1] = '\0';
        }

        //If the string was changed
        if( str != temp )
        {
            //Free the old surface
            SDL_FreeSurface( text );

            //Render a new text surface
            text = TTF_RenderText_Solid( font, str, textColor );
        }

        if( ( event.key.keysym.sym == SDLK_RETURN )  )
        {
            entered = 1;
        }

    }

    return text;
}

/** le meme, mais retourner une surface avec des etoile ' * ' */
SDL_Surface * StringInput_handle_input_pw(char str[], SDL_Surface *text, TTF_Font *font)
{
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Keep a copy of the current version of the string
        char temp[20];
        char pw[20];
        strcpy(temp, str);
        //printf("temp = %s\n", temp);

        //If the string less than maximum size
        if( strlen(str)< 13)
        {
            //If the key is a space
            if( event.key.keysym.unicode == (Uint16)' ' )
            {
                //Append the character
                //str += (char)event.key.keysym.unicode;
                str[strlen(str)] = (char)event.key.keysym.unicode;
            }
            //If the key is a number
            else if( ( event.key.keysym.unicode >= (Uint16)'0' ) && ( event.key.keysym.unicode <= (Uint16)'9' ) )
            {
                //Append the character
                str[strlen(str)] = (char)event.key.keysym.unicode;
            }
            //If the key is a uppercase letter
            else if( ( event.key.keysym.unicode >= (Uint16)'A' ) && ( event.key.keysym.unicode <= (Uint16)'Z' ) )
            {
                //Append the character
                str[strlen(str)] = (char)event.key.keysym.unicode;
            }
            //If the key is a lowercase letter
            else if( ( event.key.keysym.unicode >= (Uint16)'a' ) && ( event.key.keysym.unicode <= (Uint16)'z' ) )
            {
                //Append the character
                str[strlen(str)] = (char)event.key.keysym.unicode;
            }
        }

        //If backspace was pressed and the string isn't blank
        if( ( event.key.keysym.sym == SDLK_BACKSPACE ) && ( strlen(str) != 0 ) )
        {
            //Remove a character from the end
            str[strlen(str)-1] = '\0';
        }

        //If the string was changed
        if( str != temp )
        {
            int n;
            for(n=0; n<20; n++)
            {
                pw[n]='\0';
            }
            for(n=0; n<strlen(str); n++)
            {
                pw[n]='*';
            }

            //Free the old surface
            SDL_FreeSurface( text );

            //Render a new text surface
            text = TTF_RenderText_Solid( font, pw, textColor );
        }

        if( ( event.key.keysym.sym == SDLK_RETURN )  )
        {
            entered = 1;
        }
    }

    return text;
}

/** fct affichage la surface qui contient le id ou pw */
void StringInput_show(SDL_Surface *text, int x, int y)
{
    //If the surface isn't blank
    if( text != NULL )
    {
        //Show the name
        apply_surface( x, y, text, screen, NULL );
    }
}






