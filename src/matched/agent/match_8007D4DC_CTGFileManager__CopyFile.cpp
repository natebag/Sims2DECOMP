// 0x8007D4DC (8 bytes) — li 3, 1; blr
// CTGFileManager::CopyFile(char *, char *)

class CTGFileManager {
public:
    void CopyFile(char *, char *);
};

__attribute__((naked))
void CTGFileManager::CopyFile(char *, char *) {
    asm volatile(
        "li 3, 1
"
        "blr
"
    );
}
