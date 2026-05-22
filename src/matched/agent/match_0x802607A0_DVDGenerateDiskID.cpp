// 0x802607A0 DVDGenerateDiskID (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stmw 27,0x1c(1); addi 28,4,0; addi 29,5,0; addi 27,3,0; addi 30,6,0; addi 31,7,0; li 4,0; li 5,32; bl _s802607A0_0; cmplwi 28,0; beq 0f; addi 3,27,0; addi 4,28,0; li 5,4; bl _s802607A0_1; 0:; cmplwi 29,0; beq 1f; addi 4,29,0; addi 3,27,4; li 5,2; bl _s802607A0_2; 1:; stb 30,0x6(27); mr 3,27; stb 31,0x7(27); lwz 0,0x34(1); lmw 27,0x1c(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s802607A0_0();
extern "C" void _s802607A0_1();
extern "C" void _s802607A0_2();
extern "C" void f_802607A0() {}
