// 0x800AB558 (8 bytes) — lwz 3, -31848(13); blr
// Behavior::GetGlobNamespaceID(void)

class Behavior {
public:
    void GetGlobNamespaceID(void);
};

__attribute__((naked))
void Behavior::GetGlobNamespaceID(void) {
    asm volatile(
        "lwz 3, -31848(13)\n"
        "blr\n"
    );
}
