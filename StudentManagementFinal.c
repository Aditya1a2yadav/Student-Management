#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void spaces(void)
{
    int n = 9;
    while (n--)
    {
        printf("\t");
    }
}

//-------Structure for Students-------
struct node
{
    char name[20];
    char roll[20];
    char gender[20];
    char admi_no[20];
    char att_ee[20];
    char att_MA[20];
    char att_CS[20];
    char att_PH[20];
    char gra_EE[20];
    char gra_MA[20];
    char gra_CS[20];
    char gra_PH[20];
    struct node *next;
};
typedef struct node node;

//-------Structure for Faculty-------
struct faculty
{
    char course[40];
    char name[40];
    char dept[40];
    char post[40];
    char em_id[40];
    struct faculty *next;
};
typedef struct faculty faculty;

//-------Fuction for traversing-------
void traversal(node *ptr)
{
    int i = 1;
    while (1)
    {
        printf("\t\t%d.---------------------------------------------------\n", i);
        i++;
        printf("\t\tRoll No.: %s\n", ptr->roll);
        printf("\t\tName: %s\n", ptr->name);
        printf("\t\tAdmission No.: %s\n", ptr->admi_no);
        printf("\t\tGender: %s\n", ptr->gender);
        if (ptr->next->next == NULL)
            break;
        ptr = ptr->next;
    }
    printf("\n");
}

//-------Fuction for creation of Linked List-------
node *create_list()
{
    int k, n;
    node *p, *head;

    spaces();
    printf("How many students do you want to add?");
    scanf("%d", &n);

    FILE *ptr;
    ptr = fopen("text.txt", "a+");

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            head = (node *)malloc(sizeof(node));
            p = head;
        }
        else
        {
            p->next = (node *)malloc(sizeof(node));
            p = p->next;
        }
        char temp;
        spaces();
        printf("\nStudent %d\n\n", i + 1);

        spaces();
        printf("ROLL NUMBER : ");
        scanf("%s", p->roll);
        fprintf(ptr, "%s\n", p->roll);

        spaces();
        printf("NAME : ");
        scanf("%c", &temp);
        scanf("%[^\n]", p->name);
        fprintf(ptr, "%s\n", p->name);

        spaces();
        printf("ADIMISSION NUMBER : ");
        scanf("%s", p->admi_no);
        fprintf(ptr, "%s\n", p->admi_no);

        spaces();
        printf("GENDER : ");
        scanf("%s", p->gender);
        fprintf(ptr, "%s\n", p->gender);

        spaces();
        printf("Attendence in EE101 : ");
        scanf("%s", p->att_ee);
        fprintf(ptr, "%s\n", p->att_ee);

        spaces();
        printf("Attendence in MA101 : ");
        scanf("%s", p->att_MA);
        fprintf(ptr, "%s\n", p->att_MA);

        spaces();
        printf("Attendence in CS102 : ");
        scanf("%s", p->att_CS);
        fprintf(ptr, "%s\n", p->att_CS);

        spaces();
        printf("Attendence in PH103 : ");
        scanf("%s", p->att_PH);
        fprintf(ptr, "%s\n", p->att_PH);

        spaces();
        printf("Grade in EE101 : ");
        scanf("%s", p->gra_EE);
        fprintf(ptr, "%s\n", p->gra_EE);

        spaces();
        printf("Grade in MA101 : ");
        scanf("%s", p->gra_MA);
        fprintf(ptr, "%s\n", p->gra_MA);

        spaces();
        printf("Grade in CS102 : ");
        scanf("%s", p->gra_CS);
        fprintf(ptr, "%s\n", p->gra_CS);

        spaces();
        printf("Grade in PH103 : ");
        scanf("%s", p->gra_PH);
        fprintf(ptr, "%s\n", p->gra_PH);

        spaces();
        printf("  \n");
        spaces();
        printf(" Info of student %d complete \n", i + 1);
    }
    fclose(ptr);
    p->next = NULL;
    return head;
}

