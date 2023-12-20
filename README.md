# HODE 16-Bit Transistor Computer

## Website
- https://www.outerworldapps.com/hode

HODE is a 16-bit transistor computer that uses a RaspberryPi for memory and IO. This project includes a simulator and requires a Linux computer (x86 or Raspberry Pi) for software building. The design and PCB layouts are created using KiCad.

## Requirements
- RaspberryPi for memory and IO (optional for the simulator).
- Linux (x86 or Raspberry Pi) for building software.
- KiCad for PCB layouts.
- GNU C++ compiler, Java 8 or higher.

## Directories
- `asm`: Cross assembler and linker. Run `$ make` to build.
- `cc`: Cross compiler. Run `$ make` to build.
- `crtl`: C runtime library and example programs. Requires previous building of `asm`, `cc`, `driver`. Navigate to `library`, run `$ make`, then return to the root and run `$ make` and `$ ./runit.sh` or `$ ./runhw.sh` for simulation.
- `de0`: DE0-Nano FPGA implementation in Verilog. Requires DE0-Nano board, Raspberry Pi, and interconnect board. Use Quartus for compiling and programming.
- `driver`: Raspberry Pi control program and hardware test programs. Run `$ make` and `$ sudo insmod enabtsc.ko` on Raspberry Pi.
- `freecads`: Case component drawings.
- `goodpcbs`: Completed PCB files, including netlist and parts list.
- `kicads`: Other KiCad files for interconnects and testing.
- `modules`: Board modules for simulation and PCB generation. Includes regression test scripts and PCB file generation.
- `netgen`: Java program for compiling modules. Ensure JNI directory is correctly set and run `$ make`.

## Building and Testing
- Ensure you have the necessary components, including stackable connectors, right angle connectors, and resistors.
- Follow specific steps for building and testing each board, including power checks and script-driven testing.
- Refer to individual directories for detailed instructions on assembly, soldering, and diagnostic procedures.

## How to Build
- Detailed instructions on component assembly, soldering, and testing for each board.
- Tips for testing the sequencer board, register boards, and complete stack.
- Guidance on programming and running tests using scripts in the `drivers` directory.
- Advice on stacking order and LED board placement for optimal operation.

Will update this with more detailed instructions and tips on each component and testing process.
