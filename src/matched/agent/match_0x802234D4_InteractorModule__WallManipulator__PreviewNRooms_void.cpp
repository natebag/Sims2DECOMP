// 0x802234D4 InteractorModule::WallManipulator::PreviewNRooms(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 11,-21488(13); li 4,0; li 29,0; lwz 9,0x0(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; lwz 30,-21472(13); lwz 9,0x4(30); lwz 31,0x8(9); b 2f; 0:; lwz 3,0x14(31); lwz 0,0x34(3); cmpwi 0,0; beq 1f; bl _s802234D4_0; cmpwi 3,0; bne 1f; addi 29,29,1; 1:; mr 3,31; bl _s802234D4_1; mr 31,3; 2:; lwz 0,0x4(30); li 9,1; cmpw 31,0; bne 3f; li 9,0; 3:; cmpwi 9,0; bne 0b; cmpwi 7,29,19; cror 31,30,28; mfcr 3; rlwinm 3,3,0,31,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802234D4_0();
extern "C" void _s802234D4_1();
extern "C" void f_802234D4() {}
