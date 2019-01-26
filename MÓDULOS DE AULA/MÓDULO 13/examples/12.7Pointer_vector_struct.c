#include <stdio.h>
#include <stdlib.h>

// student structure
typedef struct students
{
    char id[15];
    char firstname[64];
    char lastname[64];
    float points;
} student;

int main()
{

    // number of students
    int N;
    printf("Number of students: ");
    scanf("%d", &N);

    // student structure variable
    student *std = (student *)malloc(N*sizeof(student));

    // student structure pointer variable
    student *ptr = NULL;

    // other variables
    int i;

    // assign std to ptr
    ptr = std;

    // get detail for user
    for (i = 0; i < N; i++)
    {
        printf("Enter detail of student #%d\n", (i + 1));
        printf("Enter ID: ");
        scanf("%s", ptr->id);
        printf("Enter first name: ");
        scanf("%s", ptr->firstname);
        printf("Enter last name: ");
        scanf("%s", ptr->lastname);
        printf("Enter Points: ");
        scanf("%f", &ptr->points);

        // update pointer to point at next element the array
        ptr++;
    }

    // reset pointer back to the starting
    // address of std array
    ptr = std;

    for (i = 0; i < N; i++)
    {
        printf("\nDetail of student #%d\n", (i + 1));

        // display result via std variable
        printf("\nResult via std\n");
        printf("ID: %s\n", std[i].id);
        printf("First Name: %s\n", std[i].firstname);
        printf("Last Name: %s\n", std[i].lastname);
        printf("Points: %f\n", std[i].points);

        // display result via ptr variable
        printf("\nResult via ptr\n");
        printf("ID: %s\n", ptr->id);
        printf("First Name: %s\n", ptr->firstname);
        printf("Last Name: %s\n", ptr->lastname);
        printf("Points: %f\n", ptr->points);

        // update pointer to point at next element
        // of the array std
        ptr++;
    }

    return 0;
}
