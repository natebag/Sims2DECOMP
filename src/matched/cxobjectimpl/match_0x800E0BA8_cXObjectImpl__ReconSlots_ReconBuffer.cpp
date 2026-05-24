// 0x800E0BA8 cXObjectImpl::ReconSlots(ReconBuffer (908 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-136(1); mfspr 0,8; stmw 14,0x40(1); stw 0,0x8c(1); mr 25,3; mr 19,4; cmpwi 5,4; ble 19f; addi 9,25,144; lwz 11,0x90(25); lwz 0,0x4(9); mr 28,9; mr 3,19; addi 4,1,8; subf 0,11,0; li 5,1; srawi 0,0,5; li 23,0; sth 0,0x8(1); bl _s800E0BA8_0; lha 0,0x8(1); cmpw 23,0; bge 19f; li 17,0; addi 14,1,48; addi 15,1,50; 0:; lwz 0,0x4(28); rlwinm 20,23,5,0,26; lwz 9,0x90(25); addi 18,23,1; sth 17,0x30(1); subf 0,9,0; sth 17,0x32(1); srawi 0,0,5; cmpw 23,0; blt 18f; lis 9,-32698; lis 11,-32698; addi 16,9,18992; addi 21,11,18960; mr 24,28; lis 22,-32698; 1:; addi 3,1,16; bl _s800E0BA8_1; lwz 11,0x4(24); lwz 0,0xc(24); cmpw 11,0; beq 2f; stw 21,0x0(11); lhz 0,0x14(1); sth 0,0x4(11); lwz 9,0x18(1); stw 9,0x8(11); lwz 0,0x1c(1); stw 0,0xc(11); lwz 9,0x20(1); stw 9,0x10(11); lfs f0,0x24(1); stfs f0,0x14(11); lfs f13,0x28(1); stfs f13,0x18(11); lfs f0,0x2c(1); stfs f0,0x1c(11); lwz 9,0x4(28); addi 9,9,32; stw 9,0x4(28); b 17f; 2:; lwz 29,0x4(28); li 9,1; lwz 0,0x90(25); addi 10,1,56; stw 9,0x38(1); addi 11,1,52; subf 0,0,29; srawi 9,0,5; stw 9,0x34(1); cmplwi 9,1; bge 3f; mr 11,10; 3:; lwz 0,0x0(11); add. 0,9,0; beq 5f; rlwinm 0,0,5,0,26; mr 27,0; cmplwi 0,128; ble 4f; mr 3,27; bl _s800E0BA8_2; b 6f; 4:; mr 3,27; bl _s800E0BA8_3; b 6f; 5:; li 3,0; li 27,0; 6:; mr 30,3; lwz 11,0x0(28); mr 26,30; mr 3,26; cmpw 11,29; beq 8f; addi 10,22,18960; 7:; stw 10,0x0(3); lhz 0,0x4(11); sth 0,0x4(3); lwz 9,0x8(11); stw 9,0x8(3); lwz 0,0xc(11); stw 0,0xc(3); lwz 9,0x10(11); stw 9,0x10(3); lfs f0,0x14(11); stfs f0,0x14(3); lfs f13,0x18(11); stfs f13,0x18(3); lfs f0,0x1c(11); addi 11,11,32; stfs f0,0x1c(3); cmpw 11,29; addi 3,3,32; bne 7b; 8:; lwz 0,0x38(1); mr 30,3; cmpwi 0,1; bne 9f; stw 21,0x0(30); lhz 0,0x14(1); sth 0,0x4(30); lwz 9,0x18(1); stw 9,0x8(30); lwz 0,0x1c(1); stw 0,0xc(30); lwz 9,0x20(1); stw 9,0x10(30); lfs f0,0x24(1); stfs f0,0x14(30); lfs f13,0x28(1); stfs f13,0x18(30); lfs f0,0x2c(1); stfs f0,0x1c(30); addi 30,30,32; b 12f; 9:; mr. 9,0; mr 3,30; mtspr 9,9; beq 11f; addi 11,22,18960; 10:; stw 11,0x0(3); lhz 0,0x14(1); sth 0,0x4(3); lwz 9,0x18(1); stw 9,0x8(3); lwz 0,0x1c(1); stw 0,0xc(3); lwz 9,0x20(1); stw 9,0x10(3); lfs f0,0x24(1); stfs f0,0x14(3); lfs f13,0x28(1); stfs f13,0x18(3); lfs f0,0x2c(1); stfs f0,0x1c(3); addi 3,3,32; bdnz 10b; 11:; mr 30,3; 12:; lwz 29,0x4(28); lwz 31,0x0(28); cmpw 31,29; beq 14f; 13:; lwz 9,0x0(31); li 4,2; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; addi 31,31,32; blrl; cmpw 31,29; bne 13b; 14:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 0,3,0; srawi 0,0,5; beq 16f; rlwinm 4,0,5,0,26; cmplwi 4,128; ble 15f; bl _s800E0BA8_4; b 16f; 15:; bl _s800E0BA8_5; 16:; add 0,27,26; stw 26,0x0(28); stw 30,0x4(28); stw 0,0xc(28); 17:; lwz 0,0x4(28); lwz 9,0x90(25); stw 16,0x10(1); subf 0,9,0; srawi 0,0,5; cmpw 23,0; bge 1b; 18:; lwz 9,0x90(25); mr 3,19; sth 17,0x30(1); mr 4,14; add 9,9,20; li 5,1; lha 0,0x4(9); mr 23,18; sth 0,0x32(1); bl _s800E0BA8_6; mr 3,19; mr 4,15; li 5,1; bl _s800E0BA8_7; lwz 9,0x90(25); lha 11,0x8(1); lhz 0,0x32(1); add 9,9,20; cmpw 23,11; sth 0,0x4(9); blt 0b; 19:; lwz 0,0x8c(1); mtspr 8,0; lmw 14,0x40(1); addi 1,1,136"

extern "C" void _s800E0BA8_0();
extern "C" void _s800E0BA8_1();
extern "C" void _s800E0BA8_2();
extern "C" void _s800E0BA8_3();
extern "C" void _s800E0BA8_4();
extern "C" void _s800E0BA8_5();
extern "C" void _s800E0BA8_6();
extern "C" void _s800E0BA8_7();

struct cXObjectImpl {
    void ReconSlots_ReconBuffer();
};

void cXObjectImpl::ReconSlots_ReconBuffer() {
}
