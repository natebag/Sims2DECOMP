// 0x800F2480 ObjectFolderImpl::GetNamespaceSelector(unsigned (1248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-296(1); mfspr 0,8; stmw 18,0xf0(1); stw 0,0x12c(1); mr 8,4; stw 4,0xe8(1); cmpwi 8,-1; bne 0f; li 3,0; b 23f; 0:; li 0,0; addi 10,3,1728; stw 0,0x8(1); addi 9,1,232; mr 20,10; mr 18,9; lwz 3,0x4(10); lwz 11,0x4(3); cmpwi 11,0; beq 4f; mr 4,8; 1:; lwz 0,0x10(11); cmplw 0,4; blt 2f; mr 3,11; lwz 11,0x8(3); b 3f; 2:; lwz 11,0xc(11); 3:; cmpwi 11,0; bne 1b; 4:; lwz 11,0x4(10); cmpw 3,11; beq 5f; lwz 9,0x0(9); lwz 0,0x10(3); cmplw 9,0; bge 6f; 5:; mr 3,11; 6:; lwz 0,0x4(20); li 9,1; stw 3,0x8(1); stw 0,0x10(1); cmpw 3,0; bne 7f; li 9,0; 7:; cmpwi 9,0; bne 22f; mr 11,0; addi 19,1,16; lwz 9,0x4(11); addi 23,1,24; addi 22,1,32; addi 21,1,40; cmpwi 9,0; addi 31,1,48; beq 11f; lwz 10,0x0(18); 8:; lwz 0,0x10(9); cmplw 0,10; blt 9f; mr 11,9; lwz 9,0x8(11); b 10f; 9:; lwz 9,0xc(9); 10:; cmpwi 9,0; bne 8b; 11:; lwz 0,0x4(20); li 10,0; stw 11,0x18(1); cmpw 11,0; stw 0,0x20(1); beq 12f; lwz 9,0x10(11); lwz 0,0x0(18); cmplw 0,9; bge 13f; 12:; li 10,1; 13:; cmpwi 10,0; beq 14f; lwz 9,0x18(1); li 0,-1; addi 26,1,112; stw 0,0x70(1); li 29,0; stw 9,0x30(1); addi 28,1,120; stw 29,0x4(26); stw 29,0x4(28); li 3,20; bl _s800F2480_0; mr 9,3; addi 27,1,128; stw 9,0x0(9); addi 30,1,144; stw 9,0x4(9); addi 25,1,136; stw 9,0x4(28); addi 24,1,168; li 3,20; stw 29,0x4(27); bl _s800F2480_1; mr 9,3; stw 9,0x0(9); li 3,20; stw 9,0x4(9); stw 9,0x4(27); stw 29,0x4(25); bl _s800F2480_2; mr 9,3; stw 9,0x0(9); li 3,24; stw 9,0x4(9); stw 9,0x4(25); stw 29,0x4(30); bl _s800F2480_3; mr 9,3; stw 29,0x8(30); stw 9,0x4(30); addi 3,1,60; stb 29,0xc(30); mr 4,26; stw 29,0x0(9); lwz 11,0x4(30); stw 29,0x4(11); lwz 9,0x4(30); stw 9,0x8(9); lwz 11,0x4(30); stw 11,0xc(11); stw 29,0x30(26); lwz 0,0x0(18); stw 0,0x38(1); bl _s800F2480_4; lwz 0,0x30(1); addi 3,1,40; mr 5,24; mr 4,20; stw 0,0xa8(1); addi 6,1,56; bl _s800F2480_5; lwz 0,0x28(1); addi 3,1,60; li 4,2; stw 0,0x18(1); bl _s800F2480_6; mr 3,26; li 4,2; bl _s800F2480_7; 14:; lwz 0,0xe8(1); li 30,0; lwz 29,0x18(1); li 3,20; stw 0,0x10(1); stw 30,0x4(19); addi 28,29,20; stw 30,0x4(23); bl _s800F2480_8; mr 9,3; stw 9,0x0(9); li 3,20; stw 9,0x4(9); stw 9,0x4(23); stw 30,0x4(22); bl _s800F2480_9; mr 9,3; stw 9,0x0(9); li 3,20; stw 9,0x4(9); stw 9,0x4(22); stw 30,0x4(21); bl _s800F2480_10; mr 9,3; stw 9,0x0(9); li 3,24; stw 9,0x4(9); stw 9,0x4(21); stw 30,0x4(31); bl _s800F2480_11; mr 9,3; stw 30,0x8(31); stw 9,0x4(31); mr 4,23; stb 30,0xc(31); addi 3,29,28; stw 30,0x0(9); lwz 11,0x4(31); stw 30,0x4(11); lwz 9,0x4(31); stw 9,0x8(9); lwz 11,0x4(31); stw 11,0xc(11); stw 30,0x30(19); lwz 0,0x10(1); stw 0,0x14(29); lwz 9,0x14(1); stw 9,0x4(28); bl _s800F2480_12; mr 4,22; addi 3,29,36; bl _s800F2480_13; mr 4,21; addi 3,29,44; bl _s800F2480_14; mr 4,31; addi 3,29,52; bl _s800F2480_15; lwz 0,0x40(1); mr 3,19; li 4,2; stw 0,0x30(28); bl _s800F2480_16; lwz 11,0x4(20); lwz 9,0x4(11); cmpwi 9,0; beq 18f; lwz 10,0x0(18); 15:; lwz 0,0x10(9); cmplw 0,10; blt 16f; mr 11,9; lwz 9,0x8(11); b 17f; 16:; lwz 9,0xc(9); 17:; cmpwi 9,0; bne 15b; 18:; lwz 0,0x4(20); li 10,0; stw 11,0x10(1); cmpw 11,0; stw 0,0x18(1); beq 19f; lwz 9,0x10(11); lwz 0,0x0(18); cmplw 0,9; bge 20f; 19:; li 10,1; 20:; cmpwi 10,0; beq 21f; lwz 9,0x10(1); li 0,-1; addi 26,1,104; stw 0,0x68(1); li 29,0; stw 9,0x28(1); addi 28,1,112; stw 29,0x4(26); stw 29,0x4(28); li 3,20; bl _s800F2480_17; mr 9,3; addi 27,1,120; stw 9,0x0(9); addi 30,1,136; stw 9,0x4(9); addi 25,1,128; stw 9,0x4(28); addi 24,1,160; li 3,20; stw 29,0x4(27); bl _s800F2480_18; mr 9,3; stw 9,0x0(9); li 3,20; stw 9,0x4(9); stw 9,0x4(27); stw 29,0x4(25); bl _s800F2480_19; mr 9,3; stw 9,0x0(9); li 3,24; stw 9,0x4(9); stw 9,0x4(25); stw 29,0x4(30); bl _s800F2480_20; mr 9,3; stw 29,0x8(30); stw 9,0x4(30); addi 3,1,52; stb 29,0xc(30); mr 4,26; stw 29,0x0(9); lwz 11,0x4(30); stw 29,0x4(11); lwz 9,0x4(30); stw 9,0x8(9); lwz 11,0x4(30); stw 11,0xc(11); stw 29,0x30(26); lwz 0,0x0(18); stw 0,0x30(1); bl _s800F2480_21; lwz 0,0x28(1); addi 3,1,32; mr 4,20; mr 5,24; stw 0,0xa0(1); addi 6,1,48; bl _s800F2480_22; lwz 0,0x20(1); addi 3,1,52; li 4,2; stw 0,0x10(1); bl _s800F2480_23; mr 3,26; li 4,2; bl _s800F2480_24; 21:; lwz 3,0x10(1); 22:; addi 3,3,20; 23:; lwz 0,0x12c(1); mtspr 8,0; lmw 18,0xf0(1); addi 1,1,296"

extern "C" void _s800F2480_0();
extern "C" void _s800F2480_1();
extern "C" void _s800F2480_2();
extern "C" void _s800F2480_3();
extern "C" void _s800F2480_4();
extern "C" void _s800F2480_5();
extern "C" void _s800F2480_6();
extern "C" void _s800F2480_7();
extern "C" void _s800F2480_8();
extern "C" void _s800F2480_9();
extern "C" void _s800F2480_10();
extern "C" void _s800F2480_11();
extern "C" void _s800F2480_12();
extern "C" void _s800F2480_13();
extern "C" void _s800F2480_14();
extern "C" void _s800F2480_15();
extern "C" void _s800F2480_16();
extern "C" void _s800F2480_17();
extern "C" void _s800F2480_18();
extern "C" void _s800F2480_19();
extern "C" void _s800F2480_20();
extern "C" void _s800F2480_21();
extern "C" void _s800F2480_22();
extern "C" void _s800F2480_23();
extern "C" void _s800F2480_24();

struct ObjectFolderImpl {
    void GetNamespaceSelector();
};

void ObjectFolderImpl::GetNamespaceSelector() {
}
