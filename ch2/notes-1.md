# Types of Mode Transfer
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


# Implementing safe mode transfer
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
