//library management system
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<Windows.h>

void insertnode();
void deletenode();
void searchnode();
void view();
int menu();

struct books
{
	int serialnumber, studentid;
	char bookname[20], issuedby[20];
	struct books*link;
};
struct books*start = NULL;
struct books*createnode() //making node
{
	struct books*n;
	n = (struct books*)malloc(sizeof(struct books));
	return(n);
}
void insertnode()//inserting node
{
	struct books*temp, *t;
	temp = createnode();
	printf("Enter information about the book\n");
	printf("Enter book serial number");
	scanf_s("%d", &temp->serialnumber);
	fflush(stdin);
	printf("\nEnter student ID");
	scanf_s("%d", &temp->studentid);
	printf("Student name");
	fflush(stdin);
	fgets(temp->issuedby,20,stdin);
	printf("\nEnter book name");
	fflush(stdin);
	fgets(temp->bookname,20,stdin);
	temp->link = NULL;
	if (start == NULL)
	{
		start = temp;
	}
	else
	{
		t = start;
		while (t->link != NULL)
		{
			t = t->link;
		}
		t->link = temp;
	}
}

void searchnode()//linearsearch
{
	//seraching from serial of book
	struct books *t;
	int sno;
	t = start;
	printf("Enter Serial number book");
	scanf_s("%d", &sno);
	while (t->link != NULL)
	{
		if (sno == t->serialnumber)
		{
			printf("Serial Number\t");
			printf("Student ID\t");
			printf("Student Name\t");
			printf("Book name\t");
			printf("\n");
			printf("%d\t\t", t->serialnumber);
			printf("%d\t", t->studentid);
			printf("%s\t", t->issuedby);
			printf("%s\t", t->bookname);
			printf("\n");
		}
		else
		{
			printf("Search unsuccessfull Book not found\n");
		}
	}
}
void deletenode()//deleting books
{
	struct books *del, *viewdel, *prev, *temp;
	int sno;
	printf("Enter Book serial number which you want to delete");
	scanf_s("%d", &sno);
	if (start == NULL)//no book in database
	{
		printf("No books are in the system\n");
		return;
	}
	else if (start->serialnumber == sno)//node next to start
	{
		viewdel = start;
		printf("\nDeleted book serialnumber = %d\n", viewdel->serialnumber);
		del = start;
		start = start->link;
		free(del);//freeing memory
	}
	temp = start;
	while (temp != NULL && temp->serialnumber != sno)//looking for previous node of node to be deleted to deleted
	{
		prev = temp;
		temp = temp->link;
	}
	if (temp == NULL)//serial number not in database
	{
		printf("No book with serial number %d is present in the database\n", sno);
		return;
	}
	//prev->link = temp->link;
	//error!!^
	free(temp);//freeing memory
	//free(prev);//freeing memory
}
void view()//display database
{
	struct books*node;
	if (start == NULL)//no books
	{
		printf("No Books in the database\n");
	}
	else
	{
		node = start;
		printf("\n\t\tLibary Managment System\n");
		printf("Serial Number\t");
		printf("Student ID\t");
		printf("Student Name\t");
		printf("Book name\t");
		printf("\n");
		while (node != NULL)
		{
			printf("\t%d", node->serialnumber);
			printf("%d\t", node->studentid);
			printf("%s\t", node->issuedby);
			printf("%s\t", node->bookname);
			printf("\n");
			node = node->link;
		}
	}
}
int menu()//choices
{
	int choice, flag = 1;
	while (flag)//safe guard
	{
		printf("Welcome to Kunal Libary Managment System\n");
		printf("Enter your choice\n");
		printf("To issue book\t\t   Enter 1\n");
		printf("Return book\t\t   Enter 2\n");
		printf("Search for a book\t   Enter 3\n");
		printf("Display all issused books  Enter 4\n");
		printf("To exit/t\t\t   Enter 5\n");
		scanf_s("%d", &choice);
		flag = 0;
		if (choice < 0 && choice>5)
		{
			flag = 1;
			printf("Wrong choice\n");
			printf("Do again\n");
		}
	}
	return choice;
}
int main()
{
	while (1)
	{
		switch (menu())
		{
		case 1:
			insertnode();
			break;
		case 2:
			deletenode();
			break;
		case 3:
			searchnode();
			break;
		case 4:
			view();
			break;
		case 5:
			printf("Exit");
			printf("\nThank You for visting\n");
			printf("Press Anything to continue\n");
			exit(0);
		default:
			printf("Wrong choice\n");
			continue;
		}
		_getch();
		system("cls");
	}
	_getch();
	return 0;
}