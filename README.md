# concept-using-concept

*Brief Demonstration of how one C++20 Concept can depend on another C++20 Concept*

## Background
C++20 Concepts provide a way to define constraints on template parameters, enabling better compile-time checking and more readable error messages.  


## Description

This project demonstrates how one Concept (`DataProcessorConcept`) can depend on another (`DataRetrieverConcept`), enforcing structure at the type level. The following classes, Concepts and templates are used:

### `SimpleData`

- Data container type that other classes retrieve and operate on

### `DataRetrieverConcept`  
- Concept requiring a **`GetData()`** method that returns a **`SimpleData`** object.

### `DataProcessorConcept`
- Concept requiring a **`ProcessData(std::shared_ptr<DataRetrieverConcept>)`**  method that returns a **`SimpleData`** object.

### Two Concrete Classes that Comply with **`DataRetrieverConcept`**
- `TwoRetriever`
- `FourRetriever`


### Two Class Templates that Comply with **`DataProcessorConcept`**
- `MultiplyByTwoProcessor`
- `DivideByTwoProcessor`


### Function Template `void demonstrate<P>()`
- Compile-time `static_assert` requires `P` to comply with `DataProcessorConcept` 


## Building

```
git clone https://gist.github.com/8239a11398d5ec356730a192516d785f.git concepts-example
cd concepts-example
mkdir build
cmake -B build
cmake --build build
```
> [!NOTE]  
> To  enable verbose Concepts-related compiler error messages, replace:  
`cmake -B build`  
with:  
`cmake -B build -DENABLE_CONCEPT_ERROR_DETAIL=ON`.

## Running
```
./build/bin/concept_using_concept
```

### Calls to `demonstrate<P>()` and their expected outputs:
```
demonstrate<MultiplyByTwoProcessor<TwoRetriever>>()   →  2 x 2 = 4
demonstrate<DivideByTwoProcessor<TwoRetriever>>()     →  2 / 2 = 1
demonstrate<MultiplyByTwoProcessor<FourRetriever>>()  →  4 x 2 = 8
demonstrate<DivideByTwoProcessor<FourRetriever>>()    →  4 / 2 = 2
```
