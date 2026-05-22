// 0x80176AB4 UI3D::AddEntry(char (436 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 25,0x4c(1); stw 0,0x6c(1); lwz 31,0x8(3); mr 30,5; mr 26,6; mr 25,7; lwz 11,0x4(31); mr 10,9; stw 11,0x8(3); cmpwi 11,0; beq 0f; li 0,0; stw 0,0x0(11); 0:; lwz 0,0x0(3); cmpwi 0,0; bne 1f; stw 31,0x0(3); stw 0,0x0(31); stw 31,0x4(3); stw 0,0x4(31); b 2f; 1:; lwz 9,0x4(3); li 11,0; stw 31,0x4(9); lwz 0,0x4(3); stw 0,0x0(31); stw 31,0x4(3); stw 11,0x4(31); 2:; lwz 27,0x1c(31); stw 4,0x8(31); stw 8,0x20(31); cmpwi 27,0; stw 10,0x18(31); stw 30,0xc(31); stw 26,0x10(31); stw 25,0x14(31); bne 3f; bl _s80176AB4_0; lis 29,-32706; li 4,1264; li 5,16; li 6,0; li 7,0; bl _s80176AB4_1; lis 28,-32706; bl _s80176AB4_2; stw 3,0x1c(31); lis 8,-32706; stw 30,0x8(1); addi 9,1,24; stw 26,0xc(1); addi 10,1,40; stw 25,0x10(1); lis 30,-32706; stw 27,0x14(1); addi 11,1,56; lfs f0,0x239c(8); mr 5,9; lwz 3,0x1c(31); mr 7,11; stfs f0,0x18(1); addi 4,1,8; stfs f0,0x4(9); mr 6,10; stfs f0,0x8(9); stfs f0,0x28(1); stfs f0,0x4(10); stfs f0,0x8(10); lfs f13,0x23a0(30); stfs f0,0x38(1); stfs f0,0x4(11); stfs f13,0x8(11); bl _s80176AB4_3; lwz 3,0x1c(31); lfs f1,0x23a4(29); bl _s80176AB4_4; lfs f1,0x23a4(29); lwz 3,0x1c(31); bl _s80176AB4_5; lwz 3,0x1c(31); lfs f1,0x23a8(28); bl _s80176AB4_6; lfs f1,0x23a8(28); lwz 3,0x1c(31); bl _s80176AB4_7; lis 9,-32706; lis 11,-32706; lfs f2,0x23b0(9); li 4,0; lfs f1,0x23ac(11); lwz 3,0x1c(31); fmr f3,f2; bl _s80176AB4_8; lis 9,-32706; lwz 3,0x1c(31); lfs f1,0x23b4(9); fmr f2,f1; fmr f3,f2; bl _s80176AB4_9; lwz 4,0x20(31); lwz 3,0x1c(31); bl _s80176AB4_10; 3:; lwz 0,0x6c(1); mtspr 8,0; lmw 25,0x4c(1); addi 1,1,104"
extern "C" void _s80176AB4_0();
extern "C" void _s80176AB4_1();
extern "C" void _s80176AB4_2();
extern "C" void _s80176AB4_3();
extern "C" void _s80176AB4_4();
extern "C" void _s80176AB4_5();
extern "C" void _s80176AB4_6();
extern "C" void _s80176AB4_7();
extern "C" void _s80176AB4_8();
extern "C" void _s80176AB4_9();
extern "C" void _s80176AB4_10();
extern "C" void f_80176AB4() {}
