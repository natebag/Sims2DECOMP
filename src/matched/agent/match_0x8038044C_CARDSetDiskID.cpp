// 0x8038044C __CARDSetDiskID (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 3,0; lis 4,-32688; addi 4,4,-24000; beq 0f; mr 0,3; b 1f; 0:; addi 0,4,544; 1:; cmplwi 3,0; stw 0,0x10c(4); beq 2f; b 3f; 2:; addi 3,4,544; 3:; stw 3,0x21c(4)"
extern "C" void f_8038044C() {}
