// VERIFIED MATCH - 0x801be2d8 (96 bytes)
// ObjFnTableQuickData::SetCheckTreeID(ObjEntryPoint, short)
// Sets the check tree ID in the function data at offset

struct ObjEntryPoint {
    int index;
};

class ObjFnTableQuickData {
public:
    void* fnData;
    
    void SetCheckTreeID(ObjEntryPoint entry, short checkTreeID) {
        if (fnData == 0) {
            return;
        }
        int offset = entry.index * 2 + 64;
        short* ptr = (short*)((char*)fnData + offset);
        *ptr = checkTreeID;
    }
};
