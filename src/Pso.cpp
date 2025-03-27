#pragma once

#include "Pso.h"
#include "Point.h"
#include <random>
#include <utility>
#include <vector>

std::vector<std::vector<int>> Pso::_initPoints()
{
    std::random_device random;
    std::mt19937 gen(random());
    std::uniform_int_distribution<> distrPoints(_bound.first, _bound.second);
    std::uniform_real_distribution<> distrVal(-1, 1);
    
    std::vector<std::vector<int>> points;
    
    for (auto i  = 0; i < _pointsAmount; i++) 
    {
        std::vector<int> startPos;
        std::vector<double> velocityVector;
        for (auto j = 0; j < _pointDimensionAmount; j++) 
        {
            int dimVal = distrPoints(gen);
            startPos.push_back(dimVal);
            double velVal = distrVal(gen);
            velocityVector.push_back(velVal);
            auto point = Point(startPos, velocityVector);
            point.evalPoint();
            points.push_back(point);
        }
    }
    return points;
}