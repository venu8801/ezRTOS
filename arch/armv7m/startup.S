.section .vector_table, "a"
.align 2
.global __vector_table
__vector_table:
    .word _estack                    // Initial stack pointer
    .word Reset_Handler              // Reset handler
    .word NMI_Handler                // NMI handler
    .word HardFault_Handler          // Hard fault handler
    .word MemManage_Handler          // Memory management fault
    .word BusFault_Handler           // Bus fault
    .word UsageFault_Handler         // Usage fault
    .word 0                          // Reserved
    .word 0                          // Reserved
    .word 0                          // Reserved
    .word 0                          // Reserved
    .word SVC_Handler                // SVCall
    .word DebugMon_Handler           // Debug monitor
    .word 0                          // Reserved
    .word PendSV_Handler             // PendSV
    .word SysTick_Handler            // SysTick
    .word WWDG_IRQHandler            // Window WatchDog
    .word PVD_IRQHandler             // PVD through EXTI Line detect
    .word TAMPER_IRQHandler          // Tamper
    .word RTC_IRQHandler             // RTC
    .word FLASH_IRQHandler           // Flash
    .word RCC_IRQHandler             // RCC
    .word EXTI0_IRQHandler           // EXTI Line 0
    .word EXTI1_IRQHandler           // EXTI Line 1
    .word EXTI2_IRQHandler           // EXTI Line 2
    .word EXTI3_IRQHandler           // EXTI Line 3
    .word EXTI4_IRQHandler           // EXTI Line 4
    .word DMA1_Channel1_IRQHandler   // DMA1 Channel 1
    .word DMA1_Channel2_IRQHandler   // DMA1 Channel 2
    .word DMA1_Channel3_IRQHandler   // DMA1 Channel 3
    .word DMA1_Channel4_IRQHandler   // DMA1 Channel 4
    .word DMA1_Channel5_IRQHandler   // DMA1 Channel 5
    .word DMA1_Channel6_IRQHandler   // DMA1 Channel 6
    .word DMA1_Channel7_IRQHandler   // DMA1 Channel 7
    .word ADC1_2_IRQHandler          // ADC1 & ADC2
    .word USB_HP_CAN1_TX_IRQHandler  // USB High Priority or CAN1 TX
    .word USB_LP_CAN1_RX0_IRQHandler // USB Low Priority or CAN1 RX0
    .word CAN1_RX1_IRQHandler        // CAN1 RX1
    .word CAN1_SCE_IRQHandler        // CAN1 SCE
    .word EXTI9_5_IRQHandler         // EXTI Line 9..5
    .word TIM1_BRK_IRQHandler        // TIM1 Break
    .word TIM1_UP_IRQHandler         // TIM1 Update
    .word TIM1_TRG_COM_IRQHandler    // TIM1 Trigger and Commutation
    .word TIM1_CC_IRQHandler         // TIM1 Capture Compare
    .word TIM2_IRQHandler            // TIM2
    .word TIM3_IRQHandler            // TIM3
    .word TIM4_IRQHandler            // TIM4
    .word I2C1_EV_IRQHandler         // I2C1 Event
    .word I2C1_ER_IRQHandler         // I2C1 Error
    .word I2C2_EV_IRQHandler         // I2C2 Event
    .word I2C2_ER_IRQHandler         // I2C2 Error
    .word SPI1_IRQHandler            // SPI1
    .word SPI2_IRQHandler            // SPI2
    .word USART1_IRQHandler          // USART1
    .word USART2_IRQHandler          // USART2
    .word USART3_IRQHandler          // USART3
    .word EXTI15_10_IRQHandler       // EXTI Line 15..10
    .word RTC_Alarm_IRQHandler       // RTC Alarm through EXTI Line
    .word USBWakeUp_IRQHandler       // USB Wakeup from suspend

// Default handlers
.weak NMI_Handler
.type NMI_Handler, %function
NMI_Handler:
    b .

