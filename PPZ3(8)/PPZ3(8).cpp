#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int val) : data(val), next(nullptr) {}
};

void add(Node*& head, int N, int j)
{
	if (N > j)
	{
		int n = rand() % 1001;
		Node* cur = new Node(n);
		head->next = cur;
		j++;
		add(cur, N, j);
	}
}

void add(Node*& head, int o)
{
	Node* cur = new Node(o);
	cur->next = head;
	head = cur;
}

void show(Node* head)
{
	Node* current = head;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

void deleteList(Node* head)
{
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

Node* reverseKNodes(Node* head, int k) {
	if (head == nullptr || k == 1) {
		return head;
	}

	Node* dummy = new Node(0);
	dummy->next = head;
	Node* prev = dummy;
	Node* curr = head;
	int count = 0;

	// Count the number of nodes in the list
	while (head) {
		head = head->next;
		count++;
	}

	// Reverse k nodes at a time
	while (count >= k) {
		Node* first = curr;
		Node* prevBlockEnd = prev;

		// Reverse k nodes
		for (int i = 0; i < k; i++) {
			Node* nextNode = curr->next;
			curr->next = prevBlockEnd;
			prevBlockEnd = curr;
			curr = nextNode;
		}

		prev->next = prevBlockEnd;
		first->next = curr;

		prev = first;
		count -= k;
	}

	return dummy->next;
}

int main()
{
	int N = -1, k = -1;
	Node* head = new Node(1);
	srand(time(NULL));

	do {
		cout << "Count of elements (1 <= N <= 5000): ";
		cin >> N;
	} while (N >= 5000 || N <= 1);

	do {
		cout << "Value of k (1 <= k <= " << N << "): ";
		cin >> k;
	} while (k > N || k < 0);

	add(head, N, 0);
	head = head->next;

	cout << "Original List: ";
	show(head);

	// Reverse nodes in k-groups
	head = reverseKNodes(head, k);

	cout << "Modified List: ";
	show(head);

	deleteList(head);
	return 0;
}
