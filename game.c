#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "header.h"


/** tableau contenant tous les cartes */
struct Card deck[ 57 ];
/** tableau contenant les joueur ordi */
struct Game_player_com com[8];
/** joueur */
struct Game_player_human human;

SDL_Surface *bg_game = NULL;
SDL_Surface *sum_surface = NULL;

/** somme */
int sum;
/** direction du jeu */
int direction; //1 for clockwise, 2 for Counterclockwise
/** variable montrer qui est en train de jouer */
long playing_player; //0 for player, 1-8 for com
/** 5 buttons pour jouer une carte */
struct Button b_card1;
struct Button b_card2;
struct Button b_card3;
struct Button b_card4;
struct Button b_card5;
SDL_Surface *b_card_surface = NULL;
SDL_Rect clips_card[4];

/** la derrnier carte jouee */
struct Card card_played;
/** montrer si le joueur a deja jouer une carte ou pas */
int human_player_played;
/** la carte choisi par le button */
int selected_card;

/** la derrnier carte jouee */
int human_last_played_card;
int com1_last_played_card;
int com2_last_played_card;
int com3_last_played_card;
int com4_last_played_card;
int com5_last_played_card;
int com6_last_played_card;
int com7_last_played_card;
int com8_last_played_card;

/** variable montrer si c'est la fin du jeu */
int end;//0 for not end, 1 for up to 77, 2 for game over


/** solution pour reussir la carte x2 */
int x2_activated = 0;


/** solution pour laisser l'ordin jouer doucement
* je n'utilise pas SDL_Delay() ici, car il va arreter le jeu completement
* mais ici je peux par exemple choisir ma carte pendant l'ordin est jouer
*/
int com_thinking = 0;
int com_thinking_start = 0;
/** solution pour voir si l'ordin a joue une carte,  */
struct Card last_card;
int last_player;

/** les surface */
SDL_Surface *card_back = NULL;

SDL_Surface *com_lose = NULL;
SDL_Surface *portrait_light = NULL;

SDL_Surface *e1 = NULL;
SDL_Surface *e2 = NULL;
SDL_Surface *e3 = NULL;
SDL_Surface *e4 = NULL;
SDL_Surface *e5 = NULL;
SDL_Surface *e6 = NULL;
SDL_Surface *e7 = NULL;
SDL_Surface *e8 = NULL;
SDL_Surface *n1 = NULL;
SDL_Surface *n2 = NULL;
SDL_Surface *n3 = NULL;
SDL_Surface *n4 = NULL;
SDL_Surface *n5 = NULL;
SDL_Surface *n6 = NULL;
SDL_Surface *n7 = NULL;
SDL_Surface *n8 = NULL;
SDL_Surface *h1 = NULL;
SDL_Surface *h2 = NULL;
SDL_Surface *h3 = NULL;
SDL_Surface *h4 = NULL;
SDL_Surface *h5 = NULL;
SDL_Surface *h6 = NULL;
SDL_Surface *h7 = NULL;
SDL_Surface *h8 = NULL;

SDL_Surface *coins_3 = NULL;
SDL_Surface *coins_2 = NULL;
SDL_Surface *coins_1 = NULL;
SDL_Surface *coins_0 = NULL;

SDL_Surface *lobo = NULL;
SDL_Surface *lobo_11 = NULL;
SDL_Surface *lobo_22 = NULL;
SDL_Surface *lobo_33 = NULL;
SDL_Surface *lobo_44 = NULL;
SDL_Surface *lobo_55 = NULL;
SDL_Surface *lobo_66 = NULL;
SDL_Surface *lobo_77 = NULL;

/** pour reussir anime au debut du jeu ( donner les cartes ) */
int flame = -10;


/** fct initier les cartes */
void set_card (  )
{
    //value
    deck[0].value = 0;
    deck[0].type = 0;
    deck[1].value = 0;
    deck[1].type = 0;
    deck[2].value = 0;
    deck[2].type = 0;
    deck[3].value = 0;
    deck[3].type = 0;
    deck[4].value = 2;
    deck[4].type = 0;
    deck[5].value = 2;
    deck[5].type = 0;
    deck[6].value = 2;
    deck[6].type = 0;
    deck[7].value = 3;
    deck[7].type = 0;
    deck[8].value = 3;
    deck[8].type = 0;
    deck[9].value = 3;
    deck[9].type = 0;
    deck[10].value = 4;
    deck[10].type = 0;
    deck[11].value = 4;
    deck[11].type = 0;
    deck[12].value = 4;
    deck[12].type = 0;
    deck[13].value = 5;
    deck[13].type = 0;
    deck[14].value = 5;
    deck[14].type = 0;
    deck[15].value = 5;
    deck[15].type = 0;
    deck[16].value = 6;
    deck[16].type = 0;
    deck[17].value = 6;
    deck[17].type = 0;
    deck[18].value = 6;
    deck[18].type = 0;
    deck[19].value = 7;
    deck[19].type = 0;
    deck[20].value = 7;
    deck[20].type = 0;
    deck[21].value = 7;
    deck[21].type = 0;
    deck[22].value = 8;
    deck[22].type = 0;
    deck[23].value = 8;
    deck[23].type = 0;
    deck[24].value = 8;
    deck[24].type = 0;
    deck[25].value = 9;
    deck[25].type = 0;
    deck[26].value = 9;
    deck[26].type = 0;
    deck[27].value = 9;
    deck[27].type = 0;
    deck[28].value = 10;
    deck[28].type = 0;
    deck[29].value = 10;
    deck[29].type = 0;
    deck[30].value = 10;
    deck[30].type = 0;
    deck[31].value = 10;
    deck[31].type = 0;
    deck[32].value = 10;
    deck[32].type = 0;
    deck[33].value = 10;
    deck[33].type = 0;
    deck[34].value = 10;
    deck[34].type = 0;
    deck[35].value = 10;
    deck[35].type = 0;
    //-10
    deck[36].value = -10;
    deck[36].type = 0;
    deck[37].value = -10;
    deck[37].type = 0;
    deck[38].value = -10;
    deck[38].type = 0;
    deck[39].value = -10;
    deck[39].type = 0;

    //doublet
    deck[40].value = 11;
    deck[40].type = 0;
    deck[41].value = 22;
    deck[41].type = 0;
    deck[42].value = 33;
    deck[42].type = 0;
    deck[43].value = 44;
    deck[43].type = 0;
    deck[44].value = 55;
    deck[44].type = 0;
    deck[45].value = 66;
    deck[45].type = 0;
    deck[46].value = 76;
    deck[46].type = 0;

    //x2
    deck[47].value = 0;
    deck[47].type = 1;
    deck[48].value = 0;
    deck[48].type = 1;
    deck[49].value = 0;
    deck[49].type = 1;
    deck[50].value = 0;
    deck[50].type = 1;

    //turn
    deck[51].value = 0;
    deck[51].type = 2;
    deck[52].value = 0;
    deck[52].type = 2;
    deck[53].value = 0;
    deck[53].type = 2;
    deck[54].value = 0;
    deck[54].type = 2;
    deck[55].value = 0;
    deck[55].type = 2;

    //init card for draw
    deck[ 56 ].taken = 1;

    //card_number
    deck[0].card_number = 0;
    deck[1].card_number = 1;
    deck[2].card_number = 2;
    deck[3].card_number = 3;
    deck[4].card_number = 4;
    deck[5].card_number = 5;
    deck[6].card_number = 6;
    deck[7].card_number = 7;
    deck[8].card_number = 8;
    deck[9].card_number = 9;
    deck[10].card_number = 10;
    deck[11].card_number = 11;
    deck[12].card_number = 12;
    deck[13].card_number = 13;
    deck[14].card_number = 14;
    deck[15].card_number = 15;
    deck[16].card_number = 16;
    deck[17].card_number = 17;
    deck[18].card_number = 18;
    deck[19].card_number = 19;
    deck[20].card_number = 20;
    deck[21].card_number = 21;
    deck[22].card_number = 22;
    deck[23].card_number = 23;
    deck[24].card_number = 24;
    deck[25].card_number = 25;
    deck[26].card_number = 26;
    deck[27].card_number = 27;
    deck[28].card_number = 28;
    deck[29].card_number = 29;
    deck[30].card_number = 30;
    deck[31].card_number = 31;
    deck[32].card_number = 32;
    deck[33].card_number = 33;
    deck[34].card_number = 34;
    deck[35].card_number = 35;
    deck[36].card_number = 36;
    deck[37].card_number = 37;
    deck[38].card_number = 38;
    deck[39].card_number = 39;
    deck[40].card_number = 40;
    deck[41].card_number = 41;
    deck[42].card_number = 42;
    deck[43].card_number = 43;
    deck[44].card_number = 44;
    deck[45].card_number = 45;
    deck[46].card_number = 46;
    deck[47].card_number = 47;
    deck[48].card_number = 48;
    deck[49].card_number = 49;
    deck[50].card_number = 50;
    deck[51].card_number = 51;
    deck[52].card_number = 52;
    deck[53].card_number = 53;
    deck[54].card_number = 54;
    deck[55].card_number = 55;


}

