// 0x800EDD94 ObjectFolderImpl::AddSelector(ObjDefinition (948 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 20,0x30(1); stw 0,0x64(1); mr 27,4; mr 30,9; lha 0,0x20(27); mr 28,3; mr 23,5; mr 22,6; mr 29,7; mr 31,8; cmpwi 0,0; li 9,0; beq 0f; lwz 0,0x65c(28); cmpwi 0,0; beq 0f; li 9,1; 0:; cmpwi 9,0; li 3,0; bne 26f; li 3,168; rlwinm 24,31,16,0,15; bl _s800EDD94_0; addi 26,1,24; addi 25,1,16; bl _s800EDD94_1; mr 31,3; mr 4,27; addi 3,31,28; addi 21,31,12; bl _s800EDD94_2; addi 8,28,64; cmpwi 7,30,0; mr 20,8; li 7,0; li 11,0; 1:; rlwinm 9,11,2,0,29; addi 0,11,1; lwzx 9,8,9; li 10,0; cmpwi 9,0; beq 3f; 2:; lwz 9,0xa4(9); addi 10,10,1; cmpwi 9,0; bne 2b; 3:; mr 11,0; add 7,7,10; cmpwi 11,255; ble 1b; stw 7,0x70(31); stw 28,0x50(31); stw 29,0x54(31); stw 30,0x90(31); beq cr7,5f; lwz 9,0x10(30); li 4,0; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; addi 3,1,8; bl _s800EDD94_3; mr 3,31; addi 4,1,8; bl _s800EDD94_4; addi 3,1,8; li 4,2; bl _s800EDD94_5; 5:; lwz 3,0x690(28); mr 5,26; mr 4,29; bl _s800EDD94_6; cmpwi 3,0; beq 6f; lwz 0,0x18(1); li 9,1; b 7f; 6:; li 0,-1; li 9,0; 7:; cmpwi 9,0; bne 8f; li 0,-1; 8:; stw 0,0x4(31); lwz 4,0x34(29); cmpwi 4,0; beq 12f; lwz 3,0x690(28); addi 5,1,28; bl _s800EDD94_7; cmpwi 3,0; beq 9f; lwz 0,0x1c(1); li 9,1; b 10f; 9:; li 0,-1; li 9,0; 10:; cmpwi 9,0; bne 11f; li 0,-1; 11:; stw 0,0x8(31); 12:; lhz 0,0x7e(31); li 3,8; stw 23,0x14(31); or 0,0,24; stw 22,0x18(31); rlwinm 0,0,0,30,27; stw 0,0x7c(31); bl _s800EDD94_8; mr 4,31; bl _s800EDD94_9; stw 3,0x10(31); bl _s800EDD94_10; mr 29,3; lwz 4,0x4(31); lwz 30,0x0(29); li 5,0; mr 3,25; lha 0,0x20(30); addi 30,30,32; add 29,29,0; bl _s800EDD94_11; lwz 0,0x4(30); lis 4,-24789; mr 3,29; mr 5,25; mr 6,21; ori 4,4,49436; mtspr 8,0; blrl; cmpwi 3,0; beq 13f; lwz 3,0xc(31); mr 5,31; lwz 4,0x10(31); lwz 9,0x0(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; 13:; lha 30,0xb4(27); cmpwi 30,0; beq 25f; li 3,12; addi 29,28,1632; bl _s800EDD94_12; lwz 4,0x1c(27); mr 5,30; addi 26,1,32; bl _s800EDD94_13; lwz 30,0x4(29); lwz 0,0xc(29); stw 3,0x20(1); cmpw 30,0; beq 14f; stw 3,0x0(30); lwz 9,0x4(29); addi 9,9,4; stw 9,0x4(29); b 25f; 14:; lwz 0,0x660(28); li 9,1; stw 9,0x28(1); addi 11,1,40; subf 0,0,30; addi 9,1,36; srawi 3,0,2; stw 3,0x24(1); cmplwi 3,1; bge 15f; mr 9,11; 15:; lwz 0,0x0(9); add. 0,3,0; beq 17f; rlwinm 0,0,2,0,29; mr 27,0; cmplwi 0,128; ble 16f; mr 3,27; bl _s800EDD94_14; mr 28,3; b 18f; 16:; mr 3,27; bl _s800EDD94_15; mr 28,3; b 18f; 17:; li 28,0; li 27,0; 18:; lwz 4,0x0(29); cmpw 30,4; beq 19f; subf 30,4,30; mr 3,28; mr 5,30; bl _s800EDD94_16; add 0,3,30; b 20f; 19:; mr 0,28; 20:; lwz 9,0x28(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 22f; 21:; lwz 0,0x0(26); stw 0,0x0(30); addi 30,30,4; bdnz 21b; 22:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 24f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 23f; bl _s800EDD94_17; b 24f; 23:; bl _s800EDD94_18; 24:; add 0,27,28; stw 28,0x0(29); stw 0,0xc(29); stw 30,0x4(29); 25:; mr 3,31; bl _s800EDD94_19; rlwinm 9,3,2,22,29; lwzx 0,20,9; li 3,1; stw 0,0xa4(31); stwx 31,20,9; 26:; lwz 0,0x64(1); mtspr 8,0; lmw 20,0x30(1); addi 1,1,96"

extern "C" void _s800EDD94_0();
extern "C" void _s800EDD94_1();
extern "C" void _s800EDD94_2();
extern "C" void _s800EDD94_3();
extern "C" void _s800EDD94_4();
extern "C" void _s800EDD94_5();
extern "C" void _s800EDD94_6();
extern "C" void _s800EDD94_7();
extern "C" void _s800EDD94_8();
extern "C" void _s800EDD94_9();
extern "C" void _s800EDD94_10();
extern "C" void _s800EDD94_11();
extern "C" void _s800EDD94_12();
extern "C" void _s800EDD94_13();
extern "C" void _s800EDD94_14();
extern "C" void _s800EDD94_15();
extern "C" void _s800EDD94_16();
extern "C" void _s800EDD94_17();
extern "C" void _s800EDD94_18();
extern "C" void _s800EDD94_19();

struct ObjectFolderImpl {
    void AddSelector_ObjDefinition();
};

void ObjectFolderImpl::AddSelector_ObjDefinition() {
}
