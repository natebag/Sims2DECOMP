// 0x8001EAA4 (8 bytes) — lwz r3, 0x4(r3); blr

class ESimsCam {
public:
    int _pad0;
    int m_playerId;  // 0x004

    int GetPlayerId();
};

int ESimsCam::GetPlayerId() {
    return m_playerId;
}
