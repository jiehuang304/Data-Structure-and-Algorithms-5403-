#include <string.h>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdbool.h>

using namespace std;
// Created by Jie Huang
// N#: 12687614
// Contact: jh5005@nyu.edu
// CS 5403 HW 4

struct node 
{
    int val;
    node *left;
    node *right;
    node *up;
    node *down;
};


class mSquare
{
public:
    node *head;
    int n;
    mSquare (int k){
        n  = k;
    }
    
   void addNode(int k) 
    {   //initialize new node
        node *next = new node;
        (*next).val = 0;
        (*next).left = NULL;
        (*next).right = NULL;
        (*next).up = NULL;
        (*next).down = NULL;
       
        //1st head
        if (k == 1){
            head = next;
        }

        //1st row only consider left and right
       else if (k <= n && k != 1){
           //find left node
            node *cur = new node;
            cur = findNode(k - 1);
            (*cur).right = next;
            (*next).left = cur;
            cur = next;

        }
        //1st colomn only consider up and down
        else if (k > n && k % n == 1){
            node *tmp = new node;
            tmp = findNode(k - n);
            (*tmp).down = next;
            (*next).up = tmp;
        } else {
            //other situations: alway link the up and left with other nodes
            //link the left node
            if (k > n) {
                node *tmpLeft = new node;
                tmpLeft = findNode(k - 1);
                (*tmpLeft).right = next;
                (*next).left = tmpLeft;
                //linkthe up node
                node *tmpUp = new node;
                tmpUp = findNode(k - n);
                (*tmpUp).down = next;
                (*next).up = tmpUp;
            } 
        }
    }

    //find the # node you need to link with
    node* findNode(int k)
    {  
        
        node *find = new node;
        find = head;
        int colomn = (k - 1) % n + 1;
        int row = (k - 1) / n;
        
        for (int i = 0; i < colomn - 1; i++) {
            find = (*find).right;
        }
        for (int i = 0; i < row; i++) {
            find = (*find).down;
        }
        return find;
        
    }

    void createMagicSquare()
    {   //create empty magic square
        for (int i = 1; i <= n * n ; i++) addNode(i);
        
        //add 1st node 1 to the top middel position
        node *frist = new node;
        frist = head;
        for (int i = 1; i < n / 2 ; i++) {
            frist = frist->right;
        }
        head = frist->right;
        head->val = 1;
        
        //add value in the sauqre;
        addVal(n);
        
    }
    
    
    void addVal(int n)
    {  
        for (int i = 2; i <= n*n; i++) {
            if ((*head).up == NULL && (*head).right != NULL) {
                node *cur = new node;
                cur = head;
                while ((*cur).down != NULL) {
                    cur = (*cur).down;
                }
                cur = (*cur).right;
                (*cur).val = i;
                head = cur;
            }
            
            else if ((*head).up != NULL && (*head).right == NULL) {
                node *cur = new node;
                cur = head;
                while ((*cur).left != NULL) {
                    cur = (*cur).left;
                } 
                cur = (*cur).up;
                (*cur).val = i;
                head = cur;
            }
            else if ((*head).up == NULL && (*head).right == NULL) {
                head = (*head).down;
                (*head).val = i;
            }
            else if (head->right->up->val != 0) {
                head = head->down;
                head->val = i;
            }
            else if (head->right != NULL && head->up != NULL) {
                head = head->right->up;
                head->val = i;
            }
        }

    } 
};


int main()
{
    int n;
    cout << "Builds a magic square for any odd integer n=" <<endl;
     cin >> n;
    if (n%2 == 0 ) {
        cout << "Must be an odd integer!"<< endl;
        return 0;
    }
    mSquare *pHJ = new mSquare(n);
    mSquare hJSquare = *pHJ;
    //create magic square
    hJSquare.createMagicSquare();
   
    node *pos = hJSquare.head;
    //put cur at left top position
    while(pos->left != NULL) {
        pos = pos->left;
    }
    while (pos->up != NULL) {
        pos = pos->up;
    }
    cout << "There is a " << n << " X " << n <<"Magic Square:" << endl;
    //print out the square
    while (pos != NULL) {
        node * print = pos;
        //print by row;
        while (print != NULL) {
            cout<<print->val<<" ";
            print = print->right;
        }
        cout << endl;
        pos = pos->down;
    }

   delete pHJ;
    return 0;
}
