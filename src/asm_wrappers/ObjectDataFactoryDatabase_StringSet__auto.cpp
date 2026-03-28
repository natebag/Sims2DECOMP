#include "types.h"

class StringSet;

template <typename T>
class ObjectDataFactoryDatabase {
public:
    void GetDataSourceType() const { return 4; }
    char _stub_data[16];
};
template class ObjectDataFactoryDatabase<StringSet>;
