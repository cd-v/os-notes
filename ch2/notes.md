# The Kernel Abstraction
- Kernel: lowest-level of software in system, full access to machine hardware
    - Implements "protection"

- Process: active execution of a program 
    - "instance" of program

- Two perspectives:
    1. Kernel, with full access
    2. Application, with restricted access


# The Process Abstraction
- Executable image: Code converted (by compiler) into machine instructions
    - Also contains definition/declaration of static variables

- Program run process:
    1. OS copies instructions/data from img into physical memory
        - Execution stack: holds local variable states during procedure calls
        - Heap: holds dynamically-allocated data structures
    2. Set stack pointer, jump to program's first instruction

- Process control block: Data structure to keep track of all computer processes
    - Location in memory, location of img on disk, user asked to execute, privileges, etc.

- Principle of least privilege: each part of the system has privileges to do its job, and NOTHING more


# Dual-mode Operation
- Dual-mode operation: single bit in processer status register, signifies current mode of processor
    - User mode: Processer checks each instruction before execution to verify it is permitted (to execute)
    - Kernel mode: operating system executes instructions with protection checks turned off
    - Typically 1-bit register: 0 for kernel, 1 for user

- How can kernel protect applications/users from one another, while allowing CPU to execute code?
    - Hardware must support 3 things:
        1. Privileged insturctions: potentially unsafe instructions prohibited from execution in user mode
        2. Memory protection: memory access outside of process' valid memory region is prohibited
        3. Timer interrupts: kernel must have ability to periodically regain control from current process

- System call: special instruction, allows processes to change privilege level
    - Transfers control into kernel at fixed location

- Privileged instruction: instruction available in kernel mode, but NOT user mode

- Base-and-bound memory protection
    - Base: specifies beginning point of process' memory region in physical memory
    - Bound: specifies end point ...
    - Can only be changed in kernel mode

- Limitation of base-and-bound
    1. Lack of dynamic memory allocation for heap/stack
    2. Unable to share memory between processes
    3. Usage of physical memory addresses
        - Program loaded into physical memory at runtime, then must use that region
        - Any difference in location requires kernel changing instructions that refer to global address, etc.
    4. Memory fragmentation
        - As applications start/finish, memory regions become fragmented
        - No possible continuous region for program, despite fragmented space available

- Virtual addresses

- Timer interrupts: Transfers control from user process to kernel (in kernel mode)
    - Hardware timers
