#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

typedef struct {
    int posx, posy;
    float speed;
    int fuel_quantity;
    char teste;

}PLAYER;

void InitPlayer(PLAYER *p);

void DrawPlayer(PLAYER p);

void UpdatePlayer(PLAYER *P);




#endif // PLAYER_H_INCLUDED
