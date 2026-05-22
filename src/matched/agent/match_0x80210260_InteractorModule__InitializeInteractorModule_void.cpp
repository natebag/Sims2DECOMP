// 0x80210260 InteractorModule::InitializeInteractorModule(void) (516 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 28,0x40(1); stw 0,0x54(1); lis 9,-32697; li 0,-1; lwz 11,0x5c70(9); addi 31,1,56; stw 0,0x38(1); li 9,1; stw 0,0x4(31); cmpwi 11,0; beq 0f; li 9,2; 0:; stw 9,0x38(1); li 0,2; stw 0,0x4(31); bl _s80210260_0; mr 4,31; bl _s80210260_1; lis 11,-32697; lis 9,-32698; lbz 0,0x5e84(11); addi 9,9,-10560; addi 11,1,8; mr 29,11; stw 9,0x10(11); cmpwi 0,1; beq 1f; li 0,0; 1:; stw 0,0x8(1); li 0,0; stw 0,0x10(1); stw 0,0xc(1); stw 0,0x14(1); bl _s80210260_2; lwz 31,0x4(29); mr 30,3; mr 4,31; bl _s80210260_3; cmpwi 3,0; beq 2f; li 0,1; lbz 9,0x3c(30); slw 0,0,31; rlwinm 0,0,0,24,31; and. 11,9,0; bne 2f; or 0,0,9; li 3,20; stb 0,0x3c(30); bl _s80210260_4; lwz 11,0xc(29); lis 9,-32698; lwz 8,0x4(29); addi 9,9,-10560; lwz 10,0x8(29); rlwinm 7,31,3,0,28; lwz 0,0x8(1); stw 9,0x10(3); stw 8,0x4(3); stw 10,0x8(3); stw 11,0xc(3); stw 0,0x0(3); stw 9,0x20(1); lwz 11,0x2c(30); stw 0,0x30(1); stw 3,0x34(1); add 9,11,7; stw 0,0x28(1); stw 3,0x2c(1); stwx 0,11,7; stw 3,0x4(9); 2:; lwz 0,0x38(1); cmpwi 0,2; bne 4f; lis 9,-32697; lbz 0,0x5e85(9); cmpwi 0,1; beq 3f; li 0,0; 3:; stw 0,0x8(1); li 28,1; stw 28,0xc(1); bl _s80210260_5; lwz 31,0x4(29); mr 30,3; mr 4,31; bl _s80210260_6; cmpwi 3,0; beq 4f; slw 0,28,31; lbz 9,0x3c(30); rlwinm 0,0,0,24,31; and. 11,9,0; bne 4f; or 0,0,9; li 3,20; stb 0,0x3c(30); bl _s80210260_7; lwz 11,0xc(29); lis 9,-32698; lwz 8,0x4(29); addi 9,9,-10560; lwz 10,0x8(29); rlwinm 7,31,3,0,28; lwz 0,0x8(1); stw 9,0x10(3); stw 8,0x4(3); stw 10,0x8(3); stw 11,0xc(3); stw 0,0x0(3); stw 9,0x20(1); lwz 11,0x2c(30); stw 0,0x30(1); stw 3,0x34(1); add 9,11,7; stw 0,0x28(1); stw 3,0x2c(1); stwx 0,11,7; stw 3,0x4(9); 4:; lis 9,-32698; addi 9,9,-10560; stw 9,0x10(29); lwz 0,0x54(1); mtspr 8,0; lmw 28,0x40(1); addi 1,1,80"
extern "C" void _s80210260_0();
extern "C" void _s80210260_1();
extern "C" void _s80210260_2();
extern "C" void _s80210260_3();
extern "C" void _s80210260_4();
extern "C" void _s80210260_5();
extern "C" void _s80210260_6();
extern "C" void _s80210260_7();
extern "C" void f_80210260() {}
