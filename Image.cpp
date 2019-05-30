#include "Image.h"

Image::Image() {

}

Image::Image(std::string image_name, int cam_n, int r, float timeDiff) {
    name = image_name;
    cam_number = cam_n;
    round = r;
    time_difference = timeDiff;
    number_in_sequence = (round - 1) * 3 + cam_number;
}

std::string Image::get_name() {
    return name;
}

int Image::get_cam() {
    return cam_number;
}

int Image::get_round() {
    return round;
}

float Image::get_time_difference() {
    return time_difference;
}

int Image::get_number() {
    return number_in_sequence;
}