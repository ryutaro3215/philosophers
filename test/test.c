// bank.c
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "test.h"

// 預入れ関数
void* deposit(void* data) {
    BankAccount *account = (BankAccount*) data;
    int amount = 500;  // この例では固定金額を預けます

    pthread_mutex_lock(&account->lock);
    account->balance += amount;
    printf("Deposited %d, New Balance = %d\n", amount, account->balance);
    pthread_mutex_unlock(&account->lock);   

    return NULL;
}

// 引き出し関数
void* withdraw(void* data) {
    BankAccount *account = (BankAccount*) data;
    int amount = 200;  // この例では固定金額を引き出します

    pthread_mutex_lock(&account->lock);
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrew %d, New Balance = %d\n", amount, account->balance);
    } else {
        printf("Failed to withdraw %d, Insufficient funds, Balance = %d\n", amount, account->balance);
    }
    pthread_mutex_unlock(&account->lock);

    return NULL;
}

int main() {
    BankAccount account = {1000, PTHREAD_MUTEX_INITIALIZER};
    pthread_t t1, t2;

    // スレッドの作成
    pthread_create(&t1, NULL, deposit, &account);
    pthread_create(&t2, NULL, withdraw, &account);

    // スレッドの終了を待機
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // ミューテックスの破棄
    pthread_mutex_destroy(&account.lock);

    return 0;
}
