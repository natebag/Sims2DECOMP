extern char gSoundMode[4];
extern "C" void updateMode(void*);
void cBoxX_UpdateGameMode(void* self) {
    if (*(int*)gSoundMode) {
        updateMode((char*)self + 0x30);
    }
}