/** le meme */
void set_card_surface ( )
{
    //load img
    deck[0].sf = N_load_img( "pic/card/0.png" );
    deck[1].sf = N_load_img( "pic/card/0.png" );
    deck[2].sf = N_load_img( "pic/card/0.png" );
    deck[3].sf = N_load_img( "pic/card/0.png" );
    deck[4].sf = N_load_img( "pic/card/2.png" );
    deck[5].sf = N_load_img( "pic/card/2.png" );
    deck[6].sf = N_load_img( "pic/card/2.png" );
    deck[7].sf = N_load_img( "pic/card/3.png" );
    deck[8].sf = N_load_img( "pic/card/3.png" );
    deck[9].sf = N_load_img( "pic/card/3.png" );
    deck[10].sf = N_load_img( "pic/card/4.png" );
    deck[11].sf = N_load_img( "pic/card/4.png" );
    deck[12].sf = N_load_img( "pic/card/4.png" );
    deck[13].sf = N_load_img( "pic/card/5.png" );
    deck[14].sf = N_load_img( "pic/card/5.png" );
    deck[15].sf = N_load_img( "pic/card/5.png" );
    deck[16].sf = N_load_img( "pic/card/6.png" );
    deck[17].sf = N_load_img( "pic/card/6.png" );
    deck[18].sf = N_load_img( "pic/card/6.png" );
    deck[19].sf = N_load_img( "pic/card/7.png" );
    deck[20].sf = N_load_img( "pic/card/7.png" );
    deck[21].sf = N_load_img( "pic/card/7.png" );
    deck[22].sf = N_load_img( "pic/card/8.png" );
    deck[23].sf = N_load_img( "pic/card/8.png" );
    deck[24].sf = N_load_img( "pic/card/8.png" );
    deck[25].sf = N_load_img( "pic/card/9.png" );
    deck[26].sf = N_load_img( "pic/card/9.png" );
    deck[27].sf = N_load_img( "pic/card/9.png" );
    deck[28].sf = N_load_img( "pic/card/10.png" );
    deck[29].sf = N_load_img( "pic/card/10.png" );
    deck[30].sf = N_load_img( "pic/card/10.png" );
    deck[31].sf = N_load_img( "pic/card/10.png" );
    deck[32].sf = N_load_img( "pic/card/10.png" );
    deck[33].sf = N_load_img( "pic/card/10.png" );
    deck[34].sf = N_load_img( "pic/card/10.png" );
    deck[35].sf = N_load_img( "pic/card/10.png" );

    deck[36].sf = N_load_img( "pic/card/-10.png" );
    deck[37].sf = N_load_img( "pic/card/-10.png" );
    deck[38].sf = N_load_img( "pic/card/-10.png" );
    deck[39].sf = N_load_img( "pic/card/-10.png" );

    deck[40].sf = N_load_img( "pic/card/11.png" );
    deck[41].sf = N_load_img( "pic/card/22.png" );
    deck[42].sf = N_load_img( "pic/card/33.png" );
    deck[43].sf = N_load_img( "pic/card/44.png" );
    deck[44].sf = N_load_img( "pic/card/55.png" );
    deck[45].sf = N_load_img( "pic/card/66.png" );
    deck[46].sf = N_load_img( "pic/card/76.png" );

    deck[47].sf = N_load_img( "pic/card/x2.png" );
    deck[48].sf = N_load_img( "pic/card/x2.png" );
    deck[49].sf = N_load_img( "pic/card/x2.png" );
    deck[50].sf = N_load_img( "pic/card/x2.png" );

    deck[51].sf = N_load_img( "pic/card/turn.png" );
    deck[52].sf = N_load_img( "pic/card/turn.png" );
    deck[53].sf = N_load_img( "pic/card/turn.png" );
    deck[54].sf = N_load_img( "pic/card/turn.png" );
    deck[55].sf = N_load_img( "pic/card/turn.png" );

    deck[56].sf = NULL;

    card_back = N_load_img("pic/card/card_back.png");
}

/** initier l'etat de tous les cartes */
void reset_deck (  )
{
    int i;
    for( i = 0; i < 56; i++ )
    {
        deck[ i ].taken = 0;
    }
}

/** fct de piocher une carte */
struct Card draw (  )
{
    int rand_num=56;
    int j;
    int drawed = 0;

    for(j=0; j<56; j++)
    {
        if( deck[j].taken == 1 || deck[j].taken == 2 )
        {
            drawed++;
        }
    }

    while( ( deck[ rand_num ].taken == 1 || deck[ rand_num ].taken == 2 ) && drawed != 56)
    {
        rand_num = rand()%56;
    }

    if( drawed == 56 )
    {
        //end = 1;
        printf("no more cards\n");

        //reset played cards
        for(j=0; j<56; j++)
        {
            if(deck[ j ].taken == 2)
            {
                deck[ j ].taken = 0;
            }
        }
        //redraw
        while( deck[ rand_num ].taken == 1 || deck[ rand_num ].taken == 2 )
        {
            rand_num = rand()%56;
        }
    }

    deck[ rand_num ].taken = 1;

    return deck[ rand_num ];
}

/** fct de piocher 5 cartes au debut du jeu */
void game_start_draw (  )
{
    int i;

    if( com[1].diff !=0 && com[1].diff !=4 )
    {
        for( i = 0; i <5 ; i ++ )
        {
            com[1].hand_card[i] = draw( );
        }
    }

    if( com[2].diff !=0 && com[2].diff !=4 )
    {
        for( i = 0; i <5 ; i ++ )
        {
            com[2].hand_card[i] = draw( );
        }
    }

    if( com[3].diff !=0 && com[3].diff !=4 )
    {
        for( i = 0; i <5 ; i ++ )
        {
            com[3].hand_card[i] = draw( );
        }
    }

    if( com[4].diff !=0 && com[4].diff !=4 )
    {
        for( i = 0; i <5 ; i ++ )
        {
            com[4].hand_card[i] = draw( );
        }
    }

    if( com[5].diff !=0 && com[5].diff !=4 )
    {
        for( i = 0; i <5 ; i ++ )
        {
            com[5].hand_card[i] = draw( );
        }
    }

    if( com[6].diff !=0 && com[6].diff !=4 )
    {
        for( i = 0; i <5 ; i ++ )
        {
            com[6].hand_card[i] = draw( );
        }
    }

    if( com[7].diff !=0 && com[7].diff !=4 )
    {
        for( i = 0; i <5 ; i ++ )
        {
            com[7].hand_card[i] = draw( );
        }
    }

    if( com[0].diff !=0 && com[0].diff !=4 )
    {
        for( i = 0; i <5 ; i ++ )
        {
            com[0].hand_card[i] = draw( );
        }
    }

    for( i = 0; i <5 ; i ++ )
    {
        human.hand_card[i] = draw( );
    }
}

/** fct de voir si ordin peut jouer ce carte tout simplement */
//1 for good, 0 for bad
int good_card_or_not ( int card_value )
{
    if( ( card_value + sum >=77 ) || ( card_value + sum == 66 ) || ( card_value + sum == 55 ) || ( card_value + sum == 44 ) || ( card_value + sum == 33 ) || ( card_value + sum == 22 ) || ( card_value + sum == 11 ) )
    {
        return 0;
    }
    else
        return 1;
}


/** 3 fct principale pour ordi, pour choisir une carte a jouer */
//3 difficulty
//easy:
//don't use specail card
//avoid losing sum
// play the first card which won't make him lose the coins
//else, play the first card in his hand
struct Card AI_easy ( struct Card hand_card[ ] )
{
    int hand;
    int sum_if;
    for(hand=0; hand<5; hand++)
    {
        if( hand_card[hand].type == 0 )
        {
            sum_if = hand_card[hand].value + sum;
            if( sum_if != 11 && sum_if != 22 && sum_if != 33 && sum_if != 44 && sum_if != 55 && sum_if != 66 && sum_if < 77 )
            {
                return hand_card[hand];
            }
        }
    }
    return hand_card[0];
}

//normal:
//play the biggest double value card
//play a specail card if in dangerous
//play -10 card if no specail card and in dangerous
//else, play the first card in the hand
struct Card AI_normal ( struct Card hand_card[ ] )
{
    int i;
    int hand;

    //play 76 if possible
    if( ( hand_card[0].value == 76 || hand_card[1].value == 76 || hand_card[2].value == 76 || hand_card[3].value == 76 || hand_card[4].value == 76 ) && good_card_or_not( 76 ) == 1 )
    {
        for(i=0; i<5; i++)
        {
            if( hand_card[i].value == 76 )
                return hand_card[i];
        }
    }
    //play 66 if possible
    if( ( hand_card[0].value == 66 || hand_card[1].value == 66 || hand_card[2].value == 66 || hand_card[3].value == 66 || hand_card[4].value == 66 ) && good_card_or_not( 66 ) == 1 )
    {
        for(i=0; i<5; i++)
        {
            if( hand_card[i].value == 66 )
                return hand_card[i];
        }
    }
    //play 55 if possible
    if( ( hand_card[0].value == 55 || hand_card[1].value == 55 || hand_card[2].value == 55 || hand_card[3].value == 55 || hand_card[4].value == 55 ) && good_card_or_not( 55 ) == 1 )
    {
        for(i=0; i<5; i++)
        {
            if( hand_card[i].value == 55 )
                return hand_card[i];
        }
    }
    //play 44 if possible
    if( ( hand_card[0].value == 44 || hand_card[1].value == 44 || hand_card[2].value == 44 || hand_card[3].value == 44 || hand_card[4].value == 44 ) && good_card_or_not( 44 ) == 1 )
    {
        for(i=0; i<5; i++)
        {
            if( hand_card[i].value == 44 )
                return hand_card[i];
        }
    }
    //play 33 if possible
    if( ( hand_card[0].value == 33 || hand_card[1].value == 33 || hand_card[2].value == 33 || hand_card[3].value == 33 || hand_card[4].value == 33 ) && good_card_or_not( 33 ) == 1 )
    {
        for(i=0; i<5; i++)
        {
            if( hand_card[i].value == 33 )
                return hand_card[i];
        }
    }
    //play 22 if possible
    if( ( hand_card[0].value == 22 || hand_card[1].value == 22 || hand_card[2].value == 22 || hand_card[3].value == 22 || hand_card[4].value == 22 ) && good_card_or_not( 22 ) == 1 )
    {
        for(i=0; i<5; i++)
        {
            if( hand_card[i].value == 22 )
                return hand_card[i];
        }
    }

    //play a normal value card if possible
    for(hand=0; hand<5; hand++)
    {
        if( hand_card[hand].type == 0 && hand_card[hand].value != -10 )
        {
            if( good_card_or_not( hand_card[hand].value ) == 1 )
            {
                return hand_card[hand];
            }
        }
    }

    //play a specail card if possible
    for(hand=0; hand<5; hand++)
    {
        if( hand_card[hand].type == 1 || hand_card[hand].type == 2 )
        {
            return hand_card[hand];
        }
    }

    //play a -10 card if possible
    for(hand=0; hand<5; hand++)
    {
        if( hand_card[hand].value == -10 && good_card_or_not( -10 ) == 1 )
        {
            return hand_card[hand];
        }
    }

    //else play the first card in the hand
    return hand_card[0];
}

//hard
//try to kill the other player
//bugs:
//            playing -10 when sum = 76, losing a coin.
struct Card AI_hard ( struct Card hand_card[ ] )
{
    int up;
    int down;
    int up_x2 = 0, up_turn = 0, up_m10 = 0, up_0 = 0;
    int down_x2 = 0, down_turn = 0, down_m10 = 0, down_0 = 0;
    int me_x2 = 0, me_turn = 0, me_m10 = 0, me_0 = 0;
    int i, j, k;
    int x2ed; //am I x2ed? 0 for no, else for yes
    struct Card up_card[5], down_card[5];

