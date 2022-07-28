/*
 * Henry Gardner, Linear Algebra Library
 * Object definition of a Vector
 * Mathematics References come from "Linear Algebra" Fifth Edition Friedberg, Insel, and Spence
*/

#include "Vector.h"
#include <stdexcept>
#include <math.h>
#include <iostream>

using namespace DataGrouping;
using namespace std;

// default constructor creates a list of size 1 with no data
template <typename E> 
Vector<E>::Vector() {
    elements = new E[1];
    size = 0;
    limit = 1;
}

// destructor
template <typename E>
Vector<E>::~Vector() {
    delete[] elements;
}

// append element at the end
template <typename E>
void Vector<E>::push(E element) {
    // since this is array-based, need to make sure we aren't at the limit
    // if so, make new array with updated limit
    if(size == limit) {
        // to avoid having to recreate arrays a lot, double the limit
        E* newElements = new E[2*limit];

        // copy elements to the new array:
        for(int i = 0; i < limit; i++)
            newElements[i] = elements[i];

        //update the limit, save space by deleting the old elements and updating them
        limit *= 2;
        delete[] elements;
        elements = newElements;
    }

    // now we have a elements array of propper size, add to the end and update size:
    elements[size] = element;
    size++;
}

// append at a specific location
template <typename E>
void Vector<E>::push(E element, int location) {
    // assuming that the location already exists, if not add to end:
    if(location >= size)
        Vector::push(element);
    else {
        // make sure we have enough space
        if(size == limit){
            // to avoid having to recreate arrays a lot, double the limit
            E* newElements = new E[2*limit];

            // copy elements to the new array:
            for(int i = 0; i < limit; i++)
                newElements[i] = elements[i];

            //update the limit, save space by deleting the old elements and updating them
            limit *= 2;
            delete[] elements;
            elements = newElements;
        }
        // create a new vector with the additional element
        E* newElements = new E[limit];
        // copy all elements up to the location
        for(int i = 0; i < location; i++)
            newElements[i] = elements[i];
        // add the new element
        newElements[location] = element;
        // copy all elements after the location to the next spot
        for(int i = location+1; i < limit; i++)
            newElements[i] = elements[i-1];

        // remove old array, update both the elements and the size
        delete[] elements;
        elements = newElements;
        size++;
    }
}

// return the element at a location
template <typename E>
E Vector<E>::get(int location) {
    if(location < size && location >= 0)
        return elements[location];
    else
        throw invalid_argument("Index out of bounds...");
}

// return the first occurance of an element
template <typename E>
int Vector<E>::getLoc(E element) {
    for(int i = 0; i < limit; i++)
        if(elements[i] = element)
            return i;
    // if element not in list return -1
    return -1;
}


// remove last element and return it
template <typename E>
E Vector<E>::pop() {
    E* newElements = new E[limit];
    E returnValue = elements[size-1];
    // add everything but the last element
    for(int i = 0; i < size; i++)
        newElements[i] = elements[i];
    // update the array and its corresponding values
    delete[] elements;
    elements = newElements;
    size--; 
    return returnValue;
}

// remove element at a location and return it
template <typename E>
E Vector<E>::pop(int location) {
    E* newElements = new E[limit];
    E returnValue = elements[location];
    // add everything but the specific element
    for(int i = 0; i < location; i++)
        newElements[i] = elements[i];
    for(int i = location; i < size; i++)
        newElements[i] = elements[i+1];
    // update the array and its corresponding values
    delete[] elements;
    elements = newElements;
    size--; 
    return returnValue;
}

// return the size of the vector
template <typename E>
int Vector<E>::length() {
    return size;
}

// return the limit of the vector
template <typename E>
int Vector<E>::capacity() {
    return limit;
}

// return the elements of the vector
template <typename E>
E Vector<E>::values() {
    return elements;
}

// function to display the elements in the vector
template <typename E>
void Vector<E>::output() {
    cout << "<";
    for(int i = 0; i < size; i++) {
        if(i+1 != size)
            cout << elements[i] << ", ";
        else
            cout << elements[i];
    }
    cout << ">\n";
}

// function to return the sum of a vector
template <typename E>
E Vector<E>::sum() {
    E result = 0;
    for(int i = 0; i < size; i++)
        result += elements[i];
    return result;
}

// function to multiply a vector by a scalar value
template <typename E>
void Vector<E>::scalarMult(E scalar) {
    E result = 0;
    for(int i = 0; i < size; i++)
        elements[i] *= scalar;
}

/*
Function to calculate the norm of a vector.
NOTE: assuming the elements of the vector fall in an inner product space and are numerical.
Theory:
    Let V be an inner product space and x be a vector s.t. x in V.
    The norm (length) of the vector is defined as:

        ||x|| = ||<a_1, a_2, ... , a_n>|| = sum{|a_i|^2}^(1/2)

*/
template <typename E>
double Vector<E>::norm() {
    double result = 0;
    for(int i = 0; i < size; i++) {
        result += (elements[i]*elements[i]);
    }
    return sqrt((double)result);
}