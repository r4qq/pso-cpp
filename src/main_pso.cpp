#include "Pso.h"
#include <cmath>
#include <utility>
#include <vector>

constexpr int EPOCH = 50;
constexpr int POINTSAMOUNT = 2000;
constexpr std::pair<int, int> BOUND = {-10, 10};
constexpr float ALPHA = 0.5;
constexpr float BETA = 0.3; 

int main()
{
    auto func = [](const std::vector<int>& vars) -> double 
    {
        double x = vars[0];
        double y = vars[1];
        return std::sin(std::pow(x, 4)) - std::cos(std::pow(y, 2)) + 6 * (std::pow(x, 2)) * (std::pow(y, 2));
    };

    auto pso = new Pso(ALPHA, BETA, EPOCH, POINTSAMOUNT, 2, BOUND, func, 10, 0);
    pso->optimize();
    pso->returnBest();
    return 0;
}