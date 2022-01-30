// 12S20048 - Jevania
// 12S20050 - Putri Esrahana

#include "transaction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct transaction_t create_transaction(char *_title, unsigned short int _amount, enum type_t _type){
    struct transaction_t transaction;
    strcpy(transaction.title, _title);
    transaction.amount = _amount;
    transaction.type = _type;

    return transaction;
}

enum type_t get_type(char *_stype){
    if(strcmp(_stype, "income")==0){
        return TYPE_INCOME;
    }else if(strcmp(_stype, "expense")==0){
        return TYPE_EXPENSE;
    }
}

char *type_to_text(enum type_t _type){
    char *text = malloc(8);
    text[0] = '\0';

    switch(_type){
        case TYPE_INCOME : strcpy(text, "income");
            break;
        default : strcpy(text, "expense");
    }
    return text;
}

short int register_transaction(struct transaction_t **_transactions,
                               unsigned short int _transaction_size,
                               struct transaction_t _transaction){
    _transaction_size++;

    if( _transaction_size == 1){
        *_transactions = malloc(sizeof(struct transaction_t )*_transaction_size);
    }else{
        *_transactions = realloc(*_transactions, sizeof(struct transaction_t )*_transaction_size);
    }
    (*_transactions)[_transaction_size-1] = _transaction;

    return _transaction_size;
}

short int get_balance(struct transaction_t *_transactions,
                      unsigned short int _transaction_size){
    int totIncome=0, totExpense=0;
    int i;
    int totSum = 0;

    for(i=0; i<_transaction_size; i++){
        if(_transactions[i].type = TYPE_INCOME){
            totIncome = totIncome + _transactions[i].amount;
        }else if(_transactions[i].type = TYPE_EXPENSE){
            totExpense = totExpense + _transactions[i].amount;
        }
        totSum = totSum + totIncome - totExpense;
    }
    return totSum;  
}

void print_income_transactions(struct transaction_t *_transactions,
                               unsigned short int _transaction_size){
    int i;

    for(i=0; i<_transaction_size; i++){
        printf("%s;%hi;%s\n", _transactions[i].title, _transactions[i].amount, type_to_text(_transactions[i].type));
    }

}

void print_expence_transactions(struct transaction_t *_transactions,
                                unsigned short int _transaction_size){
    int i;

    for(i=0; i<_transaction_size; i++){
        printf("%s;%hi;%s\n", _transactions[i].title, _transactions[i].amount, type_to_text(_transactions[i].type));
    }   
}

void print_summary(struct transaction_t *_transactions,
                   unsigned short int _transaction_size){
    int totIncome=0, totExpense=0;
    int i;

    for(i=0; i<_transaction_size; i++){
        if(_transactions[i].type = TYPE_INCOME){
            totIncome = totIncome + _transactions[i].amount;
        }else if(_transactions[i].type = TYPE_EXPENSE){
            totExpense = totExpense + _transactions[i].amount;
        }
    }
    for(i=0; i<_transaction_size; i++){
        if(totIncome>totExpense){
            printf("%d surplus\n", get_balance(_transactions, _transaction_size));
        }else if(totIncome=totExpense){
            printf("%d balanced\n", get_balance(_transactions, _transaction_size));
        }else if(totIncome<totExpense){
            printf("%d deficit\n", get_balance(_transactions, _transaction_size));
        }
    }   
}
                
