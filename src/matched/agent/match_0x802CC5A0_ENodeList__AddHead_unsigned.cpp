// 0x802CC5A0 ENodeList::AddHead(unsigned (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; li 3,12; bl _s802CC5A0_0; mr. 3,3; beq 2f; stw 30,0x0(3); lwz 9,0x0(31); stw 9,0x8(3); cmpwi 9,0; beq 0f; stw 3,0x4(9); b 1f; 0:; stw 3,0x4(31); 1:; li 0,0; stw 0,0x4(3); stw 3,0x0(31); 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802CC5A0_0();
extern "C" void f_802CC5A0() {}
