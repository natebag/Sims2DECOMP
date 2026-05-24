// 0x80058024 MorphUtilities::MorphLatticeOnHead(unsigned (512 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 28,0x18(1); stw 0,0x34(1); mr 31,3; fmr f31,f1; mr 29,5; cmpwi 4,12; beq 1f; cmplwi 4,12; bgt 0f; cmplwi 4,7; ble 1f; cmpwi 4,9; beq 1f; b 8f; 0:; cmplwi 4,18; blt 8f; cmplwi 4,20; ble 1f; cmpwi 4,24; bne 8f; 1:; lwz 11,0x0(31); rlwinm 9,4,2,0,29; lwzx 3,9,11; cmpwi 3,0; beq 8f; lwz 30,0x120(3); cmpwi 30,0; beq 8f; mr 3,30; bl _s80058024_0; cmpwi 3,0; ble 8f; mr 3,30; mr 4,29; bl _s80058024_1; cmpwi 3,6; ble 8f; lis 9,-32707; lis 28,-32707; lfs f13,0x3c48(9); fcmpu 0,f31,f13; bge 2f; fmr f31,f13; 2:; lis 9,-32707; lfs f0,0x3c4c(9); fcmpu 0,f31,f0; ble 3f; fmr f31,f0; 3:; li 0,0; li 9,-1; stw 0,0xc(1); mr 3,31; stw 9,0x14(1); fmr f1,f31; stfs f13,0x10(1); addi 4,1,8; stfs f13,0x8(1); addi 5,1,12; addi 6,1,16; addi 7,1,20; bl _s80058024_2; lwz 0,0xc(1); cmpwi 0,0; blt 4f; mr 3,30; bl _s80058024_3; cmplw 3,29; ble 4f; mr 3,30; mr 4,29; bl _s80058024_4; lwz 5,0xc(1); cmpw 5,3; bge 4f; lfs f1,0x8(1); mr 3,30; mr 4,29; bl _s80058024_5; 4:; lwz 0,0x14(1); cmpwi 0,0; blt 5f; mr 3,30; bl _s80058024_6; cmplw 3,29; ble 5f; mr 3,30; mr 4,29; bl _s80058024_7; lwz 5,0x14(1); cmpw 5,3; bge 5f; lfs f1,0x10(1); mr 3,30; mr 4,29; bl _s80058024_8; 5:; li 31,0; 6:; lwz 0,0xc(1); cmpw 31,0; beq 7f; lwz 0,0x14(1); cmpw 31,0; beq 7f; mr 3,30; bl _s80058024_9; cmplw 3,29; ble 7f; mr 3,30; mr 4,29; bl _s80058024_10; cmpw 31,3; bge 7f; lfs f1,0x3c48(28); mr 3,30; mr 4,29; mr 5,31; bl _s80058024_11; 7:; addi 31,31,1; cmpwi 31,6; ble 6b; 8:; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x18(1); lfd f31,0x28(1); addi 1,1,48"

extern "C" void _s80058024_0();
extern "C" void _s80058024_1();
extern "C" void _s80058024_2();
extern "C" void _s80058024_3();
extern "C" void _s80058024_4();
extern "C" void _s80058024_5();
extern "C" void _s80058024_6();
extern "C" void _s80058024_7();
extern "C" void _s80058024_8();
extern "C" void _s80058024_9();
extern "C" void _s80058024_10();
extern "C" void _s80058024_11();

struct MorphUtilities {
    void MorphLatticeOnHead();
};

void MorphUtilities::MorphLatticeOnHead() {
}
