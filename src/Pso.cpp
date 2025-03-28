#include "Pso.h"
#include "Point.h"
#include <iostream>
#include <ostream>
#include <random>
#include <utility>
#include <vector>
#include <algorithm>

std::vector<Point> Pso::_initPoints(void)
{
    std::random_device random;
    std::mt19937 gen(random());
    std::uniform_int_distribution<> distrPoints(_bound.first, _bound.second);

    std::uniform_real_distribution<> distrVal(-1, 1);
    
    std::vector<Point> points;
    
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
            point.evalPoint(_funcToMinimize);
            points.push_back(point);
        }
    }

    

    return points;
}

bool Pso::updateGlobalBest(void)
{
        auto tempPoint = *min_element(_points.begin(), _points.end(),
            [](const Point& a, const Point& b)
            {
                return a._grade < b._grade;
            });

        if (tempPoint._grade < _globalBestVal)
        {
            _globalBestPos = tempPoint._position;
            _globalBestVal = tempPoint._grade;
            return true;
        } 
        return false;
}

void Pso::optimize(void)
{
    for(int i = 0; i < _epoch; i++)
    {
        auto optimized = updateGlobalBest();
        for(auto& point : _points)
        {
            const auto epsilon1 = getRandomDouble(-1.0, 1.0); 
            const auto epsilon2 = getRandomDouble(-1.0, 1.0);

            point.updateVelocity(_alpha, _beta, epsilon1, epsilon2, _globalBestPos);
            point.updatePoisiton();
            point.evalPoint(_funcToMinimize);
        }

        if (optimized) 
        {
            _consecutiveUnchangedEpochs = 0;
        }
        else 
        {
            _consecutiveUnchangedEpochs += 1;
            if (_consecutiveUnchangedEpochs >= _sameGradeEpochs) 
            {
                break;
            }
        }
    }
}

void Pso::returnBest(void)
{
    std::cout << "Best position" << std::endl;
    for(const auto& e : _globalBestPos)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl << _globalBestVal << std::endl;
}


double Pso::getRandomDouble(double min, double max) 
{
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(_randomEngine);
}