// 0x802C8CD8 EHashTable::Remove(unsigned (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,3; rlwinm 4,4,2,0,29; lwz 9,0x8(11); lwzx 3,9,4; add 9,9,4; b 1f; 0:; addi 9,3,8; lwz 3,0x8(3); 1:; cmpwi 3,0; beq 2f; cmpw 3,5; bne 0b; 2:; lwz 0,0x8(3); stw 0,0x0(9); lwz 9,0x0(11); cmpw 9,3; bne 3f; lwz 0,0x4(3); stw 0,0x0(11); b 4f; 3:; lwz 9,0x0(3); lwz 0,0x4(3); stw 0,0x4(9); 4:; lwz 0,0x4(11); cmpw 0,3; bne 5f; lwz 0,0x0(3); stw 0,0x4(11); b 6f; 5:; lwz 9,0x4(3); lwz 0,0x0(3); stw 0,0x0(9); 6:; bl _s802C8CD8_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802C8CD8_0();
extern "C" void f_802C8CD8() {}
