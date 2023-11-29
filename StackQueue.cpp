// StackQueues.cpp : Defines the exported functions for the DLL application.
//

#include "StackQueue.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

ArrayBasedStack::ArrayBasedStack(void)
{
	
}

ArrayBasedStack::~ArrayBasedStack()
{
	
}

// Function to peek at the top of the stack
int ArrayBasedStack::peek() const
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		return s_array[s_count-1];
	}


}

// Function to check if the stack is empty
bool ArrayBasedStack::isEmpty() const
{
	if (s_count == 0){
		return true;
	}
	else{
		return false;
	}
}

// Function to add a value to the top of the stack
bool ArrayBasedStack::push(const int & val)
{
	s_array[s_count] = val;
	s_count ++;
	return true;
}

// Function to remove a value from the top of the stack
bool ArrayBasedStack::pop()
{
	if(isEmpty()){
		return false;
	}
	else{
		s_array[s_count] = 0;
		s_count --;
		return true;
	}
}

// Function to print all the stack contents in a string
std::string ArrayBasedStack::toString() const
{
	string str = "";

	if (s_count != 0){
		for (int i = 0; i < s_count; i++){
			str.append(to_string(s_array[i]));
			if (i == (s_count - 1)){
				return str;
			}
			else{
				str.append(" ");
			}
		}
	}
}

ArrayBasedQueue::ArrayBasedQueue(void)
{

}

ArrayBasedQueue::~ArrayBasedQueue()
{
	
}

// Function to check the first value in the queue
std::string ArrayBasedQueue::peek() const
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		//TODO
		return q_array[0];
	}


}

// Function to check if the queue is empty
bool ArrayBasedQueue::isEmpty() const
{
	if (q_count == 0){
		return true;
	}
	else{
		return false;
	}
}

// Function to add a value to the end of the queue
bool ArrayBasedQueue::enQueue(const std::string &val)
{
	q_array[q_count] = val;
	q_count++;
	return true;
}

// Function to remove the first value from the queue
bool ArrayBasedQueue::deQueue()
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < q_count; i++){
			q_array[i] = q_array[i+1];
		}
		q_count--;
		return true;
	}
}

// Function to print the queue's contents in a string
std::string ArrayBasedQueue::toString() const
{
	string str = "";

	if (q_count != 0){
		for (int i = 0; i < q_count; i++){
			str.append(q_array[i]);
			if (i == (q_count - 1)){
				return str;
			}
			else{
				str.append(" ");
			}
		}
	}
}


