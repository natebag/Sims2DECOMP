// 0x8034F298 ax_drop_voice_callback(void (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32690; mr 30,3; addi 9,9,-14064; li 29,0; addi 31,9,28; li 28,0; 0:; lwz 0,0x0(31); addi 29,29,1; mr 3,30; cmpw 0,30; bne 1f; bl _s8034F298_0; stw 28,0x0(31); 1:; addi 31,31,120; cmplwi 29,1; ble 0b; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8034F298_0();
extern "C" void f_8034F298() {}
