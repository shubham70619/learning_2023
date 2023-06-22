#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 100

struct LogEntry {
    int entryNo;
    char sensorNo[3];
    float temperature;
    int humidity;
    int light;
    char time[9];
};

void extractLogEntries(FILE *file, struct LogEntry logEntries[], int *numEntries) {
    char line[MAX_LINE_LENGTH];
    *numEntries = 0;

    while (fgets(line, sizeof(line), file) != NULL && *numEntries < MAX_ENTRIES) {
        struct LogEntry entry;

        sscanf(line, "%d,%[^,],%f,%d,%d,%s", &entry.entryNo, entry.sensorNo, &entry.temperature,
               &entry.humidity, &entry.light, entry.time);

        logEntries[*numEntries] = entry;
        (*numEntries)++;
    }
}

void displayLogEntries(struct LogEntry logEntries[], int numEntries) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTime\n");
    for (int i = 0; i < numEntries; i++) {
        struct LogEntry entry = logEntries[i];
        printf("%d\t%s\t\t%.2f\t\t%d\t\t%d\t%s\n", entry.entryNo, entry.sensorNo,
               entry.temperature, entry.humidity, entry.light, entry.time);
    }
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    struct LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    extractLogEntries(file, logEntries, &numEntries);

    displayLogEntries(logEntries, numEntries);

    fclose(file);

    return 0;
}
