#include "hittable_list.h"

// Check for hits in all of the hittable objects in the scene
// It is convenient to check for hits in an interval of t
// The hit record stores the information of the closest item
bool Hittable_list::hit(Ray &r, float t_min, float t_max, hit_record &rec) const
{
        hit_record temp_rec;
        bool hit_anything = false;
        double closest_so_far = t_max;
        for (int i = 0; i < list_size; i++)
        {
                if (list[i]->hit(r, t_min, closest_so_far, temp_rec))
                {
                        hit_anything = true;
                        closest_so_far = temp_rec.t;
                        rec = temp_rec;
                }
        }
        return hit_anything;
}
