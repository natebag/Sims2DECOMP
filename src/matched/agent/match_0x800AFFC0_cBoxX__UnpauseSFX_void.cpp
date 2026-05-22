// 0x800AFFC0 cBoxX::UnpauseSFX(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x6c(3); cmpwi 9,0; beq 0f; addi 0,9,-1; stw 0,0x6c(3); cmpwi 0,0; bne 1f; 0:; lwz 9,-24136(13); li 4,0; lwz 3,0x50(9); bl _s800AFFC0_0; lwz 9,-24136(13); li 4,1; lwz 3,0x50(9); bl _s800AFFC0_1; lwz 9,-24136(13); li 4,3; lwz 3,0x50(9); bl _s800AFFC0_2; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800AFFC0_0();
extern "C" void _s800AFFC0_1();
extern "C" void _s800AFFC0_2();
extern "C" void f_800AFFC0() {}
