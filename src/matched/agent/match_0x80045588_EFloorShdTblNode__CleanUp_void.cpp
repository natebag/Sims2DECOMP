// 0x80045588 EFloorShdTblNode::CleanUp(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; addi 3,31,4; bl _s80045588_0; lwz 3,0x0(31); cmpwi 3,0; beq 0f; bl _s80045588_1; li 0,0; stw 0,0x0(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80045588_0();
extern "C" void _s80045588_1();
extern "C" void f_80045588() {}
