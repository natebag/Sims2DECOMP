// 0x8010EC30 cXObjectImpl::TryHUDManage(StackElem (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lis 9,-32697; mr 30,3; lwz 0,0x5bc8(9); mr 31,5; cmpwi 0,0; beq 1f; lbz 4,0x2(31); mr 3,30; lha 5,0x0(31); li 6,0; li 7,0; addi 8,1,8; bl _s8010EC30_0; cmpwi 3,-1; bne 0f; cmpwi 4,-1; beq 1f; 0:; lbz 4,0x6(31); mr 3,30; lha 5,0x4(31); li 6,0; li 7,0; addi 8,1,10; bl _s8010EC30_1; cmpwi 3,-1; bne 2f; cmpwi 4,-1; bne 2f; 1:; li 3,0; li 4,0; b 3f; 2:; lis 9,-32697; lha 4,0x8(1); lbz 5,0x3(31); lwz 3,0x5bc8(9); lha 6,0xa(1); bl _s8010EC30_2; cmpwi 3,0; li 3,0; li 4,0; beq 3f; li 3,0; li 4,1; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8010EC30_0();
extern "C" void _s8010EC30_1();
extern "C" void _s8010EC30_2();
extern "C" void f_8010EC30() {}
