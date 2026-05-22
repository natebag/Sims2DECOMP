// 0x802459EC vfiprintf (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; mr 0,4; mr 6,5; lwz 3,0x5c(9); mr 4,9; mr 5,0; crxor 6,6,6; bl _s802459EC_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802459EC_0();
extern "C" void f_802459EC() {}
