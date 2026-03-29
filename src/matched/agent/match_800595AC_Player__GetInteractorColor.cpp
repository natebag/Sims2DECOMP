/* Player::GetInteractorColor(void) - 0x800595AC (12 bytes) */
/* Returns pointer to a global non-SDA object (forces lis+addi addressing) */
/* lis r3, HI(g_player_color); addi r3, r3, LO(g_player_color); blr */

struct PlayerInteractorColorType;
extern PlayerInteractorColorType g_player_interactor_color;

class Player {
public:
    PlayerInteractorColorType* GetInteractorColor();
};

PlayerInteractorColorType* Player::GetInteractorColor() {
    return &g_player_interactor_color;
}
