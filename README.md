# concept-using-concept

*One C++20 Concept Using Another*

## Description

This project is a brief demonstration of how one C++20 Concept can depend on another C++20 Concept. It includes:

- A **`DataRetrieverConcept`** requiring a **`GetData()`** method that returns a **`SimpleDat`a** object.
- A **`DataProcessorConcept`** requiring a **`ProcessData(std::shared_ptr<DataRetrieverConcept>)`**  method that returns a **`SimpleData`** object.
- Two concrete classes that comply with **`DataRetrieverConcept`** and two class templates that comply with **`DataProcessorConcept`**.
- A **`demonstration<P>`** function template with requirement that `P` comply with **`DataProcessorConcept`**, enforced by a `**static_assert**`.


### Building

```
git clone https://gist.github.com/8239a11398d5ec356730a192516d785f.git concepts-example
cd concepts-example
mkdir build
cmake -B build
cmake --build build
```

### Running
```
./build/bin/concept_using_other_concept
```

### Expected Output
```
2 x 2 = 4
2 / 2 = 1
4 x 2 = 8
4 / 2 = 2

```