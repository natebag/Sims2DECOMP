// 0x80221344 InteractorModule::WallManipulator::HandleExitRequest(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0xc4(3); andi. 0,9,1; beq 0f; li 0,-70; andi. 11,9,512; and 0,9,0; stw 0,0xc4(3); bne 1f; rlwinm 0,0,0,29,27; stw 0,0xc4(3); b 1f; 0:; stw 0,0xc4(3); bl _s80221344_0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80221344_0();
extern "C" void f_80221344() {}
