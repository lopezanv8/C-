#include<string>
using std::string;
#include <iostream>     
#include <iomanip>
#include <sstream>
using std::ostringstream;
#include <cmath>
#include <iostream>
using std::endl;
using std::cout;

#include "proj08_ball.h"
#include "proj08_twod.h"

/*
Project 08
Project focuses on the use of structs and struct methods

Ana Lopez 
Section 11
11/1/17
*/

/*
constructor
*/
Ball::Ball(double m, TwoD pos, TwoD speed, double r) {
    //reassigns values of mass, coords, velocity, and radius
    mass = m;
    coords = pos;
    velocity = speed;
    radius = r;
}

/*
return the struct in the format of a string
*/
string Ball::to_string() {
    ostringstream oss;
    oss << std::fixed << std::setprecision(2) << this->mass <<", "
    << this->coords.to_string() << ", " << this->velocity.to_string() 
    << ", " << this->radius;
    //when using this it points to mass, coords, and velocity respectively.
    return oss.str();
}

/*
ball is in contact with another ball when the distance between their two centers is equal to or less than the sum of the two radii of the balls. 
*/
bool Ball::contact_ball(Ball b) {
 
    double distance = sqrt(pow((this->coords.x - b.coords.x), 2) + pow((this->coords.y - b.coords.y), 2));
    //this points to the coords is the coords from ball already given. 
    //b.coords is the ball I initialized when passing in. 
    return ((this->radius + b.radius) >= distance);
}

/*
ball is in contact with the wall if the distance between the center and the wall is less than or equal to the balls radius. ball is contained in a box with left coordinate of (0,0) and extent of box is x and y.
*/
bool Ball::contact_wall(long xdim, long ydim) {
    if ((coords.x + radius) > xdim) { 
        return true;
    }
    else if((coords.x - radius) < 0) {
        return true;
    }
    else if((coords.y + radius) > ydim) {
        return true;
    }
    else if((coords.y - radius) < 0) {
        return true;
    }
    else { //when the ball does not make contact with the wall. 
        return false;
    }
}

/*
Updates the velocity of the ball after making contact with a wall. 
*/
TwoD Ball::update_velocity_wall(long xdim, long ydim) {
    TwoD result;
    //this points to the velocity already initialized in the struct. .x and .y      chooses which part of the velocity to use. 
    //multipes either x or y by -1 each time to show that either is changing        when contact is made
    
    if ((coords.x + radius) >= xdim) {
        result.x = this-> velocity.x * -1;
        result.y = this-> velocity.y;
        return result;
    }
    
    else if((coords.x - radius) <= 0) {
        result.x = this-> velocity.x * -1;
        result.y = this-> velocity.y;
        return result;
    }
    
    else if((coords.y + radius) >= ydim) {
        result.y = this-> velocity.y * -1;
        result.x = this-> velocity.x;
        return result;
    }
    
    else if((coords.y - radius) <= 0) {
        result.y = this-> velocity.y * -1;
        result.x = this-> velocity.x;
        return result;
    }

    //updates the value of the result each time
    
    return result;
}

/*
calculates the change in velocity when two balls are in contact. 
*/
TwoD Ball::update_velocity_ball(Ball b) {
    TwoD v_prime;
    
    //when using this it points to mass, coords, and velocity respectively.
    double t1 = ((2 * b.mass)/(this->mass + b.mass));
    TwoD t2 = this->velocity.diff(b.velocity); //vector difference
    TwoD t3 = this->coords.diff(b.coords); //vector difference
    double t4 = t2.dot_product(t3); //dot product of two vectors
    double t5 = t3.magnitude_squared(); //magnitue squared of vector difference
    double t6 = t4/t5; //divides result of dot product by magnitude square of       vector difference
    double t7 = t6 * t1; //multiplies previous result by mass change
    TwoD t8 = t3.mult(t7); //multiplies previous result by vector difference

    v_prime = this->velocity.diff(t8); //calculates the updated vector change in     velocity
    
    return v_prime;
}


