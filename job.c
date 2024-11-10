#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "job.h"

#define MAX_JOBS 100

typedef struct {
    int id;
    char title[100];
    char description[256];
} Job;

static Job jobs[MAX_JOBS];
static int job_count = 0;

void add_job() {
    if (job_count >= MAX_JOBS) {
        printf("Job list is full. Cannot add more jobs.\n");
        return;
    }

    Job new_job;
    new_job.id = job_count + 1; // Simple ID assignment
    printf("Enter job title: ");
    getchar(); // Clear newline from buffer
    fgets(new_job.title, sizeof(new_job.title), stdin);
    new_job.title[strcspn(new_job.title, "\n")] = 0; // Remove newline character

    printf("Enter job description: ");
    fgets(new_job.description, sizeof(new_job.description), stdin);
    new_job.description[strcspn(new_job.description, "\n")] = 0; // Remove newline character

    jobs[job_count++] = new_job;
    printf("Job added successfully!\n");
}

void view_jobs() {
    if (job_count == 0) {
        printf("No jobs available.\n");
        return;
    }

    printf("\nJob List:\n");
    for (int i = 0; i < job_count; i++) {
        printf("ID: %d\n", jobs[i].id);
        printf("Title: %s\n", jobs[i].title);
        printf("Description: %s\n\n", jobs[i].description);
    }
}

void delete_job() {
    int id;
    printf("Enter job ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > job_count) {
        printf("Invalid job ID.\n");
        return;
    }

    for (int i = id - 1; i < job_count - 1; i++) {
        jobs[i] = jobs[i + 1]; // Shift jobs left
    }
    job_count--;
    printf("Job deleted successfully!\n");
}
