#pragma once

#include <functional>
#include <vector>

class Point 
{
    public:
        Point(std::vector<int> position, std::vector<double> velocityVector);
        void updateVelocity(float alpha, float beta, std::vector<int> globalBest);
        void updatePoisiton(void);
        void evalPoint(std::function<double(const std::vector<int>&)> funcToMinimize);

    private:
        std::vector<int> _position;
        std::vector<double> _velocityVector;
        std::vector<int> _personalBest;
        std::vector<double> _grade;
};