.weak HardFault_Handler
.type HardFault_Handler, %function
HardFault_Handler:
    b .

.weak MemManage_Handler
.type MemManage_Handler, %function
MemManage_Handler:
    b .

.weak BusFault_Handler
.type BusFault_Handler, %function
BusFault_Handler:
    b .

.weak UsageFault_Handler
.type UsageFault_Handler, %function
UsageFault_Handler:
    b .

.weak SVC_Handler
.type SVC_Handler, %function
SVC_Handler:
    b .

.weak DebugMon_Handler
.type DebugMon_Handler, %function
DebugMon_Handler:
    b .

.weak PendSV_Handler
.type PendSV_Handler, %function
PendSV_Handler:
    b .

.weak SysTick_Handler
.type SysTick_Handler, %function
SysTick_Handler:
    b .

// Peripheral handlers - all weak and default to infinite loop
.weak WWDG_IRQHandler
.type WWDG_IRQHandler, %function
WWDG_IRQHandler:
    b .

.weak PVD_IRQHandler
.type PVD_IRQHandler, %function
PVD_IRQHandler:
    b .

.weak TAMPER_IRQHandler
.type TAMPER_IRQHandler, %function
TAMPER_IRQHandler:
    b .

.weak RTC_IRQHandler
.type RTC_IRQHandler, %function
RTC_IRQHandler:
    b .

.weak FLASH_IRQHandler
.type FLASH_IRQHandler, %function
FLASH_IRQHandler:
    b .

.weak RCC_IRQHandler
.type RCC_IRQHandler, %function
RCC_IRQHandler:
    b .

.weak EXTI0_IRQHandler
.type EXTI0_IRQHandler, %function
EXTI0_IRQHandler:
    b .

.weak EXTI1_IRQHandler
.type EXTI1_IRQHandler, %function
EXTI1_IRQHandler:
    b .

.weak EXTI2_IRQHandler
.type EXTI2_IRQHandler, %function
EXTI2_IRQHandler:
    b .

.weak EXTI3_IRQHandler
.type EXTI3_IRQHandler, %function
EXTI3_IRQHandler:
    b .

.weak EXTI4_IRQHandler
.type EXTI4_IRQHandler, %function
EXTI4_IRQHandler:
    b .

.weak DMA1_Channel1_IRQHandler
.type DMA1_Channel1_IRQHandler, %function
DMA1_Channel1_IRQHandler:
    b .

.weak DMA1_Channel2_IRQHandler
.type DMA1_Channel2_IRQHandler, %function
DMA1_Channel2_IRQHandler:
    b .

.weak DMA1_Channel3_IRQHandler
.type DMA1_Channel3_IRQHandler, %function
DMA1_Channel3_IRQHandler:
    b .

.weak DMA1_Channel4_IRQHandler
.type DMA1_Channel4_IRQHandler, %function
DMA1_Channel4_IRQHandler:
    b .

.weak DMA1_Channel5_IRQHandler
.type DMA1_Channel5_IRQHandler, %function
DMA1_Channel5_IRQHandler:
    b .

.weak DMA1_Channel6_IRQHandler
.type DMA1_Channel6_IRQHandler, %function
DMA1_Channel6_IRQHandler:
    b .

.weak DMA1_Channel7_IRQHandler
.type DMA1_Channel7_IRQHandler, %function
DMA1_Channel7_IRQHandler:
    b .

.weak ADC1_2_IRQHandler
.type ADC1_2_IRQHandler, %function
ADC1_2_IRQHandler:
    b .

.weak USB_HP_CAN1_TX_IRQHandler
.type USB_HP_CAN1_TX_IRQHandler, %function
USB_HP_CAN1_TX_IRQHandler:
    b .

.weak USB_LP_CAN1_RX0_IRQHandler
.type USB_LP_CAN1_RX0_IRQHandler, %function
USB_LP_CAN1_RX0_IRQHandler:
    b .

