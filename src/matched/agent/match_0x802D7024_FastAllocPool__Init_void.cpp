// 0x802D7024 FastAllocPool::Init(void (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,4,0,8,31; li 11,0; or 0,5,0; li 10,0; neg 9,0; stw 11,0x4(3); and 0,0,9; cmplw 10,6; stw 0,0x10(3); mr 9,4; stw 4,0x0(3); stw 6,0x8(3); stw 5,0xc(3); bgelr; lis 11,17733; ori 11,11,21062; 0:; cmpwi 9,0; beq 1f; stw 11,0x0(9); lwz 0,0x4(3); stw 0,0x4(9); stw 9,0x4(3); 1:; lwz 0,0x8(3); addi 10,10,1; add 9,9,5; cmplw 10,0; blt 0b"
extern "C" void f_802D7024() {}
