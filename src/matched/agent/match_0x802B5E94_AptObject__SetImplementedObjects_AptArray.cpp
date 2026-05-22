// 0x802B5E94 AptObject::SetImplementedObjects(AptArray (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 29,4; addi 30,1,8; mr 28,3; lis 4,-32703; mr 27,5; addi 4,4,21084; mr 3,30; bl _s802B5E94_0; mr 4,30; mr 5,29; addi 3,28,12; bl _s802B5E94_1; lwz 4,0x8(1); stb 27,0x20(28); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802B5E94_2; 0:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s802B5E94_0();
extern "C" void _s802B5E94_1();
extern "C" void _s802B5E94_2();
extern "C" void f_802B5E94() {}
