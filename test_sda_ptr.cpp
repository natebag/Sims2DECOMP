// test file for SDA pointer load pattern
extern char g_cSoundPlayer[];

int cSoundPlayer_GetSFXVolume() {
    char* ptr = *(char**)g_cSoundPlayer;
    return ptr[28];
}

int cSoundPlayer_GetMusicVolume() {
    char* ptr = *(char**)g_cSoundPlayer;
    return ptr[29];
}

int cSoundPlayer_GetVOXVolume() {
    char* ptr = *(char**)g_cSoundPlayer;
    return ptr[40];
}

int cSoundPlayer_GetAmbientVolume() {
    char* ptr = *(char**)g_cSoundPlayer;
    return ptr[41];
}
