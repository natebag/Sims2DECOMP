// 0x802531F4 __OSInitSystemCall (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); lis 5,-32768; lis 4,-32731; lis 3,-32731; addi 31,5,3072; addi 0,3,12784; addi 4,4,12756; mr 3,31; subf 5,4,0; bl _s802531F4_0; mr 3,31; li 4,256; bl _s802531F4_1; sync; mr 3,31; li 4,256; bl _s802531F4_2; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s802531F4_0();
extern "C" void _s802531F4_1();
extern "C" void _s802531F4_2();
extern "C" void f_802531F4() {}
