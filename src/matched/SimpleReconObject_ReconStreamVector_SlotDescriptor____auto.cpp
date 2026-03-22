#include "types.h"

class Neighbor;
class SlotDescriptor;
template <typename T> class ReconStreamPtrVector { public: char _s[16]; };
template <typename T> class ReconStreamVector { public: char _s[16]; };

template <typename T>
class SimpleReconObject {
public:
    int GetType() { return *(int*)((char*)this + 0x8); }
    char _stub_data[16];
};

template class SimpleReconObject<ReconStreamVector<SlotDescriptor>>;
