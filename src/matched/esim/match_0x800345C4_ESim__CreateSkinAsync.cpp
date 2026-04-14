/* ESim::CreateSkinAsync(void) at 0x800345C4 (88B) */

struct ESim {
    char pad_00[0x3D8];
    int m_skinState;
    char pad_3DC[0x630 - 0x3DC];
    int m_skinHandle;

    int CreateSkinAsync(void);
    int HasQueuedOperation(void);
};

int ESim::CreateSkinAsync(void) {
    int result = HasQueuedOperation();
    if (result != 0) {
        return 0;
    }
    if (m_skinHandle != -1) {
        return 0;
    }
    m_skinHandle = result;
    m_skinState = 1;
    return 1;
}
