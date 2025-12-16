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
    ptr = glfwCreateWindow(width, height, cfg::title, nullptr, nullptr);                                    // Create a GLFWwindow object that we can use for GLFW's functions 
    if (ptr == nullptr) {
        terminate();
        throw std::runtime_error("Window not created");
    }
}

void Window::set_viewport() {
    glViewport(0, 0, width, height);                                                                        // Define the viewport dimensions 
}

void Window::set_sizecallback(GLFWframebuffersizefun callback) {
    glfwSetFramebufferSizeCallback(ptr, callback);
}

void Window::set_keycallback(GLFWkeyfun callback) {
    glfwSetKeyCallback(ptr, callback);
}

void Window::set_cursorcallback(GLFWcursorposfun callback) {
    glfwSetCursorPosCallback(ptr, callback);
}

void Window::set_buttoncallback(GLFWmousebuttonfun callback) {
    glfwSetMouseButtonCallback(ptr, callback);
}

void Window::set_scrollcallback(GLFWscrollfun callback) {
    glfwSetScrollCallback(ptr, callback);
}

void Window::set_callbacks() {
    set_keycallback(Keyboard::key_callback);
    set_cursorcallback(Mouse::cursor_callback);
    set_buttoncallback(Mouse::button_callback);
    set_scrollcallback(Mouse::scroll_callback);
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
    set_callbacks();
}

Window::Window(int width, int height) 
    : ptr   { nullptr }
    , width { width   }
    , height{ height  }
{
    init();
}

void Window::make_target() {
    glfwMakeContextCurrent(ptr);
}

void Window::set_should_close(bool val) {
    glfwSetWindowShouldClose(ptr, val);
}

bool Window::should_close() {
    return glfwWindowShouldClose(ptr);
}

void Window::swap_buffers() {
    glfwSwapBuffers(ptr);
}

int Window::get_width() {
    return width;
}

int Window::get_height() {
    return height;
}

Window::~Window() {
    terminate();
}