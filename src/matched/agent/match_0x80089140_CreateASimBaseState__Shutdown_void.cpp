// 0x80089140 CreateASimBaseState::Shutdown(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,3; li 28,0; li 3,0; li 31,0; bl _s80089140_0; li 30,4; lis 9,-32697; addi 29,9,23428; 0:; lwz 9,0x78(29); addi 9,9,316; lwzx 3,9,31; cmpwi 3,0; beq 1f; bl _s80089140_1; lwz 9,0x78(29); addi 9,9,316; stwx 28,9,31; 1:; addi 31,31,392; addic. 30,30,-1; bne 0b; stw 30,0x24(27); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80089140_0();
extern "C" void _s80089140_1();
extern "C" void f_80089140() {}
