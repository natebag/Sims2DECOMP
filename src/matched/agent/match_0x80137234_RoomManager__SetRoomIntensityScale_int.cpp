// 0x80137234 RoomManager::SetRoomIntensityScale(int, (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; mfcr 12; stfd f31,0x30(1); stmw 28,0x20(1); stw 0,0x3c(1); stw 12,0x1c(1); mr 30,3; fmr f31,f1; cmpwi 4,4,0; li 28,1; bl _s80137234_0; mr 29,3; addi 31,1,8; lwz 9,0x4(29); lwz 3,0x8(9); b 4f; 0:; lwz 8,0x14(3); cmpwi 8,0; beq 3f; lwz 0,0x34(8); cmpwi 0,0; beq 3f; lhz 0,0x0(8); cmpw 0,30; bne 1f; beq cr4,2f; 1:; cmpw 0,30; beq 3f; beq cr4,3f; 2:; stfs f31,0x8(31); addi 10,8,56; stfs f31,0x4(31); stfs f31,0x8(1); lwz 11,0xc(1); lwz 0,0x8(1); lwz 9,0x10(1); stw 0,0x38(8); stw 9,0x8(10); stw 11,0x4(10); stw 28,0x44(8); 3:; bl _s80137234_1; 4:; lwz 0,0x4(29); li 9,1; cmpw 3,0; bne 5f; li 9,0; 5:; cmpwi 9,0; bne 0b; lwz 0,0x3c(1); lwz 12,0x1c(1); mtspr 8,0; lmw 28,0x20(1); lfd f31,0x30(1); mtcrf 8,12; addi 1,1,56"
extern "C" void _s80137234_0();
extern "C" void _s80137234_1();
extern "C" void f_80137234() {}
