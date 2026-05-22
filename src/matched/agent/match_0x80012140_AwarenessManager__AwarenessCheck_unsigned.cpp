// 0x80012140 AwarenessManager::AwarenessCheck(unsigned (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 9,0x34(31); lwz 10,0x0(9); lwz 11,0x4(10); lha 3,0x1a8(11); lwz 0,0x1ac(11); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; lwz 9,0x38(31); lwz 0,0x638(9); cmpwi 0,0; beq 1f; lwz 11,-21496(13); lwz 9,0x0(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lis 9,-32707; lfs f0,-9088(9); fcmpu 0,f1,f0; beq 1f; lwz 0,0x0(31); xori 0,0,1; andi. 9,0,1; beq 0f; mr 3,31; mr 4,30; bl _s80012140_0; 0:; mr 4,30; mr 3,31; bl _s80012140_1; mr 3,31; bl _s80012140_2; mr 3,31; mr 4,30; bl _s80012140_3; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80012140_0();
extern "C" void _s80012140_1();
extern "C" void _s80012140_2();
extern "C" void _s80012140_3();
extern "C" void f_80012140() {}
