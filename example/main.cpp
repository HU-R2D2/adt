#include  "../source/include/Acceleration.hpp"
#include  "../source/include/ADT_Base.hpp"
#include  "../source/include/Angle.hpp"
#include  "../source/include/Attitude.hpp"
#include  "../source/include/Box.hpp"
#include  "../source/include/Coordinate.hpp"
#include  "../source/include/Duration.hpp"
#include  "../source/include/Force.hpp"
#include  "../source/include/Length.hpp"
#include  "../source/include/Mass.hpp"
#include  "../source/include/Moment.hpp"
#include  "../source/include/Rotation.hpp"
#include  "../source/include/Speed.hpp"
#include  "../source/include/Translation.hpp"




#include <sstream>

using namespace std;

const long double PI = 3.141592653589793238L;


int main(int ac, char* av[]) {

            /**************** Length   ****************/

    cout << "****************Length**************** " << endl;

    //Creation of a length a b and c
    r2d2::Length a = 5 * r2d2::Length::METER;
    r2d2::Length b = 3 * r2d2::Length::METER;
    r2d2::Length c = 5 * r2d2::Length::CENTIMETER;
    r2d2::Length d = 0 * r2d2::Length::METER;
    r2d2::Length e = 0 * r2d2::Length::METER;



    // Operatorions
    r2d2::Length operatorion_a = a + b; // expected to return 8m
    r2d2::Length operatorion_b = a - b; // expected to return 2m
    r2d2::Length operatorion_c = a - c; // expected to return 4.95m
    r2d2::Length operatorion_d = a * 2 ; // expected to return 10m
    r2d2::Length operatorion_e = a / 3 ; // expected to return 1.6667m
    r2d2::Length operatorion_f = a *= 3 ; // expected to return 1.6667m


    //while d is not bigger than 10 meter add 1 meter
    while(d < (10* r2d2::Length::METER)){
        d += (1* r2d2::Length::METER);
    }
    //while d is not smaller than 0 meter negative 1 meter
    while( e >( 0* r2d2::Length::METER)){
        e-=(1* r2d2::Length::METER);
    }
    //get double value
    double value = a / r2d2::Length::METER;




    cout << " expected to return 8m        returns : "<< operatorion_a << endl;
    cout << " expected to return 2m        returns : "<< operatorion_b << endl;
    cout << " expected to return 4.95m     returns : "<< operatorion_c << endl;
    cout << " expected to return 10m       returns : "<< operatorion_d << endl;
    cout << " expected to return 1.66667m  returns : "<< operatorion_e << endl;
    cout << " expected to return 10m       returns : "<< d << endl;
    cout << " expected to return 0m        returns : "<< e << endl;
    cout << " expected to return 15m        returns : "<< operatorion_f << endl;
    cout << " expected to return 15       returns : "<< value << endl;


            /**************** Coordinate   ****************/

    cout << "****************Coordinate**************** " << endl;

    // Examples of using Coordinate's constructors.
    // Using the default constructor.
    r2d2::Coordinate coordinate1;
    r2d2::Coordinate coordinate2 {};



    // Parameter based construction.
    r2d2::Coordinate coordinate3 {2 * r2d2::Length::METER, 3
            * r2d2::Length::METER, 4 * r2d2::Length::METER};
    r2d2::Coordinate coordinate5 {10 * r2d2::Length::METER, 5
            * r2d2::Length::METER, 8 * r2d2::Length::METER};
    r2d2::Coordinate coordinate6 {8 * r2d2::Length::METER, 17
            * r2d2::Length::METER, 3 * r2d2::Length::METER};

    // Copy constructor.
    r2d2::Coordinate coordinate4 {coordinate3};

    // Determine whether 2 Coordinate's are within eachother's vicinity.

    r2d2::Translation translation = coordinate5
        -  coordinate6  ; // expected to return (2m, -12m, 5m)

    bool comparing = translation.get_length()
        < r2d2::Length::CENTIMETER; // expected to return true

    // Somewhere in a function body.
    // Writing the Coordinate to a stream.
    // Substituting the stream, you could instead save the data in a file,
    //print it to the screen, etc.
    std::stringstream stream{};
    stream << coordinate6;

    // Reading a coordinate from a stream.
    r2d2::Coordinate coordinate7;
    stream >> coordinate7;  // expected (8m, 17m, 3m)



    cout << " default constructor                                returns : "
        << coordinate1 << endl;
    cout << " default constructor                                returns : "
        << coordinate2 << endl;
    cout << " Parameter based construction                       returns : "
        << coordinate3 << endl;
    cout << " Copy constructor                                   returns : "
        << coordinate4 << endl;
    cout << " translation expected to return (2m, -12m, 5m)      returns : "
        << translation << endl;
    cout << " comparing expected to return true                  returns : "
        << comparing << endl;
    cout << " stream  expected to return (8m, 17m, 3m)           returns : "
        << coordinate7 << endl;


    /**************** Translation   ****************/

    cout << "****************Translation**************** " << endl;


    //creating translations
    r2d2::Translation translation_a(4 * r2d2::Length::METER, 5
            * r2d2::Length::METER, 6 * r2d2::Length::METER);
    r2d2::Translation translation_b(1 * r2d2::Length::METER, 2
            * r2d2::Length::METER, 3 * r2d2::Length::METER);

    r2d2::Length x = 5 * r2d2::Length::METER;
    r2d2::Length y = 6 * r2d2::Length::METER;
    r2d2::Length z = 3 * r2d2::Length::METER;
    r2d2::Translation translation_c(x,y,z); //expected (5m, 6m, 3m)

    cout << " translation_a   expected (4m, 5m, 6m)                   returns :"
        << translation_a << endl;
    cout << " translation_b   expected (1m, 2m, 3m)                   returns :"
        << translation_b << endl;
    cout << " translation_c   expected (5m, 6m, 3m)                   returns :"
        << translation_c << endl;


    /**************** Box   ****************/

    cout << "****************Box**************** " << endl;


    r2d2::Coordinate topright = r2d2::Coordinate(
        50.0  * r2d2::Length::METER,
        50.0  * r2d2::Length::METER,
        50.0  * r2d2::Length::METER
    );
    r2d2::Coordinate bottomleft = topright;
    r2d2::Box box (bottomleft, topright);


    r2d2::Translation translation_d (
        50.0  * r2d2::Length::METER,
        50.0  * r2d2::Length::METER,
        50.0  * r2d2::Length::METER
    );
    r2d2::Coordinate origin = topright;
    r2d2::Box rectangleBox (origin, translation_d);

    cout << "box   expected  (50m, 50m, 50m),(50m, 50m, 50m)     returns : "
        << box << endl;
    cout << "rectangleBox   expected (50m, 50m, 50m),(100m, 100m, 100m) returns:"
        << rectangleBox << endl;

    /**************** Acceleration   ****************/

    cout << "****************Acceleration**************** " << endl;

    r2d2::Speed speed = (5.0 * r2d2::Length::METER) / r2d2::Duration::SECOND;
    r2d2::Duration duration = 2.0 * r2d2::Duration::SECOND;
    r2d2::Acceleration acceleration = speed / duration; // expected 2.5m/s/s

    cout << " acceleration   expected 2.5m/s/s           returns : "
        << acceleration << endl;

    /**************** Moment   ****************/

    cout << "****************Moment**************** " << endl;
    /*r2d2::Clock::Duration clock_a = Clock::Duration(std::chrono::duration<long,
         std::micro>(10));
    r2d2::Moment m1;
    m1 = clock_a::get_moment(); */



    /**************** duration   ****************/

    cout << "****************duration**************** " << endl;


    //Creation of a duration
    r2d2::Duration duration_a(1 * r2d2::Duration::MINUTE);
    r2d2::Duration duration_b(2 * r2d2::Duration::SECOND);
    r2d2::Duration duration_c = 5 * r2d2::Duration::MILLISECOND;

    cout << " duration_a   expected 60secs                   returns : "
        << duration_a << endl;
    cout << " duration_b   expected 2secs                    returns : "
        << duration_b << endl;
    cout << " duration_c   expected 0.005secs                   returns : "
        << duration_c << endl;

    /**************** Speed   ****************/

    cout << "****************Speed**************** " << endl;



    //Creation of a length a b and c
    r2d2::Speed a1 = 5 * r2d2::Length::METER/r2d2::Duration::SECOND;
    r2d2::Speed b1 = 3 * r2d2::Length::METER/r2d2::Duration::SECOND;
    r2d2::Speed c1 = 5 * r2d2::Length::CENTIMETER/r2d2::Duration::SECOND;
    r2d2::Speed d1 = 0 * r2d2::Length::METER/r2d2::Duration::SECOND;
    r2d2::Speed e1 = 10 * r2d2::Length::METER/r2d2::Duration::SECOND;
    r2d2::Speed f1 = 10 * r2d2::Length::METER/r2d2::Duration::SECOND;
    r2d2::Speed g1 = 0 * r2d2::Length::METER/r2d2::Duration::SECOND;




    // Operatorions
    r2d2::Speed speed_a = a1 + b1; // expected to return 8m
    r2d2::Speed speed_b = a1 - b1; // expected to return 2m
    r2d2::Speed speed_c = a1 - c1; // expected to return 4.95m


    //while d is not bigger than 10 meter per sec add 1 meter per sec
    while(d1 < f1){
        d1 += (1* r2d2::Length::METER/r2d2::Duration::SECOND);
    }
    //while d is not smaller than 0 meter per sec negative 1 meter per sec
    while( e1 > g1 ){
        e1-=(1* r2d2::Length::METER/r2d2::Duration::SECOND);
    }
    //get double value
    double val = a1 / (r2d2::Length::METER/r2d2::Duration::SECOND);




    cout << " speed_a  expected to return 8m/s    returns : "<< speed_a << endl;
    cout << " speed_b  expected to return 2m/s    returns : "<< speed_b << endl;
    cout << " speed_c  expected to return 4.95m/s returns : "<< speed_c << endl;
    cout << " Speed d1 expected to return 10m/s   returns : "<< d1 << endl;
    cout << " Speed e1 expected to return 0m/s    returns : "<< e1 << endl;
    cout << " val expected to return 5m/s         returns : "<< val << endl;

    /**************** Angle   ****************/

    cout << "****************Angle**************** " << endl;

    //creating two angles
    r2d2::Angle angle_a;
    angle_a = PI * r2d2::Angle::rad;

    r2d2::Angle angle_b(2*PI * r2d2::Angle::rad);

    cout << " angle_a  expected to return 3.14159 rad       returns : "
        << angle_a << endl;
    cout << " angle_b  expected to return 6.28319 rad        returns : "
        << angle_b << endl;

    /**************** Mass   ****************/

    cout << "****************Mass**************** " << endl;

    //Creation of a length a b and c
    r2d2::Mass a2 = 5 * r2d2::Mass::KILOGRAM;
    r2d2::Mass b2 = 3 * r2d2::Mass::KILOGRAM;
    r2d2::Mass c2 = 5 *  r2d2::Mass::GRAM;
    r2d2::Mass d2 = 0 * r2d2::Mass::KILOGRAM;
    r2d2::Mass e2 = 10 *  r2d2::Mass::KILOGRAM;
    r2d2::Mass f2 = 10 * r2d2::Mass::KILOGRAM;
    r2d2::Mass g2 = 0 * r2d2::Mass::KILOGRAM;




    // Operatorions
    r2d2::Mass mass_a = a2 + b2; // expected to return 8kg
    r2d2::Mass mass_b = a2 - b2; // expected to return 2kg
    r2d2::Mass mass_c = a2 - c2; // expected to return 4.95kg


    //while d is not bigger than 10 meter per sec add 1 meter per sec
    while(d2 < f2){
        d2 += (1* r2d2::Mass::KILOGRAM);
    }
    //while d is not smaller than 0 meter per sec negative 1 meter per sec
    while( e2 > g2 ){
        e2-=(1* r2d2::Mass::KILOGRAM);
    }
    //get double value
    double valu = a2 / (r2d2::Mass::KILOGRAM);

    cout << " mass_a  expected to return 8kg      returns : "<< mass_a << endl;
    cout << " mass_b  expected to return 2kg      returns : "<< mass_b << endl;
    cout << " mass_c  expected to return 4.95kg   returns : "<< mass_c << endl;
    cout << " Speed d2 expected to return 10mkg   returns : "<< d2 << endl;
    cout << " Speed e2 expected to return 0kg     returns : "<< e2 << endl;
    cout << " valu expected to return 5kg         returns : "<< valu << endl;

    /**************** Force   ****************/

    cout << "****************Force**************** " << endl;

    //Creation of a Force
    r2d2::Force force_a = 2 * r2d2::Force::NEWTON;
    r2d2::Force force_b = 6 * r2d2::Force::NEWTON;

    //Get double value
    double vall = force_a / (r2d2::Force::NEWTON);

    cout << " Fprce d2 expected to return 2N      returns : "<< force_a << endl;
    cout << " Speed e2 expected to return 6N      returns : "<< force_b << endl;
    cout << " vall expected to return 2           returns : "<< vall << endl;



}
