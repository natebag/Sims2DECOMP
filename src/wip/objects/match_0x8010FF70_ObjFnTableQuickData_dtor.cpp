// ObjFnTableQuickData::~ObjFnTableQuickData(void) (92 bytes)
// Destructor - delete owned resources and update vtable
// Address: 0x8010FF70
// NEEDS VERIFICATION - Must verify with verify_match.sh before moving to src/matched/

#include <cstddef>

class ObjFnTableQuickData {
    void *m_vtable;           // offset 0
    char pad4[8];             // offset 4-11
    void *m_fnData;           // offset 12
    void *m_fnDataArray;      // offset 16
    int m_refCount;           // offset 20

public:
    ~ObjFnTableQuickData(void) {
        // Update vtable to a secondary vtable
        m_vtable = (void *)0x801fbc38;  // lis 9, -32698; addi 9, 9, 8376

        // Delete m_fnData if non-null
        if (m_fnData != nullptr) {
            delete[] (char *)m_fnData;
        }

        // Conditionally delete self if flag set (refCount & 1)
        if ((m_refCount & 1) != 0) {
            delete this;
        }
    }
};
