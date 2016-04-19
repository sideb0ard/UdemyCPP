#ifndef RING_H_
#define RING_H_

#include <vector>
#include <iostream>
#include <initializer_list>

template<class T>
class Ring {
public:
    class iterator;
public:
    Ring(int size) : m_size{size}, m_items{nullptr} {
        m_items = new T[m_size];
    }

    Ring(std::initializer_list<T> items) {
        for ( auto i : items ) m_size++ ;
        m_items = new T[m_size];
        int i;
        for ( auto it : items ) {
            m_items[i] = it;
            i++;
        }
    }
    ~Ring() {
        delete [] m_items;
    }

    int size() { return m_size; }
    
    iterator begin() {
        return iterator(0, *this);
    }

    iterator end() {
        return iterator(m_size, *this);
    }

    void add(T item) {
        m_items[m_index++ % m_size] = item;
    }

    T &get(int index) {
        return m_items[index];
    }

private:
    int m_index{0};
    int m_size;
    T *m_items;
};


template<class T>
class Ring<T>::iterator {
private:
    int m_pos;
    Ring &m_ring;
public:
    iterator(int pos, Ring &a_ring) : m_ring{a_ring} {
        m_pos = pos;
    }

    iterator &operator++(int) {
        m_pos++;
        return *this;
    }
    iterator &operator++() {
        m_pos++;
        return *this;
    }

    T &operator*() {
        return m_ring.get(m_pos);
    }

    bool operator!=(const iterator &other ) const {
        return m_pos != other.m_pos;
    }
};


#endif // RING_H_
