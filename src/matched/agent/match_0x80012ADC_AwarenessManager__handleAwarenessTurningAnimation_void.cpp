// 0x80012ADC AwarenessManager::handleAwarenessTurningAnimation(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x0(31); andi. 9,0,2; beq 2f; andi. 9,0,4; beq 4f; lwz 0,0x18(31); cmpwi 0,1; bne 0f; lis 6,-32767; lwz 3,0x8(31); addi 6,6,9364; li 4,16384; li 5,0; mr 7,31; bl _s80012ADC_0; b 1f; 0:; lis 6,-32767; lwz 3,0x8(31); addi 6,6,9864; li 4,16384; li 5,0; mr 7,31; bl _s80012ADC_1; 1:; lwz 0,0x0(31); rlwinm 0,0,0,30,28; b 3f; 2:; andi. 9,0,8; beq 4f; lwz 3,0x8(31); li 4,16384; bl _s80012ADC_2; lwz 0,0x0(31); rlwinm 0,0,0,29,27; 3:; stw 0,0x0(31); 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80012ADC_0();
extern "C" void _s80012ADC_1();
extern "C" void _s80012ADC_2();
extern "C" void f_80012ADC() {}
