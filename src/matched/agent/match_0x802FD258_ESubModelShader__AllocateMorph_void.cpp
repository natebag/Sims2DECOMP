// 0x802FD258 ESubModelShader::AllocateMorph(void) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 31,3; lwz 30,0x18(31); cmpwi 30,0; beq 3f; addi 3,31,44; mr 4,30; li 5,0; bl _s802FD258_0; mulli 5,30,52; lwz 3,0x2c(31); lwz 4,0x14(31); crxor 6,6,6; bl _s802FD258_1; cmpwi 30,0; ble 3f; mr 28,30; li 25,0; lis 26,-32702; lis 27,-32702; li 29,0; 0:; lwz 9,0x14(31); lwz 11,0x2c(31); add 9,9,29; lwz 4,0x18(9); stwx 25,11,29; lwz 0,0x10(31); andi. 9,0,16; beq 1f; lwz 30,0x2c(31); rlwinm 4,4,3,0,28; mr 3,31; addi 5,26,-2744; li 6,2862; b 2f; 1:; lwz 30,0x2c(31); rlwinm 4,4,4,0,27; mr 3,31; addi 5,26,-2744; li 6,2867; 2:; addi 7,27,-2656; bl _s802FD258_2; stwx 3,30,29; addi 29,29,52; addic. 28,28,-1; bne 0b; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s802FD258_0();
extern "C" void _s802FD258_1();
extern "C" void _s802FD258_2();
extern "C" void f_802FD258() {}
