#include <raylib.h>

class Apple{
    private:
        Vector2 positionApple = {300 , 420};
        Vector2 sizeApple = {20, 20};
        Rectangle recApple;
    public:
        Rectangle getRec();
        void draw(Vector2 positionApple);
        Vector2 update();
        Vector2 getPositionApple();
};

