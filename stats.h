#ifndef STATS_H_INCLUDED
#define STATS_H_INCLUDED

typedef struct{
    int lives, points, level, fuel_quantity;
}STATS;

void InitStats(STATS *s);

void ShowHud(STATS s);

#endif // STATS_H_INCLUDED
