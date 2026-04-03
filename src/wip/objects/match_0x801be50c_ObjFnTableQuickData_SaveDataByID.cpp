// VERIFIED MATCH - 0x801be50c (100 bytes)
// ObjFnTableQuickData::SaveDataByID(ObjectDataID &)
// Saves ObjFnData to resource using ObjectDataID

struct ObjectDataID {
    unsigned int namespaceID;
    unsigned short resourceID;
};

extern int Save_ObjFnData_To_Resource(void*, unsigned int, unsigned short);

class ObjFnTableQuickData {
public:
    void* vtable;
    ObjectDataID id;
    void* fnData;
    int refcount;
    
    int SaveDataByID(ObjectDataID& dataID) {
        int result = Save_ObjFnData_To_Resource(this, dataID.namespaceID, dataID.resourceID);
        if (result != 0) {
            id = dataID;
        }
        return result;
    }
};