//-------Fuction to convert file content of students Linked List-------
node *ftoll()
{
    node *head = (node *)malloc(sizeof(node));
    node *p;
    p = head;
    FILE *ptr;
    int c = 0;
    ptr = fopen("text.txt", "r");
    char s[20];
    while (fgets(s, 20, ptr))
    {
        c++;
        strcpy(p->roll, s);
        fgets(s, 20, ptr);
        strcpy(p->name, s);
        fgets(s, 20, ptr);
        strcpy(p->admi_no, s);
        fgets(s, 20, ptr);
        strcpy(p->gender, s);
        fgets(s, 20, ptr);
        strcpy(p->att_ee, s);
        fgets(s, 20, ptr);
        strcpy(p->att_MA, s);
        fgets(s, 20, ptr);
        strcpy(p->att_CS, s);
        fgets(s, 20, ptr);
        strcpy(p->att_PH, s);
        fgets(s, 20, ptr);
        strcpy(p->gra_EE, s);
        fgets(s, 20, ptr);
        strcpy(p->gra_MA, s);
        fgets(s, 20, ptr);
        strcpy(p->gra_CS, s);
        fgets(s, 20, ptr);
        strcpy(p->gra_PH, s);
        // fgets(s, 20, ptr);
        p->next = (node *)malloc(sizeof(node));
        p = p->next;
    }
    p->next = NULL;
    return (head);
}

