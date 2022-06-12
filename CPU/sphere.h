#ifndef SPHERE_H
#define SPHERE_H

#include "vector.h"
#include "ray.h"
#include "cmath.h"

struct Sphere{
    public:
        Vector center;
        double radius;

        Sphere()
        {
            center = Vector(0,0,0);
            radius = 1;
        }

        explicit Sphere(Vector c, double r){
            center = c;
            radius = r;
        }

        bool Intersects(Ray ray, double &t){
            Vector o = ray.origin;
            Vector d = ray.direction;
            
            // Geometric Solution

            // The vector from the rays origin to the center of the sphere
            Vector RtoC = center - o;

            // Projecting RtoC onto the direction vector will produce t_ca
            // which is the length of the origin to the point perpendicular to
            // the center of the sphere
            double t_ca = RtoC.dot(d);

            // A t_ca of less than 0 indicates we intersected behind the camera
            // which sohuldn't render.
            if(t_ca < 0)
                return false;

            // Use the pythagorean equation to see how far the perpendicular point
            // of the ray is from the center of the sphere.
            // We keep it squared because we only care about comparing it against
            // the radius, which we also square later.
            double distFromCenterSquared = RtoC.dot(RtoC) - t_ca * t_ca;

            // If the dist from the center is greater than our radius then we didn't intersect
            // the sphere.
            if(distFromCenterSquared > radius * radius)
                return false;


            // Now that we know the distance the poitn point perpendicular to C from O is,
            // We can use this to calculate t_hc using the pythagorean again.
            double c = L.dot(L) - radius*radius;
            double disc = t_ca*t_ca-4*c;

            if(disc < 0)
                return false;

            disc = sqrt(disc);
            double t0 = -t_ca-disc;
            double t1 = -t_ca+disc;

            t = (t0 < t1) ? t0 : t1;
            return true;
        }
};

#endif