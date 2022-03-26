#include <bits/stdc++.h>
using namespace std;

struct Node{
    float coeff;
    int xexpo, yexpo, zexpo;
    Node* next;
    Node(float coeff, int xexpo, int yexpo, int zexpo){
        this->coeff = coeff;
        this->xexpo = xexpo;
        this->yexpo = yexpo;
        this->zexpo = zexpo;
        this->next = NULL;
    }
};

struct Header{
    int no_of_nodes;
    Node *ll;
    Header(){
        no_of_nodes = 0;
        ll = NULL;
    }
}header1, header2, headerSum;

Node* insert(Node *head, float coeff, int xexpo, int yexpo, int zexpo){
    Node *term = new Node(coeff, xexpo, yexpo, zexpo);
    if(head == NULL || xexpo >= head->xexpo){
        if(head == NULL){
            term->next = term;
            return term;
        }
        term->next = head;
        Node *t = head;
        while(t->next != head){
            t = t->next;
        }
        head = term;
        t->next = head;
        return head;
    }
    Node *temp = head;
    while(temp->next != head && temp->next->xexpo >= xexpo){
        temp = temp->next;
    }
    term->next = temp->next;
    temp->next = term;
    return head;
}

Node* create(Node *head, Header *header){
    int n;
    cout << "Enter the no. of terms in the polynomial: ";
    cin >> n;
    header->no_of_nodes = n;
    float coeff;
    int xexpo, yexpo, zexpo;
    for(int i = 1; i <= n; i++){
        cout << "Enter the coefficient and exponent(x, y, z) of term " << i << ": ";
        cin >> coeff >> xexpo >> yexpo >> zexpo;
        head = insert(head, coeff, xexpo, yexpo, zexpo);
    }
    header->ll = head;
    return head;
}

void printPoly(Node *head){
    if(head == NULL){
        cout << "No polynomial exist!\n";
        return;
    }
    Node *temp = head;
    cout << "f(x) = ";
    do{
        cout << "(" << temp->coeff << "x^" << temp->xexpo << "y^" << temp->yexpo << "z^" << temp->zexpo << ")";
        if(temp->next != head){
            cout << " + ";
        }
        temp = temp->next;
    }while(temp != head);
    cout << "\n";
}

Node* addPoly(Node *head1, Node *head2){
    Node *res = NULL;
    Node *p, *q;
    p = head1;
    q = head2;
    int pflag = 0;
    int qflag = 0;
    do{
        if(p->xexpo == q->xexpo && p->yexpo == q->yexpo && p->zexpo == q->zexpo){
            res = insert(res, p->coeff + q->coeff, p->xexpo, p->yexpo, p->zexpo);
            p = p->next;
            q = q->next;
            pflag = qflag = 1;
            headerSum.no_of_nodes++;
        }
        else if(p->xexpo + p->yexpo + p->zexpo > q->xexpo + q->yexpo + q->zexpo){
            res = insert(res, p->coeff, p->xexpo, p->yexpo, p->zexpo);
            p = p->next;
            pflag = 1;
            headerSum.no_of_nodes++;
        }
        else if(p->xexpo + p->yexpo + p->zexpo < q->xexpo + q->yexpo + q->zexpo){
            res = insert(res, q->coeff, q->xexpo, q->yexpo, q->zexpo);
            q = q->next;
            qflag = 1;
            headerSum.no_of_nodes++;
        }
        else{
            res = insert(res, q->coeff, q->xexpo, q->yexpo, q->zexpo);
            res = insert(res, p->coeff, p->xexpo, p->yexpo, p->zexpo);
            p = p->next;
            q = q->next;
            pflag = qflag = 1;
            headerSum.no_of_nodes += 2;
        }
    }while((p != head1 && q != head2) || ((!pflag && qflag) || (pflag && !qflag)));
    
    while(p != head1 || !pflag){
        res = insert(res, p->coeff, p->xexpo, p->yexpo, p->zexpo);
        p = p->next;
        pflag = 1;
        headerSum.no_of_nodes++;
    }
    while(q != head2 || !qflag){
        res = insert(res, q->coeff, q->xexpo, q->yexpo, q->zexpo);
        q = q->next;
        qflag = 1;
        headerSum.no_of_nodes++;
    }
    headerSum.ll = res;
    return res;
}

int evaluate(Node *head){
    int x, y, z;
    cout << "Enter the value of x, y, and z: ";
    cin >> x >> y >> z;
    int ans = 0;
    if(head == NULL){
        return ans;
    }
    Node *temp = head;
    do{
        ans = ans + (temp->coeff * pow(x, temp->xexpo) * pow(y, temp->yexpo) * pow(z, temp->zexpo));
        temp = temp->next;
    }while(temp != head);
    return ans;
}

int main(){
    Node *p1, *p2, *sum;
    p1 = p2 = sum = NULL;
    cout << "Enter the polynomial 1\n";
    p1 = create(p1, &header1);
    cout << "\n";
    cout << "Enter the polynomial 2\n";
    p2 = create(p2, &header2);
    cout << "\n";
    cout << "Polynomial 1: ";
    printPoly(p1);
    cout << "Polynomial 2: ";
    printPoly(p2);
    cout << "Polynomia 1 + Polynomial 2: ";
    sum = addPoly(p1, p2);
    printPoly(sum);
    cout << "\n";
    return 0;
}