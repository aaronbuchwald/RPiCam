#include "camera.h"

using namespace std;

int capture_sequence(char* n1, char* n2, char* n3) {
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