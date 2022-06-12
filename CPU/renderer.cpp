#include "renderer.h"
#include "sphere.h"

Renderer::Renderer(int size) : Renderer::Renderer(size, size)
{
}

Renderer::Renderer(int w, int h) : width(w), height(h)
{
}

// void Render(){

//     // Sphere sphere = Sphere(Vector(w/2, h/2, 50), 20);
//     // for(int y = 0; y < h; y++){
//     //     for(int x = 0; x < w; x++){
//     //         Ray ray = Ray(Vector(x, y, 0), Vector(0, 0, 1));
//     //         double t = 2000;

//     //         if(sphere.Intersects(ray, t)) {
                
//     //         }
//     //     }
//     // }
// }

std::ostream& operator <<(std::ostream& os, const Renderer& r)
{
    os << "(" << r.width << ", " << r.height << ")" << std::endl;
    return os;
}