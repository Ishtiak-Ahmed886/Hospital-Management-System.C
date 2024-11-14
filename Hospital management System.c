#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
 Front_page();
 login_system();
 welcome_screen();

}


void Front_page(){
    printf("\n");    printf("\n");
    printf("\n");    printf("\n");
    printf("\n");    printf("\n");
    printf("\n");    printf("\n");
    printf("\t\t\t\t|-----------------------------------|\n");    printf("\t\t\t\t|\t\t\t            |\n");
    printf("\t\t\t\t|\t\t\t            |\n");    printf("\t\t\t\t|\t   A MINI PROJECT           |\n");
    printf("\t\t\t\t|\t\t ON  \t\t    |\n");    printf("\t\t\t\t|    HOSPITAL MANAGEMENT SYSTEM     |\n");
    printf("\t\t\t\t|\t\t\t\t    |\n");    printf("\t\t\t\t|\t\t\t\t    |\n");
    printf("\t\t\t\t|-----------------------------------|\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t CREATED BY:(Ishtiak,Argho and kawsar)\n");
    getch();
}


void saveAdminCredentialsToFile(char adminUsername[], char adminPassword[]) {
    FILE *file;
    file = fopen("admin_credentials.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "%s %s", adminUsername, adminPassword);
    fclose(file);
}

void signUpAdmin() {
    system("cls");

    char adminUsername[20];
    char adminPassword[20];

    printf("\t\t\tAdmin credentials not found. Let's sign up a new admin.\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t\tEnter new admin username: ");
    scanf("%s", adminUsername);
    printf("\n");
    printf("\t\t\t\tEnter new admin password: ");
    scanf("%s", adminPassword);

    saveAdminCredentialsToFile(adminUsername, adminPassword);
    printf("\t\t\t\tAdmin signup successful!\n");
}

void login_system() {
    system("cls");
    char username[20];
    char password[20];
    char fileUsername[20];
    char filePassword[20];
    int isAdminFound = 0;

    FILE *file;
    file = fopen("admin_credentials.txt", "r");
    if (file != NULL) {
        fscanf(file, "%s %s", fileUsername, filePassword);
        fclose(file);
        isAdminFound = 1;
    }

    if (!isAdminFound) {
        signUpAdmin();
        return;
    }

    printf("\t\t\t\t<<<_PLEASE ENTER YOUR USERNAME AND PASSWORD_>>>\n");
    printf("\t\t\t|----------------------------------------------------------------|\n");
    printf("\n");
    re:
    printf("\t\t\t\tUSERNAME: ");
    scanf("%s", username);

    printf("\t\t\t\tPASSWORD: ");
    scanf("%s", password);

    if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0) {
            system("cls");
            printf("\n");
        printf("\n");
        printf("\t\t\t\t-Admin login successful!-\n");
        getch();
    } else {
        system("cls");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\t\t\t\tIncorrect username or password.\n");
        getch();
        login_system();

        goto re;
    }
}




void welcome_screen()
{
    system("cls");
    int choice;

    printf("\t\t\t\t<<<WELCOME TO ABC HOSPITAL>>>\n");
    printf("\t\t\t<<--------------------------------------------->>\n\n\n");
    printf("\t\t\t\t1.PATIENT'S MANAGEMENT AREA.\n");
    printf("\t\t\t\t2.DOCTOR'S MANAGEMENT AREA.\n");
    printf("\t\t\t\t3.Change Admin\n");
    printf("\t\t\t\t4.EXIT.\n");
    printf("\n");
    printf("\t\t\t\tPLEASE ENTER YOUR CHOICE:");

    scanf("%d",&choice);

    if(choice==1)
        {
         patient() ;
    }
    else if(choice==2)
        {
         doctor();
    }else if(choice == 3){
        changeAdminCredentials();
    }else if(choice==4)
    {
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\t\t\t\tExiting\n");
    }

    else
    {
        system("cls");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\t\t\t\tinvalid choice !!!please enter the right choice.");
        getch();
        welcome_screen();

    }


    getch();
}




struct Patient {
    int id;
    char name[50];
    int age;
    char gander[20];
    char diseases[30];
    struct Patient *next;
};
struct Patient *head = NULL;

void addPatient(int id, char *name, int age,char *gander,char *diseases) {
    struct Patient *newPatient = (struct Patient *)malloc(sizeof(struct Patient));
    newPatient->id = id;
    strcpy(newPatient->name, name);
    newPatient->age = age;
    strcpy(newPatient->gander,gander);
    strcpy(newPatient->diseases,diseases);
    newPatient->next = head;
    head = newPatient;
    system("cls");
    printf("\n");
    printf("\n");
    printf("\t\t\t\t-Patient added successfully!-\n");
    getch();
}

