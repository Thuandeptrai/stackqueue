#include<iostream>
#include<string.h>
using namespace std;
int Ans[1000000];
int numb = 0;

struct Node {
  int data;
  Node * link;
};

Node * top;

void push(int data) {

  Node * temp = new Node();

  if (!temp) {

    exit(1);
  }

  temp -> data = data;

  temp -> link = top;

  top = temp;
}

int isEmpty() {

  return top == NULL;
}

int peek() {

  if (!isEmpty())
    return top -> data;
  else
    exit(1);
}

void pop() {
  Node * temp;

  if (top == NULL) {

    exit(1);
  } else {

    temp = top;

    top = top -> link;

    free(temp);
  }
}

struct QNode {
  int data;
  QNode * next;
  QNode(int d) {
    data = d;
    next = NULL;
  }
};

struct Queue {
  QNode * fronts, * rear;
  Queue() {
    fronts = rear = NULL;
  }

  void enQueue(int x) {

    QNode * temp = new QNode(x);

    if (rear == NULL) {
      fronts = rear = temp;
      return;
    }

    rear -> next = temp;
    rear = temp;
  }

  void deQueue() {

    if (fronts == NULL)
      return;

    QNode * temp = fronts;
    fronts = fronts -> next;

    if (fronts == NULL)
      rear = NULL;

    delete(temp);
  }
};

void Ispalimore(string letters) {

  Queue q;
  int a = 0, temp = 0;
  for (int i = 0; i < letters.size(); i++) {
    int Inttest = (int) letters[i] - 48;

    q.enQueue(Inttest);
    push(Inttest);

  }

  while (a != letters.size() && (q.fronts) -> data == peek()) {
    a++;
    pop();
    q.deQueue();
  }

  if (a == letters.size()) {

    if (stoi(letters) % 2 != 0) {

      numb++;
      Ans[numb] = stoi(letters);
    }

  }

}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    auto s = std::to_string(i);
    Ispalimore(s);

  }

  for (int i = 1; i <= numb; i++) {
    cout << Ans[i] << " ";
  }

  return 0;
}
