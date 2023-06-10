# AdventOfCode2022
Clean and short Advent Of Code solutions in C++

## Usage

### Make a build folder inside each day's directory by doing:
    cd <DAY_FOLDER_NAME> 
    cmake -S . -B build/

( Replace <DAY_FOLDER_NAME> with any day's folder name)

### Then put the input file insed folder, it must be called *"input.txt"*
### To run the solution after having followed the steps above use the command:
    cmake --build build

### It will generate a *"main"* executable of the given solution, to run it either click it or do:
- If on Linux do:
```
./build/main
```
- If on Windows do:
```
.\build\main
```