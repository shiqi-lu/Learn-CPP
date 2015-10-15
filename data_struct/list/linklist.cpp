template <typename DataType>
class LinkList
{
public:
    LinkList()
    {
        head = new ListNode();
    }

    LinkList(ListNode * node)
    {
        head = node;
    }

    ~LinkList()
    {
        delete head;
    }
    bool insertNode(ListNode * q, DataType newData);
    bool removeNode(ListNode * q);
    ListNode * findNode(DataType value);
    bool cleanLink();
    DataType getNodeData(ListNode * p);

private:
    ListNode * head;
};

template <typename DataType>
class ListNode
{
public:
    ListNode()
    {
        next = NULL;
    }
    ListNode(DataType item, ListNode<DataType> * nextNode = NULL)
    {
        data = item;
        next = nextNode;
    }
    ~ListNode()
    {
        next = NULL;
    }
    DataType getData()
    {
        return data;
    }
    ListNode * getNext()
    {
        return next;
    }

private:
    friend typename LinkList<DataType>;
    DataType * next;
    DataType data;
};

template <typename DataType>
bool LinkList<DataType>::insertNode(int i, DataType newData)
{
    ListNode<DataType> * p = head;
    int j;
    for (j = 1; j <= i-1; ++j) {
        p = p->next;
        if (p == NULL) {
            break;
        }
    }

    if (p == NULL && j < (i-1)) {
        std::cout << "insert invalid location" << std::endl;
        return false;
    }
    ListNode<DataType> * node = new ListNode<DataType> (newData);
    node->next = p->next;
    p->next = node;
    return true;
}

template <typename DataType>
bool LinkList<DataType>::insertNode(DataType newData)
{
    ListNode<DataType> * p = head;
    ListNode<DataType> * node = new ListNode<DataType> (newData);

    if (node == NULL) {
        return false;
    }
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = node;
    return true;
}

template <typename DataType>
bool LinkList<DataType>::removeNode(ListNode<DataType> * q)
{
    if (q == NULL) {
        std::cout << "node to be deleted not exists" << std::endl;
        return false;
    }
    ListNode<DataType> * tempPointer = head;
    while (tempPointer->next != q) {
        tempPointer = tempPointer->next;
    }
    tempPointer->next = q->next;

    delete q;
    return true;
}

template <typename DataType>
ListNode<DataType> * LinkList<DataType>::findNode(DataType value)
{
    ListNode<DataType> * currentPointer = head;
    while (currentPointer != NULL && currentPointer->data != value) {
        currentPointer = currentPointer->next;
    }
    if (currentPointer == NULL) {
        std::cout << "No such node" << std::endl;
        exit(1);
    } else {
        return currentPointer;
    }
}

template <typename DataType>
void LinkList<DataType>::cleanLink()
{
    ListNode<DataType> * current = head;
    while (head->next != NULL) {
        current = head->next;
        head->next = current->next;
        delete current;
    }
}
