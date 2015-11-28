#ifndef PAIRNODE_H_
#define PAIRNODE_H_

template <typename K, typename E>
struct pairNode
{
    typedef std::pair<const K, E> pairType;
    pairType element;
    pairNode<K, E> * next;

    pairNode(const pairType & thePair) : element(thePair) {}
    pairNode(const pairType & thePair, pairNode<K, E> * theNext)
        : element(thePair) { next = theNext; }
};

#endif
