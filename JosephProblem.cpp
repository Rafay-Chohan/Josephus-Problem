#include <iostream>
#include <string.h>
#include<ctime>
using namespace std;

template <typename T>
class Queue
{

public:
	class node
	{
		T  data;
		node* next;
		node(T d, node* p)
		{
			data = d;
			next = p;
		}
		friend class Queue<T>;
	};

	class Queueiterator
	{
	protected:
		node* current;
		friend class Queue<T>;
	public:
		//Default Constructor
		Queueiterator()
		{
			current = nullptr;
		}
		//Parameterized Constructor used in begin and end functions
		Queueiterator(node* p)
		{
			current = p;
		}
		//Dereference operation to provide access of data to user
		T& operator* () const
		{
			return current->data;
		}
		//Move forward Pre-increment
		Queueiterator& operator++ ()
		{
			if (current != nullptr)
				this->current = this->current->next;
			return *this;
		}
		//Move forward Post-increment
		Queueiterator operator++ (int)
		{
			Queueiterator old = *this;
			++(*this);
			return old;
		}
		//If two iterators point to same node
		bool operator== (const Queueiterator& rhs) const { return current == rhs.current; }
		//If two iterators point to different nodes
		bool operator!= (const Queueiterator& rhs) const { return !(*this == rhs); }
	};
	//Iterator returned that points to First Node 
	Queueiterator begin()
	{
		return front;
	}
	//Iterator returned that points to Last Node  
	Queueiterator end()
	{
		return nullptr;
	}

	//Other Functions of Link Queue
	void  printQueue();
	void  Enqueue(T value);
	void Dequeue();
	void Dequeue(T& element);
	bool isFull();
	bool isEmpty();

	Queue() { front = nullptr; rear = nullptr; }
	~Queue();
private:
	node* front;
	node* rear;
};
template <typename T>
bool Queue<T>::isFull()
{
	return false;
}
template <typename T>
bool Queue<T>::isEmpty()
{
	if (front == nullptr)
		return true;
	else
		return false;
}
//Erase
template <typename T>
void Queue<T>::Dequeue()
{
	if (front == rear)
	{
		node* curr = front;
		front = rear = NULL;
		delete curr;
		return;
	}
	node* curr = front;
	front = front->next;
	delete curr;
}
template <typename T>
void Queue<T>::Dequeue(T& element)
{
	node* curr = front;
	front = front->next;
	element = curr->data;
	delete curr;
}
//Enqueuenode at rear
template <typename T>
void Queue<T>::Enqueue(T value)
{
	node* nnode = new node(value, nullptr);
	if (front == NULL)
	{
		front = nnode;
		rear = nnode;
	}
	else
	{
		rear->next = nnode;
		rear = nnode;
	}
}
//Destructor
template <typename T>
Queue<T>::~Queue()
{
	node* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}

}

//print Queue
template <typename T>
void Queue<T>::printQueue()
{
	node* current;
	current = front;
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout<< endl << endl;
}
template <typename T>
void josephusProblem(int k, int n, Queue<T> &Q)
{
	srand(time(NULL));
	int start = rand()%n;
	T temp;
	cout << "All Players: ";
	Q.printQueue();
	for (int i = 0; i < start; i++)//Traverses to Starting index
	{
		Q.Dequeue(temp);
		Q.Enqueue(temp);
	}
	cout << "Starting from ";								//
	cout << temp;											//Shows Starting point, Current players and value of k
	cout << " every " << k << "th person will die\n\n";		//
	for (int i = 0; i < k && n > 1 ; i++)//Kills Kth person till only 1 is left
	{
		Q.Dequeue(temp);
		if (i != k-1)
		{
			Q.Enqueue(temp);
		}
		else
		{
			i = -1;
			n--;
			cout << temp << " died ;-;\n";
			(n == 1) ? cout << "Last Survivor: ":cout<<"Remaining: ";
			Q.printQueue();
		}
	}
}
void Start()
{
	Queue<string> Q;
	int player, k;
	string str;
	cout << "Welcome Josephus Game of Death"<<endl;
	cout << "Enter Number of players: ";
	cin >> player;
	for (int i = 1; i <= player; i++)
	{
		cout << "Enter name of player " << i<<": ";
		cin >> str;
		Q.Enqueue(str);
	}
	cout << "Enter value of k(kth person will die each cycle): ";
	cin >> k;
	system("cls");
	cout << "-------------------------Josephus Game: Every kth person will die till 1 survivor is remaining-------------------------\n";
	josephusProblem(k, player, Q);
	getchar();
	return;
}
int main()
{
	Start();
	system("pause");
	return 0;
}