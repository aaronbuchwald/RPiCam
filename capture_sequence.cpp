#include <string.h>
#include <string>
#include "IIC.h"
#include "camera.h"


int capture_sequence(std::string n1, std::string n2, std::string n3) {
    set_camera(1);
    capture(n1);
    set_camera(2);
    capture(n2);
    set_camera(3);
    capture(n3);

    return 0;
}

int main() {
    capture_sequence("one", "two", "three");

    return 0;
}