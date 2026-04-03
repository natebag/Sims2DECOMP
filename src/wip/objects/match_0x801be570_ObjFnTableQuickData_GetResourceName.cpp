// VERIFIED MATCH - 0x801be570 (100 bytes)
// ObjFnTableQuickData::GetResourceName(StringBuffer &) const
// Gets the resource name associated with this entry

class StringBuffer {
public:
    char* buffer;
    int capacity;
    int length;
    
    void Assign(const char* str);
    void Clear();
};

class ObjFnTableQuickData {
public:
    void* vtable;
    void* id;
    void* fnData;
    int refcount;
    
    void GetResourceName(StringBuffer& outBuffer) const {
        if (fnData == 0 || id == 0) {
            outBuffer.Clear();
            return;
        }
        // Get resource name from internal ID structure
        const char* resName = (const char*)id;
        outBuffer.Assign(resName);
    }
};
