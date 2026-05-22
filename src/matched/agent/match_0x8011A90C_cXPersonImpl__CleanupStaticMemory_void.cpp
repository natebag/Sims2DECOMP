// 0x8011A90C cXPersonImpl::CleanupStaticMemory(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 0,-31708(13); cmpwi 0,0; beq 2f; lis 9,-32696; li 31,0; addi 29,9,26300; lwz 0,0x4(29); cmpw 31,0; bge 1f; li 30,0; 0:; lwz 3,0x0(29); li 4,0; addi 31,31,1; add 3,3,30; bl _s8011A90C_0; addi 30,30,20; lwz 0,0x4(29); cmpw 31,0; blt 0b; 1:; li 0,0; stw 0,-31708(13); 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8011A90C_0();
extern "C" void f_8011A90C() {}
