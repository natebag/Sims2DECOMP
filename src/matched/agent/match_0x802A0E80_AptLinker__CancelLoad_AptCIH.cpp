// 0x802A0E80 AptLinker::CancelLoad(AptCIH (360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 30,3; lwz 0,0x0(30); stw 0,0x10(1); addi 10,1,8; b 1f; 0:; lwz 9,0x0(11); lwz 0,0x8(9); cmpw 0,4; beq 6f; lwz 0,0x4(11); stw 0,0x10(1); 1:; li 0,0; lwz 11,0x10(1); stw 0,0x18(1); li 0,1; cmpwi 11,0; bne 2f; li 0,0; 2:; cmpwi 0,0; bne 0b; stw 0,0x8(1); 3:; li 0,0; lwz 31,0x8(1); stw 0,0x10(1); li 0,1; cmpwi 7,31,0; bne cr7,4f; li 0,0; 4:; cmpwi 0,0; beq 11f; lwz 0,0x0(30); cmpw 31,0; bne 7f; beq cr7,11f; lwz 3,0x0(31); lwz 29,0x4(31); cmpwi 3,0; beq 5f; bl _s802A0E80_0; cmpwi 3,0; bne 5f; lwz 3,0x0(31); bl _s802A0E80_1; 5:; lwz 3,-23020(13); mr 4,31; li 5,8; bl _s802A0E80_2; stw 29,0x0(30); b 11f; 6:; stw 11,0x8(1); b 3b; 7:; mr. 11,0; beq 9f; lwz 0,0x4(11); cmpw 0,31; beq 9f; 8:; lwz 11,0x4(11); cmpwi 11,0; beq 9f; lwz 9,0x4(11); lwz 0,0x0(10); cmpw 9,0; bne 8b; 9:; lwz 31,0x4(11); cmpwi 31,0; beq 11f; lwz 0,0x4(31); stw 0,0x4(11); beq 11f; lwz 3,0x0(31); cmpwi 3,0; beq 10f; bl _s802A0E80_3; cmpwi 3,0; bne 10f; lwz 3,0x0(31); bl _s802A0E80_4; 10:; lwz 3,-23020(13); mr 4,31; li 5,8; bl _s802A0E80_5; 11:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s802A0E80_0();
extern "C" void _s802A0E80_1();
extern "C" void _s802A0E80_2();
extern "C" void _s802A0E80_3();
extern "C" void _s802A0E80_4();
extern "C" void _s802A0E80_5();
extern "C" void f_802A0E80() {}
