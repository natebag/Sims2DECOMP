// 0x800F6E50 ObjectModuleImpl::GetAnObjectID(short) (844 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 19,0x24(1); stw 0,0x5c(1); addi 0,4,-16383; mr 25,3; cmplwi 0,15; bgt 2f; addi 0,4,1; extsh 26,0; cmpwi 26,16398; bgt 1f; addi 3,25,8352; 0:; addi 0,26,-16384; rlwinm 0,0,2,0,29; lwzx 9,3,0; cmpwi 9,0; beq 31f; addi 0,26,1; extsh 26,0; cmpwi 26,16398; ble 0b; 1:; li 26,0; b 31f; 2:; addi 0,4,1; extsh 26,0; addi 27,25,8336; lwz 10,0x2090(25); b 4f; 3:; addi 0,26,1; extsh 26,0; 4:; lwz 0,0x4(27); rlwinm 9,26,0,16,31; mr 21,9; subf 0,10,0; srawi 11,0,2; cmplw 9,11; bgt 5f; addi 9,26,-1; rlwinm 9,9,2,0,29; lwzx 0,10,9; cmpwi 0,0; bne 3b; 5:; cmplw 11,21; bge 31f; li 19,0; mr 22,27; addi 20,1,8; li 23,1; 6:; lwz 9,0x4(22); lwz 0,0xc(22); stw 19,0x8(1); cmpw 9,0; beq 7f; stw 19,0x0(9); addi 29,25,28; addi 24,1,20; lwz 9,0x4(27); addi 9,9,4; stw 9,0x4(27); b 18f; 7:; lwz 30,0x4(27); addi 11,1,16; lwz 0,0x2090(25); addi 10,1,12; stw 23,0x10(1); subf 0,0,30; srawi 9,0,2; stw 9,0xc(1); cmplw 9,23; bge 8f; mr 10,11; 8:; lwz 0,0x0(10); add. 0,9,0; beq 10f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 9f; mr 3,28; bl _s800F6E50_0; mr 31,3; b 11f; 9:; mr 3,28; bl _s800F6E50_1; mr 31,3; b 11f; 10:; li 31,0; li 28,0; 11:; lwz 4,0x0(27); cmpw 30,4; beq 12f; subf 30,4,30; mr 3,31; mr 5,30; bl _s800F6E50_2; add 0,3,30; b 13f; 12:; mr 0,31; 13:; lwz 9,0x10(1); mr 30,0; addi 29,25,28; addi 24,1,20; mtspr 9,9; cmpwi 9,0; beq 15f; 14:; lwz 0,0x0(20); stw 0,0x0(30); addi 30,30,4; bdnz 14b; 15:; lwz 3,0x0(27); lwz 0,0xc(27); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 17f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 16f; bl _s800F6E50_3; b 17f; 16:; bl _s800F6E50_4; 17:; add 0,28,31; stw 31,0x0(27); stw 30,0x4(27); stw 0,0xc(27); 18:; lwz 30,0x4(29); li 9,0; lwz 0,0xc(29); stw 9,0x14(1); cmpw 30,0; beq 19f; stw 9,0x0(30); lwz 9,0x4(29); addi 9,9,4; stw 9,0x4(29); b 30f; 19:; lwz 0,0x1c(25); addi 11,1,28; stw 23,0x1c(1); addi 10,1,24; subf 0,0,30; srawi 9,0,2; stw 9,0x18(1); cmplw 9,23; bge 20f; mr 10,11; 20:; lwz 0,0x0(10); add. 0,9,0; beq 22f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 21f; mr 3,28; bl _s800F6E50_5; mr 31,3; b 23f; 21:; mr 3,28; bl _s800F6E50_6; mr 31,3; b 23f; 22:; li 31,0; li 28,0; 23:; lwz 4,0x0(29); cmpw 30,4; beq 24f; subf 30,4,30; mr 3,31; mr 5,30; bl _s800F6E50_7; add 0,3,30; b 25f; 24:; mr 0,31; 25:; lwz 9,0x1c(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 27f; 26:; lwz 0,0x0(24); stw 0,0x0(30); addi 30,30,4; bdnz 26b; 27:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 29f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 28f; bl _s800F6E50_8; b 29f; 28:; bl _s800F6E50_9; 29:; add 0,28,31; stw 31,0x0(29); stw 0,0xc(29); stw 30,0x4(29); 30:; lwz 0,0x4(27); lwz 9,0x2090(25); subf 0,9,0; srawi 0,0,2; cmplw 0,21; blt 6b; 31:; mr 3,26; lwz 0,0x5c(1); mtspr 8,0; lmw 19,0x24(1); addi 1,1,88"

extern "C" void _s800F6E50_0();
extern "C" void _s800F6E50_1();
extern "C" void _s800F6E50_2();
extern "C" void _s800F6E50_3();
extern "C" void _s800F6E50_4();
extern "C" void _s800F6E50_5();
extern "C" void _s800F6E50_6();
extern "C" void _s800F6E50_7();
extern "C" void _s800F6E50_8();
extern "C" void _s800F6E50_9();

struct ObjectModuleImpl {
    void GetAnObjectID_short();
};

void ObjectModuleImpl::GetAnObjectID_short() {
}