void save_File() {
    FILE *file = fopen("patients.txt", "w");
    if (file == NULL) {
        printf("Error opening the file!\n");
        return;
    }
    struct Patient *current = head;
    while (current != NULL) {
        fprintf(file, "ID: %d, Name: %s, Age: %d,Gander: %s,Diseases: %s\n", current->id, current->name, current->age,current->gander,current->diseases);
        current = current->next;

    }

    fclose(file);
    printf("\t\t\t\tPatient information saved to file!\n");
    getch();
    patient();
}

void displayPatients() {
    if (head == NULL) {
            system("cls");
            printf("\n");
            printf("\n");
            printf("\n");
        printf("\t\t\t\tNo patients in the list.\n");
        getch();
        patient();
        return;
    }

    struct Patient *current = head;
    printf("\n");
    printf("\t\t\t\tPatient Information:\n");
    printf("\t\t\t----------------------------------\n");
    printf("\n");

    int no=1;

    while (current != NULL) {

            printf("\t\t\tpatient serial no:%d\n",no);
            printf("\t\t\t-----------------\n");

        printf("\t\t\t\tID: %d\n\t\t\t\tName: %s\n \t\t\t\tAge: %d\n\t\t\t\tGander: %s\n\t\t\t\tDiseases: %s\n", current->id, current->name, current->age,current->gander,current->diseases);
        printf("\n");
        current = current->next;
        no++;
        getch();
    }
    patient();
}

