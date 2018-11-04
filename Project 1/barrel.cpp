#include <cassert>
#include "barrel.h"

namespace data_structures_assignment_1 {
    // Add the barrel class implementation here.
    barrel::barrel() {
//       Postcondition: The object has been initialized as an empty barrel ready to hold liquid. The barrel has a
//                    height of 1 meter which can hold 100 liters.
        height = 1;
        capacity = height * 100;
        current_volume = 0;
    }

    barrel::barrel(double init_height, double init_water_liters, double init_olive_oil_liters) {
//        Precondition: The specified water amount and olive oil amount must fit in a barrel of the specified height.
//                   For every 1 meter of height a barrel has it can hold 100 liters.
        assert(init_height * 100 >= init_olive_oil_liters + init_water_liters);

//     Postcondition: The object has been initialized as a barrel with the specified height (in meters),
//                    water amount (in liters), and olive oil amount (in liters).
        height = init_height;
        water_liters = init_water_liters;
        olive_oil_liters = init_olive_oil_liters;
        capacity = height * 100;
        current_volume = water_liters + olive_oil_liters;
    }

    void barrel::add_water(double liters) {
//     Precondition: `liters` cannot be negative.
        assert(liters >= 0);

//     Postcondition: Adds `liters` number of liters of water to the barrel. If the resulting liquid quantity is
//                    more than the barrel can hold, the barrel overflows. First excess olive oil is lost (because it
//                    floats on the water), and then excess water is lost until the barrel is no longer overflowing.
        current_volume += liters;

        // Oil Overflowing
        if (current_volume > capacity) {
            while (olive_oil_liters > 0) {
                olive_oil_liters -= .01;
                current_volume -= .01;
            }
        }
        // Water Overflowing
        if (current_volume > capacity) {
            while (water_liters > 0) {
                water_liters -= .01;
                current_volume -= .01;
            }
        }
    }

    void barrel::add_olive_oil(double liters) {
        // Precondition: `liters` cannot be negative.
        assert(liters >= 0);

//     Postcondition: Adds `liters` number of liters of olive oil to the barrel. If the resulting liquid quantity is
//                    more than the barrel can hold, the barrel overflows. First excess olive oil is lost (because it
//                    floats on the water), and then excess water is lost until the barrel is no longer overflowing.
        current_volume += liters;

        // Oil Overflowing
        if (current_volume > capacity) {
            while (olive_oil_liters > 0) {
                olive_oil_liters -= .01;
                current_volume -= .01;
            }
        }
        // Water Overflowing
        if (current_volume > capacity) {
            while (water_liters > 0) {
                water_liters -= .01;
                current_volume -= .01;
            }
        }
    }

    void barrel::drain(double liters) {
//     Precondition: `liters` cannot be negative.
        assert(liters >= 0);


//      If `liters` is greater than the amount of liquid in the barrel, the barrel becomes empty.
        if (liters > current_volume) {
            current_volume = 0;
        }

//     Postcondition: Drains `liters` amount of liters of liquid from the barrel. The water drains before the olive
//                    does (because the oil floats on water and it is being drained from the bottom).
        // Water Drain
        double measure = current_volume - liters;
        while (current_volume > measure) {
            while (water_liters > 0) {
                water_liters -= .01;
                current_volume -= .01;
            }
        }

        while (current_volume > measure) {
            while (olive_oil_liters > 0) {
                olive_oil_liters -= .01;
                current_volume -= .01;
            }
        }


        // Oil Drain
        if (current_volume > 0) {
            while (olive_oil_liters > 0) {
                olive_oil_liters -= .01;
                current_volume -= .01;
            }
        }
    }

//     Postcondition: The return value is the amount of water currently in the barrel (in liters).
    double barrel::get_water_liters() const {
        return current_volume;
    }

//     Postcondition: The return value is the amount of olive oil currently in the barrel (in liters).
    double barrel::get_olive_oil_liters() const {
        return olive_oil_liters;
    }

//     Postcondition: The return value is the height of the barrel (in meters).
    double barrel::get_height() const {
        return height;
    }

//     Postcondition: The return value is the amount of empty space in the barrel (in liters).
    double barrel::get_empty_space() const {
        return capacity - current_volume;
    }

    double barrel::get_total_capacity() const {
        return capacity;
    }

//     Postcondition: The two barrels are stacked. A new barrel is return which has combined height, and therefore
//                    combined the capacity or the original two barrels. The new barrel has the combined liquid
//                    contents of the original two barrels.
     barrel barrel::operator+(const barrel &s1, const barrel &s2) {
        barrel NuBarrel;
        NuBarrel.height = s1.get_height() + s2.get_height();
        NuBarrel.current_volume = s1.current_volume + s2.current_volume;
        NuBarrel.olive_oil_liters = s1.olive_oil_liters + s2.olive_oil_liters;
        NuBarrel.water_liters = s1.water_liters + s2.water_liters;
        NuBarrel.capacity = s1.get_total_capacity()+s2.get_total_capacity();
        return NuBarrel;
    }











}
