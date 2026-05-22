// 0x80039F14 FlashPiMenu::CreateObjectMenuFromObjList(TNodeList<ISimInstance (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 28,0x10(1); stw 0,0x24(1); stw 12,0xc(1); mr 30,3; lis 9,-32697; lwz 11,0x8(30); addi 9,9,24012; addi 9,9,188; rlwinm 11,11,2,0,29; lwzx 0,9,11; cmpwi 0,0; li 3,0; beq 4f; lwz 3,0x0(4); li 29,0; lwz 0,0x4(4); cmpwi 7,3,0; mfcr 28; rlwinm 28,28,31,31,31; cmpw 3,0; bne 0f; xori 29,28,1; 0:; mr 31,3; cmpwi 4,29,0; beq cr7,2f; 1:; lwz 3,0x0(31); bl _s80039F14_0; mr 4,3; mr 5,29; mr 3,30; bl _s80039F14_1; lwz 31,0x8(31); cmpwi 31,0; bne 1b; 2:; bne cr4,3f; mr 4,28; mr 3,30; bl _s80039F14_2; cmpwi 3,0; bne 3f; li 3,0; b 4f; 3:; lis 9,-32697; lwz 4,0x8(30); lwz 3,0x5bc8(9); bl _s80039F14_3; 4:; lwz 0,0x24(1); lwz 12,0xc(1); mtspr 8,0; lmw 28,0x10(1); mtcrf 8,12; addi 1,1,32"
extern "C" void _s80039F14_0();
extern "C" void _s80039F14_1();
extern "C" void _s80039F14_2();
extern "C" void _s80039F14_3();
extern "C" void f_80039F14() {}
