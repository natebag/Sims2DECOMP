// VERIFIED MATCH - 0x801be278 (96 bytes)
// ObjFnTableQuickData::SetTreeID(ObjEntryPoint, short)
// Sets the tree ID in the function data at offset

struct ObjEntryPoint {
    int index;
};

class ObjFnTableQuickData {
public:
    void* fnData;
    
    void SetTreeID(ObjEntryPoint entry, short treeID) {
        if (fnData == 0) {
            return;
        }
        int offset = entry.index * 2 + 4;
        short* ptr = (short*)((char*)fnData + offset);
        *ptr = treeID;
    }
};
