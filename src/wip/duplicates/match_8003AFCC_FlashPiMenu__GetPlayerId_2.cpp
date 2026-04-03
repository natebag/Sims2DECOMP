// 0x8003AFCC (8 bytes)
class FlashPiMenu {
public:
    int GetPlayerId();
};

int FlashPiMenu::GetPlayerId() {
    return *(unsigned char*)((char*)this + 0xB);
}
