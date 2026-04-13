// 0x8039E470 EFenceWall::SafeDelete(void) (64B)

struct EFenceWallBase {
    char _pad[0x3C];
};

struct EFenceWall : EFenceWallBase {
    virtual ~EFenceWall();
    static void SafeDelete(EFenceWall* p);
};

void EFenceWall::SafeDelete(EFenceWall* p) {
    if (p) {
        delete p;
    }
}
