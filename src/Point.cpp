#include "Point.h"
#include <functional>

void Point::evalPoint(std::function<double(const std::vector<int>&)> funcToMinimize)
{
    auto currentGrade = funcToMinimize(_position);
    if (currentGrade < _grade) 
    {
        _personalBest = _position;
        _grade = currentGrade;
    }
}

void Point::updatePoisiton(void)
{
    for(auto i = 0; i < _position.size(); i++)
    {
        _position[i] += _velocityVector[i];
    }
}

void Point::updateVelocity(float alpha, float beta, float epsilon1, float epsilon2, std::vector<int> globalBest)
{
    for(auto i = 0; i < _velocityVector.size(); i++)
    {
        _velocityVector[i] += (alpha * epsilon1 * (globalBest[i] - _position[i]) + 
                               beta * epsilon2 * (_personalBest[i] - _position[i]));
    }
}