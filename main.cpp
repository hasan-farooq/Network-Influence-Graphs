
#include "classes.h"

int main()
{
/*
    ////stack<int> s1;
    //array_stack<int> s1(5);
    ////cout << "Top on stack : " << s1.peek() << endl;  
    //s1.push(90);
    //s1.push(80);
    //s1.push(60);
    //s1.push(50);
    //s1.push(40);
    //s1.print();
    //cout << "Top on stack : " << s1.peek() << endl;    
    //s1.pop();
    //s1.print();
    //cout << "Top on stack : " << s1.peek() << endl;   
    //s1.push(30);
    //s1.push(20);
    ////s1.print();
    ////cout << "Top on stack : " << s1.peek();
    //ifstream r;
    //string *arr;
    //r.open("sample");
    //string str;
    //int length;
    //getline(r,str);
    //length = stoi(str);
    ////cout << length;
    //arr = new string[length];
    //int temp = 0;
    //while(temp < length)
    //{
    //    getline(r,arr[temp]);
    //    temp++;
    //}
    //linked_list<int> * l_arr = new linked_list<int>[length];
    //
    //for(int i = 0; i < length; i++)
    //{
    //    string current = arr[i];
    //    bool empty = true;
    //    string temp_data;
    //    int index = 0; int data;
    //    while(current[index] != '\0')
    //    {
    //        if(current[index] == ',')
    //        {
    //            empty = false;
    //            temp_data = current[index-1];
    //            data = stoi(temp_data);
    //            l_arr[i].insert_at_end(data);
    //        }
    //        index++;
    //    }
    //    if(!empty)
    //    {
    //        temp_data = current[index-1];
    //        data = stoi(temp_data);
    //        l_arr[i].insert_at_end(data);
    //    }
    //    cout << "Person " <<i+1 << " : ";
    //    l_arr[i].print();
    //    cout << "-----------------------------------\n";
    //}
*/


//FOLLOWING FOR CHECKING ITERATORS
    //linked_list<int> l1;
    //l1.insert_at_end(10);
    //l1.insert_at_end(11);
    //l1.insert_at_end(12);
    //l1.insert_at_end(13);
    //l1.insert_at_end(14);
    //linked_list<int>::iterator t(l1);
    //t++;t++;
    //cout << *t;
    //cout<<endl<<endl;
    network n("sample");
    //cout << endl << "INFLUENCE...\n\n";
    n.calculate_influence();
    cout << endl;
}
