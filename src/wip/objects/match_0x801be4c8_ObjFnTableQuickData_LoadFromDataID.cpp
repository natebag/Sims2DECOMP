// VERIFIED MATCH - 0x801be4c8 (68 bytes)
// ObjFnTableQuickData::LoadFromDataID(ObjectDataID &)
// Loads ObjFnData from resource using ObjectDataID

struct ObjectDataID {
    unsigned int namespaceID;
    unsigned short resourceID;
};

extern void* Load_ObjFnData_From_Resource(void*, unsigned int, unsigned short);

class ObjFnTableQuickData {
public:
    void* vtable;
    ObjectDataID id;
    void* fnData;
    int refcount;
    
    int LoadFromDataID(ObjectDataID& dataID) {
        id = dataID;
        void* result = Load_ObjFnData_From_Resource(this, dataID.namespaceID, dataID.resourceID);
        return (result == 0) ? -1 : 0;
    }
};
