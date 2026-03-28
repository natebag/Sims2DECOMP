#include "types.h"

class FamilyImpl;

template <typename T>
class SimpleReconObject {
public:
    int GetType() { return *(int*)((char*)this + 0x8); }
    char _stub_data[16];
};

template class SimpleReconObject<FamilyImpl>;
