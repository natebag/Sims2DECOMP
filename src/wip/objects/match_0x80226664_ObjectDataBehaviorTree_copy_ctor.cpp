// ObjectDataBehaviorTree::ObjectDataBehaviorTree(ObjectDataBehaviorTree &) (0x80226664, 188 bytes)
// Copy constructor - initialize from another ObjectDataBehaviorTree

class StringBuffer {
public:
    StringBuffer(char *buf, unsigned int size);
    void append(const char *, int len);
};

class ObjectDataID {
public:
    ObjectDataID(unsigned int nsID, unsigned short resID);
    void operator=(ObjectDataID &);
};

class ObjectDataBehaviorTree {
    int *m_vtable;          // offset 0
    short m_unused1;        // offset 4
    char pad1[8];           // offset 6-13
    StringBuffer m_resourceName;  // offset 14
    char m_nameBuf[64];     // temp buffer for StringBuffer
    int m_unused2;          // offset 84
    ObjectDataID m_dataID;  // offset 88

    short GetResID() const;
    void SetResID(short id);
    void SetResourceName(StringBuffer &);
    int GetResourceName(StringBuffer &) const;

public:
    ObjectDataBehaviorTree(ObjectDataBehaviorTree &src) {
        // Initialize vtable
        *(int**)this = g_ObjectDataBehaviorTree_vtable;
        m_unused2 = 0;

        // Initialize StringBuffer with name buffer
        // m_resourceName.StringBuffer(m_nameBuf, 64)

        // Initialize ObjectDataID
        // m_dataID.ObjectDataID(0, 0)

        // Copy from source
        m_unused2 = src.m_unused2;

        // Create temp StringBuffer for source resource name
        char tempBuf[64];
        StringBuffer tempSB(tempBuf, 64);

        // Get source resource name and set to this
        if (src.GetResourceName(tempSB)) {
            SetResourceName(tempSB);
        }

        // Copy resource ID
        short srcResID = src.GetResID();
        SetResID(srcResID);
    }
};

extern int *g_ObjectDataBehaviorTree_vtable;
