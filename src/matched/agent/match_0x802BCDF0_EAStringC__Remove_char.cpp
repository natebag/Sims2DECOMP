// 0x802BCDF0 EAStringC::Remove(char) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lis 9,-32702; rlwinm 4,4,0,24,31; lhz 0,-19600(9); rlwinm 4,4,8,0,23; lis 5,-32702; rlwinm 0,0,0,24,31; addi 5,5,-20088; or 0,0,4; addi 4,1,8; sth 0,0x8(1); bl _s802BCDF0_0; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s802BCDF0_0();
extern "C" void f_802BCDF0() {}
