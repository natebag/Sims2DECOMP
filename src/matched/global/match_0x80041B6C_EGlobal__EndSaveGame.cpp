// PRAGMA_STUB: EGlobal::EndSaveGame(void)
// EGlobal::EndSaveGame(void)
// Address: 0x80041B6C | Size: 48 bytes
// FLAGS: -fno-elide-constructors

extern void* g_saveGameContext[];

extern "C" void EndSaveGameInner(void* ptr);

void EGlobal__EndSaveGame(void) {
    void* ctx = g_saveGameContext[0];
    if (ctx != 0) {
        EndSaveGameInner(ctx);
    }
}
