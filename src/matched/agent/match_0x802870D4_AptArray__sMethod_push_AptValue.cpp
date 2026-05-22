// 0x802870D4 AptArray::sMethod_push(AptValue (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 29,4; lwz 9,0x0(31); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,22; bne 0f; rlwinm 11,9,5,31,31; 0:; cmpwi 11,0; beq 6f; li 30,0; cmpw 30,29; bge 2f; lis 28,-32694; addi 27,28,-16032; 1:; lwz 9,-16032(28); mr 3,31; lwz 0,0x8(27); subf 9,30,9; lwz 4,0x2c(31); rlwinm 9,9,2,0,29; addi 30,30,1; add 9,9,0; lwz 5,-4(9); bl _s802870D4_0; cmpw 30,29; blt 1b; 2:; lwz 3,-26908(13); lwz 31,0x2c(31); cmpwi 3,0; beq 5f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 3f; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 4f; 3:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 4:; stw 31,0xc(3); b 7f; 5:; lwz 3,-23020(13); li 4,16; bl _s802870D4_1; mr 30,3; li 4,7; bl _s802870D4_2; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; mr 3,30; stw 9,0x8(30); b 7f; 6:; lwz 3,-22936(13); 7:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s802870D4_0();
extern "C" void _s802870D4_1();
extern "C" void _s802870D4_2();
extern "C" void f_802870D4() {}
