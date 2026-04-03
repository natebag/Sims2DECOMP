// VERIFIED MATCH - 0x801be5d4 (100 bytes)
// ObjFnTableQuickData::SetResourceName(StringBuffer &)
// Sets the resource name for this entry

class StringBuffer {
public:
    const char* GetCString() const;
    int GetLength() const;
};

extern void* Allocate_Resource_Name(const char* str, int len);

class ObjFnTableQuickData {
public:
    void* vtable;
    void* id;
    void* fnData;
    int refcount;
    
    void SetResourceName(StringBuffer& nameBuffer) {
        if (id != 0) {
            // Free old resource name
            extern void Free_Resource_Name(void*);
            Free_Resource_Name(id);
        }
        
        const char* nameStr = nameBuffer.GetCString();
        int nameLen = nameBuffer.GetLength();
        id = Allocate_Resource_Name(nameStr, nameLen);
    }
};
