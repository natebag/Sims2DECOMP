// 0x800B0100 cBoxX::UnpauseMusic(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 9,0x70(31); cmpwi 9,0; beq 0f; addi 0,9,-1; cmpwi 0,0; stw 0,0x70(31); bne 1f; 0:; lwz 9,-24136(13); li 4,2; lwz 3,0x50(9); bl _s800B0100_0; addi 3,31,48; bl _s800B0100_1; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800B0100_0();
extern "C" void _s800B0100_1();
extern "C" void f_800B0100() {}
