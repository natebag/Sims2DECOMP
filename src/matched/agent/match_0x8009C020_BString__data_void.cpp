// 0x8009C020 BString::data(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s8009C020_0; cmpwi 3,0; bne 0f; li 3,0; b 1f; 0:; lwz 9,0x0(31); lwz 3,0x0(9); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8009C020_0();
extern "C" void f_8009C020() {}
