
#include "concept_using_concept.hpp"
#include <iostream>

// ==========================
// SimpleData implementation
// ==========================

SimpleData::SimpleData(int v)
    : value_(v) {}

int SimpleData::value() const { return value_; }

// ======================================================
// Implementtion of DataRetrieverConcept-compliant classes
// ======================================================

SimpleData TwoRetriever::GetData() { return SimpleData(2); }

SimpleData FourRetriever::GetData() { return SimpleData(4); }



int main() {
  std::cout << "2 x 2 = "
            << demonstrate<MultiplyByTwoProcessor<TwoRetriever>>().value()
            << std::endl;
  std::cout << "2 / 2 = "
            << demonstrate<DivideByTwoProcessor<TwoRetriever>>().value()
            << std::endl;
  std::cout << "4 x 2 = "
            << demonstrate<MultiplyByTwoProcessor<FourRetriever>>().value()
            << std::endl;
  std::cout << "4 / 2 = "
            << demonstrate<DivideByTwoProcessor<FourRetriever>>().value()
            << std::endl;
  return 0;
}
