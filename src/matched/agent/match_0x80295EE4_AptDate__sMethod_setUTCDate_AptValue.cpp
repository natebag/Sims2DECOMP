// 0x80295EE4 AptDate::sMethod_setUTCDate(AptValue (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; cmpwi 4,0; bgt 0f; lwz 3,-22936(13); b 4f; 0:; lis 9,-32694; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); bl _s80295EE4_0; stw 3,0x54(31); lwz 6,0x64(31); mr 3,31; addi 4,3,68; addi 5,3,36; neg 6,6; bl _s80295EE4_1; lwz 31,-26908(13); cmpwi 31,0; beq 3f; lwz 0,0x0(31); lwz 9,0xc(31); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); stw 11,0x0(31); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 1f; rlwinm 0,11,0,3,1; stw 0,0x0(31); b 2f; 1:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 31,11,9; stw 0,0x4(8); 2:; li 0,0; mr 3,31; stw 0,0xc(31); b 4f; 3:; lwz 3,-23020(13); li 4,16; bl _s80295EE4_2; mr 30,3; li 4,7; bl _s80295EE4_3; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; mr 3,30; stw 9,0x8(30); 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80295EE4_0();
extern "C" void _s80295EE4_1();
extern "C" void _s80295EE4_2();
extern "C" void _s80295EE4_3();
extern "C" void f_80295EE4() {}
