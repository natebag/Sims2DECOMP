// 0x802A5C8C AptKey::sMethod_getAscii(AptValue (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32694; lwz 0,-15972(9); rlwinm 11,0,30,24,31; rlwinm 31,0,15,17,31; cmpwi 11,0; bne 0f; lwz 3,-26908(13); cmpwi 3,0; beq 5f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; bge 2f; b 3f; 0:; cmpwi 31,19; bgt 1f; lis 9,-32703; rlwinm 0,31,2,0,29; addi 9,9,-19784; lwzx 31,9,0; 1:; lwz 3,-26908(13); cmpwi 3,0; beq 5f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 3f; 2:; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 4f; 3:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 4:; stw 31,0xc(3); b 6f; 5:; lwz 3,-23020(13); li 4,16; bl _s802A5C8C_0; mr 30,3; li 4,7; bl _s802A5C8C_1; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; mr 3,30; stw 9,0x8(30); 6:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802A5C8C_0();
extern "C" void _s802A5C8C_1();
extern "C" void f_802A5C8C() {}
