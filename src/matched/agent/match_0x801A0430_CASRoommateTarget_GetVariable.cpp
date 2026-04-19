// 0x801A0430 (104B) CASRoommateTarget::GetVariable(char*)
// Allocates 32-byte buffer, zeros first byte, if key matches literal calls
// GetButtonStateString into buffer, returns buffer.

char* SimsAptMalloc(unsigned int size);
extern "C" int strcmp(const char*, const char*);

class CASRoommateTarget {
public:
    void GetButtonStateString(char* buf);
    char* GetVariable(char* key);
};

char* CASRoommateTarget::GetVariable(char* key) {
    char* buf = SimsAptMalloc(32);
    buf[0] = 0;
    if (strcmp("buttonStateString", key) == 0) {
        this->GetButtonStateString(buf);
    }
    return buf;
}
