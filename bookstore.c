#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3
void read_the_disk(struct book_message bookstore[N]);
void save(struct book_message bookstore[N]);
struct Date_Type  
{
	int year;
	int month;
	int day;
};
struct book_message
{
	int accession_number;
	char book_name[10];
	char author[10];
	char class_number[5];
	char publishing_department[10];
	struct Date_Type publishing_time;
	int price;

};
int RecordNum=0;

int mainmenu()
{
	int i;
	printf("...........mainmenu...........\n");
	printf("0........read the disk\n");
	printf("1........input\n");
	printf("2........inquire\n");
	printf("3........edit\n");
	printf("4........display\n");
	printf("5........delete\n");
	printf("6........save\n");
	printf("7........quit\n");
	scanf ("%d",&i);
	return i;
}
void main()
{
	int sel=0;
    struct book_message bookstore[N];
    int loaddata(struct book_message bookstore[N]);
    void inputdata(struct book_message bookstore[N]);
    void inquire(struct book_message bookstore[N]);
    void edit(struct book_message bookstore[N]);
    void display(struct book_message bookstore[N]);
    void deldata(struct book_message bookstore[N]); 
    void savedata(struct book_message bookstore[N]);
    void quit(struct book_message bookstore[N]);
	loaddata(bookstore);
    //if(loaddata(bookstore)==0)
	//	inputdata(bookstore);
    while ((sel=mainmenu())!=7)
	{
	    switch(sel) 
		{
		case 0:loaddata(bookstore);
		  case 1:
			  inputdata(bookstore);
			  break;
		  case 2:
			  inquire(bookstore);
			  break;
		  case 3:
			  edit(bookstore);
			  break;
		  case 4:
			  display(bookstore);
			  break;
		  case 5:
			  deldata(bookstore);
			  break;
		  case 6:
			  savedata(bookstore);
			  break;
		  case 7:
			  quit(bookstore);
			  break;
		  default:printf("error\n");
		}
	}
	if(sel=7) printf("已退出\n");
	save(bookstore);
}

int loaddata(struct book_message bookstore[N])
{  
	FILE* fp;
	int recordNum=0;
	if((fp=fopen("book.data","rb"))==NULL){
		printf("data file open error!\n");
	}
	else{
		recordNum=fread(bookstore,sizeof(struct book_message),N,fp);
		if(recordNum!=N){
			printf("read %d data from file!\n",recordNum);
		}
		fclose(fp);
	}
	return recordNum;
}

void inputdata(struct book_message bookstore[N])
{
	int i,num;
	printf("This is the first time  of using this system!\n");
	printf("Please input %d Books:\n",N);
	scanf("%d",&num);
	for (i=0;i<N;i++)
	{
		printf("input accession_number:\n");
		scanf("%d",&bookstore[i].accession_number);
		printf("input book_name:\n");
		scanf("%s",bookstore[i].book_name);
		printf("input author:\n");
		scanf("%s",bookstore[i].author);
		printf("input class_number:\n");
		scanf("%s",bookstore[i].class_number);
		printf("input publishing_department:\n");
		scanf("%s",bookstore[i].publishing_department);
		printf("input the year of publishing_time:\n");
		scanf("%d",&bookstore[i].publishing_time.year);
		printf("input the month of publishing_time:\n");
		scanf("%d",&bookstore[i].publishing_time.month);
		printf("input the day of publishing_time:\n");
		scanf("%d",&bookstore[i].publishing_time.day);
		printf("input the price:\n");
		scanf("%d",&bookstore[i].price);
		printf("\n\n");
	}
	RecordNum=num;
}