    //am I x2ed?
    if(playing_player == 8)
    {
        x2ed = com[0].x2;
    }
    else
    {
        x2ed = com[playing_player].x2;
    }
    //what do I have?
    for(i=0; i<5; i++)
    {
        if( hand_card[i].type == 1 )
            me_x2++;
        if( hand_card[i].type == 2 )
            me_turn++;
        if( hand_card[i].type == 0 && hand_card[i].value == -10 )
            me_m10++;
        if( hand_card[i].type == 0 && hand_card[i].value == 0 )
            me_0++;
    }
    //found my next player and previous player
    if( direction == 1 )
    {
        if( playing_player == 8 )
        {
            up = 7;
            down = 0;
        }
        else
        {
            up = playing_player -1;
            down = playing_player +1;
        }
    }
    else
    {
        if( playing_player == 8 )
        {
            up = 0;
            down = 7;
        }
        else
        {
            up = playing_player +1;
            down = playing_player -1;
        }
    }
    //now, I  knows yours cards
    if( up == 0 )
    {
        for(i=0; i<5; i++)
        {
            if( human.hand_card[i].type == 1 )
                up_x2++;
            if( human.hand_card[i].type == 2 )
                up_turn++;
            if( human.hand_card[i].type == 0 && human.hand_card[i].value == -10 )
                up_m10++;
            if( human.hand_card[i].type == 0 && human.hand_card[i].value == 0 )
                up_0++;
            up_card[i] = human.hand_card[i];
        }
    }
    else
    {
        for(i=0; i<5; i++)
        {
            if( com[up].hand_card[i].type == 1 )
                up_x2++;
            if( com[up].hand_card[i].type == 2 )
                up_turn++;
            if( com[up].hand_card[i].type == 0 && com[up].hand_card[i].value == -10 )
                up_m10++;
            if( com[up].hand_card[i].type == 0 && com[up].hand_card[i].value == 0 )
                up_0++;
            up_card[i] = com[up].hand_card[i];
        }
    }
    if( down == 0 )
    {
        for(i=0; i<5; i++)
        {
            if( human.hand_card[i].type == 1 )
                down_x2++;
            if( human.hand_card[i].type == 2 )
                down_turn++;
            if( human.hand_card[i].type == 0 && human.hand_card[i].value == -10 )
                down_m10++;
            if( human.hand_card[i].type == 0 && human.hand_card[i].value == 0 )
                down_0++;
            down_card[i] = human.hand_card[i];
        }
    }
    else
    {
        for(i=0; i<5; i++)
        {
            if( com[down].hand_card[i].type == 1 )
                down_x2++;
            if( com[down].hand_card[i].type == 2 )
                down_turn++;
            if( com[down].hand_card[i].type == 0 && com[down].hand_card[i].value == -10 )
                down_m10++;
            if( com[down].hand_card[i].type == 0 && com[down].hand_card[i].value == 0 )
                down_0++;
            down_card[i] = com[down].hand_card[i];
        }
    }

    //if down doesn't have any specail card
    if( down_x2 == 0 && down_turn == 0 && down_m10 == 0 && down_0 == 0 )
    {
        //if any of my value cards can kill down?
        int min = down_card[0].value;
        for(i=0; i<5; i++)
        {
            if(down_card[i].value<min)
            {
                min=down_card[i].value;
            }
        }
        for(i=0; i<5; i++)
        {
            if( hand_card[i].value + min + sum > 76 && good_card_or_not( hand_card[i].value) == 1 && ( me_0 + me_x2 >= x2ed ) )
            {
                if( hand_card[i].type == 0 && hand_card[i].value != -10 )
                {
                    printf("playing_player = %d killed by value card!\n", down);
                    return hand_card[i];
                }
                else
                {
                    if( hand_card[i].type == 1 && ( me_0 + me_x2 > x2ed ) )
                    {
                        printf("playing_player = %d killed!\n",down);
                        return hand_card[i];
                    }
                }
            }
        }
        //if x2 can kill down?
        int min_of_two = down_card[0].value + down_card[1].value;
        for( i=0; i<5; i++ )
        {
            for( j=0; j<5; j++ )
            {
                if( down_card[i].value + down_card[j].value < min_of_two )
                {
                    min_of_two = down_card[i].value + down_card[j].value;
                }
            }
        }
        if( min_of_two + sum > 76 && ( me_0 + me_x2 > x2ed ) )
        {
            for( k=0; k<5; k++ )
            {
                if(hand_card[k].type == 1)
                {
                    printf("playing_player = %d killed by x2!\n", down);
                    return hand_card[k];
                }
            }
        }
    }
    //if down doesn't have -10, only has one 0/turn/x2 card, and  I have a x2 card
    if( down_m10 == 0 && ( down_x2 + down_turn + down_0 == 1 ) && me_x2 > 0 && me_0 + me_x2> x2ed )
    {
        int min_of_two = down_card[0].value + down_card[1].value;
        for( i=0; i<5; i++ )
        {
            for( j=0; j<5; j++ )
            {
                if( down_card[i].value + down_card[j].value < min_of_two )
                {
                    min_of_two = down_card[i].value + down_card[j].value;
                }
            }
        }
        if( min_of_two + sum > 76 && ( me_0 + me_x2 > x2ed ) )
        {
            for( k=0; k<5; k++ )
            {
                if(hand_card[k].type == 1)
                {
                    printf("playing_player = %d killed by x2!\n", down);
                    return hand_card[k];
                }
            }
        }
    }


    //if turn can kill up?
    if( up_x2 == 0 && up_turn == 0 && up_m10 == 0 && up_0 == 0 )
    {
        int min=up_card[0].value;
        for(i=0; i<5; i++)
        {
            if( up_card[i].value < min )
            {
                min = up_card[i].value;
            }
        }
        if( ( min + sum > 76 ) && ( me_0 +  me_x2 >= x2ed ) )
        {
            for(i=0; i<5; i++)
            {
                if( hand_card[i].type == 2 )
                {
                    printf("playing_player = %d killed by turn!\n", up);
                    return hand_card[i];
                }
            }
        }
        j = 0;
        for(i=0; i<5; i++)
        {
            if( up_card[i].value + sum > 76 || up_card[i].value + sum == 66 )
            {
                j++;
            }
        }
        if( j == 5 && ( me_0 +  me_x2 >= x2ed ) )
        {
            for(i=0; i<5; i++)
            {
                if( hand_card[i].type == 2 )
                {
                    printf("playing_player = %d killed by turn!\n", up);
                    return hand_card[i];
                }
            }
        }
    }


//else same as normal AI
    int hand;
//play 76 if possible
    if( ( hand_card[0].value == 76 || hand_card[1].value == 76 || hand_card[2].value == 76 || hand_card[3].value == 76 || hand_card[4].value == 76 ) && good_card_or_not( 76 ) == 1 )
    {
        for(i=0; i<5; i++)
        {
            if( hand_card[i].value == 76 )
                return hand_card[i];
        }
    }
//play 66 if possible
    if( ( hand_card[0].value == 66 || hand_card[1].value == 66 || hand_card[2].value == 66 || hand_card[3].value == 66 || hand_card[4].value == 66 ) && good_card_or_not( 66 ) == 1 )
    {
        for(i=0; i<5; i++)
        {
            if( hand_card[i].value == 66 )
                return hand_card[i];
        }
    }
//play 55 if possible
    if( ( hand_card[0].value == 55 || hand_card[1].value == 55 || hand_card[2].value == 55 || hand_card[3].value == 55 || hand_card[4].value == 55 ) && good_card_or_not( 55 ) == 1 )
    {
        for(i=0; i<5; i++)
        {
            if( hand_card[i].value == 55 )
                return hand_card[i];
        }
    }
//play 44 if possible
    if( ( hand_card[0].value == 44 || hand_card[1].value == 44 || hand_card[2].value == 44 || hand_card[3].value == 44 || hand_card[4].value == 44 ) && good_card_or_not( 44 ) == 1 )
    {
        for(i=0; i<5; i++)
        {
            if( hand_card[i].value == 44 )
                return hand_card[i];
        }
    }
//play 33 if possible
    if( ( hand_card[0].value == 33 || hand_card[1].value == 33 || hand_card[2].value == 33 || hand_card[3].value == 33 || hand_card[4].value == 33 ) && good_card_or_not( 33 ) == 1 )
    {
        for(i=0; i<5; i++)
        {
            if( hand_card[i].value == 33 )
                return hand_card[i];
        }
    }
//play 22 if possible
    if( ( hand_card[0].value == 22 || hand_card[1].value == 22 || hand_card[2].value == 22 || hand_card[3].value == 22 || hand_card[4].value == 22 ) && good_card_or_not( 22 ) == 1 )
    {
        for(i=0; i<5; i++)
        {
            if( hand_card[i].value == 22 )
                return hand_card[i];
        }
    }
//play 11 if possible
    if( ( hand_card[0].value == 11 || hand_card[1].value == 11 || hand_card[2].value == 11 || hand_card[3].value == 11 || hand_card[4].value == 11 ) && good_card_or_not( 11 ) == 1 )
    {
        for(i=0; i<5; i++)
        {
            if( hand_card[i].value == 11 )
                return hand_card[i];
        }
    }

//play a normal value card if possible
    for(hand=0; hand<5; hand++)
    {
        if( hand_card[hand].type == 0 && ( hand_card[hand].value != -10 ) && hand_card[hand].value != 0 )
        {
            if( good_card_or_not( hand_card[hand].value ) == 1 )
            {
                return hand_card[hand];
            }
        }
    }

//play a specail card if possible
    for(hand=0; hand<5; hand++)
    {
        if( hand_card[hand].type == 1 || hand_card[hand].type == 2 )
        {
            return hand_card[hand];
        }
    }

//play a 0 card if possible
    for(hand=0; hand<5; hand++)
    {
        if( hand_card[hand].value == 0 && good_card_or_not( 0 ) == 1 )
        {
            return hand_card[hand];
        }
    }

//play a -10 card if possible
    for(hand=0; hand<5; hand++)
    {
        if( ( hand_card[hand].value == -10 ) && ( good_card_or_not( -10 ) == 1 ) )
        {
            return hand_card[hand];
        }
    }

//else play the biggest card in the hand
    int max;
    max = hand_card[0].value;
    for(hand=1; hand<5; hand++)
    {
        if(hand_card[0].value < hand_card[hand].value)
            max = hand_card[hand].value;
    }

    for(hand=0; hand<5; hand++)
    {
        if(hand_card[hand].value == max)
            return hand_card[hand];
    }

