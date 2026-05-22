// 0x802279FC __node_alloc<false, (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x5c(30); stfs f0,0xa4(30); oris 0,0,8; stw 9,0xa8(30); stw 0,0x5c(30); stfs f0,0x9c(30); stfs f0,0xa0(30); lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32; blr; stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 30,3; mr 31,4; bl _s802279FC_0; lwz 0,0x88(30); li 9,0; cmpwi 0,0; beq 0f; li 9,1; 0:; stb 9,0x8(1); addi 4,1,8; lwz 9,0x18(31); li 5,1; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0x7c(30); li 9,0; cmpwi 0,0; beq 1f; li 9,1; 1:; stb 9,0x8(1); addi 4,1,8; lwz 9,0x18(31); li 5,1; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0x80(30); li 9,0; cmpwi 0,0; beq 2f; li 9,1; 2:; stb 9,0x8(1); addi 4,1,8; lwz 9,0x18(31); li 5,1; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x18(31); addi 4,1,16; li 5,4; lfs f0,0x8c(30); lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; stfs f0,0x10(1); mtspr 8,0; blrl; addi 4,30,144; mr 3,31; bl _s802279FC_1; lwz 4,0x84(30); bl _s802279FC_2; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s802279FC_0();
extern "C" void _s802279FC_1();
extern "C" void _s802279FC_2();
extern "C" void f_802279FC() {}
