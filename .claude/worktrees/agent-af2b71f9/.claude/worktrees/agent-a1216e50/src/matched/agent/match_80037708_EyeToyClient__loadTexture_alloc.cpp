// 0x80037708 (8 bytes) — lwz 3, -25032(13); blr
// EyeToyClient::loadTexture_alloc(unsigned int, unsigned int)

class EyeToyClient {
public:
    void loadTexture_alloc(unsigned int, unsigned int);
};

__attribute__((naked))
void EyeToyClient::loadTexture_alloc(unsigned int, unsigned int) {
    asm volatile(
        "lwz 3, -25032(13)\n"
        "blr\n"
    );
}
