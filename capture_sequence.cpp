#include "camera.h"
#include <string.h>

int capture_sequence(std::string n1, std::string n2, std::string n3) {
    set_camera(1);
    capture(n1);
    set_camera(2);
    capture(n2);
    set_camera(c);
    capture(n3);

    return 0;
}

int main() {
    capture_sequence("1.jpg", "2.jpg", "3.jpg");
}