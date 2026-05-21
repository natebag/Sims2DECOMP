// 0x8007D4E4 (88B) CTGFileManager::FileExists(char *)

extern char str_CTG_prefix[];  // 0x803D6858

extern "C" void* helper_0x802D74E8(char* filename, char* prefix);
extern "C" void helper_0x802D7534(void* file);

class CTGFileManager {
public:
    int FileExists(char* filename);
};

int CTGFileManager::FileExists(char* filename) {
    void* f = helper_0x802D74E8(filename, str_CTG_prefix);
    if (f != 0) {
        helper_0x802D7534(f);
    }
    return (f != 0) ? 1 : 0;
}
