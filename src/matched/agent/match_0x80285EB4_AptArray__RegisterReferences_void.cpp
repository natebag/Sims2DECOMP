// 0x80285EB4 AptArray::RegisterReferences(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; li 30,0; bl _s80285EB4_0; lwz 0,0x2c(31); cmpw 30,0; bge 2f; lis 28,-32704; li 29,0; 0:; lwz 9,0x24(31); lwzx 4,29,9; cmpwi 4,0; beq 1f; lwz 9,-27024(13); mr 3,31; addi 5,28,16176; mtspr 8,9; blrl; 1:; lwz 0,0x2c(31); addi 30,30,1; addi 29,29,4; cmpw 30,0; blt 0b; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80285EB4_0();
extern "C" void f_80285EB4() {}
