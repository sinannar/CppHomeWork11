/**
 * HW11
 * ITERATOR AND REVERSE ITERATOR IMPLEMENTING
 * When i try to divide files implementation and interface
 * i got some problems and i decide to solve problems about algorithm
 * i do not want to spend my time with seperating files problem
 *
 * In this case i have some helps from include directory,i try to understand stl_vector.h file
 *
 * We have two inner class in one class that named _PF_Arr_Wi
 * and _PF_Arr_Wi derived from PFArray
 *
 * I want to notice that,Begin and End function of _PF_Arr_Wi return Iterator,so that they should use with Iterators
 * Rbegin and Rend functions return reverseIterator,so on...
 *
 */

#ifndef __ARRAY__CPP__
#define __ARRAY__CPP__

#include <iostream>
#include "091044005HW11P03.cpp"

using namespace std;

template<class T>
class _PF_Arr_Wi    :   public PFArray<T>
{
    public://constructors and destructors
        _PF_Arr_Wi( );
        _PF_Arr_Wi(int capacityValue );
        _PF_Arr_Wi(const _PF_Arr_Wi<T>& pfaObject);
        virtual ~_PF_Arr_Wi( );

    public://operations...there is no operations,it all came from PFArray,in truth the use PFArray's functions
        void addElement(T element);
        bool full( ) const;
        int getCapacity( )const;
        int getNumberUsed( )const;
        void emptyArray( );
        T& operator[](int index);
        _PF_Arr_Wi<T>& operator =(const _PF_Arr_Wi<T>& rightSide);

    public://iterators forward declerations,it may necessary
        class Iterator;
        class reverseIterator;

    public:
        class Iterator{
            public://const,dest,copyConst
                Iterator();
                Iterator(T* a,int wher,int cap,int used);
                ~Iterator(){_point=NULL;}
                Iterator(const Iterator& rightSide);

            public://operatorOverloads
				// assignment operator
                Iterator& operator=(const Iterator& rightSide)
                {
                    _point=rightSide._point;
                    _used=rightSide._used;
                    _where=rightSide._where;
                    _capacity=rightSide._capacity;
                    return *this;
                }

				//prefix increment
                Iterator& operator++()
                {
                    _point=_point+1;
                    _where=_where+1;
                    return *this;
                }

				//prefix decrement
                Iterator& operator--()
                {
                    _point=_point-1;
                    _where=_where-1;
                    return *this;
                }

				//postfix increment
                Iterator& operator++(int ignoreMe)
                {
                    _PF_Arr_Wi<T>::Iterator temp(_point,_where,_capacity,_used);
                    _point=_point+1;
                    _where=_where+1;
                    return temp;
                }

				//postfix decrement
                Iterator& operator--(int ignoreMe)
                {
                    _PF_Arr_Wi<T>::Iterator temp(_point,_where,_capacity,_used);
                    _point=_point-1;
                    _where=_where-1;
                    return temp;
                }

				//this ask are they equal
                bool operator==(const Iterator&rightSide)
                {
                    if(_where==rightSide._where)
                        return true;
                    return false;
                }

				//this ask are they not equal
                bool operator!=(const Iterator&rightSide)
                {
                    if(_where!=rightSide._where)
                        return true;
                    return false;
                }

				//pointer operator
                T& operator*()
                {
                    return *_point;
                }

				//what they called i actually  dont know :)
                T* operator->()
                {
                    return _point;
                }

                //getters
                int getWhere();
                int getUsed();
                int getCapacity();

            private://privates of Iterator
                T* _point;
                int _where;
                int _capacity;
                int _used;
        };

        class reverseIterator{
            public://const,dest,copyConst
                reverseIterator();
                reverseIterator(T* a,int wher,int cap,int used);
                ~reverseIterator(){_point_=NULL;}
                reverseIterator(const reverseIterator& rightSide);

