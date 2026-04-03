// ObjFnTableQuickData::ObjFnTableQuickData(void) (88 bytes)
// Constructor - initialize vtable and ObjectDataID field
// Address: 0x8010FF18
// NEEDS VERIFICATION - Must verify with verify_match.sh before moving to src/matched/

class ObjectDataID {
public:
    ObjectDataID(unsigned int namespaceID = -1, unsigned short resourceID = 0);
};

class ObjFnTableQuickData {
    void *m_vtable;           // offset 0
    ObjectDataID m_dataID;    // offset 4
    void *m_fnData;           // offset 12
    void *m_fnDataArray;      // offset 16
    int m_refCount;           // offset 20

public:
    ObjFnTableQuickData(void) {
        // Set vtable pointer
        m_vtable = (void *)0x801fbab8;

        // Construct embedded ObjectDataID with (-1, 0)
        new (&m_dataID) ObjectDataID(-1, 0);

        // Zero out remaining fields
        m_fnData = 0;
        m_fnDataArray = 0;
        m_refCount = 0;
    }
};
