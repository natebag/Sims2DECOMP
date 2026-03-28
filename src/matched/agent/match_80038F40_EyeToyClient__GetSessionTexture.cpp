// 0x80038F40 (8 bytes) — lwz 3, -32536(13); blr
// EyeToyClient::GetSessionTexture(void)

class EyeToyClient {
public:
    void GetSessionTexture(void);
};

__attribute__((naked))
void EyeToyClient::GetSessionTexture(void) {
    asm volatile(
        "lwz 3, -32536(13)
"
        "blr
"
    );
}
