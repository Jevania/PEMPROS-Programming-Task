// 12S20048 - Jevania
// 12S20050 - Putri Esrahana

#include "repository.h"
#include "custom.h"
#include "transaction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void save_transactions_to_repository(struct transaction_t *_transactions,
                                     unsigned short int _transaction_size){
FILE *repositoryTransaction = fopen(DEFAULT_TRANSACTION_REPOSITORY, "w");
  if (repositoryTransaction == NULL)
  {
    printf("Something went wrong\n");
    return;
  }

  int i;
  for(i=0; i<_transaction_size; i++){
        printf("%s|%hi|%s\n", _transactions[i].title, _transactions[i].amount, type_to_text(_transactions[i].type));
    }

  fflush(repositoryTransaction);

  short int errorTransaction = fclose(repositoryTransaction);
  if (errorTransaction != 0)
  {
    printf("Something went wrong\n");
    return;
  }
}
