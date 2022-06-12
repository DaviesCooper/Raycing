#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include "ray.h"

class Renderer
{
    private:
        unsigned int width;
        unsigned int height;

    public:

        /**
         * @brief Construct a new Renderer object with a canvas of size (size x size)
         * @param size 
         */
        explicit Renderer(int size);

        /**
         * @brief Construct a new Renderer object with a canvas of size (width x height)
         * @param width 
         * @param height 
         */
        explicit Renderer(int w, int h);

        /**
         * @brief Allows for piping this object to a stream
         * 
         * @param os The stream
         * @param r The renderer
         * @return std::ostream& 
         */
        friend std::ostream& operator<<(std::ostream &os, const Renderer& r); 

        // void Render();
};

#endif