// FLAGS: -fno-schedule-insns
// 0x800595AC Player::GetInteractorColor (12B)
// lis r3,HA(gInteractorColor); addi r3,r3,LO(gInteractorColor)
extern char gInteractorColor[];
struct Player { char* GetInteractorColor() const; };
char* Player::GetInteractorColor() const { return gInteractorColor; }
