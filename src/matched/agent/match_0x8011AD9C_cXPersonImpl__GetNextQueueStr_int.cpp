// 0x8011AD9C cXPersonImpl::GetNextQueueStr(int) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x534(3); li 9,0; cmpwi 0,0; beq 0f; li 9,1; 0:; addi 11,3,304; add 9,4,9; lwz 3,0x2a8(11); lis 0,-13108; ori 0,0,52429; add 3,3,9; mulhwu 0,3,0; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 3,0,3; mulli 3,3,68; add 3,11,3; bl _s8011AD9C_0; bl _s8011AD9C_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8011AD9C_0();
extern "C" void _s8011AD9C_1();
extern "C" void f_8011AD9C() {}
