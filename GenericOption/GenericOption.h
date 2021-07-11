#ifndef __CppOptions__GenericOption__
#define __CppOptions__GenericOption__

#include <stdio.h>

// Option types based on direction: Call or Put
enum OptionType {
  OptionType_Call,
  OptionType_Put
};

// Class to represent a generic option

class GenericOption {
  public:
    GenericOption(double strike, OptionType type, double cost);
    GenericOption(const GenericOption &p);
    ~GenericOption();
    GenericOption &operator=(const GenericOption &p);

    double valueAtExpiration(double underlyingAtExpiration);
    double profitAtExpiration(double underlyingAtExpiration);

  private:
    double m_strike;
    OptionType m_type;
    double m_cost;
};
#endif /* defined(__CppOptions__GenericOption__) */
