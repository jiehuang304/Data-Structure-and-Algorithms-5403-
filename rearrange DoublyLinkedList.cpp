#include <iostream>

//created by Jie Huang
// N12687614
//jh5005
using namespace std;
struct Node
{
    char Data;
    Node *pPrev;
    Node *pNext;
};

struct Head
{
    Node *pFirst;
    Node *pLast;
};


Head* oldList(){
    char Color[26] = {'w','r','b','b','b','w','b','r','r','r','r','w','w','b','b','r','b','w','b','r','r','b','w','w','b','r'};
    Head *head = new Head;

    for (int i = 1; i <= 26; i++) {
        Node *tmp = new Node;
        tmp->Data = Color[i- 1];
        tmp ->pNext = NULL;
        if(i == 1) {
            head->pFirst = tmp;
            tmp->pPrev = NULL;
            continue;
        }
        if (i > 1 && i != 25) {
            Node *cur = new Node;
            cur = head->pFirst;
            while(cur->pNext != NULL) {
                cur = cur->pNext;
            }

            cur->pNext = tmp;
            tmp->pPrev = cur;
        }
        if (i == 25) {
            Node *cur = new Node;
            cur = head->pFirst;
            while(cur->pNext != NULL) {
                cur = cur->pNext;
            }
            cur->pNext = tmp;
            tmp->pPrev = cur;
            head->pLast = tmp;
        }

    }

 return head;
}


int main()
{
    Head *head = new Head;

    head = oldList();

    Head *redHead = new Head;
    Head *whiteHead = new Head;
    Head * blueHead = new Head;



    //dummy node to connect with head

    Node *redDummy = new Node;
    redDummy->Data = 'r';
    redHead->pFirst = redDummy;

    Node *whiteDummy = new Node;
    whiteDummy->Data ='w';
    whiteHead->pFirst = whiteDummy;

    Node *blueDummy = new Node;
    blueDummy->Data = 'b';
    blueHead->pFirst = blueDummy;

    //find node and add to each color head
    Node *tmp = new Node;
    tmp = head->pFirst;
    //Node * tmpNext = new Node;
    //tmpNext = tmp;

    while(tmp != NULL) {
        //tmpNext = tmp->pNext;
        //find red color
        if (tmp->Data == 'r') {
            redHead->pFirst->pNext = tmp;
            tmp->pPrev = redHead->pFirst;
            redHead->pFirst = redHead->pFirst->pNext;
            tmp = tmp->pNext;
        }

        //find white color
        else if (tmp->Data == 'w') {
            whiteHead->pFirst->pNext = tmp;
            tmp->pPrev = whiteHead->pFirst;
            whiteHead->pFirst = whiteHead->pFirst->pNext;
            tmp = tmp->pNext;
        }

        //find blue color
        else {
            blueHead->pFirst->pNext = tmp;
            tmp->pPrev = blueHead->pFirst;
            blueHead->pFirst = blueHead->pFirst->pNext;
            tmp = tmp->pNext;
        }
    }



 //connect together

    head->pFirst = redDummy->pNext;
    redDummy->pPrev = NULL;
    redHead->pFirst->pNext = whiteDummy->pNext;
    whiteDummy->pNext->pPrev = redHead->pFirst;
    whiteHead->pFirst->pNext = blueDummy->pNext;
    blueDummy->pNext->pPrev = whiteHead ->pFirst;

    head->pLast = blueHead->pFirst;
    head->pLast->pNext = NULL;

    //print
    //print

     cout << "After rearranging:" << endl;
    Node *tmp1 = new Node;
    tmp1 = head->pFirst;
    do{
        cout << tmp1->Data << " ";
        tmp1 = tmp1->pNext;
    }while(tmp1->pNext != NULL);
    cout << tmp1->Data <<" ";
     cout << endl;


    return 0;
}
