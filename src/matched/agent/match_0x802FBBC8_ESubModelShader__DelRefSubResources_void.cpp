// 0x802FBBC8 ESubModelShader::DelRefSubResources(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x8(31); cmpwi 3,0; beq 0f; bl _s802FBBC8_0; li 0,0; stw 0,0x8(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802FBBC8_0();
extern "C" void f_802FBBC8() {}
