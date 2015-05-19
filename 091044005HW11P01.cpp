#include <iostream>
#include "091044005HW11P02.cpp"

//#define TESTINHERITANDBASICFUNCTIONS
//#define TESTITERATORS


using namespace std;

int main()
{

#ifdef TESTINHERITANDBASICFUNCTIONS

    _PF_Arr_Wi<int> x(10);          ///testing _PF_Arr_Wi constructors
    x.addElement(1);                ///testing adding
    x.addElement(2);
    _PF_Arr_Wi<int> a(x);
    cout<<x[0]<<endl;               ///testing operator[]
    cout<<x[1]<<endl;
    cout<<a[0]<<endl;
    cout<<a[1]<<endl;
    cout<<x.full()<<endl;           ///testing full function
    cout<<a.full()<<endl;
    cout<<x.getCapacity()<<endl;    ///testing capacity function
    cout<<a.getCapacity()<<endl;
    cout<<x.getNumberUsed()<<endl;  ///testing getNumberUsed function
    cout<<a.getNumberUsed()<<endl<<endl;
    x.addElement(3);
    cout<<x.full()<<endl;
    cout<<a.full()<<endl;
    cout<<x.getCapacity()<<endl;
    cout<<a.getCapacity()<<endl;
    cout<<x.getNumberUsed()<<endl;
    cout<<a.getNumberUsed()<<endl<<endl;
    a=x;                            ///testing assignment
    cout<<x.full()<<endl;
    cout<<a.full()<<endl;
    cout<<x.getCapacity()<<endl;
    cout<<a.getCapacity()<<endl;
    cout<<x.getNumberUsed()<<endl;
    cout<<a.getNumberUsed()<<endl<<endl;
    a.emptyArray();                 ///testing emtyArray
    cout<<x.full()<<endl;
    cout<<a.full()<<endl;
    cout<<x.getCapacity()<<endl;
    cout<<a.getCapacity()<<endl;
    cout<<x.getNumberUsed()<<endl;
    cout<<a.getNumberUsed()<<endl<<endl;
#endif

#ifdef TESTITERATORS
    _PF_Arr_Wi<int> a(10);
    a.addElement(1);
    a.addElement(2);
    a.addElement(3);
    a.addElement(4);
    a.addElement(5);
    a.addElement(6);
    a.addElement(7);
    a.addElement(8);
    a.addElement(9);
    a.addElement(10);


    _PF_Arr_Wi<int>::Iterator i,j;                      /**testing iterator constructors**/
    i=a.Begin();                                        /**tesing Begin**/
    j=a.End();                                          /**testing End**/


    cout<<"TESTIN ITERATORS BEGIN"<<endl<<endl;
    for(i=a.Begin(),j=a.End();
    !(i==j);                                            /**tesing ==**/
    ++i)                                                /**testing prefix increment**/
    {
        cout<<*i<<"-";
    }

    cout<<endl<<endl<<"TESTIN ITERATORS BEGIN"<<endl;
    for(i=a.End(),j=a.Begin();
    !(i==j);
    i--)                                                /**testing postfix decrement**/
    {
        cout<<*i<<"-";
    }

    cout<<endl<<endl;

    _PF_Arr_Wi<int> b(10);
    b.addElement(1);
    b.addElement(2);
    b.addElement(3);
    b.addElement(4);
    b.addElement(5);
    b.addElement(6);
    b.addElement(7);
    b.addElement(8);
    b.addElement(9);
    b.addElement(10);

    _PF_Arr_Wi<int>::reverseIterator c,k;                   /**testing constructor**/
    c=b.Rbegin();                                           /**testing Rbegin**/
    k=b.Rend();                                             /**testing Rend**/
    cout<<"TESTING REVERSE ITERATORS AND RBEGIN"<<endl;
    cout<<*c<<endl;
    ++c;                                                    /**testing prefix increment**/
    cout<<*c<<endl;
    ++c;
    cout<<*c<<endl;
    ++c;
    cout<<*c<<endl;
    ++c;
    cout<<*c<<endl;
    ++c;
    cout<<*c<<endl;
    ++c;
    cout<<*c<<endl;
    ++c;
    cout<<*c<<endl;
    ++c;
    cout<<*c<<endl;
    ++c;
    cout<<*c<<endl<<endl;
    ++c;

    cout<<"TESTING REVERSE ITERATORS AND REND"<<endl;
    cout<<*k<<endl;
    --k;                                                    /**testing prefix decrement**/
    cout<<*k<<endl;
    --k;
    cout<<*k<<endl;
    --k;
    cout<<*k<<endl;
    --k;
    cout<<*k<<endl;
    --k;
    cout<<*k<<endl;
    --k;
    cout<<*k<<endl;
    --k;
    cout<<*k<<endl;
    --k;
    cout<<*k<<endl;
    --k;
    cout<<*k<<endl;
    --k;
#endif
    return 0;
}
