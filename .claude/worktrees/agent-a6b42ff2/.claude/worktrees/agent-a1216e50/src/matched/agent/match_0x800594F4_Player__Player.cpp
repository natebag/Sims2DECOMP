/* 0x800594F4 (24 bytes) - Player::Player(void) */
class Player {
public:
    int m_field_000;
    int m_field_004;
    int m_field_008;
    Player(void);
};

Player::Player(void) {
    *(volatile int*)((char*)this + 8) = 0;
    *(volatile int*)((char*)this + 0) = 0;
    *(volatile int*)((char*)this + 4) = 0;
}
