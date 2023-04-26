#include <stdio.h>

float max(float a, float b){
    if(a > b) return a;
    return b;
}

float min(float a, float b){
    if(a < b) return a;
    return b;
}

float calculateCollision(float rect1[4], float rect2[4]){
    float interval1Beg, interval1End, interval2Beg, interval2End;
    float collidingIntervalX, collidingIntervalY;
    // x colliding edge calculation
    interval1Beg = rect1[0];
    interval1End = rect1[0] + rect1[2];

    interval2Beg = rect2[0];
    interval2End = rect2[0] + rect2[2];

    if(interval1Beg > interval2End || interval2Beg > interval1End) // no collision
        return 0.0;
    collidingIntervalX = min(interval1End, interval2End) - max(interval1Beg, interval2Beg);

    // y colliding edge calculation
    interval1Beg = rect1[1];
    interval1End = rect1[1] + rect1[3];

    interval2Beg = rect2[1];
    interval2End = rect2[1] + rect2[3];

    if(interval1Beg > interval2End || interval2Beg > interval1End) // no collision
        return 0.0;
    collidingIntervalY = min(interval1End, interval2End) - max(interval1Beg, interval2Beg);

    return collidingIntervalX * collidingIntervalY;
}

int main(){

    float rect1[4], rect2[4];

    printf("Enter first rectangle\n");
    scanf("%f %f %f %f", &rect1[0], &rect1[1], &rect1[2], &rect1[3]);
    printf("Enter second rectangle\n");
    scanf("%f %f %f %f", &rect2[0], &rect2[1], &rect2[2], &rect2[3]);

    printf("Colliding area: %g", calculateCollision(rect1, rect2));

    return 0;
}