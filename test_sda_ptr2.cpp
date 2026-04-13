// test file for SDA pointer load pattern
extern char g_cSoundPlayer[];

int cSoundPlayer_GetSFXVolume() {
    register char* ptr asm("r11") = *(char**)g_cSoundPlayer;
    return ptr[28];
}
