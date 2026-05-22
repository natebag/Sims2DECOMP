// 0x801167C8 cHitControlGroup::SetVolume(int) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 30,0x28(1); stw 0,0x34(1); lwz 9,-24136(13); mr 30,3; stw 4,0x4(30); addi 9,9,4; lwz 0,0x4(9); stw 0,0x10(1); lwz 11,0x4(9); lwz 0,0x0(11); stw 0,0x8(1); stw 0,0x18(1); b 2f; 0:; lwz 9,-24136(13); lwz 31,0x8(3); lwz 3,0x50(9); mr 4,31; bl _s801167C8_0; cmpwi 3,0; beq 1f; mr 3,31; bl _s801167C8_1; lwz 0,0x0(30); cmpw 3,0; bne 1f; mr 3,31; bl _s801167C8_2; 1:; lwz 9,0x8(1); stw 9,0x20(1); lwz 0,0x0(9); stw 9,0x18(1); stw 0,0x8(1); 2:; lwz 3,0x8(1); li 9,1; lwz 0,0x10(1); cmpw 3,0; bne 3f; li 9,0; 3:; cmpwi 9,0; bne 0b; li 3,1; lwz 0,0x34(1); mtspr 8,0; lmw 30,0x28(1); addi 1,1,48"
extern "C" void _s801167C8_0();
extern "C" void _s801167C8_1();
extern "C" void _s801167C8_2();
extern "C" void f_801167C8() {}
