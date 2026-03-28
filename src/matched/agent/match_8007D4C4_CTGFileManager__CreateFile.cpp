// 0x8007D4C4 (8 bytes) — li 3, 1; blr
// CTGFileManager::CreateFile(char *)

class CTGFileManager {
public:
    void CreateFile(char *);
};

__attribute__((naked))
void CTGFileManager::CreateFile(char *) {
    asm volatile(
        "li 3, 1\n"
        "blr\n"
    );
}
