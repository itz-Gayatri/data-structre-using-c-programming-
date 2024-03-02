#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
int r_id;
char name[20];
int mem;
long long int con;
int arr_date;  //only enter date not month and year
 int depar_date;  //only enter date not month and year
char period[20];
struct node *next;
}*start=NULL;
void Create_List(int r_id, char name[], int mem, long long int con, int arr_date, int depar_date, char
period[]){
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->r_id=r_id;
strcpy(temp->name,name);
temp->mem=mem;
temp->con=con;
temp->arr_date=arr_date;   //only enter date not month and year
temp->depar_date=depar_date;   //only enter date not month and year
strcpy(temp->period,period);
temp->next=NULL;
start=temp;
}
void Insert_Item(int r_id, char name[], int mem, long long int con, int arr_date, int depar_date, char
period[]){
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->r_id=r_id;
strcpy(temp->name,name);
temp->mem=mem;
temp->con=con;
temp->arr_date=arr_date;   //only enter date not month and year
temp->depar_date=depar_date;   //only enter date not month and year
strcpy(temp->period,period);
if(start==NULL){
temp->next=start;
start=temp;
}
else{
struct node *c;
c=start;
while(c->next!=NULL){
c=c->next;
}
temp->next=c->next;
c->next=temp;
}
printf("\nData Inserted Successfully\n");
}
void Search_room(int r_id){
struct node *temp;
int flag=0;
temp=start;
while(temp->next!=NULL){
if(temp->r_id==r_id){
flag=1;
break;
}
else{
temp=temp->next;
}
}
if(temp->r_id==r_id){
flag=1;
}
if(flag==0){
printf("\nRoom not booked");
}
else{
printf("\nRoom booked");
}
}
void Delete_Record(int r_id){
struct node *temp,*q;
temp=start;
if(temp==NULL){
printf("\nList is Empty");
return;
}
else{
if(temp->r_id==r_id){
start=temp->next;
free(temp);
printf("\nRecord deleted successfully");
return;
}
while(temp->next->next!=NULL){
if(temp->next->r_id==r_id){
q=temp->next;
temp->next=q->next;
free(q);
return;
}
temp=temp->next;
}
if(temp->next->r_id==r_id){
q=temp->next;
temp->next=NULL;
free(q);
return;
}
}
}
void Count_Rooms_Booked(){
int count=0;
struct node *temp;
temp=start;
if(temp==NULL){
printf("\nList is empty");
return;
}
while(temp->next!=NULL){
count++;
temp=temp->next;
}
printf("\nNumber of Rooms booked is %d",count+1);
}
void Display_List(){
struct node *temp;
temp=start;
if(temp==NULL){
printf("\nNo Item Available");
return;
}
printf("\t\t\t\tHOTEL RESERVATIONS\n");
printf("\nRoom ID\t\t Name\t\tMembers\t\tContact\t\t\tArr_Date\t\tDepar_Date\t\tPeriod\n");
printf("\n----------------------------------------------------------------------\n");
while(temp->next!=NULL){
printf("%d\t \t",temp->r_id);
printf("%s\t\t",temp->name);
printf("%d\t\t",temp->mem);
printf("%lld\t\t",temp->con);
printf("%d\t\t\t",temp->arr_date);
printf("%d\t\t\t",temp->depar_date);
printf("%s\t\t\n",temp->period);
temp=temp->next;
}
printf("%d\t \t",temp->r_id);
printf("%s\t\t",temp->name);
printf("%d\t\t",temp->mem);
printf("%lld\t\t",temp->con);
printf("%d\t\t\t",temp->arr_date);
printf("%d\t\t\t",temp->depar_date);
printf("%s\t\t\n",temp->period);
}
int main(){
start=NULL;
int r_id;
char name[20];
int mem;
long long int con;
int arr_date;
int depar_date;
char period[20];
int choice,ch;
do{
printf("\n\t\t\tHOTEL RESERVATION");
printf("\n\tPress \n\t1 To Create a Record \n\t2To Insert a new record\n\t3 To Delete an record\n\t4 To Search a room booked or not\n\t5To Show the list of rooms\n\t6To Count the numberof rooms booked\n");
printf("\nEnter your choice:");
scanf("%d",&choice);
switch(choice){
case 1:
printf("\nEnter the Room ID:");
scanf("%d",&r_id);
printf("\nEnter the Name:");
scanf("%s",&name);
printf("\nEnter the Number of members:");
scanf("%d",&mem);
printf("\nEnter the contact:");
scanf("%lld",&con);
printf("\nEnter the Arrival date:");
scanf("%d",&arr_date);
printf("\nEnter the Departure date:");
scanf("%d",&depar_date);
printf("\nEnter the period:");
scanf("%s",&period);
Create_List(r_id,name,mem,con,arr_date,depar_date,period);
break;
case 2:
printf("\nEnter the Room ID:");
scanf("%d",&r_id);
printf("\nEnter the Name:");
scanf("%s",&name);
printf("\nEnter the Number of members:");
scanf("%d",&mem);
printf("\nEnter the contact:");
scanf("%lld",&con);
printf("\nEnter the Arrival date:");
scanf("%d",&arr_date);
printf("\nEnter the Departure date:");
scanf("%d",&depar_date);
printf("\nEnter the period:");
scanf("%s",&period);
Insert_Item(r_id,name,mem,con,arr_date,depar_date,period);
break;
case 3:
printf("\nEnter the room ID:");
scanf("%d",&r_id);
Delete_Record(r_id);
break;
case 4:
printf("\nEnter the Room ID:");
scanf("%d",&r_id);
Search_room(r_id);
break;
case 5:
Display_List();
break;
case 6:
Count_Rooms_Booked();
break;
default:
printf("\nInvalid Choice");
break;
}
printf("\n\nDo You want to Continue?");
printf("\n1.Yes\n2.No\n");
printf("\nEnter Your Choice:");
scanf("%d",&ch);
}while(ch==1);
return 0;
}