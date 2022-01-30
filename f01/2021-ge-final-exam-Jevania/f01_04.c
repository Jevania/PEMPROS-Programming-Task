// 12S20048 - Jevania
// 12S20050 - Putri Esrahana

#include "custom.h"
#include "repository.h"
#include "transaction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int _argc, char **_argv){

  while (1){
    char *kata;
    char input[100];
    char temp[100];

    unsigned short int nTransaction = 0;
    struct transaction_t *transactions = NULL;
    struct transaction_t tempTransaction;

    FILE *fptr;
    fptr = fopen("./storage/transaction-repository.txt", "r");

    while (fgets(input, 100, fptr) != NULL){
      strcpy(temp, input);
      kata = strtok(temp, "|");
        strcpy(tempTransaction.title, kata);
      kata = strtok(temp, "|");
        tempTransaction.amount = atoi(kata);
      kata = strtok(temp, "|");
        tempTransaction.type = get_type(kata);

      nTransaction += 1;
    }
    fclose(fptr);

    get_input(input, 100);

    strcpy(temp, input);
    kata = strtok(temp, "#");

    if (strcmp(kata, "---") == 0){
      break;
    }else{
      if(strcmp(kata, "register-transaction") == 0){
        kata = strtok(NULL, "#");
          tempTransaction.type = get_type(kata);
        kata = strtok(NULL, "#");
          tempTransaction.amount = atoi(kata);
        kata = strtok(NULL, "#");
          strcpy(tempTransaction.title, kata);

        struct transaction_t newTransaction = create_transaction(tempTransaction.title, tempTransaction.amount, tempTransaction.type);
        printf("register-transaction %s|%d|%s\n", newTransaction.title, newTransaction.amount, type_to_text(newTransaction.type));
        
        nTransaction = register_transaction(&transactions, nTransaction, newTransaction);

      }else if(strcmp(kata, "print-income-transactions") == 0){
        for(int i=0; i<nTransaction; i++){
          kata = strtok(NULL, "#");
            tempTransaction.type = get_type(kata);
          kata = strtok(NULL, "#");
            tempTransaction.amount = atoi(kata);
          kata = strtok(NULL, "#");
            strcpy(tempTransaction.title, kata);

          if(tempTransaction.type = TYPE_INCOME){
            print_income_transactions(transactions, nTransaction);
          }
        }

      }else if(strcmp(kata, "print-expense-transactions") == 0){
        for(int i=0; i<nTransaction; i++){
          kata = strtok(NULL, "#");
            tempTransaction.type = get_type(kata);
          kata = strtok(NULL, "#");
            tempTransaction.amount = atoi(kata);
          kata = strtok(NULL, "#");
            strcpy(tempTransaction.title, kata);
            
          if(tempTransaction.type = TYPE_EXPENSE){
            print_expence_transactions(transactions, nTransaction);
          }
        }
      }else if(strcmp(kata, "print-summary") == 0){
        print_summary(transactions, nTransaction);
      }
    }
  }

  return 0;
}
