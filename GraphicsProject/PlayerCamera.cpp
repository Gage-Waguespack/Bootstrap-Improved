#include "PlayerCamera.h"
#include "GLFW/glfw3.h"

void PlayerCamera::onUpdate(float deltaTime)
{
    GLFWwindow* window = glfwGetCurrentContext();

    int keyForward = GLFW_KEY_W;
    int keyFast = GLFW_KEY_LEFT_SHIFT;
    int keyBack = GLFW_KEY_S;
    int keyLeft = GLFW_KEY_A;
    int keyRight = GLFW_KEY_D;
    int keyUp = GLFW_KEY_SPACE;
    int keyDown = GLFW_KEY_Q;

    //Get the direction vectors
    glm::vec3 right = getTransform()->getRight();
    glm::vec3 up = getTransform()->getUp();
    glm::vec3 forward = getTransform()->getForward();

    //Check input
    if (glfwGetKey(window, keyForward)) {
        if (glfwGetKey(window, keyFast)) {
            //Move forward
            getTransform()->translate(forward * (m_moveSpeed * 2) * (float)deltaTime);
        }
        //Move forward
        getTransform()->translate(forward * m_moveSpeed * (float)deltaTime);
    }
    if (glfwGetKey(window, keyBack)) {
        if (glfwGetKey(window, keyFast)) {
            //Move forward
            getTransform()->translate(-forward * (m_moveSpeed * 2) * (float)deltaTime);
        }
        //Move back
        getTransform()->translate(-forward * m_moveSpeed * (float)deltaTime);
    }
    if (glfwGetKey(window, keyLeft)) {
        if (glfwGetKey(window, keyFast)) {
            //Move forward
            getTransform()->translate(-right * (m_moveSpeed * 2) * (float)deltaTime);
        }
        //Move left
        getTransform()->translate(-right * m_moveSpeed * (float)deltaTime);
    }
    if (glfwGetKey(window, keyRight)) {
        if (glfwGetKey(window, keyFast)) {
            //Move forward
            getTransform()->translate(right * (m_moveSpeed * 2) * (float)deltaTime);
        }
        //Move right
        getTransform()->translate(right * m_moveSpeed * (float)deltaTime);
    }
    if (glfwGetKey(window, keyUp)) {
        if (glfwGetKey(window, keyFast)) {
            //Move forward
            getTransform()->translate(up * (m_moveSpeed * 2) * (float)deltaTime);
        }
        //Move up
        getTransform()->translate(up * m_moveSpeed * (float)deltaTime);
    }
    if (glfwGetKey(window, keyDown)) {
        if (glfwGetKey(window, keyFast)) {
            //Move forward
            getTransform()->translate(-up * (m_moveSpeed * 2) * (float)deltaTime);
        }
        //Move down
        getTransform()->translate(-up * m_moveSpeed * (float)deltaTime);
    }

    //Get current mouse coordinates
    glfwGetCursorPos(window, &m_currentMouseX, &m_currentMouseY);

    //Turn the camera based on the change in mouse position (delta mouse)
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_2)) {
        float pitch = m_lookSpeed * (m_currentMouseY - m_previousMouseY);
        float yaw = m_lookSpeed * (m_currentMouseX - m_previousMouseX);
        getTransform()->rotate(-pitch, yaw, 0.0f);
    }
    //Store previous mouse coordinates
    m_previousMouseX = m_currentMouseX;
    m_previousMouseY = m_currentMouseY;
}
