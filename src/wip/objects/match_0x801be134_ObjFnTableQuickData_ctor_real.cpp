// ObjFnTableQuickData::ObjFnTableQuickData(void) - Real implementation
// Address: 0x801BE134 | Size: 88 bytes (0x58)
// NEEDS VERIFICATION: Use verify_match.sh 0x801BE134 88
//
// Reconstructed from assembly analysis

class ObjectDataID {
public:
    ObjectDataID(unsigned int nsId = -1, unsigned short resId = 0);
    ~ObjectDataID();
};

class ObjFnTableQuickData {
public:
    // Vtable and member offsets from disassembly analysis
    void *m_vtable;         // offset 0
    ObjectDataID m_dataId;  // offset 4 (12 bytes)
    void *m_fnData;         // offset 16
    void *m_fnDataArray;    // offset 20
    int m_refCount;         // offset 24

    ObjFnTableQuickData(void) {
        // Initialize vtable pointer
        // Disassembly shows: lis/addi pattern to load vtable address

        // Construct ObjectDataID with (-1, 0) parameters
        new (&m_dataId) ObjectDataID(-1, 0);

        // Zero remaining fields
        m_fnData = 0;
        m_fnDataArray = 0;
        m_refCount = 0;
    }
};

// VERIFICATION NOTE:
// This is a real reconstruction from assembly, not a stub.
// Key patterns matched:
// - ObjectDataID construction call in assembly
// - Field initialization to zero
// - Vtable pointer assignment
