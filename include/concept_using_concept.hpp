
#pragma once

#include <concepts>
#include <memory>

// Simple data container used by retrievers and processors.

class SimpleData {
  int value_;

public:
  SimpleData(int v);
  int value() const;
};

// ==========================
// Concepts
// ==========================

// DataRetrieverConcept requires:
//      GetData() -> SimpleData
template <typename T>
concept DataRetrieverConcept = requires(T t) {
  { t.GetData() } -> std::same_as<SimpleData>;
};

// DataProcessorConceptrequires:
//      ProcessData(std::shared_ptr<DataRetrieverConcept>) -> void
template <typename T, typename R>
concept DataProcessorConcept = DataRetrieverConcept<R> &&
    requires(T t, std::shared_ptr<R> retriever) {
  { t.ProcessData(retriever) } -> std::same_as<SimpleData>;
};

// =====================================================
// Concrete classes that comply with DataRetrieverConcept
// =====================================================

class TwoRetriever {
public:
  SimpleData GetData();
};

class FourRetriever {
public:
  SimpleData GetData();
};

// ======================================================
// Class templates that comply with DataProcessorConcept
// ======================================================

// MultiplyByTwoProcessor uses a DataRetrieverConcept to retrieve SimpleData
// object, multiples by two, and returns result.
template <DataRetrieverConcept R>
class MultiplyByTwoProcessor {
public:
  using RetrieverType = R;
  SimpleData ProcessData(std::shared_ptr<R> retriever) {
    return SimpleData(retriever->GetData().value() * 2);
  }
};

// DivideByTwoProcessor uses a DataRetrieverConcept to retrieve SimpleData
// object, divides by two, and returns result.
template <DataRetrieverConcept R>
class DivideByTwoProcessor {
public:
  using RetrieverType = R;
  SimpleData ProcessData(std::shared_ptr<R> retriever) {
    return SimpleData(retriever->GetData().value() / 2);
  }
};


// =====================================================================
// Function template restricted to types satisfying DataProcessorConcept
// =====================================================================
template <typename P>
SimpleData demonstrate() {
  using Retriever = typename P::RetrieverType; // Extract Retriever type
  static_assert(
      DataProcessorConcept<P, Retriever>,
      "Processor does not satisfy DataProcessorConcept"
  );

  return P().ProcessData(std::make_shared<Retriever>());
}



