#include <iostream>

#include "window/window.h"
#include "mesh/mesh.h"
#include "glm/gtc/matrix_transform.hpp"
#include "input/keyboard.h"
#include "input/mouse.h"
#include "camera/camera.h"
#include "timer/timer.h"

void process_input(Window& wnd, Camera& cam, GLfloat dt);

std::vector<Vertex> get_vertices();
std::vector<GLuint> get_indices();

int main() {
    std::cout << sizeof(float) << std::endl;

    Window wnd;
    ShaderProgram sp(cnst::simple_vs, cnst::simple_fs);

    auto vertices = get_vertices();
    auto indices = get_indices();

    Mesh mesh(vertices, indices);
    mat4 model = mat4(1.0f);

    Camera cam;

    glEnable(GL_DEPTH_TEST);

    Timer tmr;
    while (!wnd.should_close()) {                                                                           // Main loop 
        process_input(wnd, cam, tmr.get_dt());
                                                                                                            // Render 
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);                                                               // Clear the colorbuffer 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // model = glm::rotate(model, glm::radians(0.1f), glm::vec3(1.0, 1.0, 1.0));
        sp.set(uniform::model,      model);
        sp.set(uniform::projection, cam.get_proj(wnd.get_width(), wnd.get_height()));
        sp.set(uniform::view,       cam.get_view());

        mesh.draw(sp);
        wnd.swap_buffers();                                                                                 // Swap the screen buffers 
        
        glfwPollEvents();                                                                                   // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions 
    }

    return 0;
}

void process_input(Window& wnd, Camera& cam, GLfloat dt) {
    auto& keyboard = Keyboard::get_instance();
    if (keyboard.is_pressed(GLFW_KEY_ESCAPE)) {
        wnd.set_should_close(true);
    }

    cam.process_input(dt);
}

std::vector<Vertex> get_vertices() {
    std::vector<Vertex> vertices = {
        Vertex({ -0.5f,  0.5f, -0.5f  }, { 1.0f, 0.0f, 0.0f }),  // Top Left Near 
        Vertex({  0.5f,  0.5f, -0.5f  }, { 1.0f, 0.0f, 0.0f }),  // Top Right Near 
        Vertex({ -0.5f, -0.5f, -0.5f  }, { 1.0f, 0.0f, 0.0f }),  // Bottom Left Near 
        Vertex({  0.5f, -0.5f, -0.5f  }, { 1.0f, 0.0f, 0.0f }),  // Bottom Right Near 

        Vertex({ -0.5f,  0.5f,  0.5f  }, { 0.0f, 1.0f, 0.0f }),  // Top Left Far 
        Vertex({  0.5f,  0.5f,  0.5f  }, { 0.0f, 1.0f, 0.0f }),  // Top Right Far 
        Vertex({ -0.5f, -0.5f,  0.5f  }, { 0.0f, 1.0f, 0.0f }),  // Bottom Left Far 
        Vertex({  0.5f, -0.5f,  0.5f  }, { 0.0f, 1.0f, 0.0f }),  // Bottom Right Far 
    };
    return vertices;
}

std::vector<GLuint> get_indices() {
    std::vector<GLuint> indices = {
        0, 2, 1,    // Near 
        1, 2, 3,

        5, 7, 4,    // Far 
        4, 7, 6,

        4, 6, 0,    // Left 
        0, 6, 2,

        1, 3, 5,    // Right 
        5, 3, 7,

        4, 0, 5,    // Top 
        5, 0, 1,

        2, 6, 3,    // Bottom 
        3, 6, 7
    };
    return indices;
}


//std::vector<Vertex> vertices = {
//    Vertex({ 0.5f,  0.5f, 0.0f}, { 1.0f, 0.0f, 0.0f }),  // Top Right
//    Vertex({ 0.5f, -0.5f, 0.0f}, { 0.0f, 1.0f, 0.0f }),  // Bottom Right
//    Vertex({-0.5f, -0.5f, 0.0f}, { 0.0f, 0.0f, 1.0f }),  // Bottom Left
//    Vertex({-0.5f,  0.5f, 0.0f}, { 0.0f, 0.0f, 0.0f })   // Top Left
//};

//std::vector<GLuint> indices = {
//    0, 1, 3,  // First Triangle
//    1, 2, 3   // Second Triangle
//};


//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {                        // Is called whenever a key is pressed/released via GLFW 
//    std::cout << key << std::endl;
//    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, GL_TRUE);
//}

//GLfloat timeValue = glfwGetTime();
//GLfloat coef = (sin(timeValue) / 2) + 0.5;
//GLint vertexColorLocation = glGetUniformLocation(sp.get_id(), "coef");
//glUniform1f(vertexColorLocation, coef);
//sp.use();