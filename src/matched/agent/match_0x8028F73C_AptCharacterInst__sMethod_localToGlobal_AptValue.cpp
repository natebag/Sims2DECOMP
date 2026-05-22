// 0x8028F73C AptCharacterInst::sMethod_localToGlobal(AptValue (624 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 26,0x30(1); stw 0,0x4c(1); mr 28,3; cmpwi 4,0; bne 0f; lwz 3,-22936(13); b 13f; 0:; lis 9,-32694; addi 30,1,8; lwz 11,-16032(9); lis 4,-32704; addi 9,9,-16032; addi 4,4,20124; lwz 0,0x8(9); rlwinm 11,11,2,0,29; mr 3,30; mr 26,30; add 11,11,0; lwz 27,-4(11); bl _s8028F73C_0; lis 4,-32704; addi 3,1,16; addi 4,4,20128; addi 29,27,12; bl _s8028F73C_1; mr 4,30; mr 3,29; bl _s8028F73C_2; mr 31,3; addi 4,1,16; mr 3,29; bl _s8028F73C_3; lfs f13,0xc(31); mr. 29,28; stfs f13,0x28(1); lfs f0,0xc(3); stfs f0,0x2c(1); beq 2f; addi 30,1,24; 1:; addi 3,29,16; mr 4,30; mr 5,30; bl _s8028F73C_4; lwz 29,0x48(29); cmpwi 29,0; bne 1b; 2:; lwz 3,-26912(13); lwz 29,0x28(1); cmpwi 3,0; beq 5f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26912(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 3f; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 4f; 3:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 4:; stw 29,0xc(3); mr 31,3; b 6f; 5:; lwz 3,-23020(13); li 4,16; bl _s8028F73C_5; mr 30,3; li 4,6; mr 31,30; bl _s8028F73C_6; lis 9,-32702; stw 29,0xc(30); addi 9,9,-26784; stw 9,0x8(30); 6:; addi 3,27,12; mr 5,31; mr 4,26; mr 29,3; bl _s8028F73C_7; lwz 5,-26912(13); lwz 31,0x2c(1); cmpwi 5,0; beq 9f; lwz 0,0x0(5); lwz 9,0xc(5); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26912(13); stw 11,0x0(5); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 7f; rlwinm 0,11,0,3,1; stw 0,0x0(5); b 8f; 7:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 5,11,9; stw 0,0x4(8); 8:; stw 31,0xc(5); b 10f; 9:; lwz 3,-23020(13); li 4,16; bl _s8028F73C_8; mr 30,3; li 4,6; bl _s8028F73C_9; lis 9,-32702; stw 31,0xc(30); addi 9,9,-26784; mr 5,30; stw 9,0x8(30); 10:; addi 4,1,16; mr 3,29; bl _s8028F73C_10; lwz 4,0x10(1); lwz 31,-22936(13); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 11f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8028F73C_11; 11:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 12f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8028F73C_12; 12:; mr 3,31; 13:; lwz 0,0x4c(1); mtspr 8,0; lmw 26,0x30(1); addi 1,1,72"
extern "C" void _s8028F73C_0();
extern "C" void _s8028F73C_1();
extern "C" void _s8028F73C_2();
extern "C" void _s8028F73C_3();
extern "C" void _s8028F73C_4();
extern "C" void _s8028F73C_5();
extern "C" void _s8028F73C_6();
extern "C" void _s8028F73C_7();
extern "C" void _s8028F73C_8();
extern "C" void _s8028F73C_9();
extern "C" void _s8028F73C_10();
extern "C" void _s8028F73C_11();
extern "C" void _s8028F73C_12();
extern "C" void f_8028F73C() {}
