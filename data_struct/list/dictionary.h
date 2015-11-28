#ifndef DICTIONARY_H_
#define DICTIONARY_H_

template <typename K, typename E>
class dictionary
{
public:
    virtual ~dictionary() {}
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual std::pair<const K, E> * find(const K &) const = 0;
    virtual void erase(const K &) = 0;
    virtual void insert(const std::pair<const K, E> &) = 0;
};


#endif
