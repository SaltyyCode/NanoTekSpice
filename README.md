# NanoTekSpice
## Description

NanoTekSpice is a logic simulator that builds and tests digital electronic circuits from a configuration file. The program handles basic electronic components such as logic gates (AND, OR, XOR, etc.), as well as more advanced components like registers, counters, and memory units.

## Installation and Prerequisites
- A C++ compiler compatible with C++17 or later.
- Make or CMake for compilation.

## Compilation
Use the following command to compile the project:
```make```

Or with CMake:
``` 
mkdir build && cd build
cmake ..
make
```

## Usage
Run NanoTekSpice with a circuit file as a parameter:
```./nanotekspice <filename.nts>```

Once inside the interactive interface, the following commands are available:
* `exit` : closes the program.
* `display` : prints the value of all inputs and outputs.
* `input=value` : changes the value of an input. This ònly apply to `Input` and `Clock`.
* `simulate` : runs the simulation.
* `loop` : continuously runs the simulation until SIGINT is received.
* `sd` : runs the simulation once and prints the value of all inputs and outputs.

## Example Execution
Example ```or_gate.nts``` file:
```shell
.chipsets:
    input a
    input b
    4071 or
    output s

.links:
    a:1 or:1
    b:1 or:2
    or:3 s:1
```

Simulation:

```
./nanotekspice or_gate.nts
> a=1
> b=0
> simulate
> display
tick: 1
input(s):
  a: 1
  b: 0
output(s):
  s: 1
> exit
```

## Authors
[SaltyyCode](https://www.github.com/SaltyyCode)

~~[@JulienMars](https://github.com/Julienmarss)~~
