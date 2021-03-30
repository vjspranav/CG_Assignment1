#include "main.h"
#include "timer.h"
#include "ball.h"
#include "player.h"

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Player player;
vector<pair<int, int>> walls;

float screen_zoom = 0.4, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;

Timer t60(1.0 / 60);

bool has_wall(int x, int y){
    for(int k=0;k<21;k++){ 
        if(walls[k].first == x && walls[k].second == y){ 
            return 1;
        }
    }
    return 0;
}

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    player.draw(VP);
    for(auto wall: walls){
        if(wall.first!=player.position.x || wall.second != player.position.y)
            Ball(wall.first, wall.second, COLOR_GREEN).draw(VP);
    }

    for(int i=0;i<6;i++){
        for(int j=0;j<8;j++){
            if(!has_wall(i, j))
                Ball(i, j, COLOR_RED).draw(VP);
        }
    }
    
}

void tick_input(GLFWwindow *window) {
    int w  = glfwGetKey(window, GLFW_KEY_W);
    int s  = glfwGetKey(window, GLFW_KEY_S);
    int a = glfwGetKey(window, GLFW_KEY_A);
    int d = glfwGetKey(window, GLFW_KEY_D);
    int new_x = player.position.x;
    int new_y = player.position.y;
    if (a) {
        new_x += 1;
    }
    if (d) {
        new_x -= 1;
    }
    if (w) {
        new_y += 1;
    }
    if (s) {
        new_y -= 1;
    }
    if (has_wall(new_x, new_y)){
        
            player.set_position(new_x, new_y);
        
    }
}

void tick_elements() {
    //camera_rotation_angle += 1;
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    player       = Player(0, 0, COLOR_BLUE);
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("../source/shaders/shader.vert", "../source/shaders/shader.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 600;
    int height = 600;
    camera_rotation_angle -= 90;
    window = initGLFW(width, height);
    
    walls.push_back(make_pair(0, 0));
    walls.push_back(make_pair(0, 1));
    walls.push_back(make_pair(1, 1));
    walls.push_back(make_pair(2, 1));
    walls.push_back(make_pair(2, 0));
    walls.push_back(make_pair(3, 0));
    walls.push_back(make_pair(4, 0));
    walls.push_back(make_pair(4, 1));
    walls.push_back(make_pair(4, 2));
    walls.push_back(make_pair(4, 3));
    walls.push_back(make_pair(3, 3));
    walls.push_back(make_pair(2, 3));
    walls.push_back(make_pair(2, 4));
    walls.push_back(make_pair(2, 5));
    walls.push_back(make_pair(3, 5));
    walls.push_back(make_pair(4, 5));
    walls.push_back(make_pair(5, 5));
    walls.push_back(make_pair(3, 6));
    walls.push_back(make_pair(3, 7));
    walls.push_back(make_pair(4, 7));
    walls.push_back(make_pair(5, 7));

    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
