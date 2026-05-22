// 0x803C5710 MultiShaderInfo::DeAlloc(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 4,0xc(31); cmpwi 4,0; beq 0f; lis 3,-32692; addi 3,3,-17444; bl _s803C5710_0; li 0,0; stw 0,0xc(31); 0:; lwz 4,0x10(31); cmpwi 4,0; beq 1f; lis 3,-32692; addi 3,3,-17444; bl _s803C5710_1; li 0,0; stw 0,0x10(31); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s803C5710_0();
extern "C" void _s803C5710_1();
extern "C" void f_803C5710() {}