    return hand_card[0];
}

void set_clips_card( )
{
    clips_card[ CLIP_MOUSEOVER ].x = 0;
    clips_card[ CLIP_MOUSEOVER ].y = 0;
    clips_card[ CLIP_MOUSEOVER ].w = 108;
    clips_card[ CLIP_MOUSEOVER ].h = 165;

    clips_card[ CLIP_MOUSEOUT ].x = 109;
    clips_card[ CLIP_MOUSEOUT ].y = 166;
    clips_card[ CLIP_MOUSEOUT ].w = 108;
    clips_card[ CLIP_MOUSEOUT ].h = 165;

    clips_card[ CLIP_MOUSEDOWN ].x = 0;
    clips_card[ CLIP_MOUSEDOWN ].y = 0;
    clips_card[ CLIP_MOUSEDOWN ].w = 108;
    clips_card[ CLIP_MOUSEDOWN ].h = 165;

    clips_card[ CLIP_MOUSEUP ].x = 109;
    clips_card[ CLIP_MOUSEUP ].y = 166;
    clips_card[ CLIP_MOUSEUP ].w = 108;
    clips_card[ CLIP_MOUSEUP ].h = 165;
}

struct Button set_button_b_card( struct Button b, int i )
{
    b.box.x = 207+125*i;
    b.box.y = 593;
    b.box.w = 108;
    b.box.h = 165;

    return b;
}

/** fct affichage, afficher les cartes dans le main du joueur */
void show_player_human_hand_cards ()
{
    N_apply_surface( 212, 600, human.hand_card[ 0 ].sf, screen, NULL);
    N_apply_surface( 337, 600, human.hand_card[ 1 ].sf, screen, NULL);
    N_apply_surface( 462, 600, human.hand_card[ 2 ].sf, screen, NULL);
    N_apply_surface( 587, 600, human.hand_card[ 3 ].sf, screen, NULL);
    N_apply_surface( 712, 600, human.hand_card[ 4 ].sf, screen, NULL);
}

/** afficher tous les 'portraits' */
void game_show_portrait ()
{
    if( com[1].diff == 1 )
        N_apply_surface( 24, 430, e1, screen, NULL);
    if( com[2].diff == 1 )
        N_apply_surface( 24, 240, e2, screen, NULL);
    if( com[3].diff == 1 )
        N_apply_surface( 24, 50, e3, screen, NULL);
    if( com[4].diff == 1 )
        N_apply_surface( 274, 50, e4, screen, NULL);
    if( com[5].diff == 1 )
        N_apply_surface( 534, 50, e5, screen, NULL);
    if( com[6].diff == 1 )
        N_apply_surface( 794, 50, e6, screen, NULL);
    if( com[7].diff == 1 )
        N_apply_surface( 794, 240, e7, screen, NULL);
    if( com[0].diff == 1 )
        N_apply_surface( 794, 430, e8, screen, NULL);

    if( com[1].diff == 2 )
        N_apply_surface( 24, 430, n1, screen, NULL);
    if( com[2].diff == 2 )
        N_apply_surface( 24, 240, n2, screen, NULL);
    if( com[3].diff == 2 )
        N_apply_surface( 24, 50, n3, screen, NULL);
    if( com[4].diff == 2 )
        N_apply_surface( 274, 50, n4, screen, NULL);
    if( com[5].diff == 2 )
        N_apply_surface( 534, 50, n5, screen, NULL);
    if( com[6].diff == 2 )
        N_apply_surface( 794, 50, n6, screen, NULL);
    if( com[7].diff == 2 )
        N_apply_surface( 794, 240, n7, screen, NULL);
    if( com[0].diff == 2 )
        N_apply_surface( 794, 430, n8, screen, NULL);

    if( com[1].diff == 3 )
        N_apply_surface( 24, 430, h1, screen, NULL);
    if( com[2].diff == 3 )
        N_apply_surface( 24, 240, h2, screen, NULL);
    if( com[3].diff == 3 )
        N_apply_surface( 24, 50, h3, screen, NULL);
    if( com[4].diff == 3 )
        N_apply_surface( 274, 50, h4, screen, NULL);
    if( com[5].diff == 3 )
        N_apply_surface( 534, 50, h5, screen, NULL);
    if( com[6].diff == 3 )
        N_apply_surface( 794, 50, h6, screen, NULL);
    if( com[7].diff == 3 )
        N_apply_surface( 794, 240, h7, screen, NULL);
    if( com[0].diff == 3 )
        N_apply_surface( 794, 430, h8, screen, NULL);

    if( com[1].diff == 4 )
        N_apply_surface( 24, 430, com_lose, screen, NULL);
    if( com[2].diff == 4 )
        N_apply_surface( 24, 240, com_lose, screen, NULL);
    if( com[3].diff == 4 )
        N_apply_surface( 24, 50, com_lose, screen, NULL);
    if( com[4].diff == 4 )
        N_apply_surface( 274, 50, com_lose, screen, NULL);
    if( com[5].diff == 4 )
        N_apply_surface( 534, 50, com_lose, screen, NULL);
    if( com[6].diff == 4 )
        N_apply_surface( 794, 50, com_lose, screen, NULL);
    if( com[7].diff == 4 )
        N_apply_surface( 794, 240, com_lose, screen, NULL);
    if( com[0].diff == 4 )
        N_apply_surface( 794, 430, com_lose, screen, NULL);

    N_apply_surface( 90, 600, portrait_list[player.portrait], screen, NULL );
}

/** afficher les jetons */
void game_show_coins ()
{
    if( com[0].diff != 0 )
    {
        if( com[0].coin == 3 )
        {
            N_apply_surface( 794, 530, coins_3, screen, NULL );
        }
        if( com[0].coin == 2 )
        {
            N_apply_surface( 794, 530,coins_2, screen, NULL );
        }
        if( com[0].coin == 1 )
        {
            N_apply_surface( 794, 530, coins_1, screen, NULL );
        }
        if( com[0].coin == 0 )
        {
            N_apply_surface( 794, 530, coins_0, screen, NULL );
        }
    }

    if( com[1].diff != 0 )
    {
        if( com[1].coin == 3 )
        {
            N_apply_surface( 24, 530, coins_3, screen, NULL );
        }
        if( com[1].coin == 2 )
        {
            N_apply_surface( 24, 530, coins_2, screen, NULL );
        }
        if( com[1].coin == 1 )
        {
            N_apply_surface( 24, 530, coins_1, screen, NULL );
        }
        if( com[1].coin == 0 )
        {
            N_apply_surface( 24, 530, coins_0, screen, NULL );
        }
    }

    if( com[2].diff != 0 )
    {
        if( com[2].coin == 3 )
        {
            N_apply_surface( 24, 340, coins_3, screen, NULL );
        }
        if( com[2].coin == 2 )
        {
            N_apply_surface( 24, 340, coins_2, screen, NULL );
        }
        if( com[2].coin == 1 )
        {
            N_apply_surface( 24, 340, coins_1, screen, NULL );
        }
        if( com[2].coin == 0 )
        {
            N_apply_surface( 24, 340, coins_0, screen, NULL );
        }
    }

    if( com[3].diff != 0 )
    {
        if( com[3].coin == 3 )
        {
            N_apply_surface( 24, 150, coins_3, screen, NULL );
        }
        if( com[3].coin == 2 )
        {
            N_apply_surface( 24, 150, coins_2, screen, NULL );
        }
        if( com[3].coin == 1 )
        {
            N_apply_surface( 24, 150, coins_1, screen, NULL );
        }
        if( com[3].coin == 0 )
        {
            N_apply_surface( 24, 150, coins_0, screen, NULL );
        }
    }

    if( com[4].diff != 0 )
    {
        if( com[4].coin == 3 )
        {
            N_apply_surface( 274, 150, coins_3, screen, NULL );
        }
        if( com[4].coin == 2 )
        {
            N_apply_surface( 274, 150, coins_2, screen, NULL );
        }
        if( com[4].coin == 1 )
        {
            N_apply_surface( 274, 150, coins_1, screen, NULL );
        }
        if( com[4].coin == 0 )
        {
            N_apply_surface( 274, 150, coins_0, screen, NULL );
        }
    }

    if( com[5].diff != 0 )
    {
        if( com[5].coin == 3 )
        {
            N_apply_surface( 534, 150, coins_3, screen, NULL );
        }
        if( com[5].coin == 2 )
        {
            N_apply_surface( 534, 150, coins_2, screen, NULL );
        }
        if( com[5].coin == 1 )
        {
            N_apply_surface( 534, 150, coins_1, screen, NULL );
        }
        if( com[5].coin == 0 )
        {
            N_apply_surface( 534, 150, coins_0, screen, NULL );
        }
    }

    if( com[6].diff != 0 )
    {
        if( com[6].coin == 3 )
        {
            N_apply_surface( 794, 150, coins_3, screen, NULL );
        }
        if( com[6].coin == 2 )
        {
            N_apply_surface( 794, 150, coins_2, screen, NULL );
        }
        if( com[6].coin == 1 )
        {
            N_apply_surface( 794, 150, coins_1, screen, NULL );
        }
        if( com[6].coin == 0 )
        {
            N_apply_surface( 794, 150, coins_0, screen, NULL );
        }
    }

    if( com[7].diff != 0 )
    {
        if( com[7].coin == 3 )
        {
            N_apply_surface( 794, 340, coins_3, screen, NULL );
        }
        if( com[7].coin == 2 )
        {
            N_apply_surface( 794, 340, coins_2, screen, NULL );
        }
        if( com[7].coin == 1 )
        {
            N_apply_surface( 794, 340, coins_1, screen, NULL );
        }
        if( com[7].coin == 0 )
        {
            N_apply_surface( 794, 340, coins_0, screen, NULL );
        }
    }

    if (human.coin == 3)
    {
        N_apply_surface( 90, 700, coins_3, screen, NULL );
    }
    if (human.coin == 2)
    {
        N_apply_surface( 90, 700, coins_2, screen, NULL );
    }
    if (human.coin == 1)
    {
        N_apply_surface( 90, 700, coins_1, screen, NULL );
    }
    if (human.coin == 0)
    {
        N_apply_surface( 90, 700, coins_0, screen, NULL );
    }
}

