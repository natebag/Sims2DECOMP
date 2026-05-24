// 0x801374C4 Room::Room(unsigned (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 30,0x30(1); stw 0,0x3c(1); mr 30,3; li 0,0; stw 0,0x4(30); addi 9,30,12; stw 0,0x8(30); addi 11,30,20; stw 0,0x4(9); addi 10,30,28; stw 0,0x14(30); addi 8,30,36; stw 0,0x4(11); lis 7,-32706; stw 0,0x4(10); addi 11,30,44; stw 0,0x24(30); addi 9,1,32; stw 0,0x4(8); addi 6,30,56; lfs f0,-11424(7); stw 0,0x4(11); stfs f0,0x8(9); stfs f0,0x4(9); stfs f0,0x20(1); sth 4,0x0(30); lwz 11,0x20(1); lwz 10,0x8(9); lwz 8,0x4(9); stw 5,0x98(30); stw 11,0x38(30); sth 0,0x2(30); stw 0,0x90(30); stw 10,0x8(6); stw 8,0x4(6); stw 0,0x44(30); bl _s801374C4_0; mr 3,30; lwz 0,0x3c(1); mtspr 8,0; lmw 30,0x30(1); addi 1,1,56"

extern "C" void _s801374C4_0();

struct Room {
    void Room();
};

void Room::Room() {
}
