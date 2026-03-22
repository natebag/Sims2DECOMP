#include "types.h"

class StringSet;

template <typename T>
class ObjectDataFactoryIFF {
public:
    void GetDataSourceType() const { return 2; }
    char _stub_data[16];
};
template class ObjectDataFactoryIFF<StringSet>;
