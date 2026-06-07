/**
*
*
*
*
*/


#include <task.h>
#include <stdint.h>
#include <ez_syscalls.h>
uint32_t g_systicks_counter ;

void ez_systick_hanlder(void) {
  ez_log("systick handler triggered: %u", g_systicks_counter);
  g_systicks_counter++;
  return;
}

