#include "types.h"

class StringSet;

template <typename T>
class ObjectDataFactoryQuickData {
public:
    void GetDataSourceType() const { return 1; }
    char _stub_data[16];
};
template class ObjectDataFactoryQuickData<StringSet>;
