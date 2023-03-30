#include <iostream>
using namespace std;

struct Node {		//��㶨��
    int data;
    Node* next;
};

/**
    �ϲ����������µ�������
*/
void merge(Node* newList, Node* list1, Node* list2) {
    //������������ǿ�
    if (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {		//�������1<=����2
            newList->next = list1;				//���������һ���ڵ�ָ������1
            newList = newList->next;			//�������л���һ���ڵ�
            merge(newList, list1->next, list2);	//�ݹ�ϲ�
        }
        else {									//�������1>����2
            newList->next = list2;				//���������һ���ڵ�ָ������2
            newList = newList->next;			//�������л���һ���ڵ�
            merge(newList, list1, list2->next);	//�ݹ�ϲ�
        }
    }

    if (list1 != NULL && list2 == NULL) {		//�ڶ��������list1�ǿգ�list2��
        newList->next = list1;
        newList = newList->next;
        merge(newList, list1->next, NULL);
    }
    if (list2 != NULL && list1 == NULL) {		//�����������list1�գ�list2�ǿ�
        newList->next = list2;
        newList = newList->next;
        merge(newList, NULL, list2->next);
    }
}

int main() {
    Node* newList = new Node{ NULL, NULL };		//����������

    Node* list1 = new Node{ NULL,NULL };		//��������1
    Node* LinkList1 = list1;					//��������1ͷ���
    cout << "dsb:";
    int data;
    cin >> data;
    while (data != -1) {						//��������1
        Node* newNode = new Node{ data,NULL };
        list1->next = newNode;
        list1 = list1->next;
        cin >> data;
    }

    Node* list2 = new Node{ NULL,NULL };		//��������2
    Node* LinkList2 = list2;					//��������2ͷ���
    cout << "dsbc:";
    int data2;
    cin >> data2;
    while (data2 != -1) {						//��������2
        Node* newNode = new Node{ data2,NULL };
        list2->next = newNode;
        list2 = list2->next;
        cin >> data2;
    }

    merge(newList, LinkList1->next, LinkList2->next);	//���õݹ��㷨

    Node* p = newList->next;		//����������
    for (; p != NULL; p = p->next) {
        cout << p->data << " ";
    }
}

