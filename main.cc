#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "rtweekend.h"
#include "sphere.h"

double hit_sphere(const point3& center, double radius, const ray& r){
    vec3 oc = center - r.origin();
    auto a = dot(r.direction(), r.direction());
    auto b = -2.0*dot(r.direction(), oc);
    auto c = dot(oc,oc) - radius*radius;
    auto disciminant = b*b -4*a*c;
    
    if (disciminant < 0) return -1.0;
    return (-b - std::sqrt(disciminant))/(2.0*a);
}


int main() {
    // World
    hittable_list world;
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    // Camera
    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth = 10;
    cam.render(world);
    
}