// EEngine::GetMinRetraces(void)
// 0x802E2E38 | 24 bytes
// lwz r0,8(r3) | cmpwi r0,0 | li r3,1 | beqlr | lwz r3,G_minRetraces | blr
// If field_008 is zero, return 1, else return global min retraces

extern int G_minRetraces;

class EEngine {
public:
    int m_pad0;
    int m_pad4;
    int m_bActive;  // offset 8
    int GetMinRetraces();
};

int EEngine::GetMinRetraces() {
    if (m_bActive == 0) return 1;
    return G_minRetraces;
}
