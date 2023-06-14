#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct BUS
{
    int seat_number;
    char name[20];
    int book;
    struct BUS *next;
} node;

void input(node *head,int seat_number)
{
    while(head->next != NULL)
    {
        head= head->next;
    }
    node *first=(node*)malloc(sizeof(node));

    first->seat_number = seat_number;
    first->book = 0;
    strcpy(first->name," ");
    first->next = NULL;
    head->next = first;

}

void display(node *head1, node *head2, node *head3)
{

    if(head1->next == NULL || head2->next == NULL || head3->next == NULL)
    {
        return;
    }
    else
    {
        if(head1->next->book == 0) printf("\t[]    Seat number:  %d -> Not BOOKED [] ",head1->next->seat_number);
        else printf("\t[]    Seat number:  %d -> BOOKED     [] ",head1->next->seat_number);

        if(head2->next->book == 0) printf("Seat number:  %d -> Not BOOKED [] ",head2->next->seat_number);
        else printf("Seat number:  %d -> BOOKED     [] ",head2->next->seat_number);

        if(head3->next->book == 0) printf("Seat number:  %d -> Not BOOKED  []\n",head3->next->seat_number);
        else printf("Seat number:  %d -> BOOKED      []\n",head3->next->seat_number);

    }
    display(head1->next, head2->next, head3->next);

}

void booking(node *head,int seat_no, char name[])
{
    int c=0;
    while(head->next != NULL && head->next->seat_number != seat_no)
    {
        head = head->next;
        c++;
    }

    if(c == 10)
    {
        printf("\n\n\t\t[]******************************************************************[]\n");
        printf("\t\t[]                                                                  []\n");
        printf("\t\t[]                        Wrong seat number                         []\n");
        printf("\t\t[]                                                                  []\n");
        printf("\t\t[]******************************************************************[]\n");
        return;
    }
    if(head->next->book == 1)
    {
        printf("\n\n\t\t[]******************************************************************[]\n");
        printf("\t\t[]                                                                  []\n");
        printf("\t\t[]               Sorry! Seat has already booked                     []\n");
        printf("\t\t[]                    Choose another seat                           []\n");
        printf("\t\t[]                                                                  []\n");
        printf("\t\t[]******************************************************************[]\n");
        return;
    }
    if(head->next->book == 0)
    {
        head->next->book = 1;
        strcpy(head->next->name,name);
        printf("\n\n\t\t******************************************************************\n");
        printf("\t\t                                                                    \n");
        printf("\t\t                   Seat is Successfully booked                      \n");
        printf("\t\t                   Your name is %s                                  \n",head->next->name);
        printf("\t\t                   Your seat number is %d                           \n",head->next->seat_number);
        printf("\t\t                                                                    \n");
        printf("\t\t******************************************************************\n");
        return;
    }
}

void find(node *head,int seat_no)
{
    while(head->next != NULL && head->next->seat_number != seat_no)
    {
        head = head->next;
    }
    if(head->next->seat_number == seat_no)
    {
        printf("\n\n\t\t******************************************************************\n");
        printf("\t\t                                                                    \n");
        printf("\t\t                   Your name is %s                                  \n",head->next->name);
        printf("\t\t                   Your seat number is %d                           \n",head->next->seat_number);
        printf("\t\t                                                                    \n");
        printf("\t\t******************************************************************\n\n");
    }
    else
    {
        printf("\n\n\t\t[]******************************************************************[]\n");
        printf("\t\t[]                                                                  []\n");
        printf("\t\t[]                        Wrong seat number                         []\n");
        printf("\t\t[]                                                                  []\n");
        printf("\t\t[]******************************************************************[]\n");
        return;
    }
}

int find1(node *head,int seat_no,char name[])
{
    while(head->next != NULL && head->next->seat_number != seat_no)
    {
        head = head->next;
    }
    if(head->next->seat_number == seat_no && strcmp(head->next->name,name)==0)
    {
        return 1;
    }
    else
    {
        printf("\n\n\t\t[]******************************************************************[]\n");
        printf("\t\t[]                                                                  []\n");
        printf("\t\t[]                        Wrong seat number                         []\n");
        printf("\t\t[]                                                                  []\n");
        printf("\t\t[]******************************************************************[]\n");
        return 0;
    }
}

