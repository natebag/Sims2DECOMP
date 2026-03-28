// 0x800EC084 (8 bytes) — lha 3, 4(3); blr
// GlobalConstantsClient::GetID(void)

class GlobalConstantsClient {
public:
    void GetID(void);
};

__attribute__((naked))
void GlobalConstantsClient::GetID(void) {
    asm volatile(
        "lha 3, 4(3)
"
        "blr
"
    );
}
