/* QuickDataSoundInfo::AddRef(void) - 0x80145804 - 20 bytes */

struct QuickDataSoundInfo {
    char _pad[88];
    int m_refCount;

    int AddRef();
};

int QuickDataSoundInfo::AddRef() {
    return ++m_refCount;
}
