# The Kernel Abstraction
- Kernel: lowest-level of software in system, full access to machine hardware
    - Implements "protection"

- Process: active execution of a program 
    - "instance" of program

- Two perspectives:
    1. Kernel, with full access
    2. Application, with restricted access
---
## The Process Abstraction
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
---
## Dual-mode Operation
- Dual-mode operation: single bit in processer status register, signifies current mode of processor
    - User mode: Processer checks each instruction before execution to verify it is permitted (to execute)
    - Kernel mode: operating system executes instructions with protection checks turned off
    - Typically 1-bit register: 0 for kernel, 1 for user

- How can kernel protect applications/users from one another, while allowing CPU to execute code?
    - Hardware must support 3 things:
        1. Privileged instructions: potentially unsafe instructions prohibited from execution in user mode
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
---
## Types of Mode Transfer
- User-to-kernel mode
    - Three reasons for kernel to control user process:
        1. Interrupts
            - Asynchronous signal to processor that external event has occurred, possibly requiring its attention
        2. Exceptions
            - Hardware event caused by user program that causes control transfer to kernel
        3. System calls
            - Procedure provided by kernel that can be called at user level

- Trap: synchronous transfer of control from user mode -> kernel mode

- Kernel-to-user mode
    - Four reasons:
        1. Start a new process
            - Kernel copies program into memory...
                sets PC (program counter) to first instruction...
                sets stack pointer to base of user stack...
                switches to user mode
        2. Resume after interrupt/exception/system call
            - Restores PC, registers, and changes back to user mode
        3. Switch to different process
            - Save process state to PCB, then have kernel load state of other process into processor
        4. User-level upcall
            - Receive user-level asynchronous notifications of events
---
## Implementing safe mode transfer
- Common sequence of instructions for entering/exiting kernel mode
    - Minimum of 3 requirements:
        1. Limited entry into kernel
            - eg. kernel entry point is decided by kernel
        2. Atomic changes to processor state
            - eg. switching between user/kernel mode is atomic
                - mode, program counter, stack, memory protection all *changed at the same time*
        3. Transparent, restartable execution
            - eg. OS must be able to restore user-level process state as before kernel-level mode switch

- Interrupt Vector Table
    - Special area of kernel memory
    - Array of pointers
    - Each entry points to first instruction of certain handler procedure in kernel
        - Interrupt handler: procedure called by kernel on interrupt

- Interrupt Stack
    - Kernel-level interrupt stack necessary because:
        1. Reliability
        2. Security
    - Two stacks per process
        - User-level kernel stack, w/ pointer at kernel PCB to user-level stack

- Interrupt Masking
    - Interrupt disable: defers delivery of interrupt until safe to do so
    - Interrupt enable: any pending interrupts delivered to the processor 
    - If multiple interrupts, they are delivered in-turn when interrupts re-enabled
---
## x86 Mode Transfer
- Steps required:
    1. Mask interrupts
        - Prevent interrupts from occurring while processor is in middle of switching from user mode -> kernel mode
    2. Saves values of 3 key values:
        1. Stack pointer (x86: esp/ss registers)
        2. Execution flags (x86: eflags register)
        3. Instruction pointer (x86: eip/cs registers)
    3. Switch onto kernel interrupt stack
        - Stack segment/stack pointer switched to base of kernel interrupt stack
    4. Push 3 key values onto new stack
        - Same 3 as above
    5. (Optional) save error code
        - extra error output for certain exceptions
        - if none, then a dummy value is used to replicate it
    6. Invoke interrupt handler
        - Code segment/program counter to addr. of interrupt handler procedure
---
## Implementing Secure System Calls
- System call: executed by operating system, when process needs to execute an action outside of its domain 

- Calling convention

- Pair of stubs
    - Pair of procedures that mediate between both environments (kernel, user)
    - Bridging of 2 views:
        1. User program calling the system call
        2. Kernel implementing the system call

- Sequence of a system call:
    1. User prgoram calls user stub
    2. User stub fills in code for system call, executes trap instruction
    3. Hardware transfers control to kernel
        ...
    4. Once system call completes, returns to handler
    5. Handler returns to user level at next instruction in stub
    6. Stub returns to the caller

- Kernel stub has 4 tasks:
    1. Locate system call arguments
    2. Validate parameters
    3. Copy before check
    4. Copy back any results

- Time of check vs. time of use attack
---
## Starting a New Process 
- Kernel steps:
    - Allocate/init process control block
    - Allocate memory for process
    - Copy program from disk into new memory
    - Allocate user-level stack for user-level execution
    - Allocate kernel-level stack for interrupts, exceptions, system calls
- Also:
    1. Copy arguments into user memory
    2. Transfer control to user mode
---
## User-level Upcalls
- Illustrates useful pattern:
    - Need of virtualizing some part of the kernel so applications behave more like OS

- Upcalls: virtualized interrupts/exceptions
    - Linux: Signals
    - Windows: Asynchronous events

- Uses:
    1. Preemptive user-level threads
        - Timer upcall for trigger to switch tasks, evenly share processor for user-level tasks, end runaway task, etc. 
    2. Asynchronous IO notification
        - System call makes request, returns immediately
        - Then, application polls kernel for IO completion
            - Or, separate notifcations can be sent via upcall when IO is finished
    3. Interprocess communication
    4. User-level exception handling
    5. User-level resource allocation