/** afficher tous les dernieres cartes jouees */
void game_show_card (  )
{
    N_apply_surface( 462, 450, deck[human_last_played_card].sf, screen, NULL );
    N_apply_surface( 146, 430, deck[com1_last_played_card].sf, screen, NULL );
    N_apply_surface( 146, 240, deck[com2_last_played_card].sf, screen, NULL );
    N_apply_surface( 146, 50, deck[com3_last_played_card].sf, screen, NULL );
    N_apply_surface( 394, 50, deck[com4_last_played_card].sf, screen, NULL );
    N_apply_surface( 654, 50, deck[com5_last_played_card].sf, screen, NULL );
    N_apply_surface( 914, 50, deck[com6_last_played_card].sf, screen, NULL );
    N_apply_surface( 914, 240, deck[com7_last_played_card].sf, screen, NULL );
    N_apply_surface( 914, 430, deck[com8_last_played_card].sf, screen, NULL );
}

/** afficher le somme */
void game_show_sum ()
{
    char sum_c[5];
    sprintf( sum_c, "%d", sum);
    sum_surface = message( sum_c, font_l );
    N_apply_surface( 450, 300, sum_surface, screen, NULL);
}

/** afficher le lumiere autour de la carte quand on le choisit */
int human_player_selecting ()
{
    b_card1 = handle_events( b_card1, clips_card );
    b_card2 = handle_events( b_card2, clips_card );
    b_card3 = handle_events( b_card3, clips_card );
    b_card4 = handle_events( b_card4, clips_card );
    b_card5 = handle_events( b_card5, clips_card );

    show_button( b_card1, b_card_surface );
    show_button( b_card2, b_card_surface );
    show_button( b_card3, b_card_surface );
    show_button( b_card4, b_card_surface );
    show_button( b_card5, b_card_surface );


    if( b_card1.pressed )
    {
        human_player_played = 1;
        return 0;
    }
    if( b_card2.pressed )
    {
        human_player_played = 1;
        return 1;
    }
    if( b_card3.pressed )
    {
        human_player_played = 1;
        return 2;
    }
    if( b_card4.pressed )
    {
        human_player_played = 1;
        return 3;
    }
    if( b_card5.pressed )
    {
        human_player_played = 1;
        return 4;
    }
    return 999;
}

/** solution pour savoir une carte est deja joue */
void set_taken_equal_2 ()
{
    int i;
    for(i=0; i<56; i++)
    {
        if(card_played.card_number == deck[ i ].card_number)
        {
            deck[ i ].taken = 2;
        }
    }
}

/** pour voir qui est perdu */
void game_loser_detect()
{
    SDL_Surface *lose_msg = NULL;
    if(human.coin == -1 || com[0].coin == -1 || com[1].coin == -1 || com[2].coin == -1 || com[3].coin == -1 || com[4].coin == -1 || com[5].coin == -1 || com[6].coin == -1 || com[7].coin == -1)
    {
        if( human.coin == -1 )
        {
            end = 2;
            printf("player lose\n");
            lose_msg = message("Vous etes perdu", font_l);
            player.stat.lose++;
        }
        if( com[0].coin == -1 )
        {
            end = 1;
            com[0].diff = 4;
            com[0].coin = 0;
            printf("com[0] lose\n");
            lose_msg = message("com 8 est perdu", font_l);
            SDL_Delay(2000);
        }
        if( com[1].coin == -1 )
        {
            end = 1;
            com[1].diff = 4;
            com[1].coin = 0;
            printf("com[1] lose\n");
            printf("com[0] lose\n");
            lose_msg = message("com 1 est perdu", font_l);
        }
        if( com[2].coin == -1 )
        {
            end = 1;
            com[2].diff = 4;
            com[2].coin = 0;
            printf("com[2] lose\n");
            printf("com[0] lose\n");
            lose_msg = message("com 2 est perdu", font_l);
        }
        if( com[3].coin == -1 )
        {
            end = 1;
            com[3].diff = 4;
            com[3].coin = 0;
            printf("com[3] lose\n");
            lose_msg = message("com 3 est perdu", font_l);
        }
        if( com[4].coin == -1 )
        {
            end = 1;
            com[4].diff = 4;
            com[4].coin = 0;
            printf("com[4] lose\n");
            lose_msg = message("com 4 est perdu", font_l);
        }
        if( com[5].coin == -1 )
        {
            end = 1;
            com[5].diff = 4;
            com[5].coin = 0;
            lose_msg = message("com 5 est perdu", font_l);
            printf("com[5] lose\n");
        }
        if( com[6].coin == -1 )
        {
            end = 1;
            com[6].diff = 4;
            com[6].coin = 0;
            printf("com[6] lose\n");
            lose_msg = message("com 6 est perdu", font_l);
        }
        if( com[7].coin == -1 )
        {
            end = 1;
            com[7].diff = 4;
            com[7].coin = 0;
            printf("com[7] lose\n");
            lose_msg = message("com 7 est perdu", font_l);
        }


        N_apply_surface( 0, 0, bg_game, screen, NULL );
        show_player_human_hand_cards();
        game_show_coins ();
        game_show_portrait ();
        N_apply_surface( 100, 400, lose_msg, screen, NULL );
        SDL_Flip(screen);
        SDL_Delay(2000);
    }
    if ( ( com[0].diff == 0 || com[0].diff == 4 ) && ( com[1].diff == 0 || com[1].diff == 4 ) && ( com[2].diff == 0 || com[2].diff == 4 ) && ( com[3].diff == 0 || com[3].diff == 4 ) && ( com[7].diff == 0 || com[7].diff == 4 ) && ( com[5].diff == 0 || com[5].diff == 4 ) && ( com[6].diff == 0 || com[6].diff == 4 ) && ( com[7].diff == 0 || com[7].diff == 4 ) )
    {
        end = 2;
        player.stat.win++;
    }
}

/** chercher le prochain joueur, en fct de direction et x2ed */
int game_find_next_player()
{
    int next = playing_player;

    if( playing_player != 0 && com_thinking == 0 )
    {
        if( playing_player != 8 )
        {
            if( com[playing_player].x2 != 0 )
            {
                com[playing_player].x2--;
            }
            else
            {
                if( direction == 1 )
                {
                    next++;
                }
                else
                {
                    next--;
                }
            }
        }
        else
            //playing player = 8
        {
            if( com[0].x2 != 0 )
            {
                com[0].x2--;
            }
            else
            {
                if( direction == 1 )
                    next = 0;
                else
                    next--;
            }
        }

    }
    else
    {
        //playing_player = 0
        if( com_thinking == 0 )
        {
            if( human_player_played == 1 )
            {
                if( human.x2 != 0)
                {
                    human.x2--;
                }
                else
                {
                    if( direction == 1 )
                        next = 1;
                    else
                        next = 8;
                }
                human_player_played = 0;
            }
        }
    }
    return next;
}

