#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 255

typedef struct node{
  char word[MAX_WORD_LENGTH];
  // simple circular list to iterate through everything
  struct node *next;
  // markov chain
  int child_length;
  struct node *child;
  struct node *sibling;
} node;

node *addToEmpty(node *last, char word[MAX_WORD_LENGTH])
{
    last = (node*)malloc(sizeof(node));

    strcpy(last -> word, word);

    last -> next = last;
    last -> sibling = NULL;
    last -> child_length = 1;

    return last;
}

node *addEnd(node *last, char word[MAX_WORD_LENGTH])
{
    if (last == NULL)
        return addToEmpty(last, word);

    node *temp = (node *)malloc(sizeof(node));

    strcpy(temp -> word, word);
    temp -> sibling = NULL;
    temp -> child_length = 1;
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;

    return last;
}


void freeList(node *head)
{
   node *tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}

// false if not same, true if same;
int compareTwoNodes(node *a, node *b, int n) {
  for (int i = 0; i < n; i++) {
    if (strcmp(a->word, b->word)) return 0;
    a = a->next;
    b = b->next;
  }
  return 1;
}

// find first match
node *findMatch(node *a, int n, int length) {
  node *b = a;
  for (int i = 1; i < length; i++) {
    if (compareTwoNodes(a, b->next, n)) {
      return b;
    }
    b = b->next;
  }
  return NULL;
}

void addSibling(node *a, node *b) {
  if (a->sibling == NULL) {
    a->sibling = b;
    return;
  }
  addSibling(a->sibling, b);
}

void createTree(node *head, int length, int n) {
  node *a = head;
  for (int i = 0; i < length; i++) {
    node *b = findMatch(a, n, length - i);
    if (b != NULL) {
      printf("\r%d/%d", i+1, length);
      // change b child to a
      b->child = a;
      // add b_value to a_value sibling
      node *a_value = a, *b_value = b->next;
      for (int j = 0; j < n; j++) {
        a_value = a_value->next;
        b_value = b_value->next;
      }
      addSibling(a_value, b_value);
    }
    a = a->next;
  }
  printf("\r               ");
}

void *countChild(node *head, int length) {
  for (int i = 0; i < length; i++) {
    int count = 0;
    node *child = head->child;
    while(child != NULL) {
      count++;
      child = child->sibling;
    }
    head->child_length = count;
    head = head->next;
  }
}

node *getChild(node *parent, int index) {
  node *child = parent->child;
  for (int i = 0; i < index; i++)
    child = child->sibling;
  return child;
}

node *getRandomNode(node *head, int length) {
  int index = (rand() % length);
  for (int i = 0; i < index; i++) {
    head = head->next;
  }
  return head;
}

int main() {
  // to be user input
  int n ;
  int print_length ;
  char infile[255];
  time_t t;
  char *outfile = "outfile3.txt";
  srand((unsigned)(time(&t)));
  printf("                            Welcome to N-Gram Simulation\n");
  printf("                                Delivered by Group C6\n");
  printf("\n");
  printf("__________________________________________________________________________________________\n");
  printf("\n");
  printf("1.Kendrik Emkel Ginting 13218077\n");
  printf("2.Rizki Habibi Alamsyah 13218080\n");
  printf("3.Mohammad Salman Subki 13218078\n");
  printf("4.Anindhita Nayazirly   13218083\n");
  printf("5.Michael Kresna Putra  13218066\n");
  printf("\n");
  printf("Dalam dunia computational linguistics dan probabilitas dikenal istilah n-gram, yaitu rangkaian\nkata-kata, fonem, huruf, suku kata, atau yang lainnya dari sebuah teks atau kalimat. Model\nn-gram merupakan pendekatan bahasa menggunakan konsep probabilitas untuk memprediksi atau\nmenebak kata selanjutnya dari suatu rangkaian kata-kata.\n");
  printf("\n");
  printf("Sok Mangga Dipilih Textnya:\n");
  printf("APoemFromAFriend.txt\ncisneros.txt\nhamlet.txt\nhurston.txt\nisiguro.txt\nladygaga.txt\nmobydick.txt\nmorrison.txt\nshort.txt\ntiny.txt\ntomsawyer.txt\nTextReference_13218066.txt\nTextReference_13218077.txt\n");
  printf("Atau Masukkan Pilihan Teksmu.");
  printf("\n\n");
  int akhir=0;
  int isEnd=0;
  char End[5];
  char coba[5];
  while(akhir==0){
    printf("Masukkan Text File                        :");scanf("%s",infile);
    printf("Masukkan N                                :");scanf("%d",&n);
  //while (isEnd==0){
  //printf("Masukkan Jumlah Kata Yang Ingin Dicetak   :");scanf("%d",&print_length);
  //printf("\n");
  // scan text
  //printf("reading text..\n");
    FILE *fptr = fopen(infile, "r");
    char temp[MAX_WORD_LENGTH];

    node *last = NULL;
    int length = 0;
    while (fscanf(fptr, "%s", temp) != EOF) {
      last = addEnd(last, temp);
      length++;
    }
  //printf("length = %d\n", length);

  // copy next to child
    for (int i = 0; i < length; i++) {
      last->child = last->next;
      last = last->next;
    }
  // create tree
    printf("Processing...\n");
    createTree(last->next, length, n);
    countChild(last->next, length);
    printf("\rTree Created\n");
    while (isEnd==0){
      printf("Masukkan Jumlah Kata Yang Ingin Dicetak   :");scanf("%d",&print_length);
      printf("\n");
      // mainkeun
      printf("Printing...\n\n");
      //srand(time(0));
      int max;
      node *print = getRandomNode(last, length);
      fptr = fopen(outfile, "w");
      fprintf(fptr, "... ");
      printf("...");
      for (int i = 0; i < print_length; i++) {
        printf("%s ", print->word);
        fprintf(fptr, "%s", print->word);
        max = print->child_length;
        int num = (rand() % max);
        print = getChild(print, num);
      }
      fprintf(fptr, "...");
      printf("...\n\n");
      printf("Finished Printing\n\n");
      printf("Wish to print more words?(Yes/No)\n");scanf("%s",End);
      if (strcmp(End,"Yes")){
      isEnd=1;
      }
    }
  printf("Wish to restart?(Yes/No)\n");scanf("%s",coba);
  if (strcmp(coba,"Yes")){
    akhir=1;
  }
  }
  

  #ifdef DEBUG
  // ini nge print semua node
  last = last->next;
  for (int i = 0; i < length; i++) {
    printf("%s %d\n", last->word, last->child_length);
    printf("child = ");
    node *child = last->child;

    for (int j = 0; j < last->child_length; j++) {
      printf("%s ", child->word);
      child = child->sibling;
    }
    printf("\n");

    last = last->next;
  }
  printf("\n");
  #endif

  // unlink circular list
  node *head = last -> next;
  last->next = NULL;

  freeList(head);
}