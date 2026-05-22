// 0x8036C614 AsyncAramRequestCallback(unsigned (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32690; addi 0,9,-6528; li 9,0; cmpw 0,3; beq 1f; mr 11,0; 0:; addi 9,9,1; addi 11,11,40; cmplwi 9,63; bgt 1f; cmpw 11,3; bne 0b; 1:; cmpwi 9,64; beq 3f; mulli 31,9,40; lis 9,-32690; addi 30,9,-6528; addi 11,30,32; lwzx 0,11,31; cmpwi 0,0; beq 2f; add 9,31,30; addi 11,30,36; lwz 0,0x20(9); lwzx 3,11,31; mtspr 8,0; blrl; 2:; addi 9,30,36; li 0,-1; stwx 0,9,31; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_8036C614() {}
