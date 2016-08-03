/*
 * stackbasedBFS.c
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
#include <stdlib.h>
#include <unistd.h>

#define CCOUNT 7
#define false 0
#define true 1

typedef char bool;

typedef struct NODE {
       char data;
       struct NODE* child;
}NODE;

/*Tree Intializatin routine ** Not part of the algorithm*/
NODE* initializetree(NODE* root, int childrencount, int level) {
int i;
static int si;
if(root == NULL) {
si=level;
root=(NODE*)malloc(sizeof(NODE));
root->data='a';
root->child=NULL;
}
if(--level == 0) return root;
root->child=(NODE*)malloc(childrencount * sizeof(NODE));
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

/*BFS sub routine*/
bool printtree(NODE* node, int target, int level) {
int i;
bool returnval=false;
if (target > level) {
for(i=0;i<CCOUNT;i++) if(printtree(node->child+i,target,level+1) ) returnval=true;
}
else {
printf("%c",(node->data));
if(node->child != NULL) returnval=true;
}
return returnval;
}

/*BFS routine*/
void printbfstree(NODE* root) {
if(root == NULL) return;
int target=0;
while(printtree(root,target++,0)) {
printf("\n");
}
}

/*Main routine*/
int main(int argc, char **argv){
int c;
int desiredlevel=3;
while ((c=getopt(argc, argv, "hl:")) != -1)
switch(c) {
case 'l' :
desiredlevel=atoi(optarg);
break;
case 'h' :
printf("stackbasedBFS [-l level] [-h]\n");
return -1;
}
NODE* root=NULL;
root=initializetree(NULL,CCOUNT,desiredlevel);
printbfstree(root);
deallocatetree(root,1);
return 0;
}