            public://operatorOverloads
				//assignments
                reverseIterator& operator=(const reverseIterator& rightSide)
                {
                    _point_=rightSide._point_;
                    _used_=rightSide._used_;
                    _where_=rightSide._where_;
                    _capacity_=rightSide._capacity_;
                    return *this;
                }

				//prefix increment
                reverseIterator& operator++()
                {
                    _point_=_point_-1;
                    _where_=_where_-1;
                    return *this;
                }

				//prefix decrement
                reverseIterator& operator--()
                {
                    _point_=_point_+1;
                    _where_=_where_+1;
                    return *this;
                }

				//postfix increment
                reverseIterator operator++(int ignoreMe)
                {
                    _PF_Arr_Wi<T>::reverseIterator temp(_point_,_where_,_capacity_,_used_);
                    _point_=_point_-1;
                    _where_=_where_-1;
                    return temp;
                }

				//postfix decrement
                reverseIterator operator--(int ignoreMe)
                {
                    _PF_Arr_Wi<T>::reverseIterator temp(_point_,_where_,_capacity_,_used_);
                    _point_=_point_+1;
                    _where_=_where_+1;
                    return temp;
                }

				//equality operator
                bool operator==(const reverseIterator&rightSide)
                {
                    if(_where_==rightSide._where_)
                        return true;
                    return false;
                }

				//it ask are they not equal
                bool operator!=(const reverseIterator& rightSide)
                {
                    if(_where_!=rightSide._where_)
                        return true;
                    return false;
                }

				//pointer operator
                T& operator*()
                {
                    return *_point_;
                }

				//i still dont know what it called
                T* operator->()
                {
                    return _point_;
                }



            private://private members of reverseIterator
                T* _point_;
                int _where_;
                int _capacity_;
                int _used_;
        };

	/**
	 * FUNCTIONS ABOUT RELATIONs _PF_Arr_Wi with Iterator an reverseIterator
	 * Begin	:it return the Iterator that has info about begining
	 * End		:it return the Iterator that has info about end
	 * Rbegin	:it return the reverseIterator that has info about end of array,so its the begining of reverseIterator
	 * Rend		:it return the reverseIterator that has info about begining of array,so its the end of reverseIterator
	 */
    public:
        Iterator Begin( )
        {
            return Iterator(&(PFArray<T>::operator*()),0,getCapacity(),getNumberUsed());
        }

        reverseIterator Rend( )
        {
            return reverseIterator((&(PFArray<T>::operator*())),getNumberUsed(),getCapacity(),getNumberUsed());
        }

        Iterator End( )
        {
            return Iterator(&(PFArray<T>::operator*())+getNumberUsed()-1,getNumberUsed(),getCapacity(),getNumberUsed());
        }


        reverseIterator Rbegin( )
        {
            return reverseIterator(&(PFArray<T>::operator*())+getNumberUsed()-1,0,getCapacity(),getNumberUsed());
        }


};

/****    _PF_Arr_Wi CONSTRUCTORS and DESTRUCTOR IMPLEMENTATION START    ****/
/*
 *CONSTRUCTOR
 *no parameter
 */
template<class T>
_PF_Arr_Wi<T>::_PF_Arr_Wi( )
:PFArray<T>::PFArray()
{

}

/*
 *CONSTRUCTOR
 *integer parameter
 */
template<class T>
_PF_Arr_Wi<T>::_PF_Arr_Wi(int capacityValue )
:PFArray<T>::PFArray(capacityValue)
{

}

/*
 *CONSTRUCTOR
 *copy constructor
 */
template<class T>
_PF_Arr_Wi<T>::_PF_Arr_Wi(const _PF_Arr_Wi<T>& pfaObject)
:PFArray<T>::PFArray(pfaObject)
{

}

/*
 *DESTRUCTOR
 */
template<class T>
_PF_Arr_Wi<T>::~_PF_Arr_Wi( )
{

}
/****    _PF_Arr_Wi CONSTRUCTORS and DESTRUCTOR IMPLEMENTATION FINISH    ****/




