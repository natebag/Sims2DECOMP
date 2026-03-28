/* EyeToyClient::GetSessionTexture(void) - 0x80038F40 (8 bytes) */

struct ETexture;
extern ETexture *g_sessionTexture;

struct EyeToyClient {
    static ETexture* GetSessionTexture();
};

ETexture* EyeToyClient::GetSessionTexture() {
    return g_sessionTexture;
}
