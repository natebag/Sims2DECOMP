// 0x8003AFCC (8 bytes) — lbz r3, 0xB(r3); blr

class FlashPiMenu {
public:
    char _pad[0xB];
    unsigned char m_playerId;

    unsigned char GetPlayerId();
};

unsigned char FlashPiMenu::GetPlayerId() {
    return m_playerId;
}
