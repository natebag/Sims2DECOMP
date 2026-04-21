// 0x80328F44 (12B) EyeToyManager::ConvertHandleToInstancePtr(int)
// Add offset (in bytes) to SDA-global base pointer.

extern char* g_eyeToyBase;

class EyeToyManager {
public:
    static char* ConvertHandleToInstancePtr(int handle);
};

char* EyeToyManager::ConvertHandleToInstancePtr(int handle) {
    return g_eyeToyBase + handle;
}
