#include "Monitor.h"
#include <Logtra.h>

namespace Wintra {

    std::vector<Monitor> Wintra::Monitor::GetMonitors()
    {
        int count;
        GLFWmonitor** pMoni = glfwGetMonitors(&count);

        std::vector<Monitor> monitors(count);

        for (int i = 0; i < count; i++) {
            monitors[i] = pMoni[i];
        }

        return monitors;
    }

    Monitor Monitor::getPrimaryMonitor()
    {
        return Monitor(glfwGetPrimaryMonitor());
    }

    Monitor::Monitor() : monitor(nullptr)
    {
        
    }

    Monitor::Monitor(GLFWmonitor* monitor) : monitor(monitor)
    {
        
    }

    std::string Monitor::getName() const
    {
        return glfwGetMonitorName(monitor);
    }

    int* Monitor::getPos() const
    {
        int pos[2];
        glfwGetMonitorPos(monitor, &pos[0], &pos[1]);
        return pos;
    }
}