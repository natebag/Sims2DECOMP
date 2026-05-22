// 0x803233C8 EControllerManager::Init(void) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 11,4; li 9,0; mtspr 9,11; li 0,1; 0:; stw 9,0x0(3); stw 0,0x10(3); addi 9,9,1; addi 3,3,4; bdnz 0b; li 3,1"
extern "C" void f_803233C8() {}
