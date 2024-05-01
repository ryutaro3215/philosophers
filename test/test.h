// bank.h
#ifndef BANK_H
#define BANK_H

#include <pthread.h>

// 口座情報を保持する構造体
typedef struct {
    int balance;
    pthread_mutex_t lock;
} BankAccount;

// 関数プロトタイプ
void* deposit(void* account);
void* withdraw(void* account);

#endif

