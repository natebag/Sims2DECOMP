// 0x8035D2E8 ERotDecomp::Init(EBitArray (384 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 0,4; li 9,0; mr 30,5; stb 9,0x21(31); mr 3,0; mr 4,30; stw 0,0x0(31); li 5,20; addi 30,30,20; bl _s8035D2E8_0; stw 3,0x18(31); mr 4,30; lwz 3,0x0(31); li 5,5; addi 30,30,5; bl _s8035D2E8_1; stb 3,0x1e(31); mr 4,30; lwz 3,0x0(31); li 5,5; addi 30,30,5; bl _s8035D2E8_2; extsb 4,3; stb 3,0x20(31); cmpwi 4,0; beq 0f; lwz 3,0x0(31); bl _s8035D2E8_3; stfs f1,0x28(31); b 1f; 0:; lis 9,-32702; lfs f0,0x2d80(9); stfs f0,0x28(31); 1:; lwz 3,0x0(31); mr 4,30; li 5,5; bl _s8035D2E8_4; extsb 0,3; stb 3,0x1f(31); cmpwi 0,0; bne 2f; li 0,32; stb 0,0x1f(31); 2:; lbz 4,0x1f(31); addi 30,30,5; lwz 3,0x0(31); li 29,0; extsb 4,4; bl _s8035D2E8_5; lbz 10,0x1f(31); li 8,0; lbz 9,0x1e(31); lbz 11,0x20(31); extsb 10,10; rlwinm 0,10,1,0,30; extsb 9,9; extsb 11,11; add 0,0,10; add 9,9,11; lwz 10,0x18(31); add 9,9,0; stfs f1,0x24(31); addi 9,9,1; stw 30,0x4(31); sth 9,0x1c(31); cmpw 29,10; stw 8,0x10(31); bge 4f; 3:; lha 4,0x1c(31); lwz 0,0x4(31); mullw 4,29,4; lbz 5,0x1e(31); lwz 3,0x0(31); addi 29,29,1; extsb 5,5; add 4,0,4; bl _s8035D2E8_6; lwz 0,0x10(31); addi 3,3,1; lwz 9,0x18(31); add 0,0,3; stw 0,0x10(31); cmpw 29,9; blt 3b; 4:; mr 3,31; bl _s8035D2E8_7; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8035D2E8_0();
extern "C" void _s8035D2E8_1();
extern "C" void _s8035D2E8_2();
extern "C" void _s8035D2E8_3();
extern "C" void _s8035D2E8_4();
extern "C" void _s8035D2E8_5();
extern "C" void _s8035D2E8_6();
extern "C" void _s8035D2E8_7();
extern "C" void f_8035D2E8() {}
