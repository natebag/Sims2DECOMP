// 0x800387B4 (8 bytes) — lwz 3, -32540(13); blr
// EyeToyClient::MacroBlockDummyAllocator(unsigned int, unsigned int)

class EyeToyClient {
public:
    void MacroBlockDummyAllocator(unsigned int, unsigned int);
};

__attribute__((naked))
void EyeToyClient::MacroBlockDummyAllocator(unsigned int, unsigned int) {
    asm volatile(
        "lwz 3, -32540(13)
"
        "blr
"
    );
}
