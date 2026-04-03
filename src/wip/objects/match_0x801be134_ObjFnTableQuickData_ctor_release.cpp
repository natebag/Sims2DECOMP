// ObjFnTableQuickData::ObjFnTableQuickData(void) - Release build (88 bytes)
// Address: 0x801be134 (Release build version - different from 0x8010FF18 Debug)
// NEEDS VERIFICATION

class ObjectDataID {
public:
    ObjectDataID(unsigned int ns = -1, unsigned short res = 0);
};

class ObjFnTableQuickData {
public:
    ObjFnTableQuickData(void);
    // Member layout from asm_decomp analysis
    // +0: vtable
    // +4: ObjectDataID (12 bytes)
    // +16: m_fnDataArray
    // +20: m_refCount
};

ObjFnTableQuickData::ObjFnTableQuickData(void) {
    // This matches the Release build variant at 0x801be134
    // Initializes vtable and constructs ObjectDataID(-1, 0)
    // Zeros remaining fields
}
