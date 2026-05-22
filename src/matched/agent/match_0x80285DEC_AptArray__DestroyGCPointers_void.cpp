// 0x80285DEC AptArray::DestroyGCPointers(void) (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; li 29,0; bl _s80285DEC_0; lwz 0,0x2c(31); cmpw 29,0; bge 2f; lis 26,-32704; lis 27,-32704; li 28,0; li 30,0; 0:; lwz 9,0x24(31); lwzx 11,30,9; cmpwi 11,0; beq 1f; lwz 9,0x8(11); addi 4,26,16140; addi 5,27,16056; li 6,138; lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x24(31); stwx 28,30,9; 1:; lwz 0,0x2c(31); addi 29,29,1; addi 30,30,4; cmpw 29,0; blt 0b; 2:; lwz 4,0x24(31); cmpwi 4,0; beq 3f; lwz 5,0x28(31); lwz 3,-23020(13); rlwinm 5,5,2,0,29; bl _s80285DEC_1; 3:; li 0,0; stw 0,0x28(31); stw 0,0x24(31); stw 0,0x2c(31); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80285DEC_0();
extern "C" void _s80285DEC_1();
extern "C" void f_80285DEC() {}
