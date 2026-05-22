// 0x8011917C cSampleChannel::SetPatch(cSamplePatch (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 11,0x4(31); stw 30,0x0(31); cmpwi 11,0; beq 0f; lwz 9,0x0(11); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x4(31); 0:; lwz 0,0x18(30); cmpwi 0,0; stw 0,0x4(31); bne 1f; mr 3,30; bl _s8011917C_0; lwz 0,0x18(30); stw 0,0x4(31); 1:; lwz 3,0x4(31); lwz 9,0x0(3); lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; li 3,1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8011917C_0();
extern "C" void f_8011917C() {}
