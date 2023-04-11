#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods); //2.6 deo

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{

    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------nullptr isto sto i NULL
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate(); //deinicijaliyacija glfw
        return -1;
    }
    glfwMakeContextCurrent(window); // kazemo da zelimo da crtamo u kreiranom prozoru
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); //treba da kazemo dim unutar prozora
    // na kojima renderujemo
    //u glfw registrujemo callback koji ce biti pozvan kada se neko dugme pritisne
    //glfwSetKeyCallback(window, key_callback); // u 2.6 uradjeno
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) // ucitavanje svih OpenGL funkcija
        // arg je funkcija koja nalazi opengl na sistemu, ako ne uspe vraca nulu
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    // glfwSetKeyCallback(window, callback) -poziva se kada je pretisnuto neko dugme
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window)) // dokle god prozor nije receno da se zatvori
    {
        // input
        // -----
        processInput(window); //azuriranje

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window); // za renderovanje
        glfwPollEvents(); // kupimo akcije koje su se desile // gledamo sta se desilo
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //ispitujemo da li je esc pritisnuto
        glfwSetWindowShouldClose(window, true); // u sledecoj iteraciji prozor treba da se zatvori
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height); // prva dva broja je pozicija donjeg levog ugla
}