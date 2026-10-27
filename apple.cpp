#include "apple.hpp"

Rectangle Apple::getRec(){
    recApple = {positionApple.x, positionApple.y, sizeApple.x, sizeApple.y};
    return recApple;
}
void Apple::draw(Vector2 positionApple){
    DrawRectangleV(positionApple,  sizeApple, RED);
}
Vector2 Apple::update(){
    Vector2 positionAppleRand = {float(GetRandomValue(0, 29)), float(GetRandomValue(0, 29))};
    positionApple.x = positionAppleRand.x * 20;
    positionApple.y = positionAppleRand.y * 20;
    return positionApple;
}
Vector2 Apple::getPositionApple(){
    return positionApple;
}