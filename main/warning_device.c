#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include <inttypes.h>

#define BUTTON_GPIO GPIO_NUM_15

volatile int64_t interrupt_counter = 0;

static void IRAM_ATTR gpio_isr_handler(void* arg)
{ 
    /* Disable the Interrupt */
    gpio_intr_disable(BUTTON_GPIO);
    gpio_isr_handler_remove(BUTTON_GPIO);

    /* Increment the interrupt counter */
    interrupt_counter++;

    /* Re-Enable the Interrupt */
    gpio_isr_handler_add(BUTTON_GPIO, gpio_isr_handler, NULL);
    gpio_intr_enable(BUTTON_GPIO);
}

static void setup(void) {

    /* Reset the pin */
    gpio_reset_pin(BUTTON_GPIO);

    /* Set the GPIO to Input mode */
    gpio_set_direction(BUTTON_GPIO, GPIO_MODE_INPUT);

    /* Enable Pullup for Input Pin */
    gpio_pullup_en(BUTTON_GPIO);

    /* Disable pulldown for Input Pin */
    gpio_pulldown_dis(BUTTON_GPIO);

    /* Configure Raising Edge detection Interrupt for Input Pin */
    gpio_set_intr_type(BUTTON_GPIO, GPIO_INTR_POSEDGE);

    /* install gpio isr service to default values */
    gpio_install_isr_service(0);

    /* Attach the ISR to the GPIO interrupt */
    gpio_isr_handler_add(BUTTON_GPIO, gpio_isr_handler, NULL);

    /* Enable the Interrupt */
    gpio_intr_enable(BUTTON_GPIO);
}

void app_main(void)
{
    setup();
    while (1) 
    {
        printf("Interrupt count: %" PRId64 "\n", interrupt_counter);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
