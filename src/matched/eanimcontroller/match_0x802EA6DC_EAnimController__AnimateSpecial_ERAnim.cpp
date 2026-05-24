// 0x802EA6DC EAnimController::AnimateSpecial(ERAnim (772 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 28,0x18(1); stw 0,0x34(1); mr 29,7; mr 30,4; lwz 9,0x10(29); fmr f31,f1; mr 28,5; mr 31,8; cmpwi 7,9,0; beq cr7,5f; lwz 0,0x0(6); andi. 11,0,16; bne 5f; ble cr7,0f; lwz 10,0x44(30); rlwinm 9,9,2,0,29; lis 11,-32702; lfsx f13,10,9; lfs f0,-4572(11); fcmpu 7,f13,f0; crnor 31,30,30; mfcr 3; rlwinm 3,3,0,31,31; b 2f; 0:; lwz 3,0xc(28); cmpwi 3,0; beq 1f; fmr f1,f31; bl _s802EA6DC_0; b 2f; 1:; li 3,1; 2:; cmpwi 3,0; beq 3f; lwz 0,0x0(31); rlwinm 0,0,0,29,27; b 4f; 3:; lwz 0,0x0(31); ori 0,0,8; 4:; stw 0,0x0(31); 5:; lwz 10,0x14(29); cmpwi 10,0; beq 8f; lwz 0,0x0(31); ori 0,0,32; stw 0,0x0(31); ble 6f; lwz 8,0x44(30); rlwinm 9,10,2,0,29; addi 11,10,1; lfsx f0,8,9; rlwinm 11,11,2,0,29; addi 10,10,2; stfs f0,0x2c(31); rlwinm 10,10,2,0,29; lwz 9,0x44(30); lfsx f0,9,11; stfs f0,0x30(31); lwz 9,0x44(30); lfsx f0,9,10; stfs f0,0x34(31); b 9f; 6:; lwz 4,0x10(28); cmpwi 4,0; beq 7f; addi 3,1,8; fmr f1,f31; bl _s802EA6DC_1; lwz 10,0x8(1); addi 9,1,8; lwz 8,0x8(9); addi 11,31,44; lwz 0,0x4(9); stw 10,0x2c(31); stw 8,0x8(11); stw 0,0x4(11); b 9f; 7:; lis 11,-32702; addi 9,1,8; lfs f0,-4568(11); addi 8,31,44; stfs f0,0x8(1); stfs f0,0x8(9); stfs f0,0x4(9); lwz 10,0x8(9); lwz 0,0x8(1); lwz 11,0x4(9); stw 0,0x2c(31); stw 10,0x8(8); stw 11,0x4(8); lwz 0,0x0(31); rlwinm 0,0,0,27,25; stw 0,0x0(31); b 9f; 8:; lis 11,-32702; addi 9,1,8; lfs f0,-4568(11); addi 8,31,44; stfs f0,0x8(1); stfs f0,0x8(9); stfs f0,0x4(9); lwz 10,0x8(9); lwz 0,0x8(1); lwz 11,0x4(9); stw 0,0x2c(31); stw 10,0x8(8); stw 11,0x4(8); 9:; lwz 11,0x18(29); cmpwi 11,0; beq 12f; lwz 0,0x0(31); ori 0,0,64; stw 0,0x0(31); ble 10f; lwz 9,0x44(30); rlwinm 11,11,2,0,29; lfsx f0,9,11; b 13f; 10:; lwz 3,0x14(28); cmpwi 3,0; beq 11f; fmr f1,f31; bl _s802EA6DC_2; stfs f1,0x38(31); b 14f; 11:; lis 9,-32702; rlwinm 0,0,0,26,24; lfs f0,-4568(9); stw 0,0x0(31); b 13f; 12:; lis 9,-32702; lfs f0,-4568(9); 13:; stfs f0,0x38(31); 14:; lwz 11,0x1c(29); cmpwi 11,0; beq 17f; lwz 0,0x0(31); ori 0,0,128; stw 0,0x0(31); ble 15f; lwz 9,0x44(30); rlwinm 11,11,2,0,29; lfsx f0,9,11; b 18f; 15:; lwz 3,0x18(28); cmpwi 3,0; beq 16f; fmr f1,f31; bl _s802EA6DC_3; stfs f1,0x3c(31); b 19f; 16:; lis 9,-32702; rlwinm 0,0,0,25,23; lfs f0,-4564(9); stw 0,0x0(31); b 18f; 17:; lis 9,-32702; lfs f0,-4564(9); 18:; stfs f0,0x3c(31); 19:; lwz 7,0x20(29); cmpwi 7,0; beq 22f; lwz 0,0x0(31); ori 0,0,256; stw 0,0x0(31); ble 20f; lwz 9,0x44(30); rlwinm 11,7,2,0,29; lfsx f0,9,11; b 23f; 20:; lwz 3,0x1c(28); cmpwi 3,0; beq 21f; fmr f1,f31; bl _s802EA6DC_4; stfs f1,0x40(31); b 24f; 21:; lis 9,-32702; rlwinm 0,0,0,24,22; lfs f0,-4572(9); stw 0,0x0(31); b 23f; 22:; lis 9,-32702; lfs f0,-4572(9); 23:; stfs f0,0x40(31); 24:; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x18(1); lfd f31,0x28(1); addi 1,1,48"

extern "C" void _s802EA6DC_0();
extern "C" void _s802EA6DC_1();
extern "C" void _s802EA6DC_2();
extern "C" void _s802EA6DC_3();
extern "C" void _s802EA6DC_4();

struct EAnimController {
    void AnimateSpecial();
};

void EAnimController::AnimateSpecial() {
}