/** fct contenant processure principal du jeu */
void game_process ()
{
    card_played.card_number = 56;
    int i;
    SDL_Surface *end_msg = NULL;
    char *end_msg_char = NULL;

    b_card1.pressed = 0;
    b_card2.pressed = 0;
    b_card3.pressed = 0;
    b_card4.pressed = 0;
    b_card5.pressed = 0;

    //play card
    if( playing_player == 0 )
    {
        N_apply_surface( 70, 580, portrait_light, screen, NULL);

        human_player_played = 0;

        selected_card = human_player_selecting();

        if( human_player_played == 1 )
        {
            card_played = human.hand_card[selected_card];
            human_last_played_card = human.hand_card[selected_card].card_number;
            human.hand_card[selected_card] = draw();
        }
    }

    if( playing_player == 1 )
    {
        if( com[1].diff != 0 && com[1].diff != 4 )
        {
            N_apply_surface( 4, 410, portrait_light, screen, NULL);
            if( com_thinking - com_thinking_start > 1000 )
            {
                //com_thinking = 0;
                if( com[1].diff == 1 )
                {
                    card_played = AI_easy( com[1].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[1].hand_card[i].card_number )
                        {
                            com[1].hand_card[i] = draw();
                        }
                    }
                }
                if( com[1].diff == 2 )
                {
                    card_played = AI_normal( com[1].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[1].hand_card[i].card_number )
                        {
                            com[1].hand_card[i] = draw();
                        }
                    }
                }
                if( com[1].diff == 3 )
                {
                    card_played = AI_hard( com[1].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[1].hand_card[i].card_number )
                        {
                            com[1].hand_card[i] = draw();
                        }
                    }
                }
                com1_last_played_card = card_played.card_number;
            }
            else
            {
                com_thinking = SDL_GetTicks();
            }
        }
        else
        {
            com_thinking = 0;
        }
    }

    if( playing_player == 2 )
    {
        if( com[2].diff != 0 && com[2].diff != 4 )
        {
            N_apply_surface( 4, 220, portrait_light, screen, NULL);
            if( com_thinking - com_thinking_start > 1000 )
            {
                if( com[2].diff == 1 )
                {
                    card_played = AI_easy( com[2].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[2].hand_card[i].card_number )
                        {
                            com[2].hand_card[i] = draw();
                        }
                    }
                }
                if( com[2].diff == 2 )
                {
                    card_played = AI_normal( com[2].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[2].hand_card[i].card_number )
                        {
                            com[2].hand_card[i] = draw();
                        }
                    }
                }
                if( com[2].diff == 3 )
                {
                    card_played = AI_hard( com[2].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[2].hand_card[i].card_number )
                        {
                            com[2].hand_card[i] = draw();
                        }
                    }
                }
                com2_last_played_card = card_played.card_number;
            }
            else
            {
                com_thinking = SDL_GetTicks();
            }
        }
        else
        {
            com_thinking = 0;
        }
    }

    if( playing_player == 3 )
    {
        if( com[3].diff != 0 && com[3].diff != 4 )
        {
            N_apply_surface( 4, 30, portrait_light, screen, NULL);
            if( com_thinking - com_thinking_start > 1000 )
            {
                if( com[3].diff == 1 )
                {
                    card_played = AI_easy( com[3].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[3].hand_card[i].card_number )
                        {
                            com[3].hand_card[i] = draw();
                        }
                    }
                }
                if( com[3].diff == 2 )
                {
                    card_played = AI_normal( com[3].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[3].hand_card[i].card_number )
                        {
                            com[3].hand_card[i] = draw();
                        }
                    }
                }
                if( com[3].diff == 3 )
                {
                    card_played = AI_hard( com[3].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[3].hand_card[i].card_number )
                        {
                            com[3].hand_card[i] = draw();
                        }
                    }
                }
                com3_last_played_card = card_played.card_number;
            }
            else
            {
                com_thinking = SDL_GetTicks();
            }
        }
        else
        {
            com_thinking = 0;
        }
    }

    if( playing_player == 4 )
    {
        if( com[4].diff != 0 && com[4].diff != 4)
        {
            N_apply_surface( 254, 30, portrait_light, screen, NULL);
            if( com_thinking - com_thinking_start > 1000 )
            {
                if( com[4].diff == 1 )
                {
                    card_played = AI_easy( com[4].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[4].hand_card[i].card_number )
                        {
                            com[4].hand_card[i] = draw();
                        }
                    }
                }
                if( com[4].diff == 2 )
                {
                    card_played = AI_normal( com[4].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[4].hand_card[i].card_number )
                        {
                            com[4].hand_card[i] = draw();
                        }
                    }
                }
                if( com[4].diff == 3 )
                {
                    card_played = AI_hard( com[4].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[4].hand_card[i].card_number )
                        {
                            com[4].hand_card[i] = draw();
                        }
                    }
                }
                com4_last_played_card = card_played.card_number;
            }
            else
            {
                com_thinking = SDL_GetTicks();
            }
        }
        else
        {
            com_thinking = 0;
        }
    }

    if( playing_player == 5)
    {
        if( com[5].diff != 0 && com[5].diff != 4)
        {
            N_apply_surface( 514, 30, portrait_light, screen, NULL);
            if( com_thinking - com_thinking_start > 1000 )
            {
                if( com[5].diff == 1 )
                {
                    card_played = AI_easy( com[5].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[5].hand_card[i].card_number )
                        {
                            com[5].hand_card[i] = draw();
                        }
                    }
                }
                if( com[5].diff == 2 )
                {
                    card_played = AI_normal( com[5].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[5].hand_card[i].card_number )
                        {
                            com[5].hand_card[i] = draw();
                        }
                    }
                }
                if( com[5].diff == 3 )
                {
                    card_played = AI_hard( com[5].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[5].hand_card[i].card_number )
                        {
                            com[5].hand_card[i] = draw();
                        }
                    }
                }
                com5_last_played_card = card_played.card_number;
            }
            else
            {
                com_thinking = SDL_GetTicks();
            }
        }
        else
        {
            com_thinking = 0;
        }
    }

    if( playing_player == 6 )
    {
        if( com[6].diff != 0 && com[6].diff != 4 )
        {
            N_apply_surface( 774, 30, portrait_light, screen, NULL);
            if( com_thinking - com_thinking_start > 1000 )
            {
                if( com[6].diff == 1 )
                {
                    card_played = AI_easy( com[6].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[6].hand_card[i].card_number )
                        {
                            com[6].hand_card[i] = draw();
                        }
                    }
                }
                if( com[6].diff == 2 )
                {
                    card_played = AI_normal( com[6].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[6].hand_card[i].card_number )
                        {
                            com[6].hand_card[i] = draw();
                        }
                    }
                }
                if( com[6].diff == 3 )
                {
                    card_played = AI_hard( com[6].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[6].hand_card[i].card_number )
                        {
                            com[6].hand_card[i] = draw();
                        }
                    }
                }
                com6_last_played_card = card_played.card_number;
            }
            else
            {
                com_thinking = SDL_GetTicks();
            }
        }
        else
        {
            com_thinking = 0;
        }
    }

    if( playing_player == 7)
    {
        if( com[7].diff != 0 && com[7].diff != 4 )
        {
            N_apply_surface( 774, 220, portrait_light, screen, NULL);
            if( com_thinking - com_thinking_start > 1000 )
            {
                if( com[7].diff == 1 )
                {
                    card_played = AI_easy( com[7].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[7].hand_card[i].card_number )
                        {
                            com[7].hand_card[i] = draw();
                        }
                    }
                }
                if( com[7].diff == 2 )
                {
                    card_played = AI_normal( com[7].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[7].hand_card[i].card_number )
                        {
                            com[7].hand_card[i] = draw();
                        }
                    }
                }
                if( com[7].diff == 3 )
                {
                    card_played = AI_hard( com[7].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[7].hand_card[i].card_number )
                        {
                            com[7].hand_card[i] = draw();
                        }
                    }
                }
                com7_last_played_card = card_played.card_number;
            }
            else
            {
                com_thinking = SDL_GetTicks();
            }
        }
        else
        {
            com_thinking = 0;
        }
    }

    if( playing_player == 8 )
    {
        if( com[0].diff != 0 && com[0].diff != 4 )
        {
            N_apply_surface( 774, 410, portrait_light, screen, NULL);
            if( com_thinking - com_thinking_start > 1000 )
            {
                if( com[0].diff == 1 )
                {
                    card_played = AI_easy( com[0].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[0].hand_card[i].card_number )
                        {
                            com[0].hand_card[i] = draw();
                        }
                    }
                }
                if( com[0].diff == 2 )
                {
                    card_played = AI_normal( com[0].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[0].hand_card[i].card_number )
                        {
                            com[0].hand_card[i] = draw();
                        }
                    }
                }
                if( com[0].diff == 3 )
                {
                    card_played = AI_hard( com[0].hand_card );
                    for( i=0; i<5; i++ )
                    {
                        if( card_played.card_number == com[0].hand_card[i].card_number )
                        {
                            com[0].hand_card[i] = draw();
                        }
                    }
                }
                com8_last_played_card = card_played.card_number;
            }
            else
            {
                com_thinking = SDL_GetTicks();
            }
        }
        else
        {
            com_thinking = 0;
        }
    }


    //count sum, x2 card,  turn direction card
    if( card_played.card_number != 56 )
    {
        com_thinking_start = SDL_GetTicks();
        com_thinking = 0;

        sum = sum + card_played.value;

        //show info
        if( playing_player == 8 )
        {
            if( com[0].x2 != 0 )
                printf("com[0].x2 = %d\n", com[0].x2);
        }
        else
        {
            if( playing_player == 0 )
            {
                if( human.x2 != 0 )
                    printf("human.x2 = %d\n", human.x2);
            }
            else
            {
                if( com[playing_player].x2 != 0 )
                    printf("com[%ld].x2 = %d\n", playing_player, com[playing_player].x2);
            }
        }

        if( playing_player == 0 )
        {
            printf("player : card_number = %d, value = %d, type = %d, taken = %ld, sum = %d\n", card_played.card_number, card_played.value, card_played.type, card_played.taken, sum);
        }
        else
        {
            printf("playing_player %ld : card_number = %d, value = %d, type = %d, taken = %ld, sum = %d\n", playing_player, card_played.card_number, card_played.value, card_played.type, card_played.taken, sum);
        }



        //detect end
        if(( sum == 11 || sum == 22 || sum == 33 || sum == 44 || sum == 55 || sum == 66 ) && com_thinking == 0  )
        {

            game_show_card();
            game_show_coins();
            game_show_portrait();

            if( playing_player == 0 )
            {
                if( human_player_played == 1 )
                {
                    human.coin--;
                }
            }
            else
            {
                if( playing_player != 8 )
                    com[playing_player].coin--;
                else
                    com[0].coin--;
            }
            printf( "playing_player = %ld lose a coin\n", playing_player );

            if( playing_player != 0 )
            {
                if( playing_player == 1 )
                    end_msg_char = "com 1 perde un jeton";
                if( playing_player == 2 )
                    end_msg_char = "com 2 perde un jeton";
                if( playing_player == 3 )
                    end_msg_char = "com 3 perde un jeton";
                if( playing_player == 4 )
                    end_msg_char = "com 4 perde un jeton";
                if( playing_player == 5 )
                    end_msg_char = "com 5 perde un jeton";
                if( playing_player == 6 )
                    end_msg_char = "com 6 perde un jeton";
                if( playing_player == 7 )
                    end_msg_char = "com 7 perde un jeton";
                if( playing_player == 8 )
                    end_msg_char = "com 8 perde un jeton";
            }
            else
            {
                end_msg_char = "vous perdez un jeton";
            }

            //SDL_Delay(500);


            if(sum == 11)
            {
                N_apply_surface( 350, 370, lobo_11, screen, NULL);
                SDL_Flip(screen);
                SDL_Delay(1000);
            }
            if(sum == 22)
            {
                N_apply_surface( 350, 370, lobo_22, screen, NULL);
                SDL_Flip(screen);
                SDL_Delay(1000);
            }
            if(sum == 33)
            {
                N_apply_surface( 350, 370, lobo_33, screen, NULL);
                SDL_Flip(screen);
                SDL_Delay(1000);
            }
            if(sum == 44)
            {
                N_apply_surface( 350, 370, lobo_44, screen, NULL);
                SDL_Flip(screen);
                SDL_Delay(1000);
            }
            if(sum == 55)
            {
                N_apply_surface( 350, 370, lobo_55, screen, NULL);
                SDL_Flip(screen);
                SDL_Delay(1000);
            }
            if(sum == 66)
            {
                N_apply_surface( 350, 370, lobo_66, screen, NULL);
                SDL_Flip(screen);
                SDL_Delay(1000);
            }

            if(b_effect_on.pressed == 1 )
            {
                Mix_PlayChannel ( -1, effect_hey, 0 ) ;
            }
            N_apply_surface( 200, 130, lobo, screen, NULL);
            SDL_Flip(screen);
            SDL_Delay(1000);

            N_apply_surface(0,0,bg_game,screen,NULL);
            game_show_card();
            game_show_coins();
            game_show_portrait();
            game_show_sum();
            show_player_human_hand_cards();
            end_msg = message(end_msg_char, font_l );
            N_apply_surface( 100, 400, end_msg, screen, NULL );
            SDL_Flip(screen);
            SDL_Delay(1000);

            com_thinking_start = SDL_GetTicks();
            com_thinking = 0;
        }
        if( sum >= 77 )
        {
            game_show_card();
            game_show_coins();
            game_show_portrait();

            end = 1;
            if( playing_player == 0 )
            {
                human.coin--;
            }
            else
            {
                if( playing_player != 8 )
                    com[playing_player].coin--;
                else
                    com[0].coin--;
            }

            printf( "playing_player = %ld lose a coin\n", playing_player );

            if( playing_player != 0 )
            {
                if( playing_player == 1 )
                    end_msg_char = "com 1 perde un jeton";
                if( playing_player == 2 )
                    end_msg_char = "com 2 perde un jeton";
                if( playing_player == 3 )
                    end_msg_char = "com 3 perde un jeton";
                if( playing_player == 4 )
                    end_msg_char = "com 4 perde un jeton";
                if( playing_player == 5 )
                    end_msg_char = "com 5 perde un jeton";
                if( playing_player == 6 )
                    end_msg_char = "com 6 perde un jeton";
                if( playing_player == 7 )
                    end_msg_char = "com 7 perde un jeton";
                if( playing_player == 8 )
                    end_msg_char = "com 8 perde un jeton";
            }
            else
                end_msg_char = "vous perdez un jeton";

            //SDL_Delay(500);
            N_apply_surface( 350, 370, lobo_77, screen, NULL);
            SDL_Flip(screen);
            SDL_Delay(1000);

            if(b_effect_on.pressed == 1 )
            {
                Mix_PlayChannel ( -1, effect_hey, 0 ) ;
            }

            N_apply_surface( 200, 130, lobo, screen, NULL);
            SDL_Flip(screen);
            SDL_Delay(1000);

            N_apply_surface(0,0,bg_game,screen,NULL);
            game_show_card();
            game_show_coins();
            game_show_portrait();
            game_show_sum();
            show_player_human_hand_cards();
            end_msg = message(end_msg_char, font_l );
            N_apply_surface( 100, 400, end_msg, screen, NULL );
            SDL_Flip(screen);
            SDL_Delay(1000);

            com_thinking_start = SDL_GetTicks();
            com_thinking = 0;
        }

        //x2  ! it's not multiplied by 2 !
        //turn card will cancel x2's effect.  fixed
        //if player A is x2ed, if he play a x2 as the first card, he will be x2ed by his x2 card.  fixed
        //I don't know what should happen if, a player who is x2ed, play a x2, then, play a turn. who should be x2ed ? Now, the next player before turned is x2ed.
        if( card_played.type == 1 )
        {
            if(direction == 1)
            {
                if ( playing_player == 8 )
                {
                    if( human.x2 != 0 )
                    {
                        human.x2 = human.x2 + 2;
                    }
                    else
                        human.x2++;
                }
                else
                {
                    if( playing_player == 7 )
                    {
                        if(com[0].diff != 0 && com[0].diff != 4)
                        {
                            if( com[0].x2 != 0 )
                            {
                                com[0].x2 = com[0].x2 + 2;
                            }
                            else
                                com[0].x2++;
                        }
                        else
                        {
                            if( human.x2 != 0 )
                            {
                                human.x2 = human.x2 + 2;
                            }
                            else
                                human.x2++;
                        }
                    }
                    else
                    {
                        int for_x2 = playing_player + 1;
                        while( ( com[for_x2].diff == 4 || com[for_x2].diff == 0 ) && for_x2 < 8 )
                        {
                            for_x2++;
                        }
                        if(for_x2 < 8)
                        {
                            if( com[for_x2].x2 != 0 )
                            {
                                com[for_x2].x2 = com[for_x2].x2 + 2;
                            }
                            else
                                com[for_x2].x2++;
                        }
                        else
                        {
                            if( com[0].diff != 0 && com[0].diff != 4 )
                            {
                                if( com[0].x2 != 0 )
                                {
                                    com[0].x2 = com[0].x2 + 2;
                                }
                                else
                                    com[0].x2++;
                            }
                            else
                            {
                                if( human.x2 != 0 )
                                {
                                    human.x2 = human.x2 + 2;
                                }
                                else
                                    human.x2++;
                            }
                        }
                    }
                }
            }
            else
            {
                if ( playing_player == 1 )
                {
                    if( human.x2 != 0 )
                    {
                        human.x2 = human.x2 + 2;
                    }
                    else
                        human.x2++;
                }
                else
                {
                    if(playing_player == 0)
                    {
                        if( com[0].diff != 0 && com[0].diff != 4 )
                        {
                            if( com[0].x2 != 0 )
                            {
                                com[0].x2 = com[0].x2 + 2;
                            }
                            else
                                com[0].x2++;
                        }
                        else
                        {
                            int for_x2 = 7;
                            while( com[for_x2].diff == 4 || com[for_x2].diff == 0 )
                            {
                                for_x2--;
                            }
                            if( for_x2 != 0 )
                            {
                                if( com[for_x2].x2 != 0 )
                                {
                                    com[for_x2].x2 = com[for_x2].x2 + 2;
                                }
                                else
                                    com[for_x2].x2++;
                            }
                            else
                            {
                                if( human.x2 != 0 )
                                {
                                    human.x2 = human.x2 + 2;
                                }
                                else
                                    human.x2++;
                            }
                        }
                    }
                    else
                    {
                        int for_x2 = playing_player - 1;
                        while( com[for_x2].diff == 4 || com[for_x2].diff == 0 )
                        {
                            for_x2--;
                        }
                        if( for_x2 != 0 )
                        {
                            if( com[for_x2].x2 != 0 )
                            {
                                com[for_x2].x2 = com[for_x2].x2 + 2;
                            }
                            else
                                com[for_x2].x2++;
                        }
                        else
                        {
                            if( human.x2 != 0 )
                            {
                                human.x2 = human.x2 + 2;
                            }
                            else
                                human.x2++;
                        }
                    }
                }
            }
        }

        //turn
        if( card_played.type == 2 )
        {
            if( direction == 1 )
                direction = 2;
            else
                direction = 1;
        }

        //set taken = 2
        set_taken_equal_2 ();
    }


    //show
    game_show_sum();
    game_show_card( card_played );
    human_player_selecting();

    game_loser_detect();

    //find next player
    playing_player = game_find_next_player();
}

