// 0x80013CEC AwarenessManager::RainAwarenessCheck(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s80013CEC_0; cmpwi 3,0; beq 0f; lwz 0,0x0(31); andi. 9,0,512; bne 1f; mr 3,31; bl _s80013CEC_1; b 1f; 0:; lwz 0,0x0(31); andi. 9,0,512; beq 1f; mr 3,31; bl _s80013CEC_2; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80013CEC_0();
extern "C" void _s80013CEC_1();
extern "C" void _s80013CEC_2();
extern "C" void f_80013CEC() {}
