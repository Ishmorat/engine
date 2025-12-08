#include "window.h"
#include <iostream>

void Window::init_glfw() {
    glfwInit();                                                                                             // Init GLFW 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                                                          // Set all the required options for GLFW 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

void Window::init_glew() {
    glewExperimental = GL_TRUE;                                                                             // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions 
    if (glewInit() != GLEW_OK) {                                                                            // Initialize GLEW to setup the OpenGL Function pointers 
        terminate();
        throw std::runtime_error("GLEW not initialize");
    }
}

void Window::create() {
    ptr = glfwCreateWindow(cfg::width, cfg::height, cfg::title, nullptr, nullptr);                          // Create a GLFWwindow object that we can use for GLFW's functions 
    if (ptr == nullptr) {
        terminate();
        throw std::runtime_error("Window not created");
    }
}

void Window::set_viewport() {
    int width, height;                                                                                      // Define the viewport dimensions 
    glfwGetFramebufferSize(ptr, &width, &height);
    glViewport(0, 0, width, height);
}

void Window::terminate() {
    glfwTerminate();                                                                                        // Terminate GLFW, clearing any resources allocated by GLFW 
}

void Window::init() {
    init_glfw();
    create();
    make_target();
    init_glew();
    set_viewport();
}

Window::Window() {
    init();
}

void Window::make_target() {
    glfwMakeContextCurrent(ptr);
}

bool Window::should_close() {
    return glfwWindowShouldClose(ptr);
}

void Window::set_keycallback(GLFWkeyfun callback) {
    glfwSetKeyCallback(ptr, callback);
}

void Window::swap_buffers() {
    glfwSwapBuffers(ptr);
}

Window::~Window() {
    terminate();
}