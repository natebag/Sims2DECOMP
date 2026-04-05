// EGlobal::EndSaveGame(void)
// Address: 0x80041B6C | Size: 48 bytes

// External function at 0x80024E04
extern "C" void EndSaveGameInner(void* ptr);

void EGlobal__EndSaveGame(void) {
    // Access global at 0x80475E94 via SDA
    register char* r13 asm("r13");
    void** g_saveGameContext = (void**)(r13 - 0x5E94);
    
    if (*g_saveGameContext != 0) {
        EndSaveGameInner(*g_saveGameContext);
    }
}
