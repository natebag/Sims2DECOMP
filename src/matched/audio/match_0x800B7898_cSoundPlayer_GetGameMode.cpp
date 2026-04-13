// 0x800B7898 cSoundPlayer::GetGameMode (24b)
// FLAGS: -msdata=eabi -G 8

extern void* g_cSoundPlayer;

int cSoundPlayer_GetGameMode() {
    int result = 3;
    if (!g_cSoundPlayer) return result;
    result = ((int*)g_cSoundPlayer)[12];
    return result;
}
