/* EyeToyClient::SaveSessionToSlot(int) at 0x80038EEC (84B) */

extern int g_hasEyeToyData;

struct ETexture;

ETexture *EyeToyClient_GetSessionTexture(void);
void EyeToyClient_WriteTextureToRepSlot(int slot, ETexture *tex, int imageType);

void EyeToyClient_SaveSessionToSlot(int slot) {
    if (g_hasEyeToyData == 0) {
        return;
    }
    ETexture *tex = EyeToyClient_GetSessionTexture();
    if (tex == 0) {
        return;
    }
    tex = EyeToyClient_GetSessionTexture();
    EyeToyClient_WriteTextureToRepSlot(slot, tex, 1);
}
