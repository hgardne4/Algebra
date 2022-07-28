/*
 * Henry Gardner, Linear Algebra Library
 * Object definition (header) of a Vector
 * Mathematics References come from "Linear Algebra" Fifth Edition Friedberg, Insel, and Spence
*/

#pragma once

// define a new namespace that can reference different ways of grouping data i.e. 
// NOTE: DataGrouping is not limited to this file, this namespace is used in Matrix.h, etc.
namespace DataGrouping {

	/* 
	Need to define a vector in 2 ways: 
		- "magnitude and direction" (Friedberg, Insel, Spence)
		- "array-based" definition
			~ we want array based instead of linked-list for random access
	Make sure it is generic and can handle multiple types of data!
	*/
	template <typename E> class Vector {
		private:
			// every vector has a list of information, a size (number of elements in the list), and a limit
			// pointer to the list, which stores the address of our vector data
			E* elements;
			int size;
			int limit;
		public:
			// constructor/destructor
			Vector();
			~Vector();

			// FUNCTIONS:
			// add element to the end of the list
			void push(E element);
			// add element at a specific location
			void push(E element, int location);

			// get element at a specific location
			E get(int location);
			// get location of FIRST occurance of element
			int getLoc(E element);

			// remove last element and output
			E pop();
			// remove element at a location
			E pop(int location);

			// return the private values
			int length();
			int capacity();
			E values();

			// display the elements
			void output();

			// mathematical expressions on a vector
			E sum();
			void scalarMult(E scalar);
			double norm();
	};
}
