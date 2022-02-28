#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include "rtweekend.h"

class material;

struct hit_record{
   point3 p;  // 交点
   vec3 normal; //法向量
   shared_ptr<material> mat_ptr;
   double t; //distance 
   bool front_face;

   inline void set_face_normal(const ray& r,const vec3& outward_normal){
      front_face=dot(r.direction(),outward_normal)<0;
      normal=front_face? outward_normal : -outward_normal;      //保证法向量与入射向量方向相反
   }
};

class hittable{
   public:
     virtual bool hit(const ray& r,double t_min,double t_max,hit_record& rec) const =0;     
};

#endif