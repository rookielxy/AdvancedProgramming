#ifndef HW4_LIST_H
#define HW4_LIST_H

template <class T>
struct _List_Node {
    _List_Node<T> *prev;
    _List_Node<T> *next;
    T data;
    _List_Node(): prev(nullptr), next(nullptr) {}
    explicit _List_Node(T x): data(x), prev(nullptr), next(nullptr) {}
};

template <class T>
struct _List_iterator {
    _List_Node<T> *_p_node;

    explicit _List_iterator(_List_Node<T> *x): _p_node(x) {}
    ~_List_iterator() = default;

    bool operator==(_List_iterator it) {
        return _p_node == it._p_node;
    }

    bool operator!=(_List_iterator it) {
        return not (*this == it);
    }

    _List_iterator& operator++() {
        _p_node = _p_node->next;
        return *this;
    }

    const _List_iterator operator++(int) {
        auto temp = *this;
        _p_node = _p_node->next;
        return temp;
    }

    _List_iterator& operator--() {
        _p_node = _p_node->prev;
        return *this;
    }

    const _List_iterator operator--(int) {
        auto temp = *this;
        _p_node = _p_node->prev;
        return temp;
    }

    T& operator*() {
        return _p_node->data;
    }
};

template <class T>
class List {
public:
    typedef _List_Node<T>* link_type;
    typedef _List_iterator<T> iterator;
private:
    int length;
    link_type head;
    link_type tail;
public:
    List();
    ~List();
    bool empty();
    iterator begin();
    iterator end();
    iterator insert(iterator it, T e);
    iterator erase(iterator it);
};

template <class T>
List<T>::List() {
    head = tail = new _List_Node<T>();
    tail->prev = head;
    tail->next = head;
    length = 0;
}

template <class T>
List<T>::~List() {
    while (head != tail) {
        auto todel = head;
        head = head->next;
        delete todel;
    }
    delete head;
    head = tail = nullptr;
    length = 0;
}

template <class T>
bool List<T>::empty() {
    return length == 0;
}

template <class T>
typename List<T>::iterator List<T>::begin() {
    return iterator(head);
}

template <class T>
typename List<T>::iterator List<T>::end() {
    return iterator(tail);
}

template <class T>
typename List<T>::iterator List<T>::insert(List<T>::iterator it, T e) {
    ++length;
    auto toadd = new _List_Node<T>(e);
    auto pre = it._p_node->prev;
    pre->next = toadd;
    toadd->prev = pre;
    it._p_node->prev = toadd;
    toadd->next = it._p_node;
    head = tail->next;
    return iterator(toadd);
}

template <class T>
typename List<T>::iterator List<T>::erase(List<T>::iterator it) {
    --length;
    auto todel = it._p_node;
    auto prev = todel->prev, next = todel->next;
    prev->next = next;
    next->prev = prev;
    delete todel;
    head = tail->next;
    return iterator(next);
}
#endif
