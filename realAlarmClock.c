#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <time.h>

void alarm(struct tm currentTime,int alarmTime)
{
    int alarmHour = alarmTime / 10000; 
    int alarmMinute = (alarmTime % 10000) / 100; 
    int alarmSecond = alarmTime % 100;
    int choice;

    if (currentTime.tm_hour == alarmHour &&
        currentTime.tm_min == alarmMinute &&
        currentTime.tm_sec == alarmSecond)
    {
        printf("ALARM! ALARM! Current time is: %02dhr-%02dmin-%02dsec\n",
        currentTime.tm_hour,
        currentTime.tm_min,
        currentTime.tm_sec);
 
    printf("Would you like to set another Alarm?\n");
    printf("1 -- Yes || 2 -- No\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        main();
    }
    else if (choice == 2)
    {
        printf("Have a Nice Day!");
        return(0);
    }
    else
    {
        exit(0);
    }
    }

}

int main()
{
    time_t rawTime = time(NULL);
    struct tm currentTime = *localtime(&rawTime);
    int alarmTime;

    printf("Your current time (24hrs format) is: %02dhr-%02dmins-%02dsecs\n",
    currentTime.tm_hour,
    currentTime.tm_min,
    currentTime.tm_sec);
    
    printf("Please input your Alarm Time in format of HHMMSS (24hrs format):\n");
    if (scanf("%6d", &alarmTime) != 1)
    {
       printf("DUde it's invalid try to read the intruction!\n");
       return 1;
    }
    else if (alarmTime < 0 || alarmTime > 235959)
    {
        printf("Its INvalid format, try again");
       return 1;
    }
    else
    {
        printf("alarm has been set!...\n");
    }
    
    while (1)
    {
        time(&rawTime);
        currentTime = *localtime(&rawTime);
        alarm(currentTime, alarmTime);
        sleep(1); 
    }

return 0; 
}