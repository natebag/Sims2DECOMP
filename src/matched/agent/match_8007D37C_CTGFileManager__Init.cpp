// 0x8007D37C (8 bytes) — li 3, 1; blr
// CTGFileManager::Init(void)

class CTGFileManager {
public:
    void Init(void);
};

__attribute__((naked))
void CTGFileManager::Init(void) {
    asm volatile(
        "li 3, 1
"
        "blr
"
    );
}
