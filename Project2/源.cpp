#include <iostream>
using namespace std;

struct Node {		//结点定义
    int data;
    Node* next;
};

/**
    合并两个链表到新的链表方法
*/
void merge(Node* newList, Node* list1, Node* list2) {
    //如果两个链表都非空
    if (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {		//如果链表1<=链表2
            newList->next = list1;				//新链表的下一个节点指向链表1
            newList = newList->next;			//新链表切换下一个节点
            merge(newList, list1->next, list2);	//递归合并
        }
        else {									//如果链表1>链表2
            newList->next = list2;				//新链表的下一个节点指向链表2
            newList = newList->next;			//新链表切换下一个节点
            merge(newList, list1, list2->next);	//递归合并
        }
    }

    if (list1 != NULL && list2 == NULL) {		//第二种情况，list1非空，list2空
        newList->next = list1;
        newList = newList->next;
        merge(newList, list1->next, NULL);
    }
    if (list2 != NULL && list1 == NULL) {		//第三种情况，list1空，list2非空
        newList->next = list2;
        newList = newList->next;
        merge(newList, NULL, list2->next);
    }
}

int main() {
    Node* newList = new Node{ NULL, NULL };		//创建新链表

    Node* list1 = new Node{ NULL,NULL };		//创建链表1
    Node* LinkList1 = list1;					//保存链表1头结点
    cout << "dsb:";
    int data;
    cin >> data;
    while (data != -1) {						//创建链表1
        Node* newNode = new Node{ data,NULL };
        list1->next = newNode;
        list1 = list1->next;
        cin >> data;
    }

    Node* list2 = new Node{ NULL,NULL };		//创建链表2
    Node* LinkList2 = list2;					//保存链表2头结点
    cout << "dsbc:";
    int data2;
    cin >> data2;
    while (data2 != -1) {						//创建链表2
        Node* newNode = new Node{ data2,NULL };
        list2->next = newNode;
        list2 = list2->next;
        cin >> data2;
    }

    merge(newList, LinkList1->next, LinkList2->next);	//调用递归算法

    Node* p = newList->next;		//遍历输出结果
    for (; p != NULL; p = p->next) {
        cout << p->data << " ";
    }
}

