/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   clientcxnmanager.h
 * Author: aurelio
 *
 */
#include "config.h"

#ifndef CLIENTCXNMANAGER_H
#define CLIENTCXNMANAGER_H

#define BUFFERSIZE 2048

void *threadProcess(void * ptr);
int open_connection(ClientConfig cfgClient);

#endif /* CLIENTCXNMANAGER_H */

