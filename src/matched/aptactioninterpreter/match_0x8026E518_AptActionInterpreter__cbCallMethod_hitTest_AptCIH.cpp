// 0x8026E518 AptActionInterpreter::cbCallMethod_hitTest(AptCIH (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stfd f30,0x40(1); stfd f31,0x48(1); stmw 27,0x2c(1); stw 0,0x54(1); mr 28,4; mr 27,3; cmpwi 28,1; lwz 29,-22936(13); beq 4f; ble 4f; lis 30,-32694; addi 31,30,-16032; lwz 9,-16032(30); lwz 0,0x8(31); rlwinm 9,9,2,0,29; add 9,9,0; lwz 3,-4(9); bl _s8026E518_0; lwz 9,-16032(30); fmr f30,f1; lwz 0,0x8(31); addi 9,9,-1; rlwinm 9,9,2,0,29; add 9,9,0; lwz 3,-4(9); bl _s8026E518_1; fmr f31,f1; cmpwi 28,2; ble 0f; lwz 9,-16032(30); lwz 0,0x8(31); addi 9,9,-2; rlwinm 9,9,2,0,29; add 9,9,0; lwz 3,-4(9); bl _s8026E518_2; 0:; mr 3,27; addi 4,1,8; bl _s8026E518_3; lfs f0,0x8(1); fcmpu 0,f30,f0; blt 4f; lfs f0,0x10(1); fcmpu 0,f30,f0; bgt 4f; lfs f0,0xc(1); fcmpu 0,f31,f0; blt 4f; lfs f0,0x14(1); fcmpu 0,f31,f0; bgt 4f; lwz 3,-26908(13); li 31,1; cmpwi 3,0; beq 3f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 1f; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 2f; 1:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 2:; stw 31,0xc(3); mr 29,3; b 4f; 3:; lwz 3,-23020(13); li 4,16; bl _s8026E518_4; mr 30,3; li 4,7; mr 29,30; bl _s8026E518_5; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; stw 9,0x8(30); 4:; mr 3,29; lwz 0,0x54(1); mtspr 8,0; lmw 27,0x2c(1); lfd f30,0x40(1); lfd f31,0x48(1); addi 1,1,80"

extern "C" void _s8026E518_0();
extern "C" void _s8026E518_1();
extern "C" void _s8026E518_2();
extern "C" void _s8026E518_3();
extern "C" void _s8026E518_4();
extern "C" void _s8026E518_5();

struct AptActionInterpreter {
    void cbCallMethod_hitTest_AptCIH();
};

void AptActionInterpreter::cbCallMethod_hitTest_AptCIH() {
}
