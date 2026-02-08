/*
 * main.h
 *
 *  Created on: Feb 1, 2026
 *      Author: erkutdonmez
 */

#ifndef MAIN_H_
#define MAIN_H_

//1024(1KB) ---> 100 0000 0000 ---> 0x800

#define SRAM_START					0x20000000
#define SRAM_SIZE 					((128) * (1024)) //sram is 128 kb
#define SRAM_END 					(SRAM_START) + (SRAM_SIZE)

#define TASK1_STACK_END				SRAM_END
#define TASK1_STACK_START			TASK1_STACK_END - 0x800

#define TASK2_STACK_END				TASK1_STACK_START
#define TASK2_STACK_START			TASK2_STACK_END - 0x800

#define TASK3_STACK_END				TASK2_STACK_START
#define TASK3_STACK_START			TASK3_STACK_END - 0x800

#define TASK4_STACK_END				TASK3_STACK_START
#define TASK4_STACK_START			TASK4_STACK_END - 0x800

#define IDLE_TASK_STACK_END			TASK4_STACK_START
#define IDLE_TASK_STACK_START		IDLE_TASK_STACK_END - 0x800

#define SCHEDULER_STACK_END			IDLE_TASK_STACK_START
#define SCHEDULER_STACK_START		SCHEDULER_STACK_END - 0x800

#define NUM_OF_TASKS				5U
#define DUMMY_XPSR 					0x01000000U

#define TICK_HZ 					1000U
#define HSI_CLK						16000000U //16MHz
#define SYSTICK_TIM_CLK 			HSI_CLK

#define TASK_READY_STATE			1U
#define TASK_BLOCKED_STATE			0U

#define DISABLE_INTERRUPTS()  		do{__asm volatile("MOV r0,0x1"); __asm volatile("MSR PRIMASK,r0");}while(0)
#define ENABLE_INTERRUPTS()  		do{__asm volatile("MOV r0,0x0"); __asm volatile("MSR PRIMASK,r0");}while(0)

static void task1_handler(void);
static void task2_handler(void);
static void task3_handler(void);
static void task4_handler(void);
static void idle_task(void);
static void init_systick_timer(uint32_t tick_hz);
static void init_scheduler_stack(uint32_t sched_top_of_stack);
static void init_tasks(void);
uint32_t get_current_psp(void);
void save_psp_value(uint32_t current_psp_value);
void update_next_task(void);
void unblock_tasks(void);
static void switch_sp_to_psp(void);
static void enable_processor_faults(void);
void task_delay(uint32_t tick_count);

//TCB stands for task control block
typedef struct {
	uint32_t psp_value;
	uint32_t block_count;
	uint8_t state; //whether it is running or blocked
	void (*task_handler)(void);
}TCB_t;

#endif /* MAIN_H_ */
