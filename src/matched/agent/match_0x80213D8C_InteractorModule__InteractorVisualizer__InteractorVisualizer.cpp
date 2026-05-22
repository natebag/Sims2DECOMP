// 0x80213D8C InteractorModule::InteractorVisualizer::InteractorVisualizer(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); li 0,0; mr 10,3; addi 11,10,8; stw 0,0x8(10); addi 9,11,8; stw 0,0x4(11); stw 0,0x4(9); li 9,4; stb 0,0x10(11); mtspr 9,9; 0:; bdnz 0b; li 0,4; mtspr 9,0; 1:; bdnz 1b; li 0,0; mr 3,10; stw 0,0x0(10); stw 0,0x4(10); addi 1,1,32"
extern "C" void f_80213D8C() {}
