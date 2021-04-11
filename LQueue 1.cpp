#include "LQueue.h"
using namespace std;

void show_Menu()
{
    cout << "****************************************************************************" << endl;
    cout << "*****************0.退出系统*************************************************" << endl;
    cout << "*****************1.入队操作*************************************************" << endl;
    cout << "*****************2.查看队头元素*********************************************" << endl;
    cout << "*****************3.检查队列是否为空*****************************************" << endl;
    cout << "*****************4.确定队列长度*********************************************" << endl;
    cout << "*****************5.出队操作*************************************************" << endl;
    cout << "*****************6.清空队列*************************************************" << endl;
    cout << "*****************7.销毁队列*************************************************" << endl;
    cout << "*****************8.遍历函数操作*********************************************" << endl;
    cout << "*****************9.操作函数*************************************************" << endl;
    cout << "****************************************************************************" << endl;
    cout << endl;
}

void exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}


//初始化队列
Status InitLQueue(LinkQueue* Q) {
    Q->front = Q->rear = (QuenePtr)malloc(sizeof(QNode));
    if (!Q->front)exit(OVERFLOW);
    Q->front->next = NULL;
    return TRUE;
}

//销毁队列
void DestoryLQueue(LinkQueue* Q) {
    while (Q->front) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
}

//检查队列是否为空
Status IsEmptyLQueue(const LinkQueue* Q) {
    if (Q->front == Q->rear) {
        cout << "队列里面什么都没有!" << endl;
        return FALSE;
    }
    else {
        cout << "队列不为空" << endl;
        return TRUE;
    }
}
//确定队列长度
void LengthLQueue(LinkQueue* Q) {
    cout <<"队列长度为："<< Q->length << endl;
}

//查看队头元素
Status GetHeadLQueue(LinkQueue* Q) {
    if (Q->front == Q->rear) { cout << "队列里面什么都没有!" << endl;  return FALSE; }
    cout << Q->front->next->data << endl;
    return TRUE;
}

//入队操作
LinkQueue* EnLQueue(LinkQueue* Q, int data) {
    QuenePtr p;
    p= (QuenePtr)malloc(sizeof(QNode));
    if(!p)exit(OVERFLOW);
    p->data = data;
    p->next = NULL;
    if (Q->length == 0)Q->front = p;
    Q->rear->next = p;
    Q->rear = p;
    return Q;
}

//出队操作
Status DeLQueue(LinkQueue* Q) {
    QuenePtr p;
    if (Q->front == Q->rear) { cout << "队列里面什么都没有!" << endl;  return FALSE; }
    p = Q->front->next;
    cout << p->data << endl;
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->rear = Q->front;
    }
    delete p;
    return TRUE;
}

//遍历函数操作
Status TraverseLQueue(const LinkQueue* Q, void (*foo)(QuenePtr p)) {
    QuenePtr p;
    p = Q->front->next;
    if (Q->front == Q->rear) { cout << "队列里面什么都没有!" << endl; return FALSE; }
    while (p) {
        foo(p);
        p = p->next;
    }
    return TRUE;
}

void foo(QuenePtr p) {
    cout << p->data << endl;
}

//操作函数
void LPrint(LinkQueue* Q) {
    QuenePtr p;
    if (Q->front == Q->rear) { cout << "队列里面什么都没有!" << endl; return; }
    p = Q->front->next;
    while (p) {
        cout << p->data << endl;
        p = p->next;
    }
}

//清空队列
void ClearLQueue(LinkQueue* Q) {
    QuenePtr p;
    if (Q->front == Q->rear) { cout << "队列里面什么都没有!" << endl; return; }
    p = Q->front;
    while (p) {
        p->data = 0;
        p = p->next;
    }
    cout << "队列已清空" << endl;
}

int main() 
{
	int choice = 0;
    int data;
    Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	cout << "正在初始化中......" << endl;
    InitLQueue(Q);
	cout << "初始化已经完成。" << endl;
	cout << "感谢您的使用。" << endl;

	
    while (true)
    {
        show_Menu();
        cout << "请输入您的选择" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0://退出系统
            exitSystem();
            break;
        case 1://入队操作
            cout << "请输入data的值：（0为结束）" << endl;
            cin >> data;
            Q->length = 0;
            Q->length++;
            while (data) {
                Q=EnLQueue(Q, data);
                cout << "请输入data的值：（0为结束）" << endl;
                cin >> data;
                Q->length++;
            }
            break;
        case 2://查看队头元素
            cout << "队头元素是：" << endl;
            GetHeadLQueue(Q);
            break;
        case 3://检查队列是否为空
            IsEmptyLQueue(Q);
            break;
        case 4://确定队列长度
            LengthLQueue(Q);
            break;
        case 5://出队操作
            DeLQueue(Q);
            break;
        case 6://清空队列
            ClearLQueue(Q);
            break;
        case 7://销毁队列
            DestoryLQueue(Q);
            break;
        case 8://遍历函数操作
            TraverseLQueue(Q, foo);
            break;
        case 9://操作函数
            LPrint(Q);
            break;
        default:
            cout << "输入错误" << endl;
            cout << "请重新输入" << endl;
            system("pause");
            system("cls");
            break;
        }
    }


	system("pause");
	return 0;
}