// 0x801FFA08 PSETarget::PopAptButtonFilters(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32697; li 29,1; lwz 0,0x5c70(9); cmpwi 0,0; beq 0f; li 29,2; 0:; li 30,0; cmpw 30,29; bge 3f; lis 9,-32697; addi 31,3,140; addi 27,9,24012; li 28,-1; 1:; lwz 5,0x0(31); cmpwi 5,-1; beq 2f; lwz 3,0xb4(27); mr 4,30; bl _s801FFA08_0; stw 28,0x0(31); 2:; addi 30,30,1; addi 31,31,4; cmpw 30,29; blt 1b; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s801FFA08_0();
extern "C" void f_801FFA08() {}
