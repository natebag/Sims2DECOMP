// 0x8032339C EControllerManager::EControllerManager(void) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; li 11,4; addi 9,9,-17768; mtspr 9,11; stw 9,0x20(3); li 0,0; addi 9,3,28; 0:; stw 0,0x0(9); addi 9,9,-4; bdnz 0b"
extern "C" void f_8032339C() {}