void dischargePatient(int id) {
    struct Patient *current = head;
    struct Patient *prev = NULL;

    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("\t\t\tPatient ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("\t\t\t\tPatient with ID %d discharged.\n", id);
    getch();
    patient();
}


void patient() {
    int choice, id, age;
    char name[50];
    char gander[20];
    char diseases[30];

system("cls");
    do {
        printf("\t\t\t\t<<<<PATIENT MANAGEMANT AREA>>>>\n");
        printf("\t\t\t<<<---------------------------------------->>>\n");
        printf("\t\t\t\t 1.Add Patient.\n");
        printf("\t\t\t\t 2.Patient Information save in File.\n");
        printf("\t\t\t\t 3.Show patient data.\n");
        printf("\t\t\t\t 4.Discharge Patient.\n");
        printf("\t\t\t\t 5.Exit.\n");
        printf("\n");
        printf("\n");
        printf("\t\t\t Select your choice(from 1 to 5): ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                   system("cls");
                printf("\t\t\t\t<<-PLEASE INPUT PATIENT INFORMATION->>\n");
                printf("\t\t\t:-------------------------------------------------:");
                printf("\n");
                printf("\t\t\t\tEnter patient ID: ");
                scanf("%d", &id);
                printf("\t\t\t\tEnter patient name: ");
                scanf(" %[^\n]", name);
                printf("\t\t\t\tEnter patient age: ");
                scanf(" %d", &age);
                printf("\t\t\t\tEnter patient gender:");
                scanf("%s",gander);
                printf("\t\t\t\tEnter patient diseases:");
                scanf(" %[^\n]",diseases);
                addPatient(id, name, age,gander,diseases);
                patient();
                break;

            case 2:
                    system("cls");
                save_File();
                break;
            case 3:
                   system("cls");
                displayPatients();
                break;
            case 4:
                   system("cls");
                   printf("\n");
                printf("\t\t\t\tEnter patient ID to discharge: ");
                scanf("%d", &id);
                dischargePatient(id);
                break;
            case 5:
                   system("cls");
                   printf("\n");
                   printf("\n");
                printf("\t\t\t\tExiting...\n");
                getch();
                welcome_screen();
                break;
            default:
                     system("cls");
                printf("\t\t\t\tInvalid choice! Please enter a valid option.\n");
                getch();
                patient();

        }
    } while (choice != 5);
    return 0;
}



struct Doctor {
    char name[50];
    char specialization[50];
    int experience;
    int age;
    int contact;
    struct Doctor *next;
};

struct Doctor *d_head=NULL;

void addDoctor() {
    struct Doctor *curr;
    struct Doctor *newDoctor = (struct Doctor *)malloc(sizeof(struct Doctor));
    if (!newDoctor) {
        printf("\t\t\t\tMemory allocation failed!\n");
        return;
    }
    printf("\t\t\t\t<<<_PLEASE INPUT A DOCTOR'S INFORMATION_>>>\n");
    printf("\t\t\t|----------------------------------------------------|\n");
    printf("\t\t\t\tEnter doctor's name: ");
    scanf(" %[^\n]", newDoctor->name);
    printf("\t\t\t\tEnter doctor's specialization: ");
    scanf(" %[^\n]", newDoctor->specialization);
    printf("\t\t\t\tEnter doctor's experience (in years): ");
    scanf("%d", &newDoctor->experience);
    printf("\t\t\t\t Enter age:");
    scanf("%d",&newDoctor->age);
    printf("\t\t\t\t enter contact number:");
    scanf("%d",&newDoctor->contact);

    newDoctor->next = NULL;
    if(d_head == NULL){
    d_head = newDoctor;
        curr = newDoctor;
    }
    else{
        curr->next=newDoctor;
        curr = newDoctor;
    }

    system("cls");
    printf("\n");
    printf("\n");
    printf("\t\t\t\t-Add doctor succesfully-\n");
    getch();
    doctor();
}


void displayDoctors(struct Doctor *head) {
    struct Doctor *curr;
    if (d_head == NULL) {
            system("cls");
            printf("\n");
        printf("\n");
        printf("\t\t\t\tNo doctors found!\n");
        getch();
        doctor();
        return;
    }

    printf("\t\t\t\tList of Doctors:\n");
    printf("\t\t\t\t----------------");
    int count=0;

    curr = d_head;
    while (curr != NULL) {
            system("cls");
            printf("\t\t\t\tDoctor no:%d\n",count);
            printf("\t\t\t\t----------\n");
        printf("\t\t\t\tName: %s\n\t\t\t\tSpecialization: %s\n\t\t\t\tExperience: %d years\n\t\t\t\tAge: %d\n\t\t\t\tContact:%d \n", curr->name, curr->specialization, curr->experience,curr->age, curr->contact);
        printf("\t\t\t|---------------------------------------------|\n");
        curr = curr->next;
        count++;

    }
    getch();
    doctor();
}


void saveToFile(struct Doctor *head) {
    FILE *file = fopen("doctors.txt", "w");
    if (file == NULL) {
            printf("\n");
    printf("\n");
        printf("\t\t\t\tError opening file!\n");
        return;
    }

    while (head != NULL) {
        fprintf(file, "%s %s %d %d %d \n", head->name, head->specialization, head->experience,head->age,head->contact);
        head = head->next;
    }

    fclose(file);
    printf("\n");
    printf("\n");
    printf("\t\t\t\t'Doctor's data saved in file'!\n");
    getch();
    doctor();
}


void searchBySpecialization(struct Doctor *head, char *specialization) {
    int found = 0;
    while (head != NULL) {
        if (strcmp(head->specialization, specialization) == 0) {
            printf("Name: %s, Specialization: %s, Experience: %d years,Age: %d,Contact No: %d\n", head->name, head->specialization, head->experience,head->age,head->contact);
            found = 1;
        }
        head = head->next;
    }

    if (!found) {
        printf("\t\t\t\tNo doctors found with specialization: %s\n", specialization);
        getch();
    }
    doctor();
}

void doctor() {
    struct Doctor *head = NULL;
    int choice;
    char searchSpecialization[50];


    do {
            system("cls");
        printf("\t\t\t\t<<<<_DOCTORS MANAGEMENT AREA_>>>>\n");
        printf("\t\t\t|------------------------------------------------|\n");
        printf("\t\t\t\t 1. Add a Doctor\n");
        printf("\t\t\t\t 2. Display all Doctors\n");
        printf("\t\t\t\t 3. Search Doctors by Specialization\n");
        printf("\t\t\t\t 4. Save Doctors' data to file\n");
        printf("\t\t\t\t 5. Exit\n");
        printf("\t\t\t\t Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls");
                addDoctor();
                break;
            case 2:
                system("cls");
                displayDoctors(head);
                break;
            case 3:
                system("cls");
                printf("Enter specialization to search: ");
                scanf("%s", searchSpecialization);
                searchBySpecialization(head, searchSpecialization);
                break;
            case 4:
                system("cls");
                saveToFile(head);
                break;
            case 5:
                system("cls");
                printf("Exiting...\n");
                getch();
                welcome_screen();
                break;
            default:
                system("cls");
                printf("\n");
                printf("\n");
                printf("\t\t\t\tInvalid choice! Please enter a valid option.\n");
                getch();
                doctor();

        }
    } while (choice != 5);

    return 0;
}

void changeAdminCredentials() {
    system("cls");
    char adminUsername[20];
    char adminPassword[20];
    printf("\n");
    printf("\n");
    printf("singup for a new admin\n");
    printf("\n");


    printf("\t\t\t\tEnter new admin username: ");
    scanf("%s", adminUsername);
    printf("\n");
    printf("\t\t\t\tEnter new admin password: ");
    scanf("%s", adminPassword);

    saveAdminCredentialsToFile(adminUsername, adminPassword);
    printf("\t\t\t\t-dentials updated successfully!-\n");
}
