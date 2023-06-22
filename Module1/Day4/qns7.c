#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long computeTotalSeconds(const char *timeString) {
    char *token;
    char *strCopy;
    unsigned long totalSeconds = 0;
    
    // Create a copy of the timeString for tokenization
    strCopy = strdup(timeString);
    
    // Split the timeString into hours, minutes, and seconds using strtok
    token = strtok(strCopy, ":");
    int hours = strtoul(token, NULL, 10);
    token = strtok(NULL, ":");
    int minutes = strtoul(token, NULL, 10);
    token = strtok(NULL, ":");
    int seconds = strtoul(token, NULL, 10);
    
    // Compute total seconds
    totalSeconds = hours * 3600 + minutes * 60 + seconds;
    
    // Free the allocated memory
    free(strCopy);
    
    return totalSeconds;
}

int main() {
    const char *timeString1 = "10:12:50";
    const char *timeString2 = "13:10:40";
    
    unsigned long totalSeconds1 = computeTotalSeconds(timeString1);
    unsigned long totalSeconds2 = computeTotalSeconds(timeString2);
    
    printf("Time: %s\nTotal Seconds: %lu\n", timeString1, totalSeconds1);
    printf("Time: %s\nTotal Seconds: %lu\n", timeString2, totalSeconds2);
    
    return 0;
}
