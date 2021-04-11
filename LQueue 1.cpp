#include "LQueue.h"
using namespace std;

void show_Menu()
{
    cout << "****************************************************************************" << endl;
    cout << "*****************0.�˳�ϵͳ*************************************************" << endl;
    cout << "*****************1.��Ӳ���*************************************************" << endl;
    cout << "*****************2.�鿴��ͷԪ��*********************************************" << endl;
    cout << "*****************3.�������Ƿ�Ϊ��*****************************************" << endl;
    cout << "*****************4.ȷ�����г���*********************************************" << endl;
    cout << "*****************5.���Ӳ���*************************************************" << endl;
    cout << "*****************6.��ն���*************************************************" << endl;
    cout << "*****************7.���ٶ���*************************************************" << endl;
    cout << "*****************8.������������*********************************************" << endl;
    cout << "*****************9.��������*************************************************" << endl;
    cout << "****************************************************************************" << endl;
    cout << endl;
}

void exitSystem()
{
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}


//��ʼ������
Status InitLQueue(LinkQueue* Q) {
    Q->front = Q->rear = (QuenePtr)malloc(sizeof(QNode));
    if (!Q->front)exit(OVERFLOW);
    Q->front->next = NULL;
    return TRUE;
}

//���ٶ���
void DestoryLQueue(LinkQueue* Q) {
    while (Q->front) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
}

//�������Ƿ�Ϊ��
Status IsEmptyLQueue(const LinkQueue* Q) {
    if (Q->front == Q->rear) {
        cout << "��������ʲô��û��!" << endl;
        return FALSE;
    }
    else {
        cout << "���в�Ϊ��" << endl;
        return TRUE;
    }
}
//ȷ�����г���
void LengthLQueue(LinkQueue* Q) {
    cout <<"���г���Ϊ��"<< Q->length << endl;
}

//�鿴��ͷԪ��
Status GetHeadLQueue(LinkQueue* Q) {
    if (Q->front == Q->rear) { cout << "��������ʲô��û��!" << endl;  return FALSE; }
    cout << Q->front->next->data << endl;
    return TRUE;
}

//��Ӳ���
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

//���Ӳ���
Status DeLQueue(LinkQueue* Q) {
    QuenePtr p;
    if (Q->front == Q->rear) { cout << "��������ʲô��û��!" << endl;  return FALSE; }
    p = Q->front->next;
    cout << p->data << endl;
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->rear = Q->front;
    }
    delete p;
    return TRUE;
}

//������������
Status TraverseLQueue(const LinkQueue* Q, void (*foo)(QuenePtr p)) {
    QuenePtr p;
    p = Q->front->next;
    if (Q->front == Q->rear) { cout << "��������ʲô��û��!" << endl; return FALSE; }
    while (p) {
        foo(p);
        p = p->next;
    }
    return TRUE;
}

void foo(QuenePtr p) {
    cout << p->data << endl;
}

//��������
void LPrint(LinkQueue* Q) {
    QuenePtr p;
    if (Q->front == Q->rear) { cout << "��������ʲô��û��!" << endl; return; }
    p = Q->front->next;
    while (p) {
        cout << p->data << endl;
        p = p->next;
    }
}

//��ն���
void ClearLQueue(LinkQueue* Q) {
    QuenePtr p;
    if (Q->front == Q->rear) { cout << "��������ʲô��û��!" << endl; return; }
    p = Q->front;
    while (p) {
        p->data = 0;
        p = p->next;
    }
    cout << "���������" << endl;
}

int main() 
{
	int choice = 0;
    int data;
    Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	cout << "���ڳ�ʼ����......" << endl;
    InitLQueue(Q);
	cout << "��ʼ���Ѿ���ɡ�" << endl;
	cout << "��л����ʹ�á�" << endl;

	
    while (true)
    {
        show_Menu();
        cout << "����������ѡ��" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0://�˳�ϵͳ
            exitSystem();
            break;
        case 1://��Ӳ���
            cout << "������data��ֵ����0Ϊ������" << endl;
            cin >> data;
            Q->length = 0;
            Q->length++;
            while (data) {
                Q=EnLQueue(Q, data);
                cout << "������data��ֵ����0Ϊ������" << endl;
                cin >> data;
                Q->length++;
            }
            break;
        case 2://�鿴��ͷԪ��
            cout << "��ͷԪ���ǣ�" << endl;
            GetHeadLQueue(Q);
            break;
        case 3://�������Ƿ�Ϊ��
            IsEmptyLQueue(Q);
            break;
        case 4://ȷ�����г���
            LengthLQueue(Q);
            break;
        case 5://���Ӳ���
            DeLQueue(Q);
            break;
        case 6://��ն���
            ClearLQueue(Q);
            break;
        case 7://���ٶ���
            DestoryLQueue(Q);
            break;
        case 8://������������
            TraverseLQueue(Q, foo);
            break;
        case 9://��������
            LPrint(Q);
            break;
        default:
            cout << "�������" << endl;
            cout << "����������" << endl;
            system("pause");
            system("cls");
            break;
        }
    }


	system("pause");
	return 0;
}