#include <stdio.h>
struct student{
    int roll_no;
    char name[20];
    int sem;
    int m1,m2,m3;
    };
void enter_details(struct student *ptr){
    int i;
    for(i=0;i<5;i++){
        printf("Enter the details of student %d",i+1);
        printf("\nName: ");
        scanf("%s",ptr->name);
        printf("Roll No: ");
        scanf("%d",&ptr->roll_no);
        printf("Semester: ");
        scanf("%d",&ptr->sem);
        printf("Marks of subject 1: ");
        scanf("%d",&ptr->m1);
        printf("Marks of subject 2: ");
        scanf("%d",&ptr->m2);
        printf("Marks of subject 3: ");
        scanf("%d",&ptr->m3);
        ptr++;
    }
}

void display(struct student *ptr) {
    int i;
    for(i=0;i<5;i++){
        printf("\nDetails of student %d",i+1);
        printf("\nName: %s",ptr->name);
        printf("\nRoll No: %d",ptr->roll_no);
        printf("\nSemester: %d",ptr->sem);
        printf("\nMarks of subject 1: %d",ptr->m1);
        printf("\nMarks of subject 2: %d",ptr->m2);
        printf("\nMarks of subject 3: %d",ptr->m3);
        ptr++;
    }
}
void total(struct student *ptr){
    int i,total,sub1,sub2,sub3;
    total=0;
    sub1=0;
    sub2=0;
    sub3=0;
    printf("Student wise total \n");
    for(i=0;i<5;i++){
        total=ptr->m1+ptr->m2+ptr->m3;
        printf("total:%d",total);
        sub1=sub1+ptr->m1;
        sub2=sub2+ptr->m2;
        sub3=sub3+ptr->m3;
        ptr++;
    }
    printf("subject wise total:\n");
    printf("subject1:%d",sub1);
    printf("subject2:%d",sub2);
    printf("subject3:%d",sub3);
}
void main(){
    struct student s[5];
    enter_details(s);
    display(s);
    total(s);
}