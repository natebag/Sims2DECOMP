// 0x801398BC SpacePartition::Deallocate(void) (840 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 26,0x28(1); stw 0,0x44(1); mr 31,3; addi 6,1,8; li 0,0; addi 8,6,8; stw 0,0x8(1); addi 7,31,20; stw 0,0x4(6); mr 30,6; stw 0,0x4(8); addi 28,1,24; lwz 0,0xc(31); lwz 9,0x10(31); lwz 11,0x8(1); lwz 10,0xc(1); stw 0,0x8(1); stw 9,0xc(1); stw 11,0xc(31); lwz 0,0x4(8); stw 10,0x10(31); stw 0,0x24(1); lwz 9,0x14(31); lwz 0,0x4(7); stw 9,0x8(6); stw 0,0x4(8); lwz 9,0x20(1); lwz 0,0x24(1); stw 9,0x14(31); stw 0,0x4(7); lwz 0,0x4(6); lwz 9,0x8(1); cmpw 9,0; beq 1f; 0:; addi 9,9,20; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(6); cmpwi 3,0; beq 3f; lwz 0,0xc(6); lis 9,-13108; ori 9,9,52429; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,20; cmplwi 4,128; ble 2f; bl _s801398BC_0; b 3f; 2:; bl _s801398BC_1; 3:; li 0,0; addi 8,30,8; stw 0,0x8(1); addi 7,31,84; stw 0,0x4(30); addi 29,31,36; stw 0,0x4(8); addi 27,31,52; lwz 0,0x50(31); addi 26,31,68; lwz 11,0x4c(31); lwz 9,0x8(1); lwz 10,0xc(1); stw 11,0x8(1); stw 0,0xc(1); stw 9,0x4c(31); lwz 0,0x4(8); stw 10,0x50(31); stw 0,0x4(28); lwz 9,0x54(31); lwz 0,0x4(7); stw 9,0x8(30); stw 0,0x4(8); lwz 9,0x18(1); lwz 0,0x1c(1); stw 9,0x54(31); stw 0,0x4(7); lwz 0,0x4(30); lwz 9,0x8(1); cmpw 9,0; beq 5f; 4:; addi 9,9,44; cmpw 9,0; bne 4b; 5:; lwz 3,0x0(30); cmpwi 3,0; beq 7f; lwz 0,0xc(30); lis 9,-17874; ori 9,9,35747; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,44; cmplwi 4,128; ble 6f; bl _s801398BC_2; b 7f; 6:; bl _s801398BC_3; 7:; li 0,0; addi 8,30,8; stw 0,0x8(1); stw 0,0x4(30); stw 0,0x4(8); lwz 0,0x20(31); lwz 9,0x1c(31); lwz 11,0x8(1); lwz 10,0xc(1); stw 9,0x8(1); stw 0,0xc(1); stw 11,0x1c(31); stw 10,0x20(31); lwz 11,0x24(31); lwz 0,0x4(8); stw 0,0x4(28); lwz 9,0x4(29); stw 11,0x8(30); stw 9,0x4(8); lwz 0,0x18(1); lwz 3,0x8(1); lwz 9,0x1c(1); stw 0,0x24(31); cmpwi 3,0; stw 9,0x4(29); beq 9f; lwz 0,0xc(30); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 8f; bl _s801398BC_4; b 9f; 8:; bl _s801398BC_5; 9:; li 0,0; addi 8,30,8; stw 0,0x8(1); stw 0,0x4(30); stw 0,0x4(8); lwz 0,0x30(31); lwz 9,0x2c(31); lwz 11,0x8(1); lwz 10,0xc(1); stw 9,0x8(1); stw 0,0xc(1); stw 11,0x2c(31); stw 10,0x30(31); lwz 11,0x34(31); lwz 0,0x4(8); stw 0,0x4(28); lwz 9,0x4(27); stw 11,0x8(30); stw 9,0x4(8); lwz 0,0x18(1); lwz 3,0x8(1); lwz 9,0x1c(1); stw 0,0x34(31); cmpwi 3,0; stw 9,0x4(27); beq 11f; lwz 0,0xc(30); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 10f; bl _s801398BC_6; b 11f; 10:; bl _s801398BC_7; 11:; li 0,0; addi 8,30,8; stw 0,0x8(1); stw 0,0x4(30); stw 0,0x4(8); lwz 0,0x40(31); lwz 9,0x3c(31); lwz 11,0x8(1); lwz 10,0xc(1); stw 9,0x8(1); stw 0,0xc(1); stw 11,0x3c(31); stw 10,0x40(31); lwz 11,0x44(31); lwz 0,0x4(8); stw 0,0x4(28); lwz 9,0x4(26); stw 11,0x8(30); stw 9,0x4(8); lwz 0,0x18(1); lwz 3,0x8(1); lwz 9,0x1c(1); stw 0,0x44(31); cmpwi 3,0; stw 9,0x4(26); beq 13f; lwz 0,0xc(30); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 12f; bl _s801398BC_8; b 13f; 12:; bl _s801398BC_9; 13:; lwz 0,0x44(1); mtspr 8,0; lmw 26,0x28(1); addi 1,1,64"

extern "C" void _s801398BC_0();
extern "C" void _s801398BC_1();
extern "C" void _s801398BC_2();
extern "C" void _s801398BC_3();
extern "C" void _s801398BC_4();
extern "C" void _s801398BC_5();
extern "C" void _s801398BC_6();
extern "C" void _s801398BC_7();
extern "C" void _s801398BC_8();
extern "C" void _s801398BC_9();

struct SpacePartition {
    void Deallocate();
};

void SpacePartition::Deallocate() {
}
