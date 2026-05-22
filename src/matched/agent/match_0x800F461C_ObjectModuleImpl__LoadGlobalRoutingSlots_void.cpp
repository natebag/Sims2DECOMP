// 0x800F461C ObjectModuleImpl::LoadGlobalRoutingSlots(void) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); lwz 29,0x2078(3); addi 28,1,16; addi 27,3,8312; lwz 30,0x4(27); addi 26,3,8312; mr 31,29; cmpw 29,30; beq 1f; 0:; lwz 9,0x0(31); li 4,2; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; addi 31,31,60; blrl; cmpw 31,30; bne 0b; 1:; lwz 4,-31848(13); mr 3,28; stw 29,0x4(27); bl _s800F461C_0; li 4,100; mr 6,26; li 5,0; li 7,0; li 8,0; mr 3,28; bl _s800F461C_1; mr 3,28; li 4,2; bl _s800F461C_2; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"
extern "C" void _s800F461C_0();
extern "C" void _s800F461C_1();
extern "C" void _s800F461C_2();
extern "C" void f_800F461C() {}
