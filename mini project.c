#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_JOBS 100
#define MAX_APPLICATIONS 500
#define MAX_LENGTH 100
struct Job 
{
    int id;
    char title[MAX_LENGTH];
    char company[MAX_LENGTH];
    char description[MAX_LENGTH];
    char requirements[MAX_LENGTH];
};
struct Application 
{
    int id;
    int job_id;
    char applicant_name[MAX_LENGTH];
    char applicant_email[MAX_LENGTH];
    char status[20];
};
struct Job jobs[MAX_JOBS];
struct Application applications[MAX_APPLICATIONS];
int job_count = 0;
int application_count = 0;
void post_job();
void search_jobs();
void apply_for_job();
void manage_applications();
void display_job(struct Job job);
int main() 
{
    int choice;
    while (1) 
{
        printf("\nJob Portal\n");
        printf("1. Post a job (Employer)\n");
        printf("2. Search jobs (Job Seeker)\n");
        printf("3. Apply for a job (Job Seeker)\n");
        printf("4. Manage applications (Employer)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                post_job();
                break;
            case 2:
                search_jobs();
                break;
            case 3:
                apply_for_job();
                break;
            case 4:
                manage_applications();
                break;
            case 5:
                printf("Thank you for using the Job Portal. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void post_job() 
{
    if (job_count >= MAX_JOBS) {
        printf("Maximum number of jobs reached.\n");
        return;
    }
    
    struct Job new_job;
    new_job.id = job_count + 1;
    
    printf("Enter job title: ");
    scanf(" %[^\n]", new_job.title);
    
    printf("Enter company name: ");
    scanf(" %[^\n]", new_job.company);
    
    printf("Enter job description: ");
    scanf(" %[^\n]", new_job.description);
    
    printf("Enter job requirements: ");
    scanf(" %[^\n]", new_job.requirements);
    
    jobs[job_count++] = new_job;
    printf("Job posted successfully.\n");
}

void search_jobs() 
{
    char keyword[MAX_LENGTH];
    printf("Enter a keyword to search for jobs: ");
    scanf(" %[^\n]", keyword);
    
    printf("\nSearch Results:\n");
    for (int i = 0; i < job_count; i++) {
        if (strstr(jobs[i].title, keyword) || strstr(jobs[i].description, keyword)) {
            display_job(jobs[i]);
        }
    }
}

void apply_for_job() 
{
    int job_id;
    printf("Enter the ID of the job you want to apply for: ");
    scanf("%d", &job_id);
    
    struct Application new_application;
    new_application.id = application_count + 1;
    new_application.job_id = job_id;
    
    printf("Enter your name: ");
    scanf(" %[^\n]", new_application.applicant_name);
    
    printf("Enter your email: ");
    scanf(" %[^\n]", new_application.applicant_email);
    
    strcpy(new_application.status, "Pending");
    
    applications[application_count++] = new_application;
    printf("Application submitted successfully.\n");
}

void manage_applications() 
{
    int job_id;
    printf("Enter the job ID to view applications: ");
    scanf("%d", &job_id);
    
    printf("\nApplications for Job ID %d:\n", job_id);
    for (int i = 0; i < application_count; i++) {
        if (applications[i].job_id == job_id) {
            printf("Application ID: %d\n", applications[i].id);
            printf("Applicant Name: %s\n", applications[i].applicant_name);
            printf("Applicant Email: %s\n", applications[i].applicant_email);
            printf("Status: %s\n\n", applications[i].status);
        }
    }
}

void display_job(struct Job job) 
{
    printf("\nJob ID: %d\n", job.id);
    printf("Title: %s\n", job.title);
    printf("Company: %s\n", job.company);
    printf("Description: %s\n", job.description);
    printf("Requirements: %s\n", job.requirements);
    printf("\n");
}
