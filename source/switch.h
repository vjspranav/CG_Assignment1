#include "main.h"

#ifndef SWITCH_H
#define SWITCH_H 


class Switch {
public:
    Switch() {}
    Switch(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
private:
    VAO *object;
};

#endif // SWITCH_H
