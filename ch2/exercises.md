# Exercises

1. If, instead, the x86 hardware switched the stack pointer to the kernel stack AFTER saving the process state, then the stack pointer would be saved at the user level, not kernel. Why is this bad? Because only storing the pointer at user level is in violation of the principles of our kernel: reliability, and security - two important components of our overall goal of protection. In terms of reliability, our user-level stack pointer may not be stored at a valid address. In terms of security, our memory may be modified at the user level, eventually causing our kernel to return to code outside of our process scope.

2. Our screen memory buffer must remain protected, otherwise our code could fill it with any process it wants, malicious or otherwise. Furthermore, if an application had the ability to alter any pixel on the screen, not exclusively its own window, then it could modify the screen to show whatever it wanted to. This could lead to misleading information about the computer itself, etc.

3. With memory protection and timer interrupts, but without privileged instructions, either two things would happen. One is that the user process would have the same privileges as the kernel, and so, it would be able to do whatever it wanted - eg. switch into kernel mode, manipulate memory, etc. With privileged instructions and timer interrupts, but without memory protection, there is no guarantee our process or kernel operations would stay in the right memory region. Therefore, it could theoretically manipulate any area of memory it wanted - with good intentions, this could cause many bugs; with bad intentions, an attacker could take over areas of the kernel memory to do malicious processes. With privileged instructions and memory protection, but no timer interrupts, there would be no useful way to stop a user process and restore it after a kernel operation.

4. Our system would want to check, one, if our processes, especially within the web script, are within the right privilege levels. Also, it would want to check that each process is within its allotted memory region. Finally, it would want to check that each process is not using too many resources of the physical computer.

5. Interrupts, exceptions, and system calls.

6. Start new process; return from interrupt/exception/system call; switch process; receive upcall.

7. a) This would be used whenever we begin a new process, return from an interrupt/exception/system call, switch to another process, or receive a user-level upcall. 
   b) Our kernel will set the PC, SP, stack, and code segment and switch levels, from kernel -> user.

8. TODO

9. TODO

10. Generally, the kernel. The kernel sets the code segment, program counter, stack pointer, and stack segment into memory, and then sends privilege to the user level.

11. TODO

12. 
