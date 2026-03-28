#include "types.h"

class ObjFnTable;

template <typename T>
class ObjectDataFactoryIFF {
public:
    int GetDataSourceType() const { return 2; }
    char _stub_data[16];
};
template class ObjectDataFactoryIFF<ObjFnTable>;
