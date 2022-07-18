# Exercises

1. If, instead, the x86 hardware switched the stack pointer to the kernel stack AFTER saving the process state, then the stack pointer would be saved at the user level, not kernel. Why is this bad? Because only storing the pointer at user level is in violation of the principles of our kernel: reliability, and security - two important components of our overall goal of protection. In terms of reliability, our user-level stack pointer may not be stored at a valid address. In terms of security, our memory may be modified at the user level, eventually causing our kernel to return to code outside of our process scope.

2. Our screen memory buffer must remain protected, otherwise our code could fill it with any process it wants, malicious or otherwise. Furthermore, if an application had the ability to alter any pixel on the screen, not exclusively its own window, then it could modify the screen to show whatever it wanted to. This could lead to misleading information about the computer itself, etc.

3. With memory protection and timer interrupts, but without privileged instructions, either two things would happen. One is that the user process would have the same privileges as the kernel, and so, it would be able to do whatever it wanted - eg. switch into kernel mode, manipulate memory, etc. With privileged instructions and timer interrupts, but without memory protection, there is no guarantee our process or kernel operations would stay in the right memory region. Therefore, it could theoretically manipulate any area of memory it wanted - with good intentions, this could cause many bugs; with bad intentions, an attacker could take over areas of the kernel memory to do malicious processes. With privileged instructions and memory protection, but no timer interrupts, there would be no useful way to stop a user process and restore it after a kernel operation.

4. Our system would want to check, one, if our processes, especially within the web script, are within the right privilege levels. Also, it would want to check that each process is within its allotted memory region. Finally, it would want to check that each process is not using too many resources of the physical computer.

5. Interrupts, exceptions, and system calls.

6. Start new process; return from interrupt/exception/system call; switch process; receive upcall.

7. a) This would be used whenever we begin a new process, return from an interrupt/exception/system call, switch to another process, or receive a user-level upcall. 
   b) Our kernel will set the PC, SP, stack, and code segment and switch levels, from kernel -> user.

8. a) Overall, this would make the OS perform faster. Since, in most cases, it would have enough space to hold state in the registers, the kernel would not have to do as much work in getting the state and transferring it whenever a user/kernel level transition occurs.
   b) c) TODO

9. a) The point of virtualization is to create a guest operating system that believes it's running in privileged mode, but is just a typical user process. Some instructions, namely popf, suffer from bugs as a result of this. Popf only changes ALU flags in user mode, but will change both ALU flags and system flags (our expected behavior). So, since our guest OS thinks that it is privileged, it will try to use popf to change both ALU/system flags. It is only a user process, though, so only ALU flags change. 
   b) Create a bit that tells the host OS what level the guest OS has executed the instruction, eg. popf. Then, it can properly set the intended flags.

10. Generally, the kernel. The kernel sets the code segment, program counter, stack pointer, and stack segment into memory, and then sends privilege to the user level.

11. TODO

12. Defined in 'costs.c'. Here, our procedure call ends up being a bit faster. This is because for a system call, we have to do considerably more. Notably, our kernel has to save the state, transfer pointers/state, and then switch from user level to kernel level, and back.

13. A trap refers to any synchronous transfer of control from user level to kernel level. In contrast, an interrupt is an asynchronous signal to the processor something's happened that may require its attention, whereas an exception is a hardware event caused by a user program that causes transfer of control to the kernel. If we cannot implement traps, it would be possible to do so with interrupts/exceptions. Since the exception accomplishes a transfer from user to kernel, we could use that to provide the same transfer of control that a trap does. Furthermore, we could even utilize an interrupt to let the CPU know of a process that could utilize the exception.

14. It would not be possible to effectively use exceptions/traps as a substitute for interrupts - namely, because a trap/exception are synchronous calls. By nature, an interrupt is asynchronous. 

15. The hardware switches from user to kernel mode, disables interrupt, and then jumps to the routine specified by the handler at the address given by the interrupt vector table. The routine then saves all registers and execudes the interrupt code. Once done, the registers are restored, and then the kernel goes back to user mode, executing the instruction proceeding the interrupt. If that was the last instruction, then the kernel just jumps to idle and waits. 

16. It would need to be different. This is because if we were switching between levels, there would not be any guarantee the stack is stored in valid memory.

17. Defined in 'rogue.c'.
