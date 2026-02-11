#Bare-Metal Preemptive Task Scheduler (STM32)

This project is a **bare-metal preemptive task scheduler** implemented on an **STM32 (ARM Cortex-M4)** microcontroller without using any RTOS.

The scheduler demonstrates how context switching works at the CPU level by manually managing stack frames and using the ARM exception mechanism.

---------------------------------------------------------

##Features

- Preemptive multitasking using SysTick
- Context switching using PendSV
- Round-robin scheduling
- Separate stack for each task (PSP-based)
- Scheduler runs in Handler Mode (MSP)
- Tasks run in Thread Mode (PSP)
- Manual saving/restoring of registers R4–R11
- Automatic exception stack frame handling by hardware
- Basic tick-based delay mechanism
- Task blocking and unblocking using a global tick counter
- Bare-metal GPIO control (LED blinking tasks)

---------------------------------------------------------

##Core Concepts Used

- ARM Cortex-M exception model
- PSP vs MSP
- EXC_RETURN values (0xFFFFFFFD)
- Stack frame layout:
	- Hardware-stacked: `R0–R3, R12, LR, PC, xPSR`
	- Software-stacked: `R4–R11`
- Naked interrupt handlers
- Context switching using `STMDB / LDMIA`
- `PendSV` for deferred context switching
- `SysTick` as system time base (1 ms tick)

---------------------------------------------------------

##How It Works (High-Level)

1. Each task is assigned its own private stack.
2. Initial stack frames are manually prepared for each task.
3. SysTick interrupt triggers every 1 ms.
4. On SysTick:
	- Global tick counter is incremented.
	- Blocked tasks are checked and unblocked when their delay expires.
	- PendSV exception is triggered for context switching.

5. On PendSV:
	- Current task context (R4–R11) is saved to its PSP.
	- Next task is selected (round-robin, skipping blocked tasks).
	- Next task context is restored.
	- CPU exits the exception using EXC_RETURN, restoring PC automatically.
	- The next task continues execution from where it left off.
6. Tasks can call task_delay() to enter a blocked state for a specific number of ticks.

---------------------------------------------------------

##Hardware Setup

- Board: STM32F407-DISC1 (ARM Cortex M4 based)
- LEDs:
	- PD12 – Green
	- PD13 – Orange
	- PD14 – Red
	- PD15 – Blue

Each task toggles a different LED, exhibits parallel-like execution.

---------------------------------------------------------

## Limitations

- No task priorities
- No blocking/delay mechanism
- No synchronization primitives (mutex/semaphore)
- No dynamic task creation

This project is intended for **learning and experimentation**, not production use.

---------------------------------------------------------

## References

- ARM Cortex-M4 Generic User Guide
- ARM Architecture Reference Manual
- STM32 Reference Manual

---------------------------------------------------------

## Author

Erkut Dönmez  
Computer Engineering Graduate
Embedded Software Enthusiast