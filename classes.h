/*
	#include <iostream>
	using namespace std;
	
	template<class t>
	class node
	{
	t data;
	node<t> *next, *previous;
	};
	
	template<class t>
	class linked_list
	{
	private:
	int size;
	node<t> *head;
	node<t> *tail;         //here bottom is like head & top is like tail
	public:
	linked_list()
	{
	size = 0;
	this->bottom = nullptr;
	this->top = nullptr;
	}
	class iterator
	{
	friend
	node<t> * current;
	iterator(){current = nullptr;}
	iterator(iterator const & object){this->current = object.current;}
	iterator(linked_list<t> const& object){this->current = object.head;}
	t& operator*(){if(this->current != nullptr) return current->data;}
	bool operator==(iterator const& object) const
	{
	if(this->current == object.current)
	{
	return true;
	}
	return false;
	}
	bool operator!=(iterator const& object) const
	{
	if(this->current != object.current)
	{
	return true;
	}
	return false;
	}
	iterator& operator++()
	{
	if(this->current != nullptr)
	{
	this->current = current->next;
	}
	return *this;
	}
	
	iterator& operator++(int)
	{
	iterator temp(*this);
	if(this->current != nullptr)
	{
	this->current = current->next;
	}
	return temp;
	}
	};
	typename iterator begin()
	{
	iterator temp(*this);       //linked passed as arguement/parameter
	return temp;
	}
	typename iterator end()
	{
	iterator temp(this->tail);
	return temp;
	}
	void insert_at_end(t data)
	{
	
	}
	};
	
	int main()
	{
	
	}
*/

#include<iostream>
#include<string.h>
#include<string>
#include<fstream>

using namespace std;

//----------------------------NODE---------------------------
template<class t>
class node
{
public:
	t data;
	node<t> * next;
	~node(){next = nullptr;}
};
//----------------------------LINKED LIST--------------------
template<class t>
class linked_list
{
public:
	node<t> *head, *tail;
	int size;
	linked_list()                           //Default Constructor
	{
		head = tail = nullptr;
		size = 0;
	}
	linked_list(const linked_list<t> &obj)       //Copy Constructor
	{
		tail = nullptr;
		head = nullptr;
		this->size = 0;
		node<t> * current = obj.head;
		while (current != nullptr)
		{
			this->insert_at_end(current->data);
			current = current->next;
		}
	}
	class iterator
	{
		node<t> *current;
		//friend class linked_list<t>;
	public:
		iterator(){current = nullptr;}
		iterator(iterator const& object){current = object.current;}
		iterator(linked_list<t> const& object){current = object.head;}
		t& operator*()
		{
			if(current != nullptr)
			{
				return this->current->data;
			}
			return this->current->data;
		}
		bool operator==(iterator const& object)
		{
			if(this->current == object.current)
			{
				return true;
			}
			return false;
		}
		bool operator!=(iterator const& object)
		{
			if(this->current != object.current)
			{
				return true;
			}
			return false;
		}
		iterator& operator++()
		{
			if(current != nullptr)
			{
				this->current = current->next;
			}
			return *this;
		}
		iterator operator++(int)
		{
			iterator temp(*this);
			if(current != nullptr)
			{
				this->current = current->next;
			}
			return temp;
		}		
	};
	iterator begin()
	{
		iterator temp(*this);
		return temp;
	}
	iterator end()
	{
		iterator temp;
		temp.current = this->tail;
		return temp;
	}
	void insert_at_end(const t & data)
	{
		node<t> * new_node = new node<t>;
		new_node->data = data;                      //assignment operator invoked
		if (head != nullptr)
		{
			tail->next = new_node;
			new_node->next = nullptr;
			tail = new_node;
		}
		else
		{
			new_node->next = nullptr;
			head = tail = new_node;
		}
		size++;

	}
	void delete_from_start()
	{
		if (head != nullptr)
		{
			node<t> * current = head;
			head = head->next;
			delete current;
		}
		size--;
	}
	void delete_from_end()
	{
		if (head != nullptr)
		{
			if (head == tail)
			{
				delete tail;
				head = tail = nullptr;
				size--;
			}
			else
			{
				node<t> * current = head;
				while (current->next != tail)
				{
					current = current->next;
				}
				delete(current->next);              //verify... deletes pointer ?? or next node ??
				tail = current;
				tail->next = nullptr;
				size--;
			}
		}
	}
	void delete_from_middle(node<t> * ptr)      //ptr is the address to be deleted
	{
		if (head != nullptr)
		{
			if (head != tail)
			{
				node<t> * current = head;
				while (current->next != ptr && current != nullptr)
				{
					current = current->next;
				}
				if (current->next == ptr)
				{
					node<t> * temp = ptr->next;
					delete ptr;
					current->next = temp;
				}
				else
				{
					cout << "Address not Found...\n";
				}
			}
			else
			{
				delete head;
				head = tail = nullptr;
			}
		}
		size--;
	}

