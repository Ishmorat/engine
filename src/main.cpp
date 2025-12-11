#include <iostream>

#include "window/window.h"
#include "mesh/mesh.h"
#include "glm/gtc/matrix_transform.hpp"
#include "input/keyboard.h"
#include "input/mouse.h"

void process_input(Window& wnd);

int main() {
    Window wnd;

    ShaderProgram sp(cnst::simple_vs, cnst::simple_fs);

    std::vector<Vertex> vertices = {
        Vertex({ 0.5f,  0.5f, 0.0f}, { 1.0f, 0.0f, 0.0f }),  // Top Right
        Vertex({ 0.5f, -0.5f, 0.0f}, { 0.0f, 1.0f, 0.0f }),  // Bottom Right
        Vertex({-0.5f, -0.5f, 0.0f}, { 0.0f, 0.0f, 1.0f }),  // Bottom Left
        Vertex({-0.5f,  0.5f, 0.0f}, { 0.0f, 0.0f, 0.0f })   // Top Left
    };

    std::vector<GLuint> indices = {
        0, 1, 3,  // First Triangle
        1, 2, 3   // Second Triangle
    };

    Mesh mesh(vertices, indices);

    mat4 trans = mat4(1.0f);



    while (!wnd.should_close()) {                                                                           // Main loop 
        process_input(wnd);
                                                                                                            // Render 
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);                                                               // Clear the colorbuffer 
        glClear(GL_COLOR_BUFFER_BIT);

        trans = glm::rotate(trans, glm::radians((GLfloat)glfwGetTime() * 0.1f), glm::vec3(0.0, 0.0, 1.0));
        sp.set("trans", trans);

        mesh.draw(sp);
        wnd.swap_buffers();                                                                                 // Swap the screen buffers 
        
        glfwPollEvents();                                                                                   // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions 
    }

    return 0;
}

void process_input(Window& wnd) {
    auto& keyboard = Keyboard::get_instance();
    if (keyboard.is_pressed(GLFW_KEY_ESCAPE)) {
        wnd.set_should_close(true);
    }
}


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