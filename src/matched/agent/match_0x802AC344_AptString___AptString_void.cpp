// 0x802AC344 AptString::~AptString(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32703; mr 31,3; addi 9,9,2048; lwz 11,0xc(31); stw 9,0x8(31); mr 30,4; lhz 9,0x0(11); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(11); cmpwi 0,0; bne 0f; lhz 5,0x4(11); mr 4,11; lwz 3,-23020(13); addi 5,5,9; bl _s802AC344_0; 0:; mr 3,31; li 4,0; bl _s802AC344_1; andi. 0,30,1; beq 1f; lwz 3,-23020(13); mr 4,31; li 5,20; bl _s802AC344_2; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802AC344_0();
extern "C" void _s802AC344_1();
extern "C" void _s802AC344_2();
extern "C" void f_802AC344() {}