int Edit_booking(node *head,int seat_no, char name[])
{
    while(head->next != NULL && head->next->seat_number != seat_no)
    {
        head = head->next;
    }
    if(head->next->seat_number == seat_no && head->next->book == 0)
    {
        head->next->book = 1;
        strcpy(head->next->name,name);
        printf("\n\n\t\t******************************************************************\n");
        printf("\t\t                                                                    \n");
        printf("\t\t                   Seat is Successfully booked                      \n");
        printf("\t\t                   Your name is %s                                  \n",head->next->name);
        printf("\t\t                   Your seat number is %d                           \n",head->next->seat_number);
        printf("\t\t                                                                    \n");
        printf("\t\t******************************************************************\n");
        return 1;
    }
    else if(head->next->seat_number == seat_no && head->next->book == 1)
    {
        printf("\n\n\t\t[]******************************************************************[]\n");
        printf("\t\t[]                                                                  []\n");
        printf("\t\t[]               Sorry! Seat has already booked                     []\n");
        printf("\t\t[]                    Choose another seat                           []\n");
        printf("\t\t[]                                                                  []\n");
        printf("\t\t[]******************************************************************[]\n");
        return 0;
    }
    else
    {
        printf("\n\n\t\t[]******************************************************************[]\n");
        printf("\t\t[]                                                                  []\n");
        printf("\t\t[]                        Wrong seat number                         []\n");
        printf("\t\t[]                                                                  []\n");
        printf("\t\t[]******************************************************************[]\n");
        return 0;
    }
}

void find2(node *head,int seat_no)
{
    while(head->next != NULL && head->next->seat_number != seat_no)
    {
        head = head->next;
    }
    head->next->book = 0;
    strcpy(head->next->name," ");
}

