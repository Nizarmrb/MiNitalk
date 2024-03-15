The purpose of this project is to code a small data exchange program
using UNIX signals.


you'll need to understand this key concepts and techniques:

1. Signals in UNIX/Linux: Signals are software interrupts sent to a process by the kernel or by another process. They can be used for various purposes, including inter-process communication (IPC).

2.  Signal Handling: You'll need to understand how to set up signal handlers in your program to catch and handle signals. This involves using functions like signal() or sigaction() to specify how your program should respond to different signals.

3.  Inter-Process Communication (IPC): Signals can be used for simple IPC between processes. One process can send a signal to another process to notify it of an event or to trigger some action.

4.  Data Exchange: While signals themselves do not carry data, you can use signals to trigger data exchange mechanisms between processes. This might involve using shared memory, pipes, sockets, or other IPC mechanisms to transfer data between processes.

5.  Synchronization: When exchanging data between processes using signals, you need to ensure proper synchronization to avoid race conditions or data corruption. Techniques such as using mutexes, semaphores, or other synchronization primitives may be necessary.

6.   Error Handling: Implement robust error handling in your code to handle scenarios such as failed signal delivery, invalid data, or other unexpected conditions.
