/*
 * stackbasedBFSSpaceTime.c
 * Stack Based BFS (Breadth First Search) Tree Traversal
 * Copyright (c) 2015-2016 Minh Inc www.minhinc.com
 *
 * This file is part of StackBasedBFS
 *
 * StackBasedBFS
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * StackBasedBFS
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Mgmp; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int CCOUNT = 7;
int targetlevel=3;
int maxvalue=0;

#define false 0
#define true 1

typedef char bool;


typedef struct NODE {
       char data;
       struct NODE* child;
}NODE;

typedef struct QUEUE {
NODE *data;
}QUEUE;
int queue_front,queue_rear;

#ifdef SPACEDATA
/*In order to calculate stack space consumed by stack based approach*/
int base_ptr_begin=0,base_ptr_end=0xFFFFFFFF;
#endif
#ifdef TIMEDATA
/*In order to calculate time elapsed in both approach*/
struct timeval start_time, end_time, diff_time;
void gettimesub(struct timeval* a, struct timeval* b, struct timeval* c) {
c->tv_usec=(a->tv_usec>=b->tv_usec)?a->tv_usec-b->tv_usec:a->tv_usec+(1000000-b->tv_usec);
c->tv_sec=(a->tv_usec>=b->tv_usec)?a->tv_sec-b->tv_sec:a->tv_sec-b->tv_sec-1;
}
#endif

/*Tree Intialization routine ** Not part of the algorithm ** */
NODE* initializetree(NODE* root, int childrencount, int level) {
int i;
static int si;
if(root == NULL) {
si=level;
if( (root=(NODE*)malloc(sizeof(NODE)))==NULL) return NULL;
root->data='a';
root->child=NULL;
}
if(--level == 0) return root;
if( (root->child=(NODE*)malloc(childrencount * sizeof(NODE)))==NULL) return NULL;
for(i=0;i<childrencount;i++){
(root->child+i)->data=((si+1-level)%3?((si-level)%3?48:97):65)+i;
(root->child+i)->child=NULL;
initializetree(root->child+i,childrencount,level);
}
return root;
}

/*Tree deallocation routine ** Not part of the algorithm*/
bool deallocatetree(NODE* root,int level) {
int i;
if(root == NULL) return false;
if(root->child != NULL) {
for(i=0;i<CCOUNT;i++) if(deallocatetree(root->child+i,level+1)) break;
}else {
free(root);
return true;
}
if(i == CCOUNT) free(root->child);
if(level == 1) free(root);
return false;
}

/*stack based BFS sub routine*/
bool printtree(NODE* node, int target, int level) {
int i;
#ifdef SPACEDATA
    __asm__("movl %%ebp, %0;" : "=r" ( i));
(char*)i>(char*)base_ptr_begin && (base_ptr_begin=i) || (char*)i<(char*)base_ptr_end && (base_ptr_end=i);
#endif
bool returnval=false;
if (target > level) {
for(i=0;i<CCOUNT;i++) if(printtree(node->child+i,target,level+1) ) returnval=true;
}
else {
#ifndef NOPRINT
printf("%c",(node->data));
#endif
if(node->child != NULL) returnval=true;
}
return returnval;
}

/*stack based BFS routine*/
void printbfstree(NODE* root) {
if(root == NULL) return;
int target=0;
while(printtree(root,target++,0)) {
#ifdef LPRINT
printf("\n");
#endif
#ifdef SPACEDATA
(char*)base_ptr_begin>(char*)base_ptr_end && (char*)maxvalue<((char*)base_ptr_begin-(char*)base_ptr_end) && (maxvalue=base_ptr_begin-base_ptr_end);
base_ptr_begin=0;
base_ptr_end=0xFFFFFFFF;
#endif
}
#ifdef SPACEDATA
(char*)base_ptr_begin>(char*)base_ptr_end && (char*)maxvalue<((char*)base_ptr_begin-(char*)base_ptr_end) && (maxvalue=base_ptr_begin-base_ptr_end);
#endif
#ifndef NOPRINT
printf("\n");
#endif
}