/****    _PF_Arr_Wi OPERATIONS START    ****/
/*
 *ADD ELEMENT
 *call base classes function
 */
template<class T>
void _PF_Arr_Wi<T>::addElement(T element)
{
    PFArray<T>::addElement(element);
}

/*
 *IS THAT FULL
 *call base classes function
 */
template<class T>
bool _PF_Arr_Wi<T>::full( ) const
{
    return PFArray<T>::full();
}

/*
 *GET CAPACITY
 *call base classes function
 */
template<class T>
int _PF_Arr_Wi<T>::getCapacity( )const
{
    return PFArray<T>::getCapacity();
}

/*
 *GET NUMBER USED
 *call base classes function
 */
template<class T>
int _PF_Arr_Wi<T>::getNumberUsed( )const
{
    return PFArray<T>::getNumberUsed();
}

/*
 *EMPTY ARRAY
 *call base classes function
 */
template<class T>
void _PF_Arr_Wi<T>::emptyArray( )
{
    PFArray<T>::emptyArray();
}

/*
 *OPERATOR []
 *call base classes function
 */
template<class T>
T& _PF_Arr_Wi<T>::operator[](int index)
{
    return (PFArray<T>::operator[](index));
}

/*
 *ASSIGNMENT OPERATOR
 *call base classes function
 */
template<class T>
_PF_Arr_Wi<T>& _PF_Arr_Wi<T>::operator =(const _PF_Arr_Wi<T>& rightSide)
{
    PFArray<T>::operator=(rightSide);
}
/****    _PF_Arr_Wi OPERATIONS FINISH    ****/


/****    _PF_Arr_Wi::ITERATOR OPERATIONS START    ****/
/*
 *CONSTRUCTOR
 *no parameter
 */
template<class T>
_PF_Arr_Wi<T>::Iterator::Iterator()
{
    _point=NULL;
    _where=0;
    _capacity=0;
    _used=0;
}

/*
 *Copy CONSTRUCTOR
 */
template<class T>
_PF_Arr_Wi<T>::Iterator::Iterator(const Iterator& rightSide)
{
    _point=rightSide._point;
    _where=rightSide._where;
    _capacity=rightSide._capacity;
    _used=rightSide._used;
}

/*
 *CONSTRUCTOR
 *all member initializing
 */
template<class T>
_PF_Arr_Wi<T>::Iterator::Iterator(T* a,int wher,int cap,int used)
{
    _point=a;
    _where=wher;
    _capacity=cap;
    _used=used;
}

//getters
template<class T>
int _PF_Arr_Wi<T>::Iterator::getWhere()
{
    return _where;
}
template<class T>
int _PF_Arr_Wi<T>::Iterator::getUsed()
{
    return _used;
}

template<class T>
int _PF_Arr_Wi<T>::Iterator::getCapacity()
{
      return _capacity;
}

/****    _PF_Arr_Wi::ITERATOR OPERATIONS FINISH    ****/


/****    _PF_Arr_Wi::reverseITERATOR OPERATIONS START    ****/
/*
 *CONSTRUCTOR
 *no parameter
 */
template<class T>
_PF_Arr_Wi<T>::reverseIterator::reverseIterator()
{
    _point_=NULL;
    _where_=0;
    _capacity_=0;
    _used_=0;
}

/*
 *Copy CONSTRUCTOR
 */
template<class T>
_PF_Arr_Wi<T>::reverseIterator::reverseIterator(const reverseIterator& rightSide)
{
    _point_=rightSide._point_;
    _where_=rightSide._where_;
    _capacity_=rightSide._capacity_;
    _used_=rightSide._used_;
}

/*
 *CONSTRUCTOR
 *all member initializing
 */
template<class T>
_PF_Arr_Wi<T>::reverseIterator::reverseIterator(T* a,int wher,int cap,int used)
{
    _point_=a;
    _where_=wher;
    _capacity_=cap;
    _used_=used;
}

/****    _PF_Arr_Wi::reverseITERATOR OPERATIONS FINISH    ****/


#endif