/** au debut du jeu, le joueur qui va jouer un debut va "flash" */
void game_new_turn_flash ()
{
    int flash;

    if(playing_player == 1)
    {
        if(com[1].diff == 0 || com[1].diff == 4)
        {
            playing_player++;
        }
    }
    if(playing_player == 2)
    {
        if(com[2].diff == 0 || com[2].diff == 4)
        {
            playing_player++;
        }
    }
    if(playing_player == 3)
    {
        if(com[3].diff == 0 || com[3].diff == 4)
        {
            playing_player++;
        }
    }
    if(playing_player == 4)
    {
        if(com[4].diff == 0 || com[4].diff == 4)
        {
            playing_player++;
        }
    }
    if(playing_player == 5)
    {
        if(com[5].diff == 0 || com[5].diff == 4)
        {
            playing_player++;
        }
    }
    if(playing_player == 6)
    {
        if(com[6].diff == 0 || com[6].diff == 4)
        {
            playing_player++;
        }
    }
    if(playing_player == 7)
    {
        if(com[7].diff == 0 || com[7].diff == 4)
        {
            playing_player++;
        }
    }
    if(playing_player == 8)
    {
        if(com[0].diff == 0 || com[0].diff == 4)
        {
            playing_player = 0;
        }
    }



    for (flash = 0; flash < 3; flash++)
    {
        N_apply_surface( 0, 0, bg_game, screen, NULL );
        game_show_coins();
        game_show_portrait();
        show_player_human_hand_cards();
        SDL_Flip(screen);
        SDL_Delay(500);
        if( playing_player == 0 )
        {
            N_apply_surface( 70, 580, portrait_light, screen, NULL);
        }

        if( playing_player == 1 )
        {
            N_apply_surface( 4, 410, portrait_light, screen, NULL);
        }

        if( playing_player == 2 )
        {
            N_apply_surface( 4, 220, portrait_light, screen, NULL);
        }

        if( playing_player == 3 )
        {
            N_apply_surface( 4, 30, portrait_light, screen, NULL);
        }

        if( playing_player == 4 )
        {
            N_apply_surface( 254, 30, portrait_light, screen, NULL);
        }

        if( playing_player == 5 )
        {
            N_apply_surface( 514, 30, portrait_light, screen, NULL);
        }

        if( playing_player == 6 )
        {
            N_apply_surface( 774, 30, portrait_light, screen, NULL);
        }

        if( playing_player == 7 )
        {
            N_apply_surface( 774, 410, portrait_light, screen, NULL);
        }
        SDL_Flip(screen);
        SDL_Delay(500);
    }
    anime = 0;
}

/** reinitier chaque tour */
void game_new_turn_init ()
{

    sum = 0;
    direction = 1;
    human_player_played = 0;

    end = 0;

    reset_deck (  );

    //set first play player
    playing_player = rand()%9;

    game_new_turn_flash();

    human_last_played_card = 56;
    com1_last_played_card = 56;
    com2_last_played_card = 56;
    com3_last_played_card = 56;
    com4_last_played_card = 56;
    com5_last_played_card = 56;
    com6_last_played_card = 56;
    com7_last_played_card = 56;
    com8_last_played_card = 56;

    human.x2 = 0;
    com[0].x2 = 0;
    com[1].x2 = 0;
    com[2].x2 = 0;
    com[3].x2 = 0;
    com[4].x2 = 0;
    com[5].x2 = 0;
    com[6].x2 = 0;
    com[7].x2 = 0;

    last_card.type = 0;
    last_player = 998;


}

