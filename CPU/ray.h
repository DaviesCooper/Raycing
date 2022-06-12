#ifndef RAY_H
#define RAY_H

#include "vector.h"

class Ray
{
    public:
        Vector origin;
        Vector direction;
        /**
         * @brief Construct a new Ray object.
         * 
         * @param o The origin of the Ray.
         * @param d The direction of the Ray.
         */
        explicit Ray(Vector o, Vector d);

        /**
         * @brief Destroy the Renderer object
         */
        virtual ~Ray();
};

#endif