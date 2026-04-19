/* ENgcRenderer::AddDrawSync(void) at 0x8033CE28 (52B) */

extern unsigned short gDrawSyncCounter;
extern "C" void GXSetDrawSync(unsigned short tag);

struct ENgcRenderer_ADS {
    unsigned short AddDrawSync();
};

unsigned short ENgcRenderer_ADS::AddDrawSync() {
    int next = gDrawSyncCounter + 1;
    gDrawSyncCounter = (unsigned short)next;
    GXSetDrawSync((unsigned short)next);
    return gDrawSyncCounter;
}