	linked_list<t> operator=(const linked_list<t> & obj)
	{
		node<t> * current = obj.head;
		this->size = obj.size;
		while (current != nullptr)
		{
			node<t> * temp;
			this->insert_at_end(current->data);
			current = current->next;
		}
		return *this;
	}
	void print()
	{
		cout << "Linked List Size : " << this->size << endl;
		node<t> * current = this->head;
		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
	void swap(node<t> * ptr1, node<t> * ptr2)
	{
		t temp = ptr1->data;
		ptr1->data = ptr2->data;
		ptr2->data = temp;
	}
	void sort()
	{
		node<t> * temp;
		node<t> * current_1 = head;
		node<t> * current_2 = current_1->next;
		while (current_1->next != nullptr)
		{
			current_2 = current_1->next;
			while (current_2 != nullptr)
			{
				if (current_1->data > current_2->data)
				{
					swap(current_1, current_2);
				}
				current_2 = current_2->next;
			}
			current_1 = current_1->next;
		}
	}
};
//----------------------------LINKED LIST STACK--------------------
template<class t>
class stack
{
private:
	int size;
	node<t> *tail;
	node<t> *head;
public:
	stack() { head = tail = nullptr; size = 0; }
	stack(const stack<t> & obj);
	void push(const t & data)
	{
		node<t> * new_node = new node<t>;
		new_node->data = data;
		if (!is_empty())
		{
			tail->next = new_node;
			new_node->next = nullptr;
			tail = new_node;
		}
		else
		{
			new_node->next = nullptr;
			head = tail = new_node;
		}
		size++;
	}
	void pop()
	{
		if (!is_empty())
		{
			if (head == tail)
			{
				delete tail;
				head = tail = nullptr;
				size--;
			}
			else
			{
				node<t> * current = head;
				while (current->next != tail)
				{
					current = current->next;
				}
				delete(current->next);
				tail = current;
				tail->next = nullptr;
				size--;
			}
		}
	}
    int get_size(){return size;}
	t peek()
	{
		if (is_empty())
		{
			cout << "Stack is Empty...\n";
		}
		else
		{
			return tail->data;
		}
		return 0;
	}
	void print()
	{
		cout << "Stack Size : " << this->size << endl;
		node<t> * current = this->head;
		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
	bool is_empty()
	{
		if (head == nullptr)
		{
			return true;
		}
		return false;
	}
	bool is_full();
};

//----------------------------ARRAY STACK--------------------
template<class t>
class array_stack
{
	int top_index;
	int size;
	int *array;
public:
	array_stack() { top_index = size = 0; array = nullptr; }
	array_stack(int size)
	{
		top_index = 0;
		this->size = size;
		array = new int[size];
	}
	bool is_empty()
	{
		if (size == 0)
		{
			return true;
		}
		return false;
	}
	bool is_full()
	{
		if (top_index == (size))
		{
			return true;
		}
		return false;
	}
	void push(const t& data)
	{
		if (!is_full())
		{
			array[top_index] = data;
			top_index++;
		}
		else
		{
			cout << "Stack is Full...\n";
		}
	}
	t pop()
	{
		t temp = array[top_index - 1];
		if (!is_empty())
		{
			array[top_index - 1] = 0;        //make it null etc...
			top_index--;
			return temp;
		}
		else
		{
			cout << "Stack is Empty...\n";
		}
		return 0;
	}
	t peek()
	{
		if (!is_empty())
		{
			return array[top_index - 1];
		}
		return 0;
	}
	void print()
	{
		cout << "Capacity of Stack : " << size << endl;
		cout << "Size of Stack: " << top_index << endl;
		for (int i = 0; i < top_index; i++)
		{
			cout << array[i] << endl;
		}
		cout << endl;
	}
};
//----------------------------NETWORK--------------------
class network
{
	linked_list<int> *array;
	int total_people;
	int *influence_array;					//this can be made in the calculate_influence function...
	//the following function sets all elements of bool array FALSE
	void set_false(bool *arr, int size)		//this can be made in the calculate_influence function...
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = false;
		}
	}
public:
	network(string file_name)				//this constructor acts an input function...
	{
		ifstream read;
		read.open(file_name);
		string str;
		int length;
		getline(read, str);
		length = stoi(str);
		total_people = length;
		array = new linked_list<int>[length];	//array to store each person's direct influence
		//cout << length;
		string * arr;
		arr = new string[length];
		int temp = 0;
		while (temp < length)
		{
			getline(read, arr[temp]);
			//cout << arr[temp];
			temp++;
		}
		for (int i = 0; i < length; i++)
		{
			string current = arr[i];
			bool empty = true;
			string temp_data;
			int index = 0; int data;
			//cout << endl << current << endl;
			//cout << endl;
			while (current[index] != '\0')
			{
				if (current[index] == ',')		//stores id's accordingly
				{
					empty = false;
					temp_data = current[index - 1];
					data = stoi(temp_data);
					array[i].insert_at_end(data);
				}
                //else if(current[index] == '-' && current[index+1] == ' ')
                //{
				//	cout << endl << "HERE*************************** : " << i <<endl;
                //    empty = false;
				//	//temp_data = current[index+2];
				//	//data = stoi(temp_data);
				//	//array[i].insert_at_end(data);
                //}
				index++;
			}
			//cout << endl;
			if (!empty || index == 7)
			{
				temp_data = current[index - 1];
				data = stoi(temp_data);
				array[i].insert_at_end(data);
			}
			//cout << "Person " << i+1 << " : ";
			////cout << "		Index : " << index;
			//array[i].print();
			//cout << "-----------------------------------\n";
		}
	}
	void calculate_influence()
	{
		int max_influenced = 0;
		influence_array = new int[total_people];
		stack<int> temp;
        int people_influenced = 0;
		//bool flags[total_people];
		bool *flags = new bool[total_people];
		for (int i = 0; i < total_people; i++)
		{
            people_influenced = 0;
			cout << "Person " << i + 1 << " Influence : \n";
			set_false(flags,total_people);
			//for (int j = 0; j < total_people; j++)
			//{
			//	flags[j] = false;
			//	cout << flags[j];
			//}
			//cout << "\nhere";
			node<int> *current = array[i].head;			
			flags[i] = true;                //makes the current person id as true                                                
			while (current != nullptr)       // Should it be implemented in one loop ?
			{
				temp.push(current->data);   // fills the stack
                people_influenced++;
				//cout << "\nhere";
				flags[(current->data) - 1] = true;        //bcz starts from 0...
				current = current->next;

			}
			while (!temp.is_empty())
			{
				int l_arr_index = temp.peek();
				cout << l_arr_index << '|';
				temp.pop();
                //people_influenced++;
				node<int> *temp_current = this->array[l_arr_index - 1].head;
				while (temp_current != nullptr)
				{
					//cout << "\nhere";
					if ((flags[(temp_current->data) - 1]) != true)
					{
						//cout << temp_current->data;
						temp.push(temp_current->data);   // fills the stack
                        people_influenced++;
						flags[(temp_current->data)-1] = true;
					}
					temp_current = temp_current->next;
				}
				//cout << "\nhere";
			}
			influence_array[i] = people_influenced;
			if(people_influenced > max_influenced)
			{
				max_influenced = people_influenced;
			}
            cout << endl << "Total People Influenced : " << people_influenced << endl;
			//cout << "\nhere";
			cout << "------------------------------------" << endl;
		}
		cout << endl << "Maximum People Influenced : " << max_influenced;
		cout << endl << "ID(s) with Maximum Influence : |";
		for(int i = 0; i < total_people; i++)
		{
			//cout << influence_array[i] << endl;
			if(influence_array[i] == max_influenced)
			{
				cout << i+1 << "|";
			}
		}
		delete[] flags;
	}
	~network()
	{
		delete [] influence_array;
		delete [] array;
	}
};