int main()
{
    system("COLOR 0B");
    node *head1 =(node*)malloc(sizeof(node));
    head1->next = NULL;
    node *head2 =(node*)malloc(sizeof(node));
    head2->next = NULL;
    node *head3 =(node*)malloc(sizeof(node));
    head3->next = NULL;

    int a=11,b=21,c=31;

    for(int i=1; i<=10; i++)
    {
        input(head1,a);
        input(head2,b);
        input(head3,c);
        a++;
        b++;
        c++;
    }


    printf("\n\t\t\t\t\tWELCOME TO OUR PROJECT\n");
    printf("\n\t\t\tOUR PROJECT'S TOPIC IS :   Bus Ticket Booking system\n\n");

    printf("\n\t\t## Our Team Members Name:\n");
    printf("\n\t\t[]******************************************************************[]\n\t\t[]                                                                  []\n");
    printf("\t\t[]\tNAME: Touhidul Islam              ID: 201-15-14231          []\n\t\t[]                                                                  []\n");
    printf("\t\t[]\tNAME: Ashrafe Retheta             ID: 201-15-14085          []\n\t\t[]                                                                  []\n");
    printf("\t\t[]\tNAME: MD Shihab Uddin             ID: 201-15-14221          []\n\t\t[]                                                                  []\n");
    printf("\t\t[]\tNAME: Md. Al Masruf               ID: 201-15-14255          []\n\t\t[]                                                                  []\n");
    printf("\t\t[]                                                                  []\n\t\t[]******************************************************************[]\n");

    printf("\n\n\t\tPRESS ENTER KEY TO GO NEXT PAGE:  ");
    //getch();
    system("cls");

    printf("\n\t\t\t\t********** WELCOME TO DHAKA BUS STAND **********\n\n");

    printf("\n\t\t\t\t\t*****Bus left Time table*****\n");
    printf("\n\t\t[]******************************************************************[]\n\t\t[]                                                                  []\n");
    printf("\t\t[]\t     BUS NUMBER:                     Left Time:             []\n\t\t[]                                                                  []\n");
    printf("\t\t[]\t     Bus->1                          10:00 AM               []\n\t\t[]                                                                  []\n");
    printf("\t\t[]\t     Bus->2                          11:00 AM               []\n\t\t[]                                                                  []\n");
    printf("\t\t[]\t     Bus->3                          12:00 AM               []\n\t\t[]                                                                  []\n");
    printf("\t\t[]                                                                  []\n\t\t[]******************************************************************[]\n");

    printf("\n\n\t\tPRESS ENTER KEY TO GO NEXT PAGE:  ");
    //getch();
    system("cls");
    while (1)
    {
        int n,seat_number,x;
        int seat_no,bus_no,seat_no1,bus_no1;
        char name[20];
        printf("\n\t\t\t\t\t********** WELCOME TO DHAKA BUS STAND **********\n\n");
        printf("\n\n\t\t 1. Show total seats \n\t\t 2. Book a seat \n\t\t 3. Check your seat \n\t\t 4. Edit booking \n\t\t 5. Delete reservation. \n\t\t 6. exit\n\n");
        printf("\t\tEnter a number: ");
        scanf("%d",&n);
        system("cls");
        switch(n)
        {
        case 1:
            printf("\n\t\t\t\t\t*********** BUS Information ***********\n\n\n");
            printf("\n\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t[]                                                                                                        []\n");
            printf("\t[]            BUS->1                            BUS->2                            BUS->3                  []\n");
            printf("\t[]                                                                                                        []\n");
            display(head1, head2, head3);
            printf("\t[]                                                                                                        []\n");
            printf("\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\n\n\t\tPRESS ENTER KEY TO GO NEXT PAGE:  ");
            //getch();
            system("cls");
            break;
        case 2:
            printf("\n\t\t\t\t\t*********** BUS Information ***********\n\n\n");
            printf("\n\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t[]                                                                                                        []\n");
            printf("\t[]            BUS->1                            BUS->2                            BUS->3                  []\n");
            printf("\t[]                                                                                                        []\n");
            display(head1, head2, head3);
            printf("\t[]                                                                                                        []\n");
            printf("\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n\n");

            printf("\n\t\t\t\t\t***********   For Booking   ***********\n\n");
            printf("\t\tEnter Bus no: ");
            scanf("%d",&bus_no);
            printf("\t\tEnter Your name: ");
            scanf("%s",name);
            printf("\t\tEnter Seat no: ");
            scanf("%d",&seat_no);
            if(bus_no == 1)  booking(head1, seat_no, name);
            if(bus_no == 2)  booking(head2, seat_no, name);
            if(bus_no == 3)  booking(head3, seat_no, name);

            printf("\n\n\t\tPRESS ENTER KEY TO GO NEXT PAGE:  ");
            //getch();
            system("cls");
            break;
        case 3:
            printf("\n\n\n\t\tEnter Your Bus no: ");
            scanf("%d",&bus_no);
            printf("\t\tEnter Your Seat no: ");
            scanf("%d",&seat_no);
            if(bus_no == 1)  find(head1, seat_no);
            if(bus_no == 2)  find(head2, seat_no);
            if(bus_no == 3)  find(head3, seat_no);
            printf("\n\n\t\tPRESS ENTER KEY TO GO NEXT PAGE:  ");
            //getch();
            system("cls");
            break;
        case 4:
            printf("\n\t\t\t\t\t*********** BUS Information ***********\n\n\n");
            printf("\n\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t[]                                                                                                        []\n");
            printf("\t[]            BUS->1                            BUS->2                            BUS->3                  []\n");
            printf("\t[]                                                                                                        []\n");
            display(head1, head2, head3);
            printf("\t[]                                                                                                        []\n");
            printf("\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n\n");
            int c,d;
            printf("\n\n\n\t\tEnter Your Bus no: ");
            scanf("%d",&bus_no);
            printf("\t\tEnter Your name: ");
            scanf("%s",name);
            printf("\t\tEnter Your Seat no: ");
            scanf("%d",&seat_no);
            printf("\t\tEnter which Bus no you want to transfer your book: ");
            scanf("%d",&bus_no1);
            printf("\t\tEnter That Bus Seat no : ");
            scanf("%d",&seat_no1);
            if(bus_no == 1)  c = find1(head1, seat_no, name);
            if(bus_no == 2)  c = find1(head2, seat_no, name);
            if(bus_no == 3)  c = find1(head3, seat_no, name);
            if(c == 1)
            {
                if(bus_no1 == 1)  d = Edit_booking(head1, seat_no1, name);
                if(bus_no1 == 2)  d = Edit_booking(head2, seat_no1, name);
                if(bus_no1 == 3)  d = Edit_booking(head3, seat_no1, name);

                if(d == 1)
                {
                    if(bus_no == 1) find2(head1, seat_no);
                    if(bus_no == 2) find2(head2, seat_no);
                    if(bus_no == 3) find2(head3, seat_no);
                }
                else
                {
                }
            }
            else
            {
            }
            printf("\n\n\t\tPRESS ENTER KEY TO GO NEXT PAGE:  ");
            //getch();
            system("cls");
            break;
        case 5:
            printf("\n\n\n\t\tEnter Your Bus no: ");
            scanf("%d",&bus_no);
            printf("\t\tEnter Your name: ");
            scanf("%s",name);
            printf("\t\tEnter Your Seat no: ");
            scanf("%d",&seat_no);

            if(bus_no == 1)  x = find1(head1, seat_no, name);
            if(bus_no == 2)  x = find1(head2, seat_no, name);
            if(bus_no == 3)  x = find1(head3, seat_no, name);

            if(x == 1)
            {
                if(bus_no == 1) find2(head1, seat_no);
                if(bus_no == 2) find2(head2, seat_no);
                if(bus_no == 3) find2(head3, seat_no);
                printf("\n\n\t\t[]******************************************************************[]\n");
                printf("\t\t[]                                                                  []\n");
                printf("\t\t[]             Delete reservation is Successfully Done              []\n");
                printf("\t\t[]                                                                  []\n");
                printf("\t\t[]******************************************************************[]\n");
            }
            printf("\n\n\t\tPRESS ENTER KEY TO GO NEXT PAGE:  ");
            //getch();
            system("cls");
            break;
        case 6:
            return 0;
        default:
            printf("\n\n\t\t[]******************************************************************[]\n");
            printf("\t\t[]                                                                  []\n");
            printf("\t\t[]                           Wrong Input                            []\n");
            printf("\t\t[]                                                                  []\n");
            printf("\t\t[]******************************************************************[]\n");
            printf("\n\n\t\tPRESS ENTER KEY TO GO NEXT PAGE:  ");
            //getch();
            system("cls");
            break;
        }
    }

}

