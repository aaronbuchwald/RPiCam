#ifndef _IMAGE_H
#define _IMAGE_H

#include <cstring>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <iostream>

class Image {
    public:
        Image();
        Image(std::string image_name, int cam_n, int r, float timeDiff);
        std::string get_name();
        int get_cam();
        int get_round();
        float get_time_difference();
        int get_number();
    private:
        std::string name;
        int round, cam_number;
        float time_difference;
        int number_in_sequence;
};

#endif