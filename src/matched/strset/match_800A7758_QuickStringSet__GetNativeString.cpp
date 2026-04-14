// 0x800A7758 match_800A7758_QuickStringSet__GetNativeString (16b)
// FLAGS: -fno-schedule-insns
/* QuickStringSet::GetNativeString(int, char*) at 0x800A7758 (16B) */

class QuickStringSet {
public:
    void* _pad0;
    void* m_locInfo;
    void* m_string;

    char* GetNativeString(int idx, char* buf);
};

char* QuickStringSet::GetNativeString(int idx, char* buf) {
    if (m_string) {
        return 0;
    }
    return 0;
}
