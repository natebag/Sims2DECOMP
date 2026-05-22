// 0x802AEEC4 AptString::Destroy(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,-26892(13); mr 9,3; addi 31,9,12; li 4,33; stw 0,0x10(9); mr 3,31; stw 9,-26892(13); bl _s802AEEC4_0; cmpwi 3,0; beq 0f; mr 3,31; bl _s802AEEC4_1; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802AEEC4_0();
extern "C" void _s802AEEC4_1();
extern "C" void f_802AEEC4() {}
