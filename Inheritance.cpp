#include <iostream>

using namespace std;

class vehicle{
protected:
    int fuel;
    int maxSpeed;
    int position;
    int acceleration;
    int velocity;
public:
    vehicle() : fuel(100), maxSpeed(100), position(0), acceleration(10), velocity(0) {}
    int getFuel(){return fuel;}
    int getMaxSpeed(){return maxSpeed;}
    int getPosition(){return position;}
    int getAcceleration(){return acceleration;}
    int getVelocity(){return velocity;}

    void move(){
        
        velocity < maxSpeed ? velocity += acceleration : velocity += 0;
        if (fuel > 0) {
            position += velocity;
            fuel -= 5;
        } 
    }

    void refuel(){
        velocity = 0;
        fuel = 100;
    }

    virtual void print(){
        cout << "car is at position: " << position << endl;
    }
};

class raceCar : public vehicle{
public:
    raceCar() {acceleration = 25; maxSpeed = 200;}
    void boost(){
        position += 50;
    }

    void print(){
        cout << "racecar is at position: " << position << endl;
    }
};

int main(){
    raceCar car;
    car.move();
    car.move();
    car.move();
    //car.boost();
    car.print();
}