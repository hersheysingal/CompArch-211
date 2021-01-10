#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct block{
  int valid;
  unsigned long long int tag;
  unsigned long long int age;
  int freq;
};

int main(int argc, char** argv){
  int reads=0;
  int writes=0;
  int hits=0;
  int misses=0;
  int association;
  int numsets;
  int poli;
  
  int cachesize = atoi(argv[1]);
  char assoc = argv[2][0];
  int blocksize = atoi(argv[4]);
  char policy = argv[3][0];
  char* tname = argv[5];
  FILE* trace = fopen(tname, "r");

  if(assoc == 'd'){
    association = 1;
    numsets = cachesize/blocksize;
  }
  else if(assoc == 'a'){
    if(argv[2][5] == ':'){
      sscanf(argv[2], "assoc:%d", &association);  
      numsets =cachesize/blocksize/association;
    }
    else{
      association =cachesize/blocksize;
      numsets = 1;
    }
  }

  if(policy == 'f'){
    poli = 0;
  }
  else if(policy == 'l'){
    poli = 1;
  }
  int bbits = log(blocksize) / log(2);
  int sbits = log(numsets) / log(2);
  unsigned long long int off = (1 << sbits) - 1;

  int agec = 69;
  struct block ** c = (struct block**) malloc(numsets * sizeof(struct block*));
  for(int i=0; i<numsets; i++){
    c[i] = (struct block*) malloc(association * sizeof(struct block));
  }

  char action;
  unsigned long long int memAdd;
  
  while(!feof(trace)){
    int numofVar = fscanf(trace, "%*x: %c %llx", &action, &memAdd);
    unsigned long long int t;
    int endbits = bbits+sbits;
    t = memAdd>>(endbits);
    unsigned long long int setIndex;
    unsigned long long int memshiftb = memAdd>>bbits;
    setIndex = (memshiftb)&off;    

    if(numofVar != 2){
      break;
    }
    else if(numofVar == 2){
      int full = 1;
      int ii = 0;
      for(int i = 0; i < association; i++){
        ii = i;
        if(c[setIndex][i].valid != 0){
          if(t == c[setIndex][i].tag){
            hits += 1;
            full = -1;
            if(action == 'W'){
              writes +=1;
            }
            break;
          }
        }
        else if(c[setIndex][i].valid == 0){
          full=0;
          break;
        }
      }
      if(full == 0){
        struct block new;
        new.age = agec;
        new.valid = 1;
        agec += 1;
        new.tag = t;
        c[setIndex][ii] = new;
        misses += 1;
        reads += 1;
        if(action == 'W'){
          writes +=1;
        }
      }
      else if(full==1){
        if(poli == 0){
          int youngest=0;
          for(int i=0; i<association; i++){
            if(c[setIndex][youngest].age > c[setIndex][i].age){
              youngest=i;
            }
          }
          struct block new;
          new.age=agec;
          new.valid=1;
          agec += 1;
          new.tag=t;
          c[setIndex][youngest]=new;
          if(action == 'W'){
            writes +=1;
          }
          misses += 1;
          reads += 1;
        }
        else if(poli == 1){
          int youngest=0;
          for(int i=0; i<association; i++){
            if(c[setIndex][youngest].age <= c[setIndex][i].age){
              youngest=i;
            }
          }
          struct block new;
          new.age=agec;
          new.valid = 1;
          agec += 1;
          new.tag=t;
          c[setIndex][youngest]=new;
          if(action == 'W'){
            writes +=1;
          }
          misses += 1;
          reads += 1;
        }
      }
    }
  }
  printf("Memory reads: %d\n", reads);
  printf("Memory writes: %d\n", writes);
  printf("Cache hits: %d\n", hits);
  printf("Cache misses: %d\n", misses);
  return 0;
}
