// 0x800BCA34 IconGroupImpl::Init(int) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32702; li 10,0; addi 9,9,16428; lwzx 0,9,10; cmpw 0,4; bne 0f; stw 9,0xc(3); stw 4,0x4(3); blr; 0:; addi 10,10,1; cmpwi 10,11; bgtlr; lis 9,-32702; rlwinm 11,10,3,0,28; addi 9,9,16428; lwzx 0,9,11; cmpw 0,4; bne 0b; add 0,11,9; stw 4,0x4(3); stw 0,0xc(3)"
extern "C" void f_800BCA34() {}
