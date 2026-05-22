// 0x802CF634 ERTQuantize::Compute(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; li 28,-1; addi 31,30,136; li 29,511; 0:; lwz 0,0x4(31); cmpwi 0,0; beq 1f; mr 3,30; mr 4,31; bl _s802CF634_0; 1:; stw 28,0x4(31); addic. 29,29,-1; addi 31,31,8; bne 0b; mr 3,30; bl _s802CF634_1; lhz 9,0x1088(30); stw 29,0x10a8(30); cmpwi 9,0; beq 2f; mulli 9,9,56; lwz 0,0x108c(30); add 4,0,9; b 3f; 2:; li 4,0; 3:; mr 3,30; bl _s802CF634_2; li 0,2; stw 0,0x1090(30); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802CF634_0();
extern "C" void _s802CF634_1();
extern "C" void _s802CF634_2();
extern "C" void f_802CF634() {}
