#include <map>
#include <iostream>

void value_type()
{
    std::cout << "========== map_value_type: =========" << std::endl;
    typedef std::pair<const int, int> cInt2Int;
    std::map<int, int> m1;

    // value can be used to pass the correct type
    // explicitly to avoid implicit type conversion
    std::map<int, int>::value_type value1;
    m1.insert(std::map<int, int>::value_type(1, 10));

    // Compare other ways to insert objects into a map
    m1.insert(cInt2Int(2, 20));
    m1[3] = 30;

    // Initializing key1 and mapped1
    std::map<int, int>::key_type key1;
    key1 = (m1.begin()->first);
    std::map<int, int>::mapped_type mapped1;
    mapped1 = (m1.begin()->second);

    std::cout << "the m1 key : " << key1 << " value: " << mapped1 << std::endl;

    // The following line would cause an error because
    // the value_type is not assignable
    // value1 = cInt2Int(4, 40);
    
    std::cout << "The keys of the mapped elements are: ";
    std::map<int, int>::iterator plter;
    for (plter = m1.begin(); plter != m1.end(); ++plter) {
        std::cout << " " << plter->first;
    }
    std::cout << std::endl;

    std::cout << "The value of the mapped elements are: ";
    for (plter = m1.begin(); plter != m1.end(); ++plter) {
        std::cout << " " << plter->second;
    }
    std::cout << std::endl;
}

int main()
{

    value_type();

    return 0;
}