void inquire(struct book_message bookstore[N])
{
	int j;
    char author[10];
    printf("input author:\n");
	scanf("%s",bookstore[j].author);
    printf("Please inquire %d Books:\n",N);
	for (j=0;j<N;j++)
	{
		if (strcmp(author,bookstore[j].author)==0)
			printf("%d %s %s %s %s %d %d %d %d\n",bookstore[j].accession_number,bookstore[j].book_name,
                  bookstore[j].author,bookstore[j].class_number,bookstore[j].publishing_department,
                  bookstore[j].publishing_time.year,bookstore[j].publishing_time.month,
                  bookstore[j].publishing_time.day,bookstore[j].price);
	}
}      
void edit(struct book_message bookstore[N])
{
	int k,index;	
    char author[10];
    printf("input author:\n");
	scanf("%s",bookstore[k].author);
	for (k=0;k<RecordNum;k++)
	{
		if (strcmp(author,bookstore[k].author)==0)
		{
			printf("%d %s %s %s %s %d %d %d %d\n",bookstore[k].accession_number,bookstore[k].book_name,
                  bookstore[k].author,bookstore[k].class_number,bookstore[k].publishing_department,
                  bookstore[k].publishing_time.year,bookstore[k].publishing_time.month,
                  bookstore[k].publishing_time.day,bookstore[k].price);
                  index=k;
		}
	}
	    k=index;
        printf("输入修改后的登录号:\n");
		scanf("%d",&bookstore[k].accession_number);
		printf("输入修改后的书名:\n");
		scanf("%s",bookstore[k].book_name);
		printf("输入修改后作者名:\n");
		scanf("%s",bookstore[k].author);
		printf("输入修改后分类号:\n");
		scanf("%s",bookstore[k].class_number);
		printf("输入修改后出版单位:\n");
		scanf("%s",bookstore[k].publishing_department);
		printf("输入修改后出版年:\n");
		scanf("%d",&bookstore[k].publishing_time.year);
		printf("输入修改后出版月:\n");
		scanf("%d",&bookstore[k].publishing_time.month);
		printf("输入修改后出版日:\n");
		scanf("%d",&bookstore[k].publishing_time.day);
		printf("输入修改后价格:\n");
		scanf("%d",&bookstore[k].price);
		printf("\n\n");
}

void display(struct book_message bookstore[N])
{
	int l;
    char author[10];
    printf("input author:\n");
	scanf("%s",bookstore[l].author);
    printf("Please display %d Books:\n",N);
	for (l=0;l<N;l++)
	{
		printf("display the %d Book:\n",l);
		printf("display accession_number:\n");
		scanf("%d",&bookstore[l].accession_number);
		printf("display book_name:\n");
		scanf("%s",bookstore[l].book_name);
		printf("display author:\n");
		scanf("%s",bookstore[l].author);
		printf("display class_number:\n");
		scanf("%s",bookstore[l].class_number);
		printf("display publishing_department:\n");
		scanf("%s",bookstore[l].publishing_department);
		printf("display the year of publishing_time:\n");
		scanf("%d",&bookstore[l].publishing_time.year);
		printf("display the month of publishing_time:\n");
		scanf("%d",&bookstore[l].publishing_time.month);
		printf("display the day of publishing_time:\n");
		scanf("%d",&bookstore[l].publishing_time.day);
		printf("display the price:\n");
		scanf("%d",&bookstore[l].price);
		printf("\n\n");
	}
}

void deldata(struct book_message bookstore[N])
{ 
	int m,index_del=-1;
     char author[10];
    printf("input author:\n");
	scanf("%s",bookstore[m].author);
	for (m=0;m<RecordNum;m++)
	{
		if (strcmp(author,bookstore[m].author)==0)
		{
			printf("%d %s %s %s %s %d %d %d %d\n",bookstore[m].accession_number,bookstore[m].book_name,
                  bookstore[m].author,bookstore[m].class_number,bookstore[m].publishing_department,
                  bookstore[m].publishing_time.year,bookstore[m].publishing_time.month,
                  bookstore[m].publishing_time.day,bookstore[m].price);
                  index_del=m;
		}
	}
for(m=index_del;m<RecordNum;m++){
		strcpy(bookstore[m].book_name,bookstore[m+1].book_name);
		strcpy(bookstore[m].author,bookstore[m+1].author);
		strcpy(bookstore[m].class_number,bookstore[m+1].class_number);
		strcpy(bookstore[m].publishing_department,bookstore[m+1].publishing_department);
		bookstore[m].price=bookstore[m+1].price;
		bookstore[m].publishing_time.day=bookstore[m+1].publishing_time.day;
		bookstore[m].publishing_time.month=bookstore[m+1].publishing_time.month;
		bookstore[m].publishing_time.year=bookstore[m+1].publishing_time.year;
	    bookstore[m].accession_number=bookstore[m+1].accession_number;
	}
	RecordNum--;
}

void savedata(struct book_message bookstore[N])
{
	FILE* fp;
	int recordNum=0;
	printf("save: \n");
	if((fp=fopen("book.data","wb"))==NULL){
		printf("data file open error!\n");
	}
	else{
		recordNum=fwrite(bookstore,sizeof(struct book_message),N,fp);
		if(recordNum!=N){
			printf("write %d data to file!\n",recordNum);
		}
		fclose(fp);
	}
}

void quit(struct book_message bookstore[N])
{
	printf("quit: saving data!\n");
	savedata(bookstore);
}


