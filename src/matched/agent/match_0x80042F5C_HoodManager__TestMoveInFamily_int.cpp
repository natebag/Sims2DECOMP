// 0x80042F5C HoodManager::TestMoveInFamily(int, (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-328(1); mfspr 0,8; stmw 28,0x138(1); stw 0,0x14c(1); lwz 9,0x0(4); addi 29,3,1; addi 30,1,8; li 31,0; lwz 0,0xcc(9); lha 3,0xc8(9); mtspr 8,0; add 3,4,3; blrl; stw 31,0x8(1); li 0,-1; mr 28,3; addi 4,1,36; li 5,128; addi 3,1,28; stw 31,0xc(30); stw 0,0x10(30); stw 31,0x4(30); stw 31,0x8(30); bl _s80042F5C_0; lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0x194(9); lha 3,0x190(9); mtspr 8,0; add 3,11,3; blrl; mr 9,3; lwz 4,-32056(13); mr 5,29; mr 6,30; stw 29,0x70(9); bl _s80042F5C_1; lwz 31,0x14(1); subf. 28,31,28; bge 0f; lis 9,-32697; lwz 0,0x6188(9); cmpwi 0,0; beq 0f; li 28,0; 0:; cmpwi 28,0; li 3,-1; blt 1f; mr 3,28; 1:; lwz 0,0x14c(1); mtspr 8,0; lmw 28,0x138(1); addi 1,1,328"
extern "C" void _s80042F5C_0();
extern "C" void _s80042F5C_1();
extern "C" void f_80042F5C() {}