//-------Fuction for string comparison-------
int strcomp(char *x, char *y, int lenx, int leny)
{
    int i = 0;
    for (int i = 0; i < lenx, i < leny; i++)
    {
        if (x[i] > y[i])
        {
            return -1;
        }
        else if (x[i] < y[i])
        {
            return 1;
        }
    }
    if (i < lenx)
    {
        return -1;
    }
    else if (i < leny)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//-------Fuction for searching students-------
void search(node *head1, int m)
{
    node *p;
    p = head1;
    char a[20];
    if (m == 1)
    {
        spaces();
        printf("Enter the Roll no. : ");
        scanf("%s", a);
    }
    else if (m == 2)
    {
        spaces();
        printf("Enter the Name : ");
        char temp;
        scanf("%c", &temp);
        scanf("%[^\n]", a);
    }
    else if (m == 3)
    {
        spaces();
        printf("Enter the gender : ");
        scanf("%s", a);
    }
    printf("\n");
    int e = 1;
    while (p->next != NULL)
    {
        char u[20];
        if (m == 1)
        {
            strcpy(u, p->roll);
        }
        else if (m == 2)
        {
            strcpy(u, p->name);
        }
        else if (m == 3)
        {
            strcpy(u, p->gender);
        }
        int v = strlen(a), g = 0;
        for (int i = 0; i < v; i++)
        {
            if (u[i] != a[i])
            {
                g = 1;
            }
        }

        if (g == 0)
        {
            spaces();
            printf("%d:---------------------------\n", e);
            e++;
            spaces();
            printf("Roll No.: %s", p->roll);
            spaces();
            printf("Name: %s", p->name);
            spaces();
            printf("Admi_No.: %s", p->admi_no);
            spaces();
            printf("Gender: %s", p->gender);
        }

        p = p->next;
    }
    printf("\n");
}

//-------Fuction for rewriting-------
void rewriteF(node *head)
{
    node *p = head;
    FILE *ptr;
    ptr = fopen("text.txt", "w+");
    while (p->next != NULL)
    {
        fprintf(ptr, "%s", p->roll);
        fprintf(ptr, "%s", p->name);
        fprintf(ptr, "%s", p->admi_no);
        fprintf(ptr, "%s", p->gender);
        fprintf(ptr, "%s", p->att_ee);
        fprintf(ptr, "%s", p->att_MA);
        fprintf(ptr, "%s", p->att_CS);
        fprintf(ptr, "%s", p->att_PH);
        fprintf(ptr, "%s", p->gra_EE);
        fprintf(ptr, "%s", p->gra_MA);
        fprintf(ptr, "%s", p->gra_CS);
        fprintf(ptr, "%s", p->gra_PH);
        p = p->next;
    }
    fclose(ptr);
}

//-------Fuction for modificationt-------
node *modified(node *head)
{
    int m = 1;
    node *p;
    p = head;
    char r[20];
    spaces();
    printf("Enter Student Roll No.: ");
    scanf("%s", r);
    int g;
    while (p->next != NULL)
    {
        char u[20];
        strcpy(u, p->roll);
        int v = strlen(r);
        g = 0;
        for (int i = 0; i < v; i++)
        {
            if (u[i] != r[i])
            {
                g = 1;
            }
        }
        if (g == 0)
        {
            break;
        }
        p = p->next;
    }
    printf("\n");
    if (g == 0)
    {
        spaces();
        printf("---------------------------------\n");
        spaces();
        printf("|Old data!                      |\n");
        spaces();
        printf("---------------------------------\n");
        spaces();
        printf("Roll No.: %s\n", p->roll);
        spaces();
        printf("Name: %s\n", p->name);
        spaces();
        printf("Admi_No.: %s\n", p->admi_no);
        spaces();
        printf("Gender: %s\n", p->gender);
        printf("\n");
        spaces();
        printf("---------------------------------\n");
        spaces();
        printf("|Enter new data with changes..  |\n");
        spaces();
        printf("---------------------------------\n");
        spaces();
        char ch = '\n';
        printf("ROLL NUMBER : ");
        scanf("%s", p->roll);
        strncat(p->roll, &ch, 1);

        spaces();
        char temp;
        printf("NAME : ");
        scanf("%c", &temp);
        scanf("%[^\n]", p->name);
        strncat(p->name, &ch, 1);

        spaces();
        printf("ADIMISSION NUMBER : ");
        scanf("%s", p->admi_no);
        strncat(p->admi_no, &ch, 1);

        spaces();
        printf("GENDER : ");
        scanf("%s", p->gender);
        strncat(p->gender, &ch, 1);
    }
    else if (g == 1)
    {
        spaces();
        printf("---------------------------------------------------------------\n");
        spaces();
        printf("|Error!! Student not found.You need to add this student first.|\n");
        spaces();
        printf("---------------------------------------------------------------\n\n");
    }
    return head;
}

//-------Fuction to covert file content of faculty to Linked List-------
faculty *ftoll_fac()
{
    faculty *head = (faculty *)malloc(sizeof(faculty));
    faculty *p;
    p = head;
    FILE *ptr;
    int c = 0;
    ptr = fopen("course.txt", "r");
    char s[40];
    while (fgets(s, 40, ptr))
    {
        c++;
        strcpy(p->course, s);
        fgets(s, 40, ptr);
        strcpy(p->name, s);
        fgets(s, 40, ptr);
        strcpy(p->dept, s);
        fgets(s, 40, ptr);
        strcpy(p->post, s);
        fgets(s, 40, ptr);
        strcpy(p->em_id, s);
        p->next = (faculty *)malloc(sizeof(faculty));
        p = p->next;
    }
    p->next = NULL;
    return (head);
}

//-------Fuction for searching faculty-------
void search_fac(faculty *head2)
{
    faculty *p;
    p = head2;
    char a[20];
    spaces();
    printf("Enter the Course : ");
    scanf("%s", a);
    printf("\n");
    while (p->next != NULL)
    {
        char u[20];
        strcpy(u, p->course);
        int v = strlen(a), g = 0;
        for (int i = 0; i < v; i++)
        {
            if (u[i] != a[i])
            {
                g = 1;
            }
        }
        if (g == 0)
        {
            printf("\n");
            spaces();
            printf("%s", p->name);
            spaces();
            printf("%s", p->dept);
            spaces();
            printf("%s", p->post);
            spaces();
            printf("%s", p->em_id);
            printf("\n");
            // break;
        }
        p = p->next;
    }
}

//-------Fuction for Student performance-------
void course_str(node *head3)
{
    node *p;
    p = head3;
    char a[20];
    spaces();
    printf("Enter the Roll no. : ");
    scanf("%s", a);
    printf("\n");
    while (p->next != NULL)
    {
        char u[20];
        strcpy(u, p->roll);
        int v = strlen(a);
        int g = 0;
        for (int i = 0; i < v; i++)
        {
            if (u[i] != a[i])
            {
                g = 1;
            }
        }
        if (g == 0)
        {
            p->att_CS[2] = '\0';
            p->att_ee[2] = '\0';
            p->att_MA[2] = '\0';
            p->att_PH[2] = '\0';
            p->gra_CS[2] = '\0';
            p->gra_EE[2] = '\0';
            p->gra_MA[2] = '\0';
            p->gra_PH[2] = '\0';
            spaces();
            printf("###############################\n");
            spaces();
            printf("|Course   |");
            printf("Attendance |");
            printf("Grades |\n");
            spaces();
            printf("|_________|");
            printf("___________|");
            printf("_______|\n");
            spaces();
            printf("|EE101    |");
            printf("%s         |", p->att_ee);
            printf("%s     |\n", p->gra_EE);
            spaces();
            printf("|MA101    |");
            printf("%s         |", p->att_MA);
            printf("%s     |\n", p->gra_MA);
            spaces();
            printf("|CS102    |");
            printf("%s         |", p->att_CS);
            printf("%s     |\n", p->gra_CS);
            spaces();
            printf("|PH103    |");
            printf("%s         |", p->att_PH);
            printf("%s     |\n", p->gra_PH);
            spaces();
            printf("###############################\n");
        }
        p = p->next;
    }
    printf("\n");
}

int main()
{
    printf("\t\t::::::::::: ::::::::::: ::::::::::: :::::::::        :::::::: ::::::::::: :::    ::: :::::::::  :::::::::: ::::    ::: :::::::::::      :::::::::      ::: ::::::::::: :::     \n");
    printf("\t\t    :+:         :+:         :+:     :+:    :+:      :+:    :+:    :+:     :+:    :+: :+:    :+: :+:        :+:+:   :+:     :+:          :+:    :+:   :+: :+:   :+:   :+: :+:   \n");
    printf("\t\t    +:+         +:+         +:+     +:+    +:+      +:+           +:+     +:+    +:+ +:+    +:+ +:+        :+:+:+  +:+     +:+          +:+    +:+  +:+   +:+  +:+  +:+   +:+  \n");
    printf("\t\t    +#+         +#+         +#+     +#++:++#+       +#++:++#++    +#+     +#+    +:+ +#+    +:+ +#++:++#   +#+ +:+ +#+     +#+          +#+    +:+ +#++:++#++: +#+ +#++:++#++: \n");
    printf("\t\t    +#+         +#+         +#+     +#+                    +#+    +#+     +#+    +#+ +#+    +#+ +#+        +#+  +#+#+#     +#+          +#+    +#+ +#+     +#+ +#+ +#+     +#+ \n");
    printf("\t\t    #+#         #+#         #+#     #+#             #+#    #+#    #+#     #+#    #+# #+#    #+# #+#        #+#   #+#+#     #+#          #+#    #+# #+#     #+# #+# #+#     #+# \n");
    printf("\t\t########### ###########     ###     ###              ########     ###      ########  #########  ########## ###    ####     ###          #########  ###     ### ### ###     ### \n");
    printf("\t\t###############################################################################################################################################################################\n");
    while (2 > 1)
    {
        FILE *f;
        f = fopen("text.txt", "a+");
        printf("\n");
        spaces();
        printf("##############################################\n");
        spaces();
        printf("|To ADD in student's list : CODE=1           |\n");
        spaces();
        printf("|To Search for students : CODE=2             |\n");
        spaces();
        printf("|Student's Performance : CODE=3              |\n");
        spaces();
        printf("|Want to change the Information : CODE=4     |\n");
        spaces();
        printf("|Want to Get list of students : CODE=5       |\n");
        spaces();
        printf("|Want to End This Journey : CODE=0           |\n");
        spaces();
        printf("##############################################\n");
        spaces();
        printf("\n");
        spaces();
        printf("What do you want to do : ");
        int n;
        scanf("%d", &n);
        spaces();
        printf("\n");
        spaces();
        printf("\n");
        node *head = (node *)malloc(sizeof(node));
        head = ftoll();

        if (n == 1) // Addition of students
        {
            head = create_list();
        }
        else if (n == 2) // Searching of students
        {
            spaces();
            printf("**********************************************\n");
            spaces();
            printf("|On the basis of ROLL NO. : CODE 1           |\n");
            spaces();
            printf("|On the basis of NAME : CODE 2               |\n");
            spaces();
            printf("|On the basis of GENDER : CODE 3             |\n");
            spaces();
            printf("**********************************************\n");
            int m;
            spaces();
            printf("Enter the CODE : ");
            scanf("%d", &m);

            search(head, m);
        }
        else if (n == 3) // Student performance
        {

            spaces();
            printf("For Faculty : CODE=1\n");
            spaces();
            printf("For Students : CODE=2\n");
            spaces();
            printf("Enter the CODE : ");
            int b;
            scanf("%d", &b);
            if (b == 1)
            {
                spaces();
                printf("EE101\n");
                spaces();
                printf("MA101\n");
                spaces();
                printf("CS102\n");
                spaces();
                printf("PH103\n");
                faculty *head2;
                head2 = ftoll_fac();
                search_fac(head2);
            }
            else
            {
                node *head3;
                head3 = ftoll();
                course_str(head3);
            }
        }
        else if (n == 4) // Modification / Changes
        {
            head = modified(head);
            rewriteF(head);
        }
        else if (n == 5) // Display of List
        {
            traversal(head);
        }
        else if (n == 0) // Exit
        {
            spaces();
            printf("###############################################\n");
            spaces();
            printf("|           Thanks For Your Time....          |\n");
            spaces();
            printf("###############################################\n");
            break;
        }
    }
    return 0;
}
