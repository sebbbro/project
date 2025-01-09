
#pragma once
#include <iostream>
namespace sb {

/**
* \brief Implementation of circular buffer.
*
* This class shows implementation for circular buffer used to storing numbers 
* in a cyclicar manner. This means that when array of elements is full,
* first writed element will be overwritten by next element to be written.
*
* \param T Type of variables used as buffer elements. 
*/
template<typename T>
class CircularBuffer {
private:
    /**
     * \brief Pointer to array that stores data in buffer.
     * 
     * Pointer to dynamically allocated array.
     *  */  
    T* m_buffer; 

    /**
     * \brief Capacity of buffer.
     * 
     * Determinates maximal amount of elements, that can be saved in buffer.
     *  */   
    size_t m_capacity;  
    
    /**
     * \brief Pointer to the beginning of the buffer.
     * 
     * Indicates the first element to read.
     *  */   
    size_t m_head;   

     /**
     * \brief Pointer to the end of the buffer.
     * 
     * Point to a location in array, where an element can be saved.
     *  */ 
    size_t m_tail;

    /**
     * \brief Current size of buffer.
     * 
     * Increments when adding, decrements when removing elements from buffer.
     *  */ 
    size_t m_size;    


public: 
    /**
     * \brief Constructor of class CircularBuffer.
     * 
     * Creates a buffer of the given capacity. Initializes member variables such as capacity,
     * head and tail pointers, and size. Uses dynamic allocate memory for buffer array
     * of size equal to capacity. Warns if given capacity is equal to zero.
     
     * \param cap Capacity of buffer entered by user.
     */
    CircularBuffer(size_t cap)
        : m_capacity(cap), m_head(0), m_tail(0), m_size(0) {
        if (cap == 0) {
            std::cout<<"Buffer size must be greater than 0.\n";
        } else {
            m_buffer = new T[m_capacity];
        }
    }

    /**
     * \brief Destructor of class CircularBuffer.
     * 
     * Frees up memory used by dynamically allocated m_buffer.
     */
    ~CircularBuffer() {
        delete[] m_buffer;
    }

    /**
     * \brief Adds element to buffer.
     * 
     * The given by user number is written to buffer at index m_tail.
     * Increments m_tail field value to point to next index to overwrite.
     * Protects array index from oversize by using modulo.
     * Increments buffer size value, or, when buffer is full and element 
     * is being overwritten, increments the 'read' index.
     */
    void push(const T& element) {
        m_buffer[m_tail] = element;
        m_tail = (m_tail + 1) % m_capacity;

        if (m_size == m_capacity) {
            m_head = (m_head + 1) % m_capacity;
        } else {
            ++m_size;
        }
    }

     /**
     * \brief Reads the last saved element and removes from buffer.
     * 
     * Reads last saved value (from index m_head).
     * Increments m_head field value to point to next element to read.
     * Protects array index from oversize by using modulo.
     * Decrements buffer size value.
     * \return T variable 'element' equal to m_buffer field at index m_head.
     */
    T pop() {
        if (m_size == 0) {
            std::cout<<"Buffer is empty\n";
        }

        T element = m_buffer[m_head];
        m_head = (m_head + 1) % m_capacity;
        --m_size;
        return element;
    }

    /**
     * \brief Reads the last element without deleting it.
     *
     * \return Value of field m_buffer with index m_head.
     */
    T front() const {
        if (m_size == 0) {
            std::cout<<"Buffer is empty\n";
            return 0;
        } else {
            return m_buffer[m_head];
        }
    }

    /**
    * \brief Checks if it's empty.
    * 
    * \return True if buffer is empty, and othervise false.
    * */
    bool isEmpty() const {
        return m_size == 0;
    }
   
    /**
    * \brief Checks if it's full.
    * 
    * \return True if buffer is full, and othervise false.
    * */
    bool isFull() const {
        return m_size == m_capacity;
    }

    /**
    * \brief Displays current buffer size.
    * 
    * \return Value of m_size field.
    * */
    size_t size() const {
        return m_size;
    }
   
    /** 
    * \brief Displays buffer contents.
    * 
    * In the for loop, the next values of buffer are displayed
    * depending of current size.
    */
    void print() const {
        std::cout << "buffer: ";
        for (size_t i = 0; i < m_size; ++i) {
            std::cout << m_buffer[(m_head + i) % m_capacity] << " ";
        }
        std::cout << "\n";
    }
};
}
