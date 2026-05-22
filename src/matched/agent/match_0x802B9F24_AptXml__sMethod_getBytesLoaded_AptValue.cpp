// 0x802B9F24 AptXml::sMethod_getBytesLoaded(AptValue (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 0,0x0(3); li 31,0; rlwinm 0,0,0,25,31; cmpwi 0,33; bne 0f; lwz 11,0x24(3); cmpwi 11,0; beq 0f; lwz 9,0x0(11); lha 3,0xf0(9); lwz 0,0xf4(9); add 3,11,3; mtspr 8,0; blrl; mr 31,3; 0:; lwz 3,-26908(13); cmpwi 3,0; beq 3f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 1f; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 2f; 1:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 2:; stw 31,0xc(3); b 4f; 3:; lwz 3,-23020(13); li 4,16; bl _s802B9F24_0; mr 30,3; li 4,7; bl _s802B9F24_1; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; mr 3,30; stw 9,0x8(30); 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802B9F24_0();
extern "C" void _s802B9F24_1();
extern "C" void f_802B9F24() {}
