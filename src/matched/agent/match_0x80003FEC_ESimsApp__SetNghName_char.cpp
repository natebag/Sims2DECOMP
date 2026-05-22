// 0x80003FEC ESimsApp::SetNghName(char (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; lis 4,-32707; mr 3,31; addi 4,4,-19988; bl _s80003FEC_0; cmpwi 3,0; bne 0f; lis 4,-32707; mr 3,31; addi 4,4,-19980; bl _s80003FEC_1; cmpwi 3,0; beq 1f; 0:; mr 3,31; bl _s80003FEC_2; cmplwi 3,4; ble 1f; lis 30,-32688; mr 4,31; addi 3,30,-20016; li 5,16; bl _s80003FEC_3; addi 30,30,-20016; li 0,0; stb 0,0xf(30); 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80003FEC_0();
extern "C" void _s80003FEC_1();
extern "C" void _s80003FEC_2();
extern "C" void _s80003FEC_3();
extern "C" void f_80003FEC() {}
