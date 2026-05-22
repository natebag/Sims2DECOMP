// 0x8031B72C ERMovie::IsFinished(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 11,0x24(3); li 31,0; cmpwi 11,0; beq 0f; lwz 9,0x8(11); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; 0:; li 31,1; 1:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_8031B72C() {}
