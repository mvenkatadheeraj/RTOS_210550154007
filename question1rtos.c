#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

QueueHandle_t intmq;
void one_task(void *data)
{
    while(1)
    {
        printf(" one task start \n");
        printf(" one task end \n");
        vTaskDelay(1000/ portTICK_PERIOD_MS);

    }
}

void two_task(void *data)
{
    while(1)
    {
        printf(" second task start \n");
        printf(" second task end \n");
        vTaskDelay(2000/ portTICK_PERIOD_MS);

    }
}

void three_task(void *data)
{
    while(1)
    {
        printf(" third task start \n");
        printf(" third task end \n");
        vTaskDelay(5000/ portTICK_PERIOD_MS);

    }
}




void four_task(void *data)
{
    int value = 508;
    while(1)
    {
        printf(" four task start \n");
        printf(" four task end \n");
        xQueueSend(intmq,&value, 0);
        vTaskDelay(3000/ portTICK_PERIOD_MS);

    }
}


void five_task(void *data)
{
    int buff;
    
    while(1)
    {
        printf("five task start \n");
        xQueueReceive(intmq,&buff, 0);
        printf("value from task4 is: %d\n",buff);
    
        printf(" five task end \n");
        vTaskDelay(3000/ portTICK_PERIOD_MS);
      
      
    }
   
}



void app_main(void)
{
    xTaskCreate(one_task, "one_tsk", 2048, NULL, 10, NULL);
    xTaskCreate(two_task, "two_tsk", 2048, NULL, 8, NULL);
    xTaskCreate(three_task, "three_tsk", 2048, NULL, 6, NULL);
    xTaskCreate(four_task, "four_tsk", 2048, NULL, 5, NULL);
    xTaskCreate(five_task, "five_tsk", 2048, NULL, 3, NULL);
    intmq = xQueueCreate(3, sizeof(int));

