// 0x802B5F18 AptObject::GetImplementedObjects(int (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; lbz 0,0x20(31); stw 0,0x0(4); lbz 9,0x20(31); cmpwi 9,0; beq 1f; addi 30,1,8; lis 4,-32703; addi 4,4,21100; mr 3,30; bl _s802B5F18_0; addi 3,31,12; mr 4,30; bl _s802B5F18_1; lwz 4,0x8(1); mr 31,3; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802B5F18_2; 0:; mr 3,31; b 2f; 1:; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s802B5F18_0();
extern "C" void _s802B5F18_1();
extern "C" void _s802B5F18_2();
extern "C" void f_802B5F18() {}
