// 0x800594F4 Player::Player (24b)

struct Player {
    int f0;
    int f4;
    int f8;
    Player();
};

Player::Player() {
    Player* p = this;
    p->f0 = 0;
    p->f4 = 0;
    p->f8 = 0;
}
