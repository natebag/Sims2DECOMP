#define g_cSoundPlayer (*(char**)0x80475f14)
int cSoundPlayer_GetSFXVolume() {
    return g_cSoundPlayer[28];
}
