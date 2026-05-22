// 0x80058224 MorphUtilities::MorphLatticeOnBodyPart(unsigned (392 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 31,3; lis 9,-32707; lwz 11,0x0(31); rlwinm 30,4,2,0,29; lfs f0,0x3c50(9); li 0,0; lwzx 11,30,11; li 9,-1; mr 29,5; stw 0,0xc(1); li 28,0; stw 9,0x14(1); cmpwi 11,0; stfs f0,0x10(1); lis 27,-32707; stfs f0,0x8(1); beq 0f; lwz 0,0x120(11); cmpwi 0,0; bne 1f; 0:; li 3,0; b 6f; 1:; mr 3,31; addi 4,1,8; addi 5,1,12; addi 6,1,16; addi 7,1,20; bl _s80058224_0; lwz 9,0x0(31); lwzx 11,30,9; lwz 30,0x120(11); mr 3,30; bl _s80058224_1; cmplw 3,29; ble 2f; mr 3,30; mr 4,29; bl _s80058224_2; lwz 5,0xc(1); cmpw 5,3; bge 2f; lfs f1,0x8(1); mr 3,30; mr 4,29; li 28,1; bl _s80058224_3; 2:; lwz 0,0x14(1); cmpwi 0,0; blt 3f; mr 3,30; bl _s80058224_4; cmplw 3,29; ble 3f; mr 3,30; mr 4,29; bl _s80058224_5; lwz 5,0x14(1); cmpw 5,3; bge 3f; lfs f1,0x10(1); mr 3,30; mr 4,29; li 28,1; bl _s80058224_6; 3:; li 31,0; 4:; lwz 0,0xc(1); cmpw 31,0; beq 5f; lwz 0,0x14(1); cmpw 31,0; beq 5f; mr 3,30; bl _s80058224_7; cmplw 3,29; ble 5f; mr 3,30; mr 4,29; bl _s80058224_8; cmpw 31,3; bge 5f; lfs f1,0x3c50(27); mr 3,30; mr 4,29; mr 5,31; bl _s80058224_9; 5:; addi 31,31,1; cmpwi 31,2; ble 4b; mr 3,28; 6:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s80058224_0();
extern "C" void _s80058224_1();
extern "C" void _s80058224_2();
extern "C" void _s80058224_3();
extern "C" void _s80058224_4();
extern "C" void _s80058224_5();
extern "C" void _s80058224_6();
extern "C" void _s80058224_7();
extern "C" void _s80058224_8();
extern "C" void _s80058224_9();
extern "C" void f_80058224() {}
