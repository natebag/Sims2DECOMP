// 0x802B6D8C AptScriptColour::sMethod_getRGB(AptValue (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lwz 30,0x24(3); cmpwi 30,0; beq 3f; mr 3,30; li 4,8; bl _s802B6D8C_0; fctiwz f0,f1; mr 3,30; stfd f0,0x8(1); li 4,9; lwz 9,0xc(1); rlwinm 31,9,16,0,15; bl _s802B6D8C_1; fctiwz f0,f1; mr 3,30; stfd f0,0x8(1); li 4,10; lwz 9,0xc(1); rlwinm 9,9,8,0,23; or 31,31,9; bl _s802B6D8C_2; fctiwz f0,f1; lwz 3,-26908(13); stfd f0,0x8(1); cmpwi 3,0; lwz 9,0xc(1); or 31,31,9; beq 2f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 0f; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 1f; 0:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 1:; stw 31,0xc(3); b 4f; 2:; lwz 3,-23020(13); li 4,16; bl _s802B6D8C_3; mr 30,3; li 4,7; bl _s802B6D8C_4; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; mr 3,30; stw 9,0x8(30); b 4f; 3:; lwz 3,-22936(13); 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s802B6D8C_0();
extern "C" void _s802B6D8C_1();
extern "C" void _s802B6D8C_2();
extern "C" void _s802B6D8C_3();
extern "C" void _s802B6D8C_4();
extern "C" void f_802B6D8C() {}
