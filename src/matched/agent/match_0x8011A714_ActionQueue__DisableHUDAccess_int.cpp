// 0x8011A714 ActionQueue::DisableHUDAccess(int) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lbz 0,0x2b0(31); cmpwi 0,0; bne 1f; lis 9,-32697; lwz 3,0x5bcc(9); cmpwi 3,0; beq 0f; lbz 4,0x2b1(31); bl _s8011A714_0; 0:; li 9,1; li 0,255; stb 0,0x2b1(31); stb 9,0x2b0(31); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8011A714_0();
extern "C" void f_8011A714() {}
