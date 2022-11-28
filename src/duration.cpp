#include "duration.hpp"
#include "assert.h"

int duration::getduration()
{
    return time;
}

duration::duration() //Contructor
{
    time = 0;
    alarm = 0;
    alarmhasbeenset = false;
}

//I have chosen not to make a destructor since it isn't specified in the assignment, and when the object goes out of scope a built in destructor activates

duration::duration(int t)
{
    assert(time >= 0);
    time = t;
} //Constructor number two

bool duration::tick()
{
    time++;
    return checkAndUpdateAlarm();
}

bool duration::tick(int dt)
{
    assert(dt > 0);
    time += dt;
    return checkAndUpdateAlarm();
}
//The functions above both increase time, and then check if time >= alarm with the function checkAndUpdateAlarm

void duration::setalarm(int a)
{
    assert(a > time);
    alarm = a;
    alarmhasbeenset = true;
} //Sets an alarm

bool duration::checkAndUpdateAlarm()
{
    if(time >= alarm)
    {
        alarmhasbeenset = false;
        alarm = 0;
        return true;
    }
    return false;

   
} //Checks if time >= alarm and updates alarm if it is true