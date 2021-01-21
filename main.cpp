

//NOTE : Remove Duplicates by Recursion in Linked Lists is Incomplete
//NOTE : 

#include "practice.h"

int main()
{
/*
    //bst<int> b1;
    //b1.insert_itr(15);
    //b1.insert_itr(2);
    //b1.insert_itr(12);
    //b1.insert_rec(14);
    //b1.insert_itr(18);
    //b1.insert_itr(11);
    //b1.insert_rec(121);
    //b1.insert_itr(123);
    //b1.print_itr();
    //int *ptr = b1.search(12);
    //cout << "Smallest : " << b1.smallest() << endl;
    //if(ptr != nullptr)
    //    cout << *ptr << " Found...";
    //else
    //    cout << "Not Found...";
    //cout << endl;
    //b1.print_ancestors(11);
*/

    ss_bst<int> s;
    int arr[18] = {6,9,12,11,25,20,36,10,22,30,40,48,38,28,26,23,24,4};

//Insertion one by one...
/*  
    s.insert_itr(6);
    s.insert_itr(9);
    s.insert_itr(12);
    s.insert_itr(11);
    s.insert_itr(25);
    s.insert_itr(20);
    s.insert_itr(36);
    s.insert_itr(10);
    s.insert_itr(22);
    s.insert_itr(30);
    s.insert_itr(40);
    s.insert_itr(48);
    s.insert_itr(38);
    s.insert_itr(28);
    s.insert_itr(26);
    s.insert_itr(23);
    s.insert_itr(24);
    s.insert_itr(5);
*/
//Assignment Main

    for(int i = 0; i < 18; i++)
    {
        s.insert_itr(arr[i]);
    }
    cout << "\nOriginal Tree Ascending Order\n";
    s.print();
    cout << "\nOriginal Tree Pre-Order\n";
    s.print_r();
    cout << "\n\nCopying the Tree...\n";
    ss_bst<int> s1(s);
    cout << "\nPrinting Copied Tree (In-Order)...\n\n";
    s1.print_r();
    cout << "\n\nPrinting Copied Tree (Acsending-Order)...\n\n";    
    s1.print();
    s.print(13,40);
    cout << endl;
    s.search(30);
    s.search(34);
    cout << endl;
    cout << endl << "Printing in Reverse-Order...\n";
    s.reverse_order();
    s.print();
    cout << endl;
    s.remove(48);
    s.remove(11);
    cout <<  endl << "After Removing...\n\n";
    s.print_r();
    cout << endl;
    s.print();
    cout << endl;
    ss_bst<int> s2;
    ss_bst<int> s3;
    s2.insert_itr(25);
    s2.insert_itr(20);
    s2.insert_itr(15);
    s2.insert_itr(35);
    s2.insert_itr(30);
    s2.insert_itr(45);
    s2.insert_itr(50);
    s2.insert_itr(10);    
    s2.insert_itr(5);
    s2.insert_itr(51);
    s2.print();
    s3 = s2;
    cout << "\nOperator result...\n";
    s3.print();
    bool f = s2.depth();    
    if(f)
        cout << "Balanced Leaf Nodes....\n";
    else
    {
        cout << "Not Balanced Leaf Nodes...\n";
    }
    cout << "\n-------------------------------------------\n";

    //s.ar();
    

    //cout << fib_r(4) << ", " << fib_r(5) << ", " << fib_r(6) << endl;
    //tower(5,'A','B','C');
    //cout << endl;
}

