/* QuickDataSoundInfo::AddRef(void) - 0x80145804 - 20 bytes */

class QuickDataSoundInfo {
public:
    char _pad[0x58];
    int m_refCount;

    int AddRef(void);
};

int QuickDataSoundInfo::AddRef(void) {
    return ++m_refCount;
}
