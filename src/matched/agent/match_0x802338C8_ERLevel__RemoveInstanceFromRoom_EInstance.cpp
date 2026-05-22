// 0x802338C8 ERLevel::RemoveInstanceFromRoom(EInstance (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,4; mr 29,3; lwz 3,0x54(30); cmpwi 3,-1; beq 3f; lwz 31,0x5c(30); andis. 28,31,1; beq 0f; addis 9,29,3; rlwinm 10,3,2,0,29; lwz 11,-23932(9); li 0,0; stwx 0,10,11; b 2f; 0:; andis. 0,31,2; beq 1f; mulli 3,3,12; addis 9,29,3; lwz 0,-23936(9); lwz 4,0x78(30); add 3,3,0; bl _s802338C8_0; stw 28,0x78(30); 1:; andi. 0,31,32768; beq 2f; mr 3,29; mr 4,30; bl _s802338C8_1; 2:; li 0,-1; stw 0,0x54(30); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802338C8_0();
extern "C" void _s802338C8_1();
extern "C" void f_802338C8() {}
