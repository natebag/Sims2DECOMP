// 0x803B3484 stack<int, (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 29,0x6c(1); stw 0,0x7c(1); mr 31,3; mr 29,4; lwz 30,0x0(31); addi 9,31,16; lwz 5,0x4(31); lwz 6,0x8(31); li 4,2; lwz 7,0xc(31); stw 30,0x8(1); stw 5,0xc(1); stw 6,0x10(1); stw 7,0x14(1); lwz 0,0x4(9); lwz 10,0x10(31); lwz 8,0xc(9); lwz 11,0x8(9); stw 0,0x5c(1); stw 0,0x1c(1); stw 0,0x3c(1); stw 30,0x48(1); stw 5,0x4c(1); stw 6,0x50(1); stw 7,0x54(1); stw 10,0x58(1); stw 11,0x60(1); stw 8,0x64(1); stw 10,0x18(1); stw 11,0x20(1); stw 8,0x24(1); stw 30,0x28(1); stw 5,0x2c(1); stw 6,0x30(1); stw 7,0x34(1); stw 10,0x38(1); stw 11,0x40(1); stw 8,0x44(1); bl _s803B3484_0; andi. 0,29,1; beq 0f; mr 3,31; bl _s803B3484_1; 0:; lwz 0,0x7c(1); mtspr 8,0; lmw 29,0x6c(1); addi 1,1,120"
extern "C" void _s803B3484_0();
extern "C" void _s803B3484_1();
extern "C" void f_803B3484() {}
