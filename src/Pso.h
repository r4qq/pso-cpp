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
        int epoch,
        int pointsAmount,
        int pointDimensionAmount,
        std::pair<int, int> bound,
        std::function<double(const std::vector<int>&)> funcToMinimize,
        int sameGradeEpochs,
        int consecutiveUnchangedEpochs):
          _epoch(epoch),
          _pointsAmount(pointsAmount),
          _pointDimensionAmount(pointDimensionAmount),
          _bound(bound),
          _funcToMinimize(std::move(funcToMinimize)),
          _sameGradeEpochs(sameGradeEpochs),
          _consecutiveUnchangedEpochs(consecutiveUnchangedEpochs) {
    }

        std::vector<std::vector<int>> _initPoints();
        bool updateGlobalBest(void);
        void optimize(void);

    private:
        int _epoch;
        int _pointsAmount;
        int _pointDimensionAmount;
        std::pair<int, int> _bound;
        std::function<double(const std::vector<int>&)> _funcToMinimize;
        int _sameGradeEpochs;
        std::vector<std::vector<int>> _points;
        std::vector<int> _globalBestPos;
        double _globalBestVal;
        int _consecutiveUnchangedEpochs;

};