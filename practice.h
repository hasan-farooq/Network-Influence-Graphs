#include <iostream>
#include <string.h>

using namespace std;


//-----------------------------------NODE-----------------------------
template <class t>
class node
{
public:
    t data;
    node * next;

};
//-----------------------------------LINKED LIST-----------------------------
template <class t>
class linked_list
{
public:
    node<t> *head, *tail;
    int size;

    linked_list()                   //default constructor
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    void insert_end(node<t> * ptr, t data)
    {
        if(ptr != nullptr)
        {
            insert_end(ptr->next, data);
            if(ptr->next == nullptr)
            {
                node<t> * new_node = new node<t>;
                new_node->data = data;
                new_node->next = nullptr;
                ptr->next = new_node;
            }
        }
    }
    void insert_end(t data)
    {
        insert_end(head,data);
    }
    void insert_at_end(t data)
    {
        node<t> * new_node = new node<t>;         //new node to be inserted
        new_node->data = data;              //copies data in the node
        if (head != nullptr)                //ensures that there exist any node before
        {
            tail->next = new_node;                    //previous tail now points to the new end now
            new_node->next = nullptr;
            tail = new_node;                //tail updated
        }
        else                        //first element/node to be inserted
        {
            new_node->next = nullptr;
            head = tail = new_node;
        }
        size++;
    }
    void insert_at_start(t data)
    {
        node<t>*new_node = new node<t>;
        new_node->data = data;              //copies data in the node

        if(head != nullptr)
        {
            new_node->next = head;      //makes new node point towards previous head
            head = new_node;            //makes new node the new head (updated head)
        }
        else                            //first element in the list
        {
            new_node ->next = nullptr;
            head = new_node;
            tail = head;
        }
        size++;
    }
    void print()
    {
        cout << "Size : " << size << endl;
        node<t> * current = head;           //pointer to go through the list
        while(current != nullptr)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
    void print_r(node<t> * ptr)
    {
        if(ptr != nullptr)
        {
            cout << ptr->data << endl;
            print_r(ptr->next);
        }
    }
    void print_r()
    {
        print_r(head);
    }
    void insert_at_middle(t data, node<t> * ptr)        //ptr is the insertion location/address
    {
        node<t> * new_node = new node<t>;
        new_node->data = data;
        //cout << ptr << endl;
        if(head != nullptr && ptr->next != nullptr)     //ptr is not the tail & at least one node exists
        {
            node<t> *previous, *current;
            current = head;
            while(current != nullptr && current != ptr)
            {
                previous = current;
                current = current->next;
            }
            if (current != nullptr)             //check to ensure that loop teminated with address found
            {   
                //cout << "FOUND...\n";
                previous->next = new_node;
                new_node->next = current;
            }
        }
        else
        {
            insert_at_end(data);
        }
        size++;
        
    }
    node<t>* find(t key)
    {
        node<t> * current = head;
        bool found = false;
        while(current != tail && found == false)
        {
            if(current->data == key)
            {
                //cout <<"In if...\n";
                found = true;
                return current;
            }
            else
            {
                current = current->next;
            }   
        }
        return tail;
    }
    void delete_from_start()
    {
        if(head != nullptr)
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
            if(head == tail)
            {
                delete tail;        //can also delete head bcz both are pointing the same
                head = tail =nullptr;
            }
            else
            {
                node<t> * current = head;
                while(current->next != tail)
                {
                    current = current->next;
                }
                delete(current->next);              //verify... deletes pointer ?? or next node ??
                tail = current;
                tail->next = nullptr;
            }
            
        }
        else
        {
            cout << "No Node in the List...\n";
        }
        size--;
    }
    void delete_from_middle(node<t> * ptr)      //ptr is the address to be deleted
    {
        if(head != nullptr)
        {
            if(head != tail)
            {
                node<t> * current = head;
                while (current->next != ptr && current != nullptr)
                {
                    current = current->next;
                }
                if(current->next == ptr)
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
    void remove_duplicates(node<t> *& ptr)
    {
        if(ptr != nullptr)
        {
            remove_duplicates(ptr->next);
            if(ptr->next->data == ptr->data && ptr->next != nullptr)
            {
                node<t> * temp = ptr->next->next;
                delete ptr->next;
                ptr->next = temp;
                //delete ptr;
                //ptr = temp;
            }
        }
    }
    void remove_duplicates()
    {
        //node<t>* p = head;
        remove_duplicates(head);
        //p->next=nullptr;
    }
    void reverse_r(node<t> * ptr)
    {        
        if(ptr == nullptr)
            return;
        if(ptr->next == nullptr)
        {
            head = ptr;
            //return ptr;            
        }
        else
        {
            reverse_r(ptr->next);
            ptr->next->next = ptr;
            //reverse_r(ptr->next);
            //ptr->next = nullptr;
            //return temp;
        }
    }
    void delete_all(node<t> * &ptr)
    {
        if(ptr != nullptr)
        {
            delete_all(ptr->next);
            delete ptr;
            ptr=nullptr;
        }
    }
    void delete_all()
    {
        delete_all(head);
        //head=nullptr;
    }
    void delete_start(node<t> * ptr)
    {
        if(ptr != nullptr)
        {
            delete_start(ptr->next);
            //node<t> * temp = delete_start(ptr->next);
            if(ptr == head)
            {
                head = head->next;
                delete ptr;
            }
        }
    }
    void delete_start()
    {
        delete_start(head);
    }
    void reverse_r()
    {
        node<t>*p=head;
        reverse_r(head);
        p->next = nullptr;
    }
    void reverse()
    {
        if(head != tail && head != nullptr)
        {
            node<t> *current, *next, *previous;
            tail = head;
            current = head;
            next = current->next;           //previous = nullptr (optional)

            while (current != nullptr)
            {
                next = current->next;
                current->next = previous;
                previous = current;
                current = next;
            }
            
            head = previous;
            tail->next = nullptr;
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
//-----------------------------------TREE NODE-----------------------------
template <class t>
struct t_node
{
    t data;
    t_node *left, *right;
};
//-----------------------------------BST-----------------------------
template <class t>
class bst
{
private:
    t_node<t> *root;
    void print_rec(t_node<t> *ptr)
    {
        if(ptr == nullptr)
        {
            return;
        }
        else
        {
            print_rec(ptr->left);
            cout << ptr->data << "|";
            print_rec(ptr->right);
        }
        
    }
    void insert_rec(t_node<t> *&ptr, t data)      //either reference or return t_node<t>* bcz we're modifying bst
    {
        if(ptr == nullptr)
        {
            t_node<t> *new_node = new t_node<t>;
            new_node->data = data;
            new_node->left = new_node->right = nullptr;
            ptr = new_node;
        }
        else
        {
            if(ptr->data > data)
            {
                insert_rec(ptr->left, data);
            }
            else if(ptr->data < data)
            {
                insert_rec(ptr->right, data);
            }
        }        
    }
    int length(t_node<t> *ptr, int size)
    {
        if(!ptr)
            return size;
        else
        {
            size = length(ptr->left, size);
            size++;
            size = length(ptr->right,size);
        }
    }
    t* search(t_node<t> *ptr, t val)
    {
        if(ptr != nullptr)
        {
            if(ptr->data < val)
            {
                return search(ptr->right, val);
            }
            else if(ptr->data > val)
            {
                return search(ptr->left, val);
            }
            else if(ptr->data == val)
            {
                t * temp = &ptr->data;
                return temp;
            }
            else
                return nullptr;
        }
        else
        {
            return nullptr;
        }
        
    }
    int smallest(t_node<t> *ptr)
    {
        if(ptr->left == nullptr)
            return ptr->data;
        return smallest(ptr->left);
    }
    void print_ancestors(t_node<t> *ptr, t data)
    {
        if(ptr != nullptr)
        {
            if(ptr->data == data)
                return;
            else if (ptr->data > data)
            {
                cout << ptr->data << "|";
                print_ancestors(ptr->left, data);
            }
            else if (ptr->data < data)
            {
                cout << ptr->data << "|";
                print_ancestors(ptr->right, data);
            }      
        }  
    }

public:
    bst(){root = nullptr;}
    void insert_itr(t const data)
    {
        if(root == nullptr)
        {
            t_node<t> *new_node = new t_node<t>;
            new_node->data = data;
            new_node->left = new_node->right = nullptr;
            root = new_node;        //links the chain
        }
        else
        {
            t_node<t> *current = root;
            bool inserted = false;
            while(current != nullptr && inserted != true)
            {
                if(data < current->data)
                {
                    if(current->left == nullptr)
                    {
                        t_node<t> *new_node = new t_node<t>;
                        new_node->data = data;;
                        new_node->left = new_node->right = nullptr;
                        current->left = new_node;
                        inserted = true;
                    }
                    current = current->left;
                }
                if(data > current->data)
                {
                    if(current->right == nullptr)
                    {
                        t_node<t> *new_node = new t_node<t>;
                        new_node->data = data;
                        new_node->left = new_node->right = nullptr;
                        current->right = new_node;
                        inserted = true;
                    }
                    current = current->right;
                }
            }
        }        
    }
    void print_rec()
    {
        this->print_rec(root);
        cout << endl;
    }
    void insert_rec(t const data)
    {
        insert_rec(root, data);
    }
    int length()
    {
        return length(root, 0);
    }
    t* search(t val)
    {
        return search(root, val);
    }
    void print_itr()
    {
        stack<t_node<t>*> s;
        t_node<t> *current = root;
        while(current != nullptr || s.is_empty() != true)
        {
            while(current != nullptr)
            {
                s.push(current);
                current = current->left;
            }
            current = s.peek();
            s.pop();
            cout << current->data << "|";
            current = current->right;
        }
        cout << endl;
    }
    int smallest()
    {
        return smallest(root);
    }
    void print_ancestors(t data)
    {
        print_ancestors(root,data);
    }
};

//-----------------------------------SS-BST-----------------------------

template <class t>
struct st_node
{
    t data;
    st_node *left, *right, *next;
};

template <class t>
class ss_bst
{
private:
    st_node<t> *root;
    int size;
    bool successor;
    st_node<t> *start;          //to keep track of minimum
    void print_rec(st_node<t> *ptr)     //Pre-Order Print
    {
        if(ptr == nullptr)
        {
            return;
        }
        else
        {
            cout << ptr->data << "|";
            print_rec(ptr->left);
            print_rec(ptr->right);
        }        
    }
// obj is the pointer of object to be copied. ptr is the pointer of the object itself (one calling constructor)
    void copy(st_node<t> *&ptr,st_node<t> *obj,st_node<t> *&start,st_node<t> *&previous)
    {
        if(obj)         //if not empty...
        {
            st_node<t> *new_node = new st_node<t>;
            new_node->data = obj->data;             //gets data 
            ptr = new_node;                     //ptr now points to the new node
            ptr->next = ptr->right;
            if(previous)
            {
                previous->next = ptr;
            }
            //cout << "Copied " << ptr->data << "...\n";
            copy(ptr->left, obj->left,start,ptr,ptr->right);     //delegate to the left
            copy(ptr->right, obj->right,start,ptr,ptr->right);     //delegate to the right
        }
    }
    void delete_from_middle(t data)
    {
        if(start != nullptr)
        {
            if(data == start->data)
            {
                start = start->next;
            }
            else
            {
                st_node<t> *current = start;
                while (current->next->data != data && current != nullptr)
                {
                    current = current->next;
                }
                if(current->next->data == data)
                {
                    current->next = current->next->next;            
                }
                else
                {
                    cout << "Data not Found...\n";
                }
            }        
        }        
    }
    void copy_i(st_node<t> *&ptr,st_node<t> *obj)
    {
        if(obj)
        {
            insert_itr(obj->data);
            copy_i(ptr->left,obj->left);
            copy_i(ptr->right,obj->right);
        }
    }
    void remove(st_node<t> *&ptr,st_node<t> *&previous,t data)
    {
        if(ptr)
        {
            if(ptr->data == data)
            {
                if(ptr->right == nullptr && ptr->left == nullptr)   //Case 1 : No Child
                {
                    delete ptr;
                    ptr = ptr->left = ptr->right = nullptr;
                    cout << "\nCase 1...\n";
                    return;
                }
                else if(ptr->right == nullptr && ptr->left != nullptr)   //Case 2 : Left Child
                {
                    previous->left = ptr->left;
                    cout << "\nCase 2...\n";
                    delete ptr;
                    ptr = ptr->left = nullptr;
                    return;
                }
                else if(ptr->right != nullptr && ptr->left == nullptr)   //Case 3 : Right Child
                {
                    cout << "\nCase 3...\n";
                    previous->right = ptr->right;
                    delete ptr;
                    ptr = ptr->right = nullptr;
                    return;
                }
                else                //Case 4 : Both Children
                {
                    st_node<t> *temp = ptr->left;
                    while(temp->right != nullptr)
                    {
                        temp = temp->right;
                    }
                    cout << "\nCase 4...\n";
                    ptr->data = temp->data;
                    delete temp;
                    temp = temp->right = nullptr;
                    return;
                }               
            }
            else
            {
                remove(ptr->left,ptr,data);
                remove(ptr->right,ptr,data);
            }            
        }
    }
    int depth(st_node<t> *ptr)
    {
        int l_depth, r_depth = 0;
        if(ptr)
        {
            l_depth = depth(ptr->left);
            r_depth = depth(ptr->right);
            if(l_depth > r_depth)
                return l_depth + 1;
            else
                return r_depth + 1;
        }
        else
        {
            return 0;
        }
        
    }
    //st_node<t>* reverse_r(st_node<t> *ptr)
    //{
    //    if(ptr == nullptr)
    //        return ptr;
    //    if(ptr->next == nullptr)
    //    {
    //        start = ptr;
    //        return ptr;
    //    }
    //    st_node<t> *temp = reverse_r(ptr->next);
    //    temp->next = ptr;
    //    ptr->next = nullptr;
    //    return ptr;
    //}
    void reverse_r(st_node<t> *ptr)
    {
        if(ptr == nullptr)
            return;
        if(ptr->next == nullptr)
        {
            start = ptr;   
        }
        else
        {
            reverse_r(ptr->next);
            ptr->next->next = ptr;
        }
    }
public:
    ss_bst(){root = start = nullptr; size = 0;}    
    void print_r()      //Pre-Order Print
    {
        cout << "Size of Tree : " << size << endl;
        print_rec(root);
    }
    void remove(t data)
    {
        st_node<t> *previous = nullptr;
        delete_from_middle(data);
        remove(root,previous,data);
        size--;
    }
    ss_bst(ss_bst<t> const& object)
    {
        root = start = nullptr;
        size = 0;
        ////st_node<t> *ptr = this->root = nullptr;     //why this gives error 
        //this->size = object.size;
        //st_node<t> *previous = nullptr;
        //copy(this->root,object.root,start,previous);
        //st_node<t> *current = root;
        //while(current->left != nullptr)
        //    current = current->left;
        //start = current;
        //cout << "HAHA : " << start->data << endl;
        copy_i(root,object.root);
    }
    ss_bst<t>& operator=(ss_bst<t> const& obj)
    {
        root = start = nullptr;
        size = 0;
        copy_i(root,obj.root);
        return *this;
    }
    ss_bst<t>* bst_to_threaded(st_node<t> *&ptr,st_node<t> *&suc,st_node<t> *&pre)
    {
        if(ptr)
        {
            pre = bst_to_threaded(ptr->left);
            //cout << ptr->data << "|";
            pre->next = ptr;
            ptr->next = suc;
            suc = bst_to_threaded(ptr->right);
        }
    }
    void reverse_order()
    {
        successor = false;
        st_node<t> *p = start;
        reverse_r(p);
        p->next = nullptr;
    }
    void insert_itr(t const& data)
    {
        if(successor == true)
        {
            if(root == nullptr)
            {
                st_node<t> *new_node = new st_node<t>;
                new_node->data = data;
                new_node->left = new_node->right = nullptr;
                root = new_node;        //links the chain
                new_node->next = nullptr;
                start=root;                   //update
                //cout << "Inserted : " << data << endl;
                size++;
            }
            else
            {
                st_node<t> *current = root;
                st_node<t> *previous = nullptr;
                bool inserted = false;
                while(current != nullptr && inserted != true)
                {
                    if(data < current->data)
                    {
                        if(current->left == nullptr)
                        {
                            st_node<t> *new_node = new st_node<t>;
                            new_node->data = data;
                            new_node->left = new_node->right = nullptr;
                            current->left = new_node;
                            inserted = true; size++;
                            //cout << "Inserted : " << data << endl;                        
                            new_node->next = current;
                            if(previous != nullptr)
                            {
                                previous->next=new_node;                   //update
                                //start = new_node;
                            }
                            else
                            {
                                start = new_node;
                            }            
                        }
                        else
                            current = current->left;
                    }
                    else if(data > current->data)
                    {
                        if(current->right == nullptr)
                        {
                            st_node<t> *new_node = new st_node<t>;
                            new_node->data = data;
                            new_node->left = new_node->right = nullptr;
                            current->right = new_node;
                            inserted = true; size++;
                            previous = current;
                            //cout << "Inserted : " << data << endl;
                            new_node->next = previous->next;                   //update
                            previous->next = new_node;                   //update

                        }                    
                        else
                        {
                            previous = current;
                            current = current->right;
                        }
                    }
                    else if(data == current->data)
                    {
                        cout << data << " Not Inserted. Repitition...\n";
                        return;
                    }
                }
            }        
        }
    }
    void print()
    {
        st_node<t> *current = start;
        //while(current->left != nullptr)
        //{
        //    current = current->left;
        //}
        //cout << "Size of Tree : " << size << endl;
        //current = start;
        while(current != nullptr)
        {
            cout << current->data << "|";
            current = current->next;
        }
        cout << endl;
    }
    bool search(t const& val)
    {
        bool found = false;
        st_node<t> *current = start;
        //while(current->left != nullptr)
        //{
        //    current = current->left;
        //}
        while(current != nullptr && found != true)
        {
            if(current->data == val)
            {
                cout << current->data << " Found...\n";
                found = true;
            }
            current = current->next;
        }
        if(found == false)
            cout << val << " Not Found...\n";
        return found;
    }
    void print(t low, t high)
    {
        st_node<t> *current = start;
        bool flag = false;
        if(start->data < low && start->data > high) {return;}        //printing not needed...
        cout << "\nPrinting from " << low << " to " <<  high << " : \n";
        while(current != nullptr && flag != true)
        {
            if(current->data >= low && current->data <= high)
            {
                cout << current->data << "|";
            }
            else if(current->data > high)
            {
                flag = true;
            }
            current = current->next;
        }
        cout << endl;
    }
    bool depth()
    {
        if(root == nullptr)
            return true;
        else
        {
            int l_depth, r_depth = 0;
            l_depth = depth(root->left);
            r_depth = depth(root->right);
            cout << endl << "Left Depth : " << l_depth << endl;
            cout << endl << "Right Depth : " << r_depth << endl;
            if(r_depth == l_depth)
                return true;
            else
                return false;
        }        
    }
    ~ss_bst()
    {
        cout << "Destructor Invoked...\n";
        st_node<t> *current = start;
        while(current != nullptr)
        {
            //cout << "Deleting " << current->data << "...";        
            delete current;
            //if(!current)
            //    cout << "Not Deleted..." << current->data;
            current = current->next;
            //cout << endl;
        }
        root = start = nullptr; size = 0; successor = false;
    }

};

int fib_r(int n)
{
    if(n <= 1)
        return n;
    else
        return fib_r(n-1) + fib_r(n-2);
}

void tower(int n, char A, char B, char C)       //n is nth index in the tower
{
    if(n > 0)
    {
        tower(n-1,A,B,C);
        //tower(n-1,A,C,B);     //why this ??
        cout << "Move Disk " << n << " from " << A << " to " << C << "\n";
        tower(n-1,B,C,A);
    }
}