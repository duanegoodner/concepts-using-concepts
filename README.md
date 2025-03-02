# concept-using-concept

*Brief Demonstration of how one C++20 Concept can depend on another C++20 Concept*

## Description

This project consists of:

### `SimpleData`

- Data container type that other classes retrieve and operate on

### `DataRetrieverConcept`  
- Concept requiring a **`GetData()`** method that returns a **`SimpleData`** object.

### `DataProcessorConcept`
- Concept requiring a a **`ProcessData(std::shared_ptr<DataRetrieverConcept>)`**  method that returns a **`SimpleData`** object.

### Two Concrete Classes that Comply with **`DataRetrieverConcept`**
- `TwoRetriever`
- `FourRetriever`


### Function Template `void demonstrate<P>()`
- Compile-time `static_assert` reuires `P` to comply with `DataProcessorConcept` 


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

### Expected Output
```
2 x 2 = 4
2 / 2 = 1
4 x 2 = 8
4 / 2 = 2
```