/*QUEUE based BFS approach*/
QUEUE* allocatequeue(int targetlevel) {
queue_front=queue_rear=-1;
int size;
size=(int)pow(CCOUNT,targetlevel-1)+1;
printf("queue based, allocated for queue size %d ,each node size %d bytes\n",size,sizeof(QUEUE));
return malloc(sizeof(QUEUE)*(size));
}

bool isqueueempty() {
if (queue_rear == queue_front) return true;
return false;
}

bool isqueuefull() {
if ((queue_front+1)%(int)pow(CCOUNT,targetlevel-1)== queue_rear) return true;
return false;
}

void pushinqueue(QUEUE* queue,NODE* itemdata) {
queue_front=(queue_front+1)%((int)pow(CCOUNT,targetlevel-1)+1);
(queue+queue_front)->data=itemdata;
}

NODE* popqueue(QUEUE* queue) {
if (queue_rear == queue_front) return NULL;
queue_rear=(queue_rear+1)%((int)pow(CCOUNT,targetlevel-1)+1);
return (queue+queue_rear)->data;
}

void deallocatequeue(QUEUE* node) {
free(node);
}

void BFS(QUEUE* queue,NODE* root) {
int i;
NODE* queuenode;
pushinqueue(queue,root);
while(!isqueueempty()) {
queuenode=popqueue(queue);
#ifndef NOPRINT
printf("%c",queuenode->data);
#endif
if(queuenode->child == NULL) continue;
for(i=0;i<CCOUNT;i++) pushinqueue(queue,(queuenode->child+i));
#ifdef SPACEDATA
maxvalue<(queue_front<queue_rear?queue_front+1+(int)pow(CCOUNT,targetlevel-1)-queue_rear:queue_front-queue_rear)&& (maxvalue=(queue_front<queue_rear?queue_front+1+(int)pow(CCOUNT,targetlevel-1)-queue_rear:queue_front-queue_rear));
#endif
}/*while*/
#ifndef NOPRINT
printf("\n");
#endif
}


/*Main routine*/
int main(int argc, char **argv){
int c;
QUEUE* rootqueue;
while ((c=getopt(argc, argv, "hc:l:")) != -1)
switch(c) {
case 'c' :
CCOUNT=atoi(optarg);
break;
case 'l' :
targetlevel=atoi(optarg);
break;
case 'h' :
printf("stackbasedBFS [-l level] [-c childcount] [-h]\n");
return -1;
}
NODE* root=NULL;
if( (root=initializetree(NULL,CCOUNT,targetlevel))==NULL) {
fprintf(stderr,"allocation failed, exiting");
exit(-1);
}
rootqueue=allocatequeue(targetlevel);
if(rootqueue == NULL) {
fprintf(stderr,"allocation failed, exiting");
exit(-1);
}
printf("printing queue based\n");
#ifdef TIMEDATA
gettimeofday(&start_time,NULL);
#endif
BFS(rootqueue,root);
#ifdef SPACEDATA
printf("queue based, queue usage size %d\n",maxvalue);
maxvalue=0;
#endif
#ifdef TIMEDATA
gettimeofday(&end_time,NULL);
gettimesub(&end_time,&start_time,&diff_time);
printf("diff time %lu sec %lu micro\n",diff_time.tv_sec,diff_time.tv_usec);
#endif
printf("\nprinting stack based\n");
#ifdef TIMEDATA
gettimeofday(&start_time,NULL);
#endif
printbfstree(root);
#ifdef SPACEDATA
printf("stack used %d\n",maxvalue);
#endif
#ifdef TIMEDATA
gettimeofday(&end_time,NULL);
gettimesub(&end_time,&start_time,&diff_time);
printf("diff time %lu sec %lu micro\n",diff_time.tv_sec,diff_time.tv_usec);
#endif
printf("\nprinting done\n");
deallocatequeue(rootqueue);
deallocatetree(root,1);
return 0;
}
