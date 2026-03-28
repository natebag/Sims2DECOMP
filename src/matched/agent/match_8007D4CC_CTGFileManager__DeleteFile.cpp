// 0x8007D4CC (8 bytes) — li 3, 1; blr
// CTGFileManager::DeleteFile(char *)

class CTGFileManager {
public:
    void DeleteFile(char *);
};

__attribute__((naked))
void CTGFileManager::DeleteFile(char *) {
    asm volatile(
        "li 3, 1\n"
        "blr\n"
    );
}
