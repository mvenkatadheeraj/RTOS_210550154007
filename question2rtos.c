#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


void one_task(void *data)
{
    while (1)
    {
        printf(" one_task created "); 
        vTaskDelay(1000/portTICK_PERIOD_MS);
    
    }
    
    
}

void two_task(void *data)
{
    while (1)
    {
        printf(" one_task created "); 
        vTaskDelay(2000/portTICK_PERIOD_MS);
    
    }
    
    
}
void three
_task(void *data)
{
    while (1)
    {
        printf(" one_task created "); 
        vTaskDelay(5000/portTICK_PERIOD_MS);
    
    }
    
    
}
void app_main(void)
{
    int i = 0;
    xTaskCreate(one_task, "temp_tsk", 2048, NULL, 10, NULL);
    xTaskCreate(two_task, "temp_tsk", 2048, NULL, 11, NULL);
    xTaskCreate(three_task, "temp_tsk", 2048, NULL, 12, NULL);
    
    while (1) {
        printf("[%d] Hello world!\n", i);
        i++;
        vTaskDelay(10000 / portTICK_PERIOD_MS);
    }
}
