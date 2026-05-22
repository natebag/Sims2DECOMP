// 0x800AFB00 cBoxX::UpdateSndobVolPan(ERSoundEvent (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stw 0,0x34(1); stw 4,0x28(1); addi 10,1,40; lwz 11,0x24(3); lwz 9,0x4(11); 0:; cmpwi 9,0; beq 2f; lwz 0,0x10(9); cmplw 0,4; blt 1f; mr 11,9; lwz 9,0x8(11); b 0b; 1:; lwz 9,0xc(9); b 0b; 2:; stw 11,0x8(1); lwz 11,0x24(3); lwz 9,0x4(11); cmpwi 9,0; beq 6f; lwz 10,0x0(10); 3:; lwz 0,0x10(9); cmplw 10,0; bge 4f; mr 11,9; lwz 9,0x8(11); b 5f; 4:; lwz 9,0xc(9); 5:; cmpwi 9,0; bne 3b; 6:; lwz 0,0x8(1); stw 11,0x10(1); cmpw 0,11; bne 7f; lwz 9,-24136(13); li 5,0; lwz 4,0x28(1); lwz 3,0x50(9); bl _s800AFB00_0; mr. 3,3; beq 8f; bl _s800AFB00_1; b 8f; 7:; stw 0,0x18(1); addi 4,1,24; stw 11,0x20(1); addi 5,1,32; bl _s800AFB00_2; 8:; lwz 0,0x34(1); mtspr 8,0; addi 1,1,48"
extern "C" void _s800AFB00_0();
extern "C" void _s800AFB00_1();
extern "C" void _s800AFB00_2();
extern "C" void f_800AFB00() {}
