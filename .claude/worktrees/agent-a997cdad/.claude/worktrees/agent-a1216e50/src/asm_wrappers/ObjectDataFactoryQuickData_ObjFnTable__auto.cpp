#include "types.h"

class ObjFnTable;

template <typename T>
class ObjectDataFactoryQuickData {
public:
    int GetDataSourceType() const { return 1; }
    char _stub_data[16];
};
template class ObjectDataFactoryQuickData<ObjFnTable>;
