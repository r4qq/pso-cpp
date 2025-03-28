#pragma once

#include <vector>
#include <functional>
#include <random>
#include <algorithm>

#include "Point.h"

class Pso
{
    public:
    Pso(
        float alpha,
        float beta,         
        int epoch,
        int pointsAmount,
        int pointDimensionAmount,
        std::pair<int, int> bound,
        std::function<double(const std::vector<int>&)> funcToMinimize,
        int sameGradeEpochs,
        int consecutiveUnchangedEpochs)
        :
          _alpha(alpha),
          _beta(beta),
          _epoch(epoch),
          _pointsAmount(pointsAmount),
          _pointDimensionAmount(pointDimensionAmount),
          _bound(bound),
          _funcToMinimize(std::move(funcToMinimize)),
          _sameGradeEpochs(sameGradeEpochs),
          _consecutiveUnchangedEpochs(consecutiveUnchangedEpochs),
          _randomEngine(std::random_device()()){
    
    }

        std::vector<Point> _initPoints(void);
        bool updateGlobalBest(void);
        void optimize(void);
        void returnBest(void);
        double getRandomDouble(double min, double max);

    private:
        float _alpha;
        float _beta;
        int _epoch;
        int _pointsAmount;
        int _pointDimensionAmount;
        std::pair<int, int> _bound;
        std::function<double(const std::vector<int>&)> _funcToMinimize;
        int _sameGradeEpochs;
        std::vector<Point> _points;
        std::vector<int> _globalBestPos;
        double _globalBestVal;
        int _consecutiveUnchangedEpochs;
        std::mt19937 _randomEngine;

};