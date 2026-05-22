// 0x803362B8 ENgcMovie::PlayerGetVideoInfo(THPVideoInfo (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32691; addi 11,9,14656; lwz 0,0xa0(11); cmpwi 0,0; bne 0f; li 3,0; blr; 0:; lwz 10,0x80(11); addi 9,11,128; lwz 0,0x8(9); li 3,1; lwz 11,0x4(9); stw 0,0x8(4); stw 10,0x0(4); stw 11,0x4(4)"
extern "C" void f_803362B8() {}
