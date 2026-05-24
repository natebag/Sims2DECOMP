// 0x801F6708 Room::Room(unsigned (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 5,0; mr 3,4; cmpwi 0,0; beq 0f; li 5,1; 0:; lis 4,-32704; addi 4,4,-30836; crxor 6,6,6; bl _s801F6708_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x84(3); addi 9,13,-28708; mr 3,4; rlwinm 0,0,2,0,29; lis 4,-32704; lwzx 5,9,0; addi 4,4,-30836; crxor 6,6,6; bl _s801F6708_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x84(3); addi 9,13,-28700; mr 3,4; rlwinm 0,0,2,0,29; lis 4,-32704; lwzx 5,9,0; addi 4,4,-30836; crxor 6,6,6; bl _s801F6708_2; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s801F6708_0();
extern "C" void _s801F6708_1();
extern "C" void _s801F6708_2();

struct Room {
    void Room();
};

void Room::Room() {
}
