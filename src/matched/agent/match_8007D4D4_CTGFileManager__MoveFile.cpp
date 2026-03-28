// 0x8007D4D4 (8 bytes) — li 3, 1; blr
// CTGFileManager::MoveFile(char *, char *)

class CTGFileManager {
public:
    void MoveFile(char *, char *);
};

__attribute__((naked))
void CTGFileManager::MoveFile(char *, char *) {
    asm volatile(
        "li 3, 1\n"
        "blr\n"
    );
}
