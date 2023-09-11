#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 5
void display();
int empty();
int full();
int enqueuerear(int value);
int dequeuerear(int *value);
int enqueuefront(int value);
int dequeuefront(int *value);
int size();
void view();
int queue[SIZE],front=-1,rear=-1;
void main()
{
int status,choice,data;
display();
while(1)
{
printf("\nEnter ur choice");
scanf("%d",&choice);
switch(choice)
{
case 0:
display();
break;
case 1:
printf("\n enter the element:");
fflush(stdin);
scanf("%d",&data);
status=enqueuefront(data);
if(status==-1)
printf("dequeue overflow on enqueue at front");
break;
case 2:
printf("\n enter the element");
fflush(stdin);
scanf("%d",&data);
status=enqueuerear(data);
if(status==-1)
printf("dequeue overflow on enqueue at rear");
break;
case 3:
status=dequeuefront(&data);
if(status==-1)
printf("\ndequeue underflow on dequeue at front");
else
printf("\n the dequeue value is %d",data);
break;
case 4:
status=dequeuerear(&data);
if(status==-1)
printf("\ndequeue underflow on dequeue at rear");
else
printf("\n the dequeue value is %d",data);
break;
case 5:
printf("number of elements in dequeue id %d",size());
break;
case 6:
view();
break;
default:
printf("\n end of run");
exit(0);
}}}
void display()
{
printf("\n dequeue using array");
printf("\n\t 0.view menu");
printf("\n\t 1.enqueue at front");
printf("\n\t 2.enqueue at rear");
printf("\n\t 3.dequeue at front");
printf("\n\t 4.dequeue at rear");
printf("\n\t 5.size of the queue");
printf("\n\t 6.view");
printf("\n\t 7.exit");
}
int empty()
{
extern int queue[],front,rear;
if(front==-1 && rear==-1)
return 1;
else
return 0;
}
int full()
{
extern int queue[],front,rear;
if(rear==(SIZE - 1))
return 1;
else
return 0;
}
int enqueuefront(int value)
{
extern int queue[],front,rear;
if(empty())
front=rear=0;
else if(full())
return -1;
else
front =front -1;
queue[front]=value;
return 0;
}
int enqueuerear(int value)
{
extern int queue[],front,rear;
if(empty())
front=rear=0;
else if(full())
return -1;
else
rear =rear + 1;
queue[rear]=value;
return 0;
}
int dequeuefront(int *value)
{
extern int queue[],front,rear;
if(empty())
return -1;
*value=queue[front];
if(front==rear)
front = rear = -1;
else
front = front + 1;
return 0;
}
int dequeuerear(int *value)
{
extern int queue[],front,rear;
if(empty())
return -1;
*value=queue[rear];
if(front==rear)
front= rear = -1;
else
rear = rear - 1;
return 0;
}
int size()
{
extern int queue[],front,rear;
if(empty())
return 0;
return(rear -front + 1);
}
void view()
{
extern int queue[],front,rear;
int f;
if(empty())
{
printf("\n dequeue is empty");
return;
}
printf("\n content of the dequeue...\n Front ->");
for(f=front;f!=rear;f=f+1)
printf("%d -->",queue[f]);
printf("%d ->REAR",queue[f]);
if(full())
printf("\n deque if full");
}
