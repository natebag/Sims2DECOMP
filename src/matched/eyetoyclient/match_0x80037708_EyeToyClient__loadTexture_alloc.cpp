/* EyeToyClient::loadTexture_alloc(unsigned int, unsigned int) - 0x80037708 (8 bytes) */

extern void *g_eyeToyTextureBuffer;

struct EyeToyClient {
    static void* loadTexture_alloc(unsigned int, unsigned int);
};

void* EyeToyClient::loadTexture_alloc(unsigned int, unsigned int) {
    return g_eyeToyTextureBuffer;
}
