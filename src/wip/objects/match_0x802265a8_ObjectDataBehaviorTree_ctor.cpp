// ObjectDataBehaviorTree::ObjectDataBehaviorTree(void) (0x802265a8, 136 bytes)
// Initialize ObjectDataBehaviorTree with vtable and default StringBuffer

class StringBuffer {
public:
    StringBuffer(char *buf, unsigned int size);
    void append(const char *, int len);
};

class ObjectDataID {
public:
    ObjectDataID(unsigned int nsID, unsigned short resID);
};

class ObjectDataBehaviorTree {
    int *m_vtable;          // offset 0
    short m_unused1;        // offset 4
    char pad1[8];           // offset 6-13
    StringBuffer m_resourceName;  // offset 14 (constructed with 64 byte buffer)
    char m_nameBuf[64];     // temp buffer for StringBuffer
    int m_unused2;          // offset 84
    ObjectDataID m_dataID;  // offset 88

public:
    ObjectDataBehaviorTree() {
        // Initialize vtable
        *(int**)this = g_ObjectDataBehaviorTree_vtable;
        m_unused2 = 0;
        // Initialize StringBuffer with name buffer
        // m_resourceName.StringBuffer(m_nameBuf, 64)
        // m_resourceName.append(some_default_string, -1)
        // Initialize ObjectDataID
        // m_dataID.ObjectDataID(0, 0)
    }
};

extern int *g_ObjectDataBehaviorTree_vtable;
