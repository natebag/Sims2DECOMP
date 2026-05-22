// 0x8020AFA8 InteractorModule::InteractorManager::InteractorManager(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mr 9,3; li 0,0; li 11,-1; stw 0,0x0(9); stw 11,0x8(9); addi 10,9,12; stw 11,0x4(9); addi 8,9,20; stw 0,0xc(9); addi 11,9,28; stw 0,0x4(10); addi 7,9,36; stw 0,0x4(8); addi 6,9,44; stw 0,0x1c(9); addi 10,9,52; stw 0,0x4(11); addi 8,9,64; stw 0,0x4(7); addi 11,9,72; stw 0,0x2c(9); stw 0,0x4(6); stw 0,0x4(10); stb 0,0x3c(9); stw 0,0x40(9); stw 0,0x4(8); stw 0,0x4(11); addi 1,1,40"
extern "C" void f_8020AFA8() {}
