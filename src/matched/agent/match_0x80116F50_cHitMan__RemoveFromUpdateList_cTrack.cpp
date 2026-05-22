// 0x80116F50 cHitMan::RemoveFromUpdateList(cTrack (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stw 31,0x2c(1); stw 0,0x34(1); addi 9,3,4; lwz 11,0x4(9); mr 10,9; lwz 0,0x0(11); stw 0,0x8(1); stw 0,0x10(1); b 1f; 0:; stw 11,0x18(1); lwz 0,0x0(11); stw 11,0x10(1); stw 0,0x8(1); 1:; lwz 0,0x4(10); li 9,1; lwz 11,0x8(1); stw 0,0x10(1); cmpw 11,0; bne 2f; li 9,0; 2:; cmpwi 9,0; beq 3f; lwz 0,0x8(11); cmpw 0,4; bne 0b; 3:; lwz 0,0x4(10); cmpw 11,0; stw 0,0x10(1); bne 4f; li 3,0; b 7f; 4:; lwz 0,0xc(3); cmpw 11,0; bne 5f; stw 11,0x20(1); lwz 0,0x0(11); stw 11,0x10(1); stw 0,0xc(3); 5:; lwz 3,0x8(1); stw 3,0x18(1); cmpwi 3,0; lwz 31,0x0(3); lwz 9,0x4(3); stw 31,0x0(9); stw 9,0x4(31); beq 6f; li 4,12; bl _s80116F50_0; 6:; stw 31,0x10(1); li 3,1; 7:; lwz 0,0x34(1); mtspr 8,0; lwz 31,0x2c(1); addi 1,1,48"
extern "C" void _s80116F50_0();
extern "C" void f_80116F50() {}
