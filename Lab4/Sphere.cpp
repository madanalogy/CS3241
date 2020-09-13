//============================================================
// STUDENT NAME: Muhammad Ahmed bin Anwar Bahajjaj
// STUDENT NO.: A0140051A
// NUS EMAIL ADDRESS: Ahmed_Bahajjaj@u.nus.edu
// COMMENTS TO GRADER: -
// 
// ============================================================

#include <cmath>
#include "Sphere.h"

using namespace std;



bool Sphere::hit( const Ray &r, double tmin, double tmax, SurfaceHitRecord &rec ) const 
{
    //***********************************************
    //*********** WRITE YOUR CODE HERE **************
    //***********************************************
    Vector3d oc = r.origin() - center;
    double a = dot(r.direction(), r.direction());
    double b = 2 * dot(r.direction(), oc);
    double c = dot(oc, oc) - (radius * radius);
    double d = (b * b) - (4 * a * c);
    if (d <= 0) return false;

    double t1 = (-b + sqrt(d)) / (2 * a);
    double t2 = (-b - sqrt(d)) / (2 * a);
    double t = (t1 < t2) ? t1 : t2;
    if ( t < tmin || t > tmax ) return false;

    // We have a hit -- populate hit record.
    rec.t = t;
    rec.p = r.pointAtParam(t);
    rec.normal = r.pointAtParam(t) - center;
    rec.mat_ptr = matp;
    return true;
}



bool Sphere::shadowHit( const Ray &r, double tmin, double tmax ) const 
{
    //***********************************************
    //*********** WRITE YOUR CODE HERE **************
    //***********************************************

    Vector3d oc = r.origin() - center;
    double a = dot(r.direction(), r.direction());
    double b = 2 * dot(r.direction(), oc);
    double c = dot(oc, oc) - (radius * radius);
    double d = (b * b) - (4 * a * c);
    if (d <= 0) return false;

    double t1 = (-b + sqrt(d)) / (2 * a);
    double t2 = (-b - sqrt(d)) / (2 * a);
    double t = (t1 < t2) ? t1 : t2;
    return ( t >= tmin && t <= tmax );
}
