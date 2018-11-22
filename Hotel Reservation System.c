#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>

int x = 55, y = 20;
int option;
int total_a, total_b, total_c;
int people_input, days_num;
int number;

char message[255];
char none[0];
void selection();
void costu_main();
void homepage();
void reservation();
void reservation_input();
//
void kingsize();
void royalsize();
void regularsize();
//
void continue_a();
void continue_b();
void continue_c();
//
void done_a();
void done_b();
void done_c();
//
int people_input;
int days_num;
//
char name_input;
//
void information();
//
void city();
//
void cagayan();
void davao();
void surigao();
void malaybalay();
//
sleep(number);
//
void admin_main_function();
void main_menu();
void add();  //FUNCTIONS
void list();
void edit();  //GLOBALLY DECLARED FUNCTIONS N VARIABLE
void delete1();
void search();

struct Rooms {
	char title[100];
	char people[100];
	char bed[100];
};

void gotoxy(int x, int y)//function used for cursor positioning
{
	COORD CR;
	CR.X=x;
	CR.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CR);
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{

    printf("\n  **************************  LOGIN FORM  **************************  ");
    printf("\n");
    printf("\n");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf("\n");
	printf("\n");
	printf(" \n                       ENTER PASSWORD:-");

	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n\n\n          WELCOME TO THE SYSTEM ADMIN !!!! LOGIN IS SUCCESSFUL !!!! ");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}

struct CustomerDetails   //STRUCTURE DECLARATION
{
	int roomnumber;
	char name[20];
	char address[20];
	char phonenumber[15];
	char nationality[15];
	char email[35];
	int period;
}s;

int main()   //MAIN FUNCTION
{
	int i=0;

	time_t t;
	time(&t);
	system("cls");   // FOR CLEARING SCREEN
 	printf("\t\t*************************************************\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*        WELCOME TO HOTEL TRANSYLVANIA          *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
    printf("\t\t*************************************************\n");

		printf("-");
	printf(" \n Press any key to continue:");

	getch();
    system("cls");
    selection();
}
void selection(){
    int option;
    system("cls");
    gotoxy(x,10);
    printf("(1) Admin\n");
    gotoxy(x,12);
    printf("(2) Costumer\n");
    gotoxy(x,14);
    scanf("%d", &option);
    system("cls");
    switch(option){
    case 1:
        return admin_main_function();
        break;
    case 2:
        return costu_main();
        break;
    default:
        return selection();
    }
}

void admin_main_function(){
    login();
    main_menu();
}

void main_menu()
{
	int i=0;

	time_t t;
	time(&t);
	char customername;
	char choice;
    system("cls");
	while (1)      // INFINITE LOOP
	{
		system("cls");

        for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("\t\t *Please enter your choice for menu*:");
		printf("\n\n");
		printf(" \n Enter (1) ---> Book a Room");
		printf("\n");
		printf("\n");
		printf(" \n Enter (2) ---> View Customer Record");
		printf("\n");
		printf("\n");
		printf(" \n Enter (3) ---> Delete Customer Record");
		printf("\n");
		printf("\n");
		printf(" \n Enter (4) ---> Search Customer Record");
		printf("\n");
		printf("\n");
		printf(" \n Enter (5) ---> Edit Record");
		printf("\n");
		printf("\n");
		printf(" \n Enter (6) ---> Exit");
		printf("\n");
		printf("\n");
		printf("\n");

	    for(i=0;i<80;i++)
		printf("-");

		choice=getche();
		choice=toupper(choice);
		switch(choice)           // SWITCH STATEMENT
		{
			case '1':
				add();break;
			case '2':
				list();break;
			case '3':
				delete1();break;
			case '4':
				search();break;
			case '5':
				edit();break;
			case '6':
				system("cls");
				printf("\n\n\t *****THANK YOU*****");
				printf("\n\t FOR TRUSTING OUR SERVICE");
			//	Sleep(2000);
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}
}
void add()
{
	FILE *f;
	int roomnumber, n, i,r , valid=0;
	char test;
	f=fopen("add.txt","a+");
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	system("cls");
	printf("\n Enter Customer Details:");
	printf("\n**************************");

	if((f = fopen("add.txt","r+"))!=NULL)
	{
		ADD:
		printf("\n Enter room number\t: ");
		scanf(" %i",&roomnumber);
		while(fscanf(f,"%i %s %s %s %s %s %i\n", &s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, &s.period)!=EOF)
	    {
	    	if(roomnumber == s.roomnumber)
	    	{
	    		printf("\n\tTHE ROOM IS ALREADY BOOKED.");
	    		goto ADD;
			}
		}
		s.roomnumber == roomnumber;

		//printf("\n Enter Room number\t: ");
		//scanf("%i",&s.roomnumber);
		Q:
		printf("\n Enter Name\t\t: ");
		fflush(stdin);
		gets(s.name);
		if(strlen(s.name)>20||strlen(s.name)<2)
		{
			printf("\nInvalid!!\n\tThe maximum number for customer's name is less than 21 and more than 1.\n");
			goto Q;
		}
		else
		{
			for (i=0;i<strlen(s.name);i++)
			{
				if(isalpha(s.name[i]))
				{
					valid = 1;
				}
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\nName contain invalid character. Please enter again.\n");
				goto Q;
			}
		}
		do
		{
			A:
			printf("\n Enter Address\t\t:");
			scanf("%s",s.address);
			if(strlen(s.address)>20 || strlen(s.address)<2)
			{
				printf("\nInvalid!!\n\tThe maximum number for customer's name is less than 21 and more than 1.\n");
				goto A;
			}
			else
			{
				for (i=0;i<strlen(s.address); ++i)
				{
					if(isalpha(s.address[i]))
					{
						valid = 1;
					}
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					printf("\nName contain invalid character. Please enter again.\n");
				}
				}
		}while(!valid);
		do
		{
			P:
			printf("\n Enter Phone Number\t: ");
			scanf("%s",s.phonenumber);
			if (strlen(s.phonenumber)!=10 || strlen(s.phonenumber)>10)
			{
				printf("\nPhone number should be of 10 numbers from 0-9. Please, enter valid number.\n");
				goto P;
			}
			for(i=0;i<strlen(s.phonenumber); i++)
			{
				if(!isalpha(s.phonenumber[i]))
				{
					valid=1;
				}
				else
				{
					valid=0;
					break;
				}
			}
			if(!valid)
			{
				printf("\nThe phone number is invalid. Please, enter numbers only.\n");
			}
		}while(!valid);
		do
		{
			X:
			printf("\nEnter Nationality\t: ");
			scanf("%s",s.nationality);
			if(strlen(s.nationality)>10 || strlen(s.nationality)<2)
			{
				printf("\nInvalid!!\n\tThe maximum name can be upto 15 and and more than 1.\n");
				goto X;
			}
			for(i=0;i<strlen(s.nationality); i++)
			{
				if(isalpha(s.nationality[i]))
				{
					valid=1;
				}
				else
				{
					valid=0;
					break;
				}
			}
			if(!valid)
			{
				printf("\nThe nationality name contains only character. Please, enter again.\n");
			}
		}while(!valid);
		do
		{
			printf("\nEnter Email\t\t: ");
			scanf(" %s",s.email);
			if(strlen(s.email)>35||strlen(s.email)<10)
			{
				printf("\nInvalid!!\n\tThe maximum number for customer's email is less than 31 and more than 10.\n");
			}
		}while(strlen(s.email)>35||strlen(s.email)<2);
		do
		{
			printf("\nEnter Period(\'x\'days)\t: ");
			scanf("%i",&s.period);
			if(s.period>10 || s.period<=0)
			{
				printf("\tInvalid!!\n\tThe maximum number for customer's stay period is upto 10 days .\n");
			}
		}while(s.period>10 || s.period<=0);


		fprintf(f,"%i %s %s %s %s %s %i\n", s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period);
		printf("\n\n Room is successfully booked!!");
		fclose(f);
	}
	printf("\n Press esc key to exit,  any other key to add another customer detail:");
	test=getche();
	if(test==27)
		main_menu();
	else
		add();
}

void list()
{
	FILE *f;
	int i, q;
	if((f=fopen("add.txt","r"))==NULL)
		exit(0);
	system("cls");
	gotoxy(1,6);
	printf("ROOM NUMBER ");
	gotoxy(15,6);
	printf("NAME ");
	gotoxy(30,6);
	printf("ADDRESS ");
	gotoxy(45,6);
	printf("PHONE NUMBER ");
	gotoxy(60,6);
	printf("NATIONALITY ");
	gotoxy(75,6);
	printf("EMAIL ");
	gotoxy(100,6);
	printf("PERIOD \n");

	for(i=0;i<110;i++)
	{
		printf("-");
	}
	q=9;
	while(fscanf(f,"%i %s %s %s %s %s %i\n", &s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, &s.period)!=EOF)
	{
		/*printf("ROOMNUMBER :\t%s\n",s.roomnumber);
		printf("NAME:\t%s\n",,s.name);
		printf("ADDRESS:\t%s\n",s.address);
		printf("PHONENUMBER:\t%s\n",s.phonenumber);
		printf("NATIONALITY \n");*/
		gotoxy(1,q);
		printf("%i",s.roomnumber);
		gotoxy(16,q);
		printf("%s",s.name);
		gotoxy(31,q);
		printf("%s",s.address);
		gotoxy(46,q);
		printf("%s",s.phonenumber);
		gotoxy(61,q);
		printf("%s",s.nationality);
		gotoxy(76,q);
		printf("%s",s.email);
		gotoxy(101,q);
		printf("%i",s.period);
		q++;
	}
	printf("\n");
	for(i=0;i<110;i++)
		printf("-");

	fclose(f);
	getch();
}

void delete1()
{
	FILE *f,*t;
	int i=0;
	int roomnumb;
	t=fopen("temp.txt","w");
	if ((f=fopen("add.txt","r"))==NULL)
	{
		printf("NO RECORD ADDED.");
		main_menu();
	}
	else
	{
		system("cls");
		printf("Enter the Room Number of the hotel to be deleted from the database: ");
		fflush(stdin);
		scanf("%i",&roomnumb);
		while(fscanf(f,"%i %s %s %s %s %s %i\n", &s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, &s.period)!=EOF)
		{
			if(roomnumb != s.roomnumber)
			{
				fprintf(t,"%i %s %s %s %s %s %i\n", s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period);
			}
			else
			{
				i=1;
			}
		}
		if(!i)
		{
			printf("\n\n Records of Customer in this  Room number is not found!!");
			//remove("E:/file.txt");
		   //rename("E:/temp.txt","E:/file.txt");
			getch();
			fclose(f);
			fclose(t);
			main_menu();
		}
		else
		{
			printf("\n\tSuccessfully deleted.\n");
		}
		fclose(f);
		fclose(t);
		remove("add.txt");
		rename("temp.txt","add.txt");
		getch();
	}
}

void search()
{
system("cls");
	FILE *f;
	int roomnumber;
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
	{
		printf("NO RECORD ADDED.");
		main_menu();
	}
	else
	{
		fflush(stdin);
		printf("Enter Room number of the customer to search its details: \n");
		scanf("%i", &roomnumber);
		while(fscanf(f,"%i %s %s %s %s %s %i\n", &s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, &s.period)!=EOF)
		{
			if(roomnumber==s.roomnumber)
			{
				flag=0;
				printf("\n\tRecord Found\n");
				printf("\nRoom Number\t: %i",s.roomnumber);
				printf("\nName\t\t: %s",s.name);
				printf("\nAddress\t\t: %s",s.address);
				printf("\nPhone number\t: %s",s.phonenumber);
				printf("\nNationality\t: %s",s.nationality);
				printf("\nEmail\t\t: %s",s.email);
				printf("\nPeriod\t\t: %i",s.period);
				break;
			}
		}
		if(flag==1){
			printf("\n\tRequested Customer could not be found!");
		}
		getch();
		fclose(f);
		main_menu();
	}

}

void edit()
{
	FILE *f, *r;
	int k=0;
	char ed;
	int roomnumber;
	long int size=sizeof(s);
	if((f=fopen("add.txt","r+"))==NULL)
	{
		printf("NO RECORD ADDED.");
		main_menu();
	}
	else
	{
		r = fopen("temp.txt","a");
		system("cls");
		printf("Enter Room number of the customer to edit:\n\n");
		scanf("%i",&roomnumber);
		fflush(stdin);
		while(fscanf(f,"%i %s %s %s %s %s %i\n", &s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, &s.period)!=EOF)
		{
			if(roomnumber==s.roomnumber)
			{

				k=1;
				printf("\n\t*** Existing Record ***");
				printf("\nRoom Number\t: %i",s.roomnumber);
				printf("\nName\t\t: %s",s.name);
				printf("\nAddress\t\t: %s",s.address);
				printf("\nPhone number\t: %s",s.phonenumber);
				printf("\nNationality\t: %s",s.nationality);
				printf("\nEmail\t\t: %s",s.email);
				printf("\nPeriod\t\t: %i",s.period);
				printf("\n\n\t*** New Record ***");
				printf("\nEnter New Name           : ");
				fflush(stdin);
				scanf("%s",s.name);
				printf("\nEnter New Address        : ");
				scanf("%s",s.address);
				printf("\nEnter New Phone number   : ");
				scanf("%s",s.phonenumber);
				printf("\nEnter New Nationality    : ");
				scanf("%s",s.nationality);
				printf("\nEnter New Email          : ");
				scanf("%s",s.email);
				printf("\nEnter New Period         : ");
				scanf("%i",&s.period);
				printf("Press 'm' to edit the existing record or any key to cancel...");
				ed=getche();
				if(ed=='m' || ed=='M')
				{
					fprintf(r,"%i %s %s %s %s %s %i\n", s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period);
					fflush(stdin);
					printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
				}
			}
			else
			{
				fprintf(r,"%i %s %s %s %s %s %i\n", s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period);
				fflush(stdin);
			}

		}
		if(!k)
		{
			printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		}
		fclose(r);
		fclose(f);
		remove("add.txt");
		rename("temp.txt","add.txt");
		getch();
	}
	main_menu();
}

// Part II

void printRoom(struct Rooms room)
{
	struct Rooms room1;
  strcpy( room1.title, "KING's ROOM\t[300 Pesos Only]\n");
   strcpy( room1.people, "Sleeps 4 people\n");
   strcpy( room1.bed, "1 King Size Bed\n");
   /////////////////////////////////////////////////
   	struct Rooms room2;
  strcpy( room2.title, "ROYAL ROOM\t[200 Pesos Only]\n");
   strcpy( room2.people, "Sleeps 2 people\n");
   strcpy( room2.bed, "1 Twin Bed\n");
   /////////////////////////////////////////////////
   	struct Rooms room3;
  strcpy( room2.title, "ROYAL ROOM\t[200 Pesos Only]\n");
   strcpy( room2.people, "Sleeps 2 people\n");
   strcpy( room2.bed, "1 Twin Bed\n");

}



void costu_main(int argc, char *argv[]) {

	gotoxy(x,10);
	printf("WELCOME");
	Sleep(3000);
	homepage();



}

void homepage(){
	system("cls");
	gotoxy(x,10);
	printf("(1) Reservation\n");
	gotoxy(x,12);
	printf("(2) Information\n");
	gotoxy(x,14);
	printf("(3) City\n");
	gotoxy(x,16);
	printf("(4) Exit\n");
	gotoxy(x,18);
	scanf("%d", &option);

	system("cls");

switch(option)
{
	case 1:
			return reservation();
		break;

	case 2:

			return information();
		break;

	case 3:

			return city();
		break;
	case 4:
		break;
	default:
		return homepage();
}

}

void reservation(){
		printf("=================================");
	printf("Welcome to Reservation");
		printf("=================================\n");
	//
	printf("Please Fill-up this for Reservation\n");
		return reservation_input();
	//

	FILE *file;
file = fopen("a.txt", "w");
gets(none);
printf("Message ");
gets(message);
printf("%s", message);
fprintf(file,"%s", message);
fclose(file);



}
void  reservation_input(){

	// 2 people is for 200 pesos.... additional is 150....
	// 200 per day...
	//
	printf("Name: ");
	scanf("\n%[^\n%]", &name_input);
	printf("How many people in room: ");
	scanf("%d", &people_input);
	printf("How many days Stay ");
	scanf("%d", &days_num);
	printf("Choose Room\n");
	printf("[1] king size room\n[2] Royal size room\n[3]Regular size room\n");
	scanf("%d", &option);
		system("cls");

	switch(option)
	{
		case 1:
			 kingsize();

			break;
		case 2:
			 royalsize();
			 break;
		case 3:
			 regularsize();
			 break;
		default:
			printf("Entered INVALID key...\n");
			reservation();
	}

}

void kingsize(){


  struct Rooms room1;
  	printf("=================================\n");
  strcpy( room1.title, "KING's ROOM\t[300 Pesos Only]\n");
   strcpy( room1.people, "Sleeps 4 people\n");
   strcpy( room1.bed, "1 King Size Bed\n");
   printf("%s", room1.title);
	printf("%s", room1.people);
	printf("%s", room1.bed);

	printf("Press:\n(1) to Continue...\n(2) to go back..\n(3) to EXIT\n");
	scanf("%d", &option);
		system("cls");
	switch(option){
		case 1:
			continue_a();
			break;
		case 2:
			 reservation_input();
			 break;
		case 3:
			exit(1);
		default:
			printf("Entered INVALID key...\n");
			reservation();
			break;
	}
}
void royalsize(){

	struct Rooms room2;
		printf("=================================");
  strcpy( room2.title, "ROYAL ROOM\t[200 Pesos Only]\n");
   strcpy( room2.people, "Sleeps 2 people\n");
   strcpy( room2.bed, "1 Twin Bed\n");
    printf("%s", room2.title);
	printf("%s", room2.people);
	printf("%s", room2.bed);

	printf("Press:\n(1) to Continue...\n(2) to go back..\n(3) to EXIT..\n");
	scanf("%d", &option);
		system("cls");
		switch(option){
		case 1:
			continue_b();
			break;
		case 2:
			 reservation_input();
			 break;
		case 3:
			exit(1);
		default:
			printf("Entered INVALID key...\n");
			reservation();
			break;
	}


}
void regularsize(){

	struct Rooms room3;
		printf("=================================");
  strcpy( room3.title, "REGULAR ROOM\t[100 Pesos Only]\n");
   strcpy( room3.people, "Sleeps 2 People\n");
   strcpy( room3.bed, "1 Twin Bed\n");
    printf("%s", room3.title);
	printf("%s", room3.people);
	printf("%s", room3.bed);

	printf("Press:\n(1) to Continue...\n(2) to go back..\n(3) to EXIT..\n");
	scanf("%d", &option);
		system("cls");
		switch(option){
		case 1:
			continue_c();
			break;
		case 2:
			 reservation_input();
			 break;
		case 3:
			exit(1);
		default:
			printf("Entered INVALID key...\n");
			reservation();
			break;
	}

}
void information(){
	gotoxy(x,1);
		printf("======================================");
		gotoxy(x,2);
		printf("WELCOME TO INFORMATION\n");
	gotoxy(x,3);
	printf("WELCOME TO HOTEL TRANSYLVANIA");
		gotoxy(x,4);
		printf("======================================");
	gotoxy(x,5);
		printf("RATED: 10 Star Hotel");
		gotoxy(x,6);
	printf("HOTEL TRANSYLVANIA is a hotel that loved by our quests and customers ");
		gotoxy(x,7);
	printf("Affordable with High Quality Standards");

	exit(1);


	FILE *file;
file = fopen("a.txt", "r");
fscanf(file,"%s", message);
printf("%s", message);
fclose(file);

	return 0;
}
void city(){
	system("cls");
		gotoxy(x,0);
	printf("=================================");
	gotoxy(x,1);
	printf("Available Cities");
	gotoxy(x,2);
	printf("=================================");
	gotoxy(x,3);
	printf("Choose Cities:  ");
	gotoxy(x,4);
	printf("(1) CAGAYAN DE ORO CITY");
	gotoxy(x,5);
	printf("(2) DAVAO CITY");
	gotoxy(x,6);
	printf("(3) SURIGAO");
	gotoxy(x,7);
	printf("(4) MALAYBALAY CITY\n");
	gotoxy(x,8);
	printf("(5) RETURN\n");

	scanf("%d", &option);
	switch(option)
{
	case 1:
		cagayan();
		break;
	case 2:
		davao();
		break;
	case 3:
		surigao();

		break;
	case 4:
		malaybalay();
		break;
	case 5:
		homepage();
		break;
	default:
		printf("INVALID ENTERED KEY..");
		exit(1);
		break;

}

	FILE *sample;
	sample = fopen("city.txt","r");
	if(!! EOF)
	{
		fgets(message,255,sample);
		printf("%s", message);
	}
	else
	{
		printf("File no such directory.");
		return;
	}

	fclose(sample);

}

void cagayan(){
	system("cls");
		gotoxy(x,0);
		printf("=================================");
		gotoxy(x,1);
	printf(" CAGAYAN DE ORO CITY\n");
		gotoxy(x,2);
	printf("Located at the Center of the City\n");
		gotoxy(x,3);
	printf("Close to Malls and Parks\n");
		gotoxy(x,4);
	printf("(1) RETURN\t (2) EXIT\n");
		gotoxy(x,5);
	scanf("%d", &option);
	switch(option){
		case 1:
		 city();
		 break;
		case 2:
			exit(1);
			break;
	}


}
void davao(){
	system("cls");
		gotoxy(x,0);
		printf("=================================");
		gotoxy(x,1);
		printf(" DAVAO CITY IS NOT YET AVAILABLE\n");
			gotoxy(x,2);
		printf("COMING SOON...\n");
			gotoxy(x,3);
		printf("WAIT FOR UPDATES\n");
			gotoxy(x,4);
		printf("(1) RETURN\t (2) EXIT\n");
	scanf("%d", &option);
	switch(option){
		case 1:
		 city();
		 break;
		case 2:
			exit(1);
			break;
	}

}
void surigao(){
	system("cls");
		gotoxy(x,0);
		printf("=================================");
		gotoxy(x,1);
		printf(" SURIGAO CITY IS NOT YET AVAILABLE\n");
			gotoxy(x,2);
		printf("COMING SOON...\n");
			gotoxy(x,3);
		printf("WAIT FOR UPDATES\n");
			gotoxy(x,4);
		printf("(1) RETURN\t (2) EXIT\n");
		scanf("%d", &option);
		switch(option){
			case 1:
			 city();
			 break;
			case 2:
				exit(1);
				break;
	}
}
void malaybalay(){
	system("cls");
		gotoxy(x,0);
		printf("=================================");
		gotoxy(x,1);
		printf(" MALAYBALAY CITY IS NOT YET AVAILABLE\n");
			gotoxy(x,2);
		printf("COMING SOON...\n");
			gotoxy(x,3);
		printf("WAIT FOR UPDATES\n");
			gotoxy(x,4);
		printf("(1) RETURN\t (2) EXIT\n");
	scanf("%d", &option);
	switch(option){
		case 1:
		 city();
		 break;
		case 2:
			exit(1);
			break;
	}
}

void continue_a(){
	struct Rooms room1;
		gotoxy(x,0);
		printf("=================================");
		gotoxy(x,1);
	printf("WELCOME!!!\n");
		gotoxy(x,2);
	printf("Name: %s\n", &name_input);
		gotoxy(x,3);
	printf("how many people in room: %d\n", people_input);
		gotoxy(x,4);
	printf("DAYS TO STAY: %d\n", days_num);
	////////////////////////////////////////////
	strcpy( room1.title, "KING's ROOM\n");
   strcpy( room1.people, "Sleeps 4 people\n");
   strcpy( room1.bed, "1 King Size Bed\n");
   ///////////////////////////////////////////
   	gotoxy(x,5);
   printf("%s", room1.title);
   	gotoxy(x,6);
	printf("%s", room1.people);
		gotoxy(x,7);
	printf("%s", room1.bed);
		gotoxy(x,8);
	printf("ARE YOU SURE ABOUT THIS?\n");
		gotoxy(x,9);
	printf("Press: \n(1) To Complete Process...\n(2) Go Back\n(3) To Exit...\n");

	scanf("%d", &option);
	switch(option)
	{
		case 1:
		 done_a();
		break;
		case 2:
		reservation_input();
		break;
		default:
			exit(1);
			break;
	}



}
void continue_b(){
	struct Rooms room2;
		gotoxy(x,0);
		printf("=================================");
		gotoxy(x,1);
	printf("WELCOME!!!\n");
		gotoxy(x,2);
	printf("Name: %s\n", &name_input);
		gotoxy(x,3);
	printf("how many people in room: %d\n", people_input);
		gotoxy(x,4);
	printf("DAYS TO STAY: %d\n", days_num);
	//////////////////////////////////////////////
	strcpy( room2.title, "ROYAL ROOM\n");
	strcpy( room2.people, "Sleeps 2 people\n");
	strcpy( room2.bed, "1 Twin Bed\n");
	///////////////////////////////////////////
		gotoxy(x,5);
	printf("%s", room2.title);
		gotoxy(x,6);
	printf("%s", room2.people);
		gotoxy(x,7);
	printf("%s", room2.bed);
		gotoxy(x,8);
	printf("ARE YOU SURE ABOUT THIS?\n");
		gotoxy(x,9);
	printf("Press (1) To Complete Process...\n(2) Go Back\n(3) To Exit...\n");
		system("cls");
	scanf("%d", &option);
	switch(option)
	{
		case 1:
		 done_b();
		break;
		case 2:
		reservation_input();
		break;
		default:
			exit(1);
			break;
	}



}
void continue_c(){
	struct Rooms room3;
	gotoxy(x,0);
		printf("=================================");
		gotoxy(x,1);
	printf("WELCOME!!!\n");
		gotoxy(x,2);
	printf("Name: %s\n", &name_input);
		gotoxy(x,3);
	printf("how many people in room: %d\n", people_input);
		gotoxy(x,4);
	printf("DAYS TO STAY: %d\n", days_num);
	///////////////////////////////////////////////////////
	 strcpy( room3.title, "REGULAR ROOM\n");
   strcpy( room3.people, "Sleeps 2 People\n");
   strcpy( room3.bed, "1 Twin Bed\n");
   /////////////////////////////////////////////////////////
   	gotoxy(x,5);
    printf("%s", room3.title);
    	gotoxy(x,6);
	printf("%s", room3.people);
		gotoxy(x,7);
	printf("%s", room3.bed);
		gotoxy(x,8);
	printf("ARE YOU SURE ABOUT THIS?\n");
		gotoxy(x,9);
	printf("Press (1) To Complete Process...\n(2) Go Back\n(3) To Exit...\n");

	scanf("%d", &option);
	switch(option)
	{
		case 1:
		 done_c();
		break;
		case 2:
		reservation_input();
		break;
		default:
			exit(1);
			break;
	}



}

void done_a()
{
system("cls");
	struct Rooms room1;

		gotoxy(x,0);
	printf("=================================");
		gotoxy(x,1);
	printf("Transaction");
		gotoxy(x,2);
	printf("=================================\n");
	gotoxy(x,3);
	printf("Name: %s\n", &name_input);
		gotoxy(x,4);
	printf("how many people in room: %d\n", people_input);
		gotoxy(x,5);
	printf("DAYS TO STAY: %d\n", days_num);
	/////////////////////////////////////////////////
	strcpy( room1.title, "KING's ROOM\n");
    strcpy( room1.people, "Sleeps 4 people\n");
    strcpy( room1.bed, "1 King Size Bed\n");
    ///////////////////////////////////////////////
    	gotoxy(x,6);
    printf("%s", room1.title);
    	gotoxy(x,7);
	printf("%s", room1.people);
		gotoxy(x,8);
	printf("%s", room1.bed);
	///////////////////////////////////////////////////////
	total_a=200*(people_input)+200*(days_num)+300;
		gotoxy(x,9);
	printf("Total Amount to pay: %d", total_a);




}
void done_b()
{
	struct Rooms room2;
		gotoxy(x,0);
	printf("=================================");
		gotoxy(x,1);
	printf("Transaction");
		gotoxy(x,2);
	printf("=================================");
		gotoxy(x,3);
	printf("Name: %s\n", &name_input);
		gotoxy(x,4);
	printf("how many people in room: %d\n", people_input);
		gotoxy(x,5);
	printf("DAYS TO STAY: %d\n", days_num);
	//////////////////////////////////////////
	strcpy( room2.title, "ROYAL ROOM\n");
	strcpy( room2.people, "Sleeps 2 people\n");
	strcpy( room2.bed, "1 Twin Bed\n");
	///////////////////////////////////////////////
		gotoxy(x,6);
	printf("%s", room2.title);
		gotoxy(x,7);
	printf("%s", room2.people);
		gotoxy(x,8);
	printf("%s", room2.bed);
	////////////////////////////////////////////////
	total_a=200*(people_input)+200*(days_num)+200;
		gotoxy(x,9);
	printf("Total Amount to pay: %d", total_b);
}

void done_c()
{
	struct Rooms room3;
		gotoxy(x,0);
	printf("=================================");
		gotoxy(x,1);
	printf("Transaction");
		gotoxy(x,2);
	printf("=================================");
		gotoxy(x,3);
	printf("Name: %s\n", &name_input);
		gotoxy(x,4);
	printf("how many people in room: %d\n", people_input);
		gotoxy(x,5);
	printf("DAYS TO STAY: %d\n", days_num);
	////////////////////////////////////////////////////
 strcpy( room3.title, "REGULAR ROOM\n");
   strcpy( room3.people, "Sleeps 2 People\n");
   strcpy( room3.bed, "1 Twin Bed\n");
   /////////////////////////////////////////////////
   	gotoxy(x,6);
    printf("%s", room3.title);
    	gotoxy(x,7);
	printf("%s", room3.people);
		gotoxy(x,8);
	printf("%s", room3.bed);
	/////////////////////////////
	total_a=200*(people_input)+200*(days_num)+100;
		gotoxy(x,9);
	printf("Total Amount to pay: %d", total_c);
}

