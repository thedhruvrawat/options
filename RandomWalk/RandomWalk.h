#ifndef __CppOptions__RandomWalkGenerator__
#define __CppOptions__RandomWalkGenerator__

#include <vector>

class RandomWalkGenerator {
  public:
    RandomWalkGenerator(int size, double start, double step);
    RandomWalkGenerator(const RandomWalkGenerator &p);
    ~RandomWalkGenerator();

    RandomWalkGenerator &operator=(const RandomWalkGenerator &p);

    std::vector<double> generateWalk();
    double computeRandomStep(double currentPrice);

  private:
    int m_numSteps;
    double m_stepSize;
    double m_initialPrice;
};
#endif // !__CppOptions__RandomWalkGenerator__

