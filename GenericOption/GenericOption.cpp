#include "GenericOption.h"
#include <iostream>

using std::cout;
using std::cin;

// Constructor for the class
GenericOption::GenericOption(double strike, OptionType type, double cost) : m_strike(strike), m_type(type), m_cost(cost) {}

GenericOption::GenericOption(const GenericOption &p) : m_strike(p.m_strike), m_type(p.m_type), m_cost(p.m_cost) {}

GenericOption::~GenericOption() {}

// Assignment
GenericOption &GenericOption::operator=(const GenericOption &p) {
  if(this!=&p) {
    m_type = p.m_type;
    m_strike = p.m_strike;
    m_cost = p.m_cost;
  }
  return *this;
}

double GenericOption::valueAtExpiration(double underlyingAtExpiration) {
  double value=0.0;
  if(m_type == OptionType_Call) {
    if (m_strike<underlyingAtExpiration) {
      value = underlyingAtExpiration - m_strike;
    }
  } else {
    if (m_strike>underlyingAtExpiration) {
      value = m_strike - underlyingAtExpiration;
    }
  }
  return value;
}

double GenericOption::profitAtExpiration(double underlyingAtExpiration) {
  double profit=0.0;
  double finalValue = valueAtExpiration(underlyingAtExpiration);
  if (finalValue > m_cost) {
    profit = finalValue - m_cost;
  }
  return profit;
}

int main() {
  double strike, premium, price;
  char type;
  OptionType opt;
  cout<<"\nOPTION DETAILS";
  cout<<"\n---------------------------------------------\n";
  cout<<"Option Type [Put(p) or Call(c)]: ";
  cin>>type;
  cout<<"Option Strike Price (in $): ";
  cin>>strike;
  cout<<"Option Premium (in $): ";
  cin>>premium;
  if(type=='p' || type=='P') opt=OptionType_Put;
  else opt=OptionType_Call;
  cout<<"Option Spot Price (in $): ";
  cin>>price;
  GenericOption option(strike, opt, premium);
  double value = option.valueAtExpiration(price);
  double profit = option.profitAtExpiration(price);
  cout<<"----------------------------------------------\n";
  cout<<"Option Value at expiration = $"<<value;
  cout<<"\nOption Profit at expiration = $"<<profit<<"\n";
  return 0;
}
