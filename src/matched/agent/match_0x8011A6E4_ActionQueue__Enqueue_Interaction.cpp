// 0x8011A6E4 ActionQueue::Enqueue(Interaction (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; lwz 0,0x2ac(9); lwz 5,0x2a8(9); subf 5,5,0; bl _s8011A6E4_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8011A6E4_0();
extern "C" void f_8011A6E4() {}
