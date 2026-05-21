// 0x801E926C GetVar_LockedStatus::Handler(char*) (68B)

extern char* strcpy(char* dst, char* src);

extern char s_lockedStr[];     // 0x803F8798
extern char s_unlockedStr[];   // 0x803F879C

class GetVar_LockedStatus {
public:
    char pad_00[12];
    int  m_locked;     // 12
    char* Handler(char* dst);
};

char* GetVar_LockedStatus::Handler(char* dst) {
    char* src;
    if (m_locked != 0) {
        src = s_lockedStr;
    } else {
        src = s_unlockedStr;
    }
    return strcpy(dst, src);
}
