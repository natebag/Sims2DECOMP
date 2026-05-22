// 0x803AE9C0 _Rb_tree<pair<unsigned (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 27,4; mr 28,6; lwz 0,0x4(27); mr 26,3; mr 31,7; cmpw 28,0; beq 2f; cmpwi 8,0; addi 29,31,4; bne 4f; cmpwi 5,0; bne 2f; lwz 9,0x0(31); li 30,0; lwz 0,0x10(28); cmplw 9,0; blt 0f; cmplw 0,9; blt 1f; mr 3,29; addi 4,28,20; bl _s803AE9C0_0; cmpwi 3,0; beq 1f; 0:; li 30,1; 1:; cmpwi 30,0; beq 4f; 2:; li 3,32; bl _s803AE9C0_1; lwz 0,0x0(31); mr 30,3; addi 3,30,20; addi 4,31,4; stw 0,0x10(30); addi 29,30,16; bl _s803AE9C0_2; lwz 0,0xc(31); stw 0,0xc(29); stw 30,0x8(28); lwz 9,0x4(27); cmpw 28,9; bne 3f; stw 30,0x4(28); lwz 9,0x4(27); b 5f; 3:; lwz 0,0x8(9); cmpw 28,0; bne 6f; stw 30,0x8(9); b 6f; 4:; li 3,32; bl _s803AE9C0_3; lwz 0,0x0(31); mr 30,3; mr 4,29; addi 3,30,20; stw 0,0x10(30); addi 29,30,16; bl _s803AE9C0_4; lwz 0,0xc(31); stw 0,0xc(29); stw 30,0xc(28); lwz 9,0x4(27); lwz 0,0xc(9); cmpw 28,0; bne 6f; 5:; stw 30,0xc(9); 6:; li 0,0; stw 28,0x4(30); stw 0,0xc(30); mr 3,30; stw 0,0x8(30); lwz 4,0x4(27); addi 4,4,4; bl _s803AE9C0_5; lwz 9,0x8(27); mr 3,26; addi 9,9,1; stw 9,0x8(27); stw 30,0x0(26); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s803AE9C0_0();
extern "C" void _s803AE9C0_1();
extern "C" void _s803AE9C0_2();
extern "C" void _s803AE9C0_3();
extern "C" void _s803AE9C0_4();
extern "C" void _s803AE9C0_5();
extern "C" void f_803AE9C0() {}