/** initier avant le jeu */
void game_start_init()
{
    set_card (  );
    set_card_surface ( );

    reset_deck (  );
    game_start_draw (  );

    set_clips_card( );
    b_card1 = set_button_b_card( b_card1, 0 );
    b_card2 = set_button_b_card( b_card2, 1 );
    b_card3 = set_button_b_card( b_card3, 2 );
    b_card4 = set_button_b_card( b_card4, 3 );
    b_card5 = set_button_b_card( b_card5, 4 );
    b_card_surface = N_load_img("pic/card/b_card.png");

    bg_game = N_load_img( "pic/bg/game.png" );

    com_lose = N_load_img("pic/portrait/com_lose.png");
    portrait_light = N_load_img("pic/portrait/portrait_light.png");

    e1 = N_load_img("pic/portrait/e1.png");
    e2 = N_load_img("pic/portrait/e2.png");
    e3 = N_load_img("pic/portrait/e3.png");
    e4 = N_load_img("pic/portrait/e4.png");
    e5 = N_load_img("pic/portrait/e5.png");
    e6 = N_load_img("pic/portrait/e6.png");
    e7 = N_load_img("pic/portrait/e7.png");
    e8 = N_load_img("pic/portrait/e8.png");
    n1 = N_load_img("pic/portrait/n1.png");
    n2 = N_load_img("pic/portrait/n2.png");
    n3 = N_load_img("pic/portrait/n3.png");
    n4 = N_load_img("pic/portrait/n4.png");
    n5 = N_load_img("pic/portrait/n5.png");
    n6 = N_load_img("pic/portrait/n6.png");
    n7 = N_load_img("pic/portrait/n7.png");
    n8 = N_load_img("pic/portrait/n8.png");
    h1 = N_load_img("pic/portrait/h1.png");
    h2 = N_load_img("pic/portrait/h2.png");
    h3 = N_load_img("pic/portrait/h3.png");
    h4 = N_load_img("pic/portrait/h4.png");
    h5 = N_load_img("pic/portrait/h5.png");
    h6 = N_load_img("pic/portrait/h6.png");
    h7 = N_load_img("pic/portrait/h7.png");
    h8 = N_load_img("pic/portrait/h8.png");

    coins_3 = N_load_img("pic/other/coins_3.png");
    coins_2 = N_load_img("pic/other/coins_2.png");
    coins_1 = N_load_img("pic/other/coins_1.png");
    coins_0 = N_load_img("pic/other/coins_0.png");

    lobo = N_load_img("pic/other/lobo.png");
    lobo_11 = N_load_img("pic/other/11.png");
    lobo_22 = N_load_img("pic/other/22.png");
    lobo_33 = N_load_img("pic/other/33.png");
    lobo_44 = N_load_img("pic/other/44.png");
    lobo_55 = N_load_img("pic/other/55.png");
    lobo_66 = N_load_img("pic/other/66.png");
    lobo_77 = N_load_img("pic/other/77.png");

    human.x2 = 0;
    com[0].x2 = 0;
    com[1].x2 = 0;
    com[2].x2 = 0;
    com[3].x2 = 0;
    com[4].x2 = 0;
    com[5].x2 = 0;
    com[6].x2 = 0;
    com[7].x2 = 0;


    com[0].coin = 3;
    com[1].coin = 3;
    com[2].coin = 3;
    com[3].coin = 3;
    com[4].coin = 3;
    com[5].coin = 3;
    com[6].coin = 3;
    com[7].coin = 3;
    human.coin = 3;

    flame = -60;

    sum = 0;
    direction = 1;
    human_player_played = 0;

    end = 0;

    reset_deck (  );

    //set first play player
    playing_player = rand()%9;

    human_last_played_card = 56;
    com1_last_played_card = 56;
    com2_last_played_card = 56;
    com3_last_played_card = 56;
    com4_last_played_card = 56;
    com5_last_played_card = 56;
    com6_last_played_card = 56;
    com7_last_played_card = 56;
    com8_last_played_card = 56;

    human.x2 = 0;
    com[0].x2 = 0;
    com[1].x2 = 0;
    com[2].x2 = 0;
    com[3].x2 = 0;
    com[4].x2 = 0;
    com[5].x2 = 0;
    com[6].x2 = 0;
    com[7].x2 = 0;

    last_card.type = 0;
    last_player = 998;
}

/** fct clean up */
void game_end_free_card_and_portrait()
{
    SDL_FreeSurface( deck[0].sf );
    SDL_FreeSurface( deck[1].sf );
    SDL_FreeSurface( deck[2].sf );
    SDL_FreeSurface( deck[3].sf );
    SDL_FreeSurface( deck[4].sf );
    SDL_FreeSurface( deck[5].sf );
    SDL_FreeSurface( deck[6].sf );
    SDL_FreeSurface( deck[7].sf );
    SDL_FreeSurface( deck[8].sf );
    SDL_FreeSurface( deck[9].sf );
    SDL_FreeSurface( deck[10].sf );
    SDL_FreeSurface( deck[11].sf );
    SDL_FreeSurface( deck[12].sf );
    SDL_FreeSurface( deck[13].sf );
    SDL_FreeSurface( deck[14].sf );
    SDL_FreeSurface( deck[15].sf );
    SDL_FreeSurface( deck[16].sf );
    SDL_FreeSurface( deck[17].sf );
    SDL_FreeSurface( deck[18].sf );
    SDL_FreeSurface( deck[19].sf );
    SDL_FreeSurface( deck[20].sf );
    SDL_FreeSurface( deck[21].sf );
    SDL_FreeSurface( deck[22].sf );
    SDL_FreeSurface( deck[23].sf );
    SDL_FreeSurface( deck[24].sf );
    SDL_FreeSurface( deck[25].sf );
    SDL_FreeSurface( deck[26].sf );
    SDL_FreeSurface( deck[27].sf );
    SDL_FreeSurface( deck[28].sf );
    SDL_FreeSurface( deck[29].sf );
    SDL_FreeSurface( deck[30].sf );
    SDL_FreeSurface( deck[31].sf );
    SDL_FreeSurface( deck[32].sf );
    SDL_FreeSurface( deck[33].sf );
    SDL_FreeSurface( deck[34].sf );
    SDL_FreeSurface( deck[35].sf );
    SDL_FreeSurface( deck[36].sf );
    SDL_FreeSurface( deck[37].sf );
    SDL_FreeSurface( deck[38].sf );
    SDL_FreeSurface( deck[39].sf );
    SDL_FreeSurface( deck[40].sf );
    SDL_FreeSurface( deck[41].sf );
    SDL_FreeSurface( deck[42].sf );
    SDL_FreeSurface( deck[43].sf );
    SDL_FreeSurface( deck[44].sf );
    SDL_FreeSurface( deck[45].sf );
    SDL_FreeSurface( deck[46].sf );
    SDL_FreeSurface( deck[47].sf );
    SDL_FreeSurface( deck[48].sf );
    SDL_FreeSurface( deck[49].sf );
    SDL_FreeSurface( deck[50].sf );
    SDL_FreeSurface( deck[51].sf );
    SDL_FreeSurface( deck[52].sf );
    SDL_FreeSurface( deck[53].sf );
    SDL_FreeSurface( deck[54].sf );
    SDL_FreeSurface( deck[55].sf );

    SDL_FreeSurface(e1);
    SDL_FreeSurface(e2);
    SDL_FreeSurface(e3);
    SDL_FreeSurface(e4);
    SDL_FreeSurface(e5);
    SDL_FreeSurface(e6);
    SDL_FreeSurface(e7);
    SDL_FreeSurface(e8);
    SDL_FreeSurface(n1);
    SDL_FreeSurface(n2);
    SDL_FreeSurface(n3);
    SDL_FreeSurface(n4);
    SDL_FreeSurface(n5);
    SDL_FreeSurface(n6);
    SDL_FreeSurface(n7);
    SDL_FreeSurface(n8);
    SDL_FreeSurface(h1);
    SDL_FreeSurface(h2);
    SDL_FreeSurface(h3);
    SDL_FreeSurface(h4);
    SDL_FreeSurface(h5);
    SDL_FreeSurface(h6);
    SDL_FreeSurface(h7);
    SDL_FreeSurface(h8);
}

/** clean up */
void clean_up_game_over ()
{
    game_end_free_card_and_portrait();

    SDL_FreeSurface(b_card_surface);
    SDL_FreeSurface(bg_game);
    SDL_FreeSurface(sum_surface);
    SDL_FreeSurface(com_lose);
    SDL_FreeSurface(portrait_light);

    SDL_FreeSurface(coins_0);
    SDL_FreeSurface(coins_1);
    SDL_FreeSurface(coins_2);
    SDL_FreeSurface(coins_3);

    printf("clean_up_game_over\n");
}

/** fct enregistrer le statistique */
void game_end_save_stat ()
{
    int i;
    int nb = count_player();
    FILE *fp = fopen("player.dat", "w");
    char id[20],pw[20];
    strcpy(id, player.id);
    strcpy(pw, player.pw);

    for(i=0; i<nb; i++)
    {
        if(strcmp(id,list[i].id)==0)
        {
            if(strcmp(pw,list[i].pw)==0)
            {
                list[i] = player;
            }
        }
    }

    for(i=0; i<nb; i++)
    {
        fwrite(&list[i], sizeof(struct Player), 1, fp);
    }
    fclose(fp);
}

/** fct decider de : continue a jouer, le nouveau tour, fin du jeu; en fct de int end */
void game ()
{
    if( end == 0 )
    {
        N_apply_surface( 0, 0, bg_game, screen, NULL );
        show_player_human_hand_cards();
        game_show_coins ();
        game_show_portrait ();
        game_process ();
    }
    else
    {
        if( end == 1 )
        {
            printf("end : up to 77\n");
            SDL_Delay(1500);
            game_new_turn_init();
        }
        if( end == 2 )
        {
            switch_menu = 8;
            clean_up_game_over ();
            game_end_save_stat();
        }
    }

    N_apply_surface( 620, 330, card_back, screen, NULL );
}

/** anime pour donner des cartes */
void anime_give_card ()
{

    N_apply_surface( 0, 0, bg_game, screen, NULL );
    game_show_coins ();
    game_show_portrait ();
    N_apply_surface( 620, 330, card_back, screen, NULL );

    if( flame >= 0 && flame < 80 )
    {
        N_apply_surface( 620 - flame * 5, 330 + flame * 3.375, card_back, screen, NULL );
    }

    if( flame >= 81 && flame < 140 )
    {
        if( flame <= 110 )
            N_apply_surface( 620 - ( flame - 80 ) * 5, 330 + ( flame - 80 ) * 4.5, card_back, screen, NULL );
        else
            N_apply_surface( 620 - ( flame - 30 - 80 ) * 4.5 - 30 * 5, 330 + ( flame - 80 ) * 4.5, card_back, screen, NULL );
    }

    if( flame >= 141 && flame < 180 )
    {
        N_apply_surface( 620 - ( flame - 140 ) * 4, 330 + ( flame - 140 ) * 6.75, card_back, screen, NULL );
    }

    if( flame >= 181 && flame < 192 )
    {
        N_apply_surface( 620 - ( flame - 180 ) * 3.5, 330 + ( flame - 180 ) * 27, card_back, screen, NULL );
    }

    if( flame >= 193 && flame < 212 )
    {
        N_apply_surface( 620 + ( flame - 193 ) * 4.6, 330 + ( flame - 193 ) * 13.5, card_back, screen, NULL );
    }

    if( flame >= 80 )
    {
        N_apply_surface( 212, 600, card_back, screen, NULL);
    }
    if( flame >= 140 )
    {
        N_apply_surface( 337, 600, card_back, screen, NULL);
    }
    if( flame >= 180 )
    {
        N_apply_surface( 462, 600, card_back, screen, NULL);
    }
    if( flame >= 192 )
    {
        N_apply_surface( 587, 600, card_back, screen, NULL);
    }
    if( flame >= 212 )
    {
        N_apply_surface( 712, 600, card_back, screen, NULL);
    }

    flame++;

    if(flame == 272)
    {
        switch_menu = 12;
        anime = 2;
    }
}










