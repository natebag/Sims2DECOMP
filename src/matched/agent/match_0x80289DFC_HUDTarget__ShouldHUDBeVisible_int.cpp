// 0x80289DFC HUDTarget::ShouldHUDBeVisible(int) (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80289DFC_0; mr 3,30; lwz 0,0x84(1); mtspr 8,0; lmw 25,0x44(1); lfd f28,0x60(1); lfd f29,0x68(1); lfd f30,0x70(1); lfd f31,0x78(1); addi 1,1,128; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 0,0x0(3); li 11,0; rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 0f; rlwinm 11,0,5,31,31; 0:; cmpwi 11,0; beq 4f; lwz 9,0x58(3); lwz 3,-26908(13); srawi 9,9,15; addi 31,9,-16384; cmpwi 3,0; beq 3f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 1f; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 2f; 1:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 2:; stw 31,0xc(3); b 5f; 3:; lwz 3,-23020(13); li 4,16; bl _s80289DFC_1; mr 30,3; li 4,7; bl _s80289DFC_2; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; mr 3,30; stw 9,0x8(30); b 5f; 4:; lwz 3,-22936(13); 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80289DFC_0();
extern "C" void _s80289DFC_1();
extern "C" void _s80289DFC_2();
extern "C" void f_80289DFC() {}
