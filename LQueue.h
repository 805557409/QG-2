#pragma once
#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

/***************************************************************************************
 *    File Name                :    LQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                    :   Mac OS
 *    Create Data                :    2020.4.2
 *    Author/Corportation        :   Chuan Shi
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
  *    Multi-Include-Prevent Section
  **************************************************************/
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#define MAXQSIZE 100

  /**************************************************************
   *    Struct Define Section
   **************************************************************/
   //��ʽ���нṹ
typedef struct Qnode
{
    int data;                   //������ָ��
    struct Qnode* next;            //ָ��ǰ������һ���
} QNode, * QuenePtr;

typedef struct Lqueue
{
    QuenePtr front;                   //��ͷ
    QuenePtr rear;                    //��β
    size_t length;            //���г���unsigned int
} LinkQueue;


LinkQueue* Q;

typedef enum
{
    FALSE = 0, TRUE = 1
} Status;
char type;
char datatype[30];

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


 /**
  *  @name        : void InitLQueue(LQueue *Q)
  *    @description : ��ʼ������
  *    @param         Q ����ָ��Q
  *  @notice      : None
  */
Status InitLQueue(LinkQueue* Q);

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LinkQueue* Q);

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LinkQueue* Q);

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LinkQueue* Q);

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
void LengthLQueue(LinkQueue* Q);

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
LinkQueue* EnLQueue(LinkQueue* Q, void* e);

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LinkQueue* Q);

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LinkQueue* Q);

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LinkQueue* Q, void (*foo)(void* q));

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(LinkQueue* Q);

void exitSystem();
void show_Menu();
void foo(QuenePtr p);

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED

