// 0x801CFCBC O2TTarget::OnCircleKeyPressed(char (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-272(1); mfspr 0,8; stw 31,0x10c(1); stw 0,0x114(1); mr 31,3; lwz 9,0x88(31); addi 5,9,1; cmpwi 9,2; bne 0f; li 5,0; 0:; lis 4,-32705; addi 3,1,8; addi 4,4,-8800; crxor 6,6,6; bl _s801CFCBC_0; lwz 9,0x80(31); lis 4,-32705; addi 4,4,16128; addi 5,1,8; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; lwz 0,0x114(1); mtspr 8,0; lwz 31,0x10c(1); addi 1,1,272"
extern "C" void _s801CFCBC_0();
extern "C" void f_801CFCBC() {}
