// 0x8025BC98 cbForSeekAsync (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lwz 12,0x38(4); cmplwi 12,0; beq 0f; mtspr 8,12; blrl; 0:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void f_8025BC98() {}
