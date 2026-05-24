// 0x800F17A8 ObjectFolderImpl::GetTreeTable(ObjSelector (740 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 30,4; mr 3,30; bl _s800F17A8_0; mr. 3,3; beq 10f; rlwinm 5,3,0,16,31; lwz 4,0x4(30); addi 3,1,8; li 26,0; bl _s800F17A8_1; addi 31,1,16; stw 26,0x10(1); bl _s800F17A8_2; lwz 9,0x0(3); lwz 11,0x10(1); lha 0,0x28(9); addi 28,9,40; lwz 27,0x4(30); cmpwi 11,0; add 29,3,0; beq 0f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; stw 26,0x10(1); 0:; lwz 0,0x4(28); lis 4,27635; mr 3,29; mr 5,27; ori 4,4,8752; mr 6,31; mtspr 8,0; blrl; lwz 11,0x10(1); cmpwi 11,0; beq 10f; lwz 9,0x0(11); addi 4,1,8; lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 2f; lwz 0,0x3c(30); addi 6,30,60; cmpwi 0,0; bne 8f; cmpw 31,6; beq 8f; lwz 31,0x10(1); cmpwi 31,0; beq 8f; lwz 9,0x0(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; lwz 11,0x3c(30); cmpwi 11,0; beq 1f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 1:; stw 31,0x3c(30); b 8f; 2:; lwz 4,0x8(30); addi 3,1,8; bl _s800F17A8_3; lwz 3,0x10(1); addi 4,1,8; lwz 9,0x0(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 9f; lwz 0,0x3c(30); addi 6,30,60; cmpwi 0,0; bne 8f; cmpw 31,6; beq 4f; lwz 31,0x10(1); cmpwi 31,0; beq 4f; lwz 9,0x0(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; lwz 11,0x3c(30); cmpwi 11,0; beq 3f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 3:; stw 31,0x3c(30); 4:; lwz 3,0x10(1); li 31,0; lwz 9,0x0(3); lha 0,0x70(9); lwz 9,0x74(9); add 3,3,0; mtspr 8,9; blrl; mr 26,3; lwz 27,0x10(1); cmpw 31,26; bge 8f; 5:; lwz 9,0x0(27); mr 4,31; addi 28,31,1; lha 3,0x78(9); lwz 0,0x7c(9); add 3,27,3; mtspr 8,0; blrl; mr. 30,3; beq 7f; lwz 9,0x0(30); li 31,0; lha 3,0xf0(9); lwz 0,0xf4(9); add 3,30,3; mtspr 8,0; blrl; mr 29,3; cmpw 31,29; bge 7f; 6:; lwz 9,0x0(30); mr 4,31; addi 31,31,1; lha 3,0x110(9); lwz 0,0x114(9); add 3,30,3; mtspr 8,0; blrl; cmpw 31,29; blt 6b; 7:; mr 31,28; cmpw 31,26; blt 5b; 8:; lwz 11,0x10(1); cmpwi 11,0; beq 10f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; b 10f; 9:; lwz 11,0x10(1); cmpwi 11,0; beq 10f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 10:; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"

extern "C" void _s800F17A8_0();
extern "C" void _s800F17A8_1();
extern "C" void _s800F17A8_2();
extern "C" void _s800F17A8_3();

struct ObjectFolderImpl {
    void GetTreeTable_ObjSelector();
};

void ObjectFolderImpl::GetTreeTable_ObjSelector() {
}
