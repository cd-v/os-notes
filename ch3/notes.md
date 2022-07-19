# The Programming Interface
- Required application functions (from OS):
    1) **Process management**
    2) **I/O**

- Location of application functions:
    - Possible options:
        1) User-level program
        2) User-level library (linked)
        3) OS Kernel
        4) System call invocation, kernel process execution
    - Tradeoff between:
        - Flexibility 
        - Reliability
        - Performance
        - Safety

- Microkernel: Privileged, but less critical parts (file system) of OS are isolated from kernel itself
---
## Process Management
- User programs creating/managing their own resources

- Shell: "job control system"
    - Allows a sequence of programs to be ran together

- Parent: Creator of process
    - Child: Created process

- Two approaches to process creation/management:
    1) Add system calls for process creation and other operations
        - CreateProcess()
            - Steps:
                1) Create/initialize process control block (kernel)
                2) Create/initialize new address space
                3) Load program into address space 
                4) Copy arguments into memory (in address space)
                5) Initiliaze hardware context to "start"
                6) Inform scheduler new process is ready to run
    2) UNIX-based; CreateProcess => fork(), exec()
        - Fork(): Creates complete copy of parent process, with one difference
            - Difference: child process sets up privileges, priorities, I/O
                - e.g., open/closing files, etc.
            - Steps:
                1) Create/initialize process control block (kernel)
                2) Create new address space
                3) Initialize address space with copy of parent's address space
                4) Inherit parent's execution context
                    - e.g., open files, etc.
                5) Inform scheduler new process is ready to run
            - Returns to BOTH parent/child
        - Exec(): Brings img into memory, starts running it
            - Steps:
                1) Load program into current address space
                2) Copy arguments into memory (in address space)
                3) Initialize hardware context to "start"
        - Wait(): Used for parent to *wait* until the child process is done
        - Signal
            - Use examples:
                1) Terminating application
                2) Suspending application (for debugging)
                3) Resuming after suspension
                4) Timer expiration
---
## Input/Output
- Regularization of all I/O devices under the same interface

- "Basic ideas" of UNIX I/O interface:
    1) Uniformity
        - Same set of system calls:
            - Read(), write(), open(), close()
    2) Open before use
        - I/O device must be opened before application processing
        - File descriptor: returned by open(), used to identify I/O device
    3) Byte-oriented
        - Accessed through byte-arrays, or bytes
    4) Kernel-buffered reads
        - Stored in kernel, given to application on request
    5) Kernel-buffered writes
        - Stored in kernel, transmitted when device is available
    6) Explicit close
        - Close() is called when done

- Interprocess Communication Concepts:
    1) Pipe: kernel buffer with two file descriptors (read/write)
    2) Replacing file descriptors: child can be read to pipe/file
    3) Multiple reads

