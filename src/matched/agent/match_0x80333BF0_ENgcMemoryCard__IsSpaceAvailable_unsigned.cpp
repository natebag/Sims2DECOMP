// 0x80333BF0 ENgcMemoryCard::IsSpaceAvailable(unsigned (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); lwz 9,0x0(3); li 29,0; stw 29,0x8(1); mr 30,5; addi 5,1,8; mr 31,6; lha 0,0x100(9); lwz 9,0x104(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x8(1); cmplw 0,30; blt 0f; li 0,1; stw 0,0x0(31); b 1f; 0:; stw 29,0x0(31); 1:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void f_80333BF0() {}
