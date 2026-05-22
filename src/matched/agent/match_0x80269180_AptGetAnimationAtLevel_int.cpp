// 0x80269180 _AptGetAnimationAtLevel(int) (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 9,-23008(13); mr 31,3; cmpwi 9,0; beq 0f; lwz 3,0x28(9); cmpwi 3,0; bne 1f; 0:; li 3,0; b 4f; 1:; lwz 3,0x0(3); cmpwi 3,0; beq 3f; 2:; lwz 0,0x58(3); srawi 0,0,15; cmpw 0,31; beq 4f; lwz 3,0x54(3); cmpwi 3,0; bne 2b; 3:; lwz 3,-23016(13); li 4,100; li 29,0; bl _s80269180_0; mr 30,3; li 5,0; li 4,19; bl _s80269180_1; lis 9,-32704; addi 3,30,12; addi 9,9,23568; stw 9,0x8(30); bl _s80269180_2; stw 29,0x4c(30); lis 9,-32704; lwz 0,0x5c(30); lis 11,-32704; lfs f13,0xd60(9); mr 3,30; rlwinm 0,0,0,18,15; li 4,1; stfs f13,0x10(30); rlwimi 0,29,12,18,19; lfs f0,0xd64(11); stw 0,0x5c(30); stw 29,0x48(30); sth 29,0x5c(30); stfs f13,0x34(30); stfs f0,0x44(30); stfs f0,0x14(30); stfs f0,0x18(30); stfs f13,0x1c(30); stfs f0,0x20(30); stfs f0,0x24(30); stfs f13,0x28(30); stfs f13,0x2c(30); stfs f13,0x30(30); stfs f0,0x38(30); stfs f0,0x3c(30); stfs f0,0x40(30); bl _s80269180_3; lwz 0,0x0(30); mr 4,31; lwz 11,0x5c(30); mr 5,30; lwz 9,0x58(30); rlwimi 0,29,26,5,5; ori 11,11,2048; rlwinm 0,0,0,23,17; ori 9,9,32766; rlwinm 11,11,0,22,20; stw 9,0x58(30); ori 0,0,256; stw 29,0x60(30); stw 11,0x5c(30); stw 0,0x0(30); lwz 9,-23008(13); lwz 3,0x28(9); bl _s80269180_4; mr 3,30; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80269180_0();
extern "C" void _s80269180_1();
extern "C" void _s80269180_2();
extern "C" void _s80269180_3();
extern "C" void _s80269180_4();
extern "C" void f_80269180() {}
