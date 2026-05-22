// 0x802A81DC AptError::~AptError(void) (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32703; mr 31,3; addi 9,9,-20464; lwz 11,0x28(31); stw 9,0x8(31); mr 30,4; lhz 9,0x0(11); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(11); cmpwi 0,0; bne 0f; lhz 5,0x4(11); mr 4,11; lwz 3,-23020(13); addi 5,5,9; bl _s802A81DC_0; 0:; lwz 4,0x24(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802A81DC_1; 1:; lis 9,-32703; addi 3,31,12; addi 9,9,21120; li 4,2; stw 9,0x8(31); bl _s802A81DC_2; mr 3,31; li 4,0; bl _s802A81DC_3; andi. 0,30,1; beq 2f; lwz 3,-23016(13); mr 4,31; li 5,44; bl _s802A81DC_4; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802A81DC_0();
extern "C" void _s802A81DC_1();
extern "C" void _s802A81DC_2();
extern "C" void _s802A81DC_3();
extern "C" void _s802A81DC_4();
extern "C" void f_802A81DC() {}
