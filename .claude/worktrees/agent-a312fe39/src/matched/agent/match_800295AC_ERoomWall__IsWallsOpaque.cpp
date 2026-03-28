// 0x800295AC (16 bytes)
// slwi r4, r4, 2; addi r3, r3, 0x2C; lwzx r3, r3, r4; blr

class ERoomWall {
public:
    int IsWallsOpaque(int index);
};

__attribute__((naked))
int ERoomWall::IsWallsOpaque(int index) {
    asm volatile(
        "slwi 4, 4, 2\n"
        "addi 3, 3, 0x2C\n"
        "lwzx 3, 3, 4\n"
        "blr\n"
    );
}
