#include<stdio.h>
#include<stdlib.h>

int roomGlobal=1;//A global counter for room number

struct node{//A structure of room details
	int NumberOfPeople;
	char name[30];
	int RoomType;
	int RoomNumber;
	int CheckInDate;
	struct node* link;

};
struct node* root=NULL; //head node

void append()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter Name\n");
	fgetc(stdin);
	fgets(temp->name, 30 , stdin);
	printf("\nEnter Number Of People In The Room\n");
	scanf("%d",&temp->NumberOfPeople);
	printf("\nEnter Room Type\n");
	printf("\nEnter 1 for Single Room\n2 For Deulex room\n3 for Penthouse\n");
	scanf("%d",&temp->RoomType);
	printf("\nEnter CheckIn date in ddmmyy\n");
	scanf("%d",&temp->CheckInDate);
	temp->RoomNumber=roomGlobal++;
	printf("\nYour room number is %d\n",temp->RoomNumber);
	temp->link=NULL;
	if(root==NULL)
		root=temp;
	else
	{
		struct node* p;
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;

	}

}


int search(int key)//giving the index of the place where the element is (takes in room number)
{
    int index;
    struct node *curNode;

    index = 1;
    curNode = root;


    while (curNode != NULL && curNode->RoomNumber != key)
    {
        index++;
        curNode = curNode->link;
    }


    return (curNode != NULL) ? index : 0;
}

int NOD(int a, int b)//a is checkout date, nod for number of days, b is check in date
{
    int temp1=a;
    int NoOfDays;
    int temp2=b;
    if(temp1%100==temp2%100)
    {
        temp1/=100;
        temp2/=100;
        if(temp1%100==temp2%100)
        {
            NoOfDays=a-b;
        }
        else
            NoOfDays=a+(31-b);

    }
    else
    {
        if((temp1%100-temp2%100)>1){
            NoOfDays=365-(a+(31-b))*31;
        }
    }
    return NoOfDays;
}

float FinalCalculation(int a, int b)//a is type of room b is numer of days
{
    float net;
    //10 percent tax;
    net=(a*b*1)*0.11;//10 percent tax
    return net;
}

void del(int room)
{
    struct node* temp;
    struct node* temp2;
    int loc;
    loc=search(room);//only if search()!=0 do later
    int x=1;
    if(loc==1)
    {
        temp2=root;
        int checkoutdate;
        printf("Enter checkout date");
        scanf("%d",&checkoutdate);
        float ans=FinalCalculation(NOD(checkoutdate,temp2->CheckInDate),temp2->RoomType);
        printf("You have to pay %f",ans);
    }
    else{
        struct node* z=root;
        while(x<loc)
        {
            z=z->link;
            x++;
        }
        int checkoutdate;
        printf("Enter checkout date");
        scanf("%d",&checkoutdate);
        float ans=FinalCalculation(NOD(checkoutdate,z->CheckInDate),z->RoomType);
        printf("You have to pay %f\n",ans);

    }
    if(loc==1)
    {
        temp=root;
        root=temp->link;
        temp->link=NULL;
        free(temp);

    }
    else
    {
        int i=1;
        struct node* p=root, *q;
        while(i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;
        free(q);
    }
}

void display()
{
    struct node* temp;
    temp=root;
    while(temp!=0)
    {
        printf("Name: %s\n",temp->name);
        printf("Room Number: %d\n",temp->RoomNumber);
        printf("Room Type: %d\n",temp->RoomType);
        printf("Check In Date: %d\n",temp->CheckInDate);
        temp=temp->link;
    }
}


struct worker
{
  int id,worktime,age,salary,extrahours;
  char name;
  struct worker*next;
};*first=NULL;


int removeColon(char s[5])
{
  int d;
  d=s[0]*1000+s[1]*100+s[3]*10+s[4];
  return d;
}


int diff(char s1[5], char s2[5])
{
    int time1 = removeColon(s1);
    int time2 = removeColon(s2);
    int hourDiff = time2 / 100 - time1 / 100 - 1;
    int minDiff = time2 % 100 + (60 - time1 % 100);
    if (minDiff >= 60) {
        hourDiff++;
        minDiff = minDiff - 60;
    } return hourDiff;
}


void detail()
{
  struct worker*l;
  l=(struct worker*)malloc(sizeof(struct worker*));
  printf("Enter workers details :- ");
  printf("\nWorkers id: ");
  scanf("%d",&l->id);
  printf("Name: ");
  scanf("%s",&l->name);
  printf("Age: ");
  scanf("%d",&l->age);
  printf("Work time: ");
  scanf("%d",&l->worktime);
  l->salary=800*l->worktime;
  printf("\n%d\n",l->salary);
  l->next=first;
  first=l;
}


void bonus()
{
struct worker *u;
u=first;
while(u!=NULL)
{
  if(u->extrahours>=30){
    printf("%s gets a bonus of 30,000 rs",u->name);
    u->salary=u->salary+30,000;
  }
  u=u->next;
}
}



void salary()
{
  int k=0;
  printf("\nTo calculate extra hours\n");
  struct worker *j;
  j=first;
  char h[5],w[5];
  int e,r;
  printf("Enter id: ");
  scanf("%d",&r);
  printf("Start time:(00:00)");
  scanf("%s",&h);
  printf("End time:(00:00) ");
  scanf("%s",&w);
  e=diff(h,w);
  while(j!=NULL)
  {
    if(j->id==r){
      j->extrahours=j->extrahours+e;
      j->salary=j->salary+e*800;
    }
    else{
      printf("User not found");
    }
  j=j->next;
  }
  printf("\nExtra hours salary has been added and noted!\n ");
  k++;
  if(k==30){
    printf("End of cycle bonus\n");
    bonus();
    k=0;
  }
}

void main()
{
  int e,r;
  label:
      printf("Select 1 for room booking\nSelect 2 for workers \n");
      scanf("%d",&e);
      if(e==1){
      int n=2;
            printf("\n\nEnter 1 for CheckIn\n2 for CHeckOut\n3for display\n");
            scanf("%d",&n);
            switch(n)
            {
            case 1:
                {
                    append();
                    break;
                }
            case 2:
                {
                    printf("Enter your room");
                    int w;
                    scanf("%d",&w);
                    del(w);
                    break;
                }
            case 3:
                {
                    display();
                    break;
                }
            default:
                {
                    break;
                }
            }
    }
    else if(e==2){
        int n;
        printf("\n\nNew employee press 1\nEnter Work hours press 2\n");
        scanf("%d",&n);
        switch(n)
        {
          case 1: detail();
                  break;
          case 2: salary();
                  break;
        }
    }
    printf("\nTo return to home page press 1\nTo exit press anything else");
    scanf("%d",&r);
    if(r==1){
        goto label;
    }
}