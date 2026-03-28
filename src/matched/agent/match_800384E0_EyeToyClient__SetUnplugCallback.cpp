// 0x800384E0 (8 bytes) — stw 3, -32528(13); blr
// EyeToyClient::SetUnplugCallback(void (*)(int))

class EyeToyClient {
public:
    void SetUnplugCallback(void (*)(int));
};

__attribute__((naked))
void EyeToyClient::SetUnplugCallback(void (*)(int)) {
    asm volatile(
        "stw 3, -32528(13)\n"
        "blr\n"
    );
}
