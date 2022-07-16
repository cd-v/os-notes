# x86 Mode Transfer
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


# Implementing Secure System Calls
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


# Starting a New Process 
- Kernel steps:
    - Allocate/init process control block
    - Allocate memory for process
    - Copy program from disk into new memory
    - Allocate user-level stack for user-level execution
    - Allocate kernel-level stack for interrupts, exceptions, system calls
- Also:
    1. Copy arguments into user memory
    2. Transfer control to user mode

* TODO: Read 2.8, summarize
