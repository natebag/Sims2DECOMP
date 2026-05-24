// 0x801B6CC0 G2DTarget::SetupDialogData(UIDialog (832 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; mr 31,3; lwz 4,0x8(29); stw 4,0xa0(31); cmplwi 4,3; ble 0f; lis 3,-32705; addi 3,3,4096; crxor 6,6,6; bl _s801B6CC0_0; 0:; lwz 0,0x4c(29); cmpwi 0,3; stw 0,0x11c(31); beq 2f; lis 30,-32705; addi 3,30,3292; bl _s801B6CC0_1; lwz 0,0x11c(31); stw 3,0x130(31); cmpwi 0,1; bne 1f; li 0,0; addi 3,30,3292; stw 0,0x9c(31); li 4,0; bl _s801B6CC0_2; b 3f; 1:; cmpwi 0,2; bne 3f; li 0,1; addi 3,30,3292; stw 0,0x9c(31); li 4,1; bl _s801B6CC0_3; b 3f; 2:; li 0,2; stw 0,0x9c(31); 3:; lwz 4,0x0(29); stw 4,0xa4(31); cmplwi 4,3; ble 4f; lis 3,-32705; addi 3,3,4140; crxor 6,6,6; bl _s801B6CC0_4; 4:; lwz 4,0xc(29); lwz 0,0xa4(31); stw 4,0xac(31); cmpwi 0,0; bne 5f; cmpwi 4,1; beq 5f; lis 3,-32705; addi 3,3,4204; crxor 6,6,6; bl _s801B6CC0_5; li 0,1; stw 0,0xac(31); 5:; lwz 4,0x4(29); lwz 5,0xa4(31); stw 4,0xa8(31); cmpwi 5,0; beq 6f; cmpw 4,5; blt 6f; lis 3,-32705; addi 3,3,4284; crxor 6,6,6; bl _s801B6CC0_6; 6:; lwz 4,0xac(31); cmplwi 4,3; ble 7f; lis 3,-32705; addi 3,3,4368; crxor 6,6,6; bl _s801B6CC0_7; 7:; lwz 0,0x10(29); li 9,1; cmpwi 0,0; bne 8f; li 9,0; 8:; stw 9,0xb4(31); li 9,1; lwz 0,0x14(29); cmpwi 0,0; bne 9f; li 9,0; 9:; li 0,0; stw 9,0xb8(31); stw 0,0xbc(31); li 9,1; lwz 0,0x1c(29); cmpwi 0,0; bne 10f; li 9,0; 10:; stw 9,0xc0(31); li 9,1; lwz 0,0x20(29); cmpwi 0,0; bne 11f; li 9,0; 11:; stw 9,0xc4(31); li 9,1; lwz 0,0x24(29); cmpwi 0,0; bne 12f; li 9,0; 12:; addi 30,29,40; stw 9,0xc8(31); mr 3,30; bl _s801B6CC0_8; cmpwi 3,0; bne 13f; lis 4,-32705; addi 3,31,252; addi 4,4,-8284; bl _s801B6CC0_9; b 14f; 13:; mr 4,30; addi 3,31,252; bl _s801B6CC0_10; 14:; addi 4,29,44; addi 3,31,256; bl _s801B6CC0_11; addi 30,31,260; addi 4,29,48; mr 3,30; bl _s801B6CC0_12; mr 3,30; bl _s801B6CC0_13; cmpwi 3,0; bne 15f; lwz 0,0xa4(31); cmpwi 0,0; ble 15f; lis 3,-32705; addi 3,3,4428; crxor 6,6,6; bl _s801B6CC0_14; 15:; addi 30,31,264; addi 4,29,52; mr 3,30; bl _s801B6CC0_15; mr 3,30; bl _s801B6CC0_16; cmpwi 3,0; bne 16f; lwz 0,0xa4(31); cmpwi 0,1; ble 16f; lis 3,-32705; addi 3,3,4504; crxor 6,6,6; bl _s801B6CC0_17; 16:; addi 30,31,268; addi 4,29,56; mr 3,30; bl _s801B6CC0_18; mr 3,30; bl _s801B6CC0_19; cmpwi 3,0; bne 17f; lwz 0,0xa4(31); cmpwi 0,2; ble 17f; lis 3,-32705; addi 3,3,4580; crxor 6,6,6; bl _s801B6CC0_20; 17:; lwz 3,0x3c(29); li 0,0; sth 0,0xd2(31); stw 3,0xcc(31); cmpwi 3,0; sth 0,0xd0(31); beq 18f; lhz 9,0x4a(29); sth 9,0xd2(31); lhz 0,0x48(29); sth 0,0xd0(31); bl _s801B6CC0_21; lwz 0,0x0(31); lis 9,-32705; lwz 5,0xcc(31); addi 4,9,2724; cmpwi 0,0; beq 18f; lwz 3,0x1c(31); cmpwi 3,0; beq 18f; lwz 6,0x7c(31); li 7,0; bl _s801B6CC0_22; 18:; addi 0,29,112; addi 9,29,80; addi 11,29,96; stw 0,0x118(31); stw 9,0x110(31); stw 11,0x114(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s801B6CC0_0();
extern "C" void _s801B6CC0_1();
extern "C" void _s801B6CC0_2();
extern "C" void _s801B6CC0_3();
extern "C" void _s801B6CC0_4();
extern "C" void _s801B6CC0_5();
extern "C" void _s801B6CC0_6();
extern "C" void _s801B6CC0_7();
extern "C" void _s801B6CC0_8();
extern "C" void _s801B6CC0_9();
extern "C" void _s801B6CC0_10();
extern "C" void _s801B6CC0_11();
extern "C" void _s801B6CC0_12();
extern "C" void _s801B6CC0_13();
extern "C" void _s801B6CC0_14();
extern "C" void _s801B6CC0_15();
extern "C" void _s801B6CC0_16();
extern "C" void _s801B6CC0_17();
extern "C" void _s801B6CC0_18();
extern "C" void _s801B6CC0_19();
extern "C" void _s801B6CC0_20();
extern "C" void _s801B6CC0_21();
extern "C" void _s801B6CC0_22();

struct G2DTarget {
    void SetupDialogData_UIDialog();
};

void G2DTarget::SetupDialogData_UIDialog() {
}
