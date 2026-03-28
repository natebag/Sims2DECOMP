// 0x800EC07C (8 bytes) — lwz 3, -31848(13); blr
// GlobalConstantsClient::GetFileID(void)

class GlobalConstantsClient {
public:
    void GetFileID(void);
};

__attribute__((naked))
void GlobalConstantsClient::GetFileID(void) {
    asm volatile(
        "lwz 3, -31848(13)
"
        "blr
"
    );
}
