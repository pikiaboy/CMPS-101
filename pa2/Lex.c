/*
  Name:Thomas Pham
  CruzID: 1593385
  Pa2
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"List.h"


int isInList(List L, int i);

int main(int argc, char* argv[]){

  if(argc != 3){
    printf("Usage: %s <input file> <output file>\n", argv[0]);
    exit(1);
  }
  List a = newList();
  char line[100];

  FILE *in, *out;
  in = fopen(argv[1], "r");
  out = fopen(argv[2], "w");

  if( in == NULL){
    printf("Unable to open file %s for reading\n", argv[1]);
    exit(1);
  }
  if(out == NULL){
    printf("Unable to open file %s for writing\n",argv[2]);
    exit(1);
  }

  int lineCount = 0;
  while( fgets(line, 100, in) != NULL){
    lineCount++;
  }
  rewind(in);

  char *lines[lineCount];
  for(int i = 0; i < lineCount; i++){
    fgets(line, 100, in);
    lines[i] = (char*)malloc(sizeof(line));
    strcpy(lines[i],line);
  }

  append(a,0);

  //sorting array
  for(int i = 1; i < lineCount; i++){
    moveFront(a);
    int found = 0;
    while (index(a) != -1) { //go until end of list
      if(strcmp(lines[i],lines[get(a)]) < 0){ //if current is bigger
        insertBefore(a,i); // insert in the correct order
        found = 1;
        break;
      }
      moveNext(a); // if not bigger, continue moving down list
    }
    if(found == 0) //if not found, append at the end
      append(a,i);
  }


  //writing array to file
  moveFront(a);
  while(index(a) != -1){
    fprintf(out, "%s",lines[get(a)]);
    moveNext(a);
  }

  //freeing all memory in lines
  for(int i = 0; i < lineCount; i++){
    free(lines[i]);
  }

  freeList(&a);

  fclose(in);
  fclose(out);

  return(0);
}


int isInList(List L, int i){
  moveFront(L);
  while(index(L) != -1){
    if(get(L) == i)
      return 1;
    moveNext(L);
  }
  return 0;
}