.weak CAN1_RX1_IRQHandler
.type CAN1_RX1_IRQHandler, %function
CAN1_RX1_IRQHandler:
    b .

.weak CAN1_SCE_IRQHandler
.type CAN1_SCE_IRQHandler, %function
CAN1_SCE_IRQHandler:
    b .

.weak EXTI9_5_IRQHandler
.type EXTI9_5_IRQHandler, %function
EXTI9_5_IRQHandler:
    b .

.weak TIM1_BRK_IRQHandler
.type TIM1_BRK_IRQHandler, %function
TIM1_BRK_IRQHandler:
    b .

.weak TIM1_UP_IRQHandler
.type TIM1_UP_IRQHandler, %function
TIM1_UP_IRQHandler:
    b .

.weak TIM1_TRG_COM_IRQHandler
.type TIM1_TRG_COM_IRQHandler, %function
TIM1_TRG_COM_IRQHandler:
    b .

.weak TIM1_CC_IRQHandler
.type TIM1_CC_IRQHandler, %function
TIM1_CC_IRQHandler:
    b .

.weak TIM2_IRQHandler
.type TIM2_IRQHandler, %function
TIM2_IRQHandler:
    b .

.weak TIM3_IRQHandler
.type TIM3_IRQHandler, %function
TIM3_IRQHandler:
    b .

.weak TIM4_IRQHandler
.type TIM4_IRQHandler, %function
TIM4_IRQHandler:
    b .

.weak I2C1_EV_IRQHandler
.type I2C1_EV_IRQHandler, %function
I2C1_EV_IRQHandler:
    b .

.weak I2C1_ER_IRQHandler
.type I2C1_ER_IRQHandler, %function
I2C1_ER_IRQHandler:
    b .

.weak I2C2_EV_IRQHandler
.type I2C2_EV_IRQHandler, %function
I2C2_EV_IRQHandler:
    b .

.weak I2C2_ER_IRQHandler
.type I2C2_ER_IRQHandler, %function
I2C2_ER_IRQHandler:
    b .

.weak SPI1_IRQHandler
.type SPI1_IRQHandler, %function
SPI1_IRQHandler:
    b .

.weak SPI2_IRQHandler
.type SPI2_IRQHandler, %function
SPI2_IRQHandler:
    b .

.weak USART1_IRQHandler
.type USART1_IRQHandler, %function
USART1_IRQHandler:
    b .

.weak USART2_IRQHandler
.type USART2_IRQHandler, %function
USART2_IRQHandler:
    b .

.weak USART3_IRQHandler
.type USART3_IRQHandler, %function
USART3_IRQHandler:
    b .

.weak EXTI15_10_IRQHandler
.type EXTI15_10_IRQHandler, %function
EXTI15_10_IRQHandler:
    b .

.weak RTC_Alarm_IRQHandler
.type RTC_Alarm_IRQHandler, %function
RTC_Alarm_IRQHandler:
    b .

.weak USBWakeUp_IRQHandler
.type USBWakeUp_IRQHandler, %function
USBWakeUp_IRQHandler:
    b .

// Reset handler
.global Reset_Handler
.type Reset_Handler, %function
Reset_Handler:
    // Copy data from flash to RAM
    ldr r0, =_sdata
    ldr r1, =_edata
    ldr r2, =_sidata
    movs r3, #0
    b LoopCopyDataInit

CopyDataInit:
    ldr r4, [r2, r3]
    str r4, [r0, r3]
    add r3, r3, #4

LoopCopyDataInit:
    add r4, r0, r3
    cmp r4, r1
    bcc CopyDataInit

    // Zero-fill the BSS section
    ldr r2, =_sbss
    ldr r4, =_ebss
    movs r3, #0
    b LoopFillZerobss

FillZerobss:
    str r3, [r2]
    add r2, r2, #4

LoopFillZerobss:
    cmp r2, r4
    bcc FillZerobss

    // Call the main function
    bl main

    // If main returns, loop forever
    b .

.size Reset_Handler, .-Reset_Handler

