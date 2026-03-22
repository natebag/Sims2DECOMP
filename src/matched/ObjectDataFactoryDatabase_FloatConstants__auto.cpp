#include "types.h"

class FloatConstants;

template <typename T>
class ObjectDataFactoryDatabase {
public:
    int GetDataSourceType() const { return 4; }
    char _stub_data[16];
};
template class ObjectDataFactoryDatabase<FloatConstants>;
