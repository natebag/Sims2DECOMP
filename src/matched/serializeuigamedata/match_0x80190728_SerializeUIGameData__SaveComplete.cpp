// 0x80190728 (60B) SerializeUIGameData::SaveComplete(NghResFile::SectionID, NghResFile::SaveRecord &)

class NghResFile {
public:
    struct SectionID {};
    struct SaveRecord {};
};

extern "C" void* MainHeap();
extern "C" void helper_EAHeap_Free(void* heap, void* p);
extern "C" void* g_serializeUIGameDataPtr;  // SDA r13-31448

class SerializeUIGameData {
public:
    static void SaveComplete(NghResFile::SectionID id, NghResFile::SaveRecord& rec);
};

void SerializeUIGameData::SaveComplete(NghResFile::SectionID id, NghResFile::SaveRecord& rec) {
    if (g_serializeUIGameDataPtr != 0) {
        helper_EAHeap_Free(MainHeap(), g_serializeUIGameDataPtr);
        g_serializeUIGameDataPtr = 0;
    }
}
