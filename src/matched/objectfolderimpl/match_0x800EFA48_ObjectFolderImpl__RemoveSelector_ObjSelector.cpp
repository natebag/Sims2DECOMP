// 0x800EFA48 ObjectFolderImpl::RemoveSelector(ObjSelector (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; mfcr 12; stmw 24,0x18(1); stw 0,0x3c(1); stw 12,0x14(1); mr 24,3; mr 28,4; mr 3,28; addi 27,24,64; bl _s800EFA48_0; li 26,0; stw 3,0x8(1); rlwinm 9,3,2,22,29; addi 25,1,8; mr 29,9; lwzx 31,27,9; b 1f; 0:; mr 26,31; lwz 31,0xa4(31); 1:; cmpwi 4,31,0; beq cr4,2f; lwz 30,0x0(25); mr 3,31; bl _s800EFA48_1; cmpw 30,3; bne 0b; cmpwi 26,0; beq 2f; lwz 0,0xa4(31); stw 0,0xa4(26); lwzx 9,27,29; stw 9,0xa4(31); stwx 31,27,29; 2:; beq cr4,7f; lwz 4,0x8(1); li 3,255; addi 31,24,64; bl _s800EFA48_2; li 4,0; li 3,220; bl _s800EFA48_3; mr 3,28; bl _s800EFA48_4; rlwinm 9,3,2,22,29; lwzx 11,31,9; cmpw 28,11; bne 3f; lwz 0,0xa4(28); stwx 0,31,9; b 6f; 3:; cmpwi 11,0; beq 6f; lwz 0,0xa4(11); mr 9,0; cmpwi 0,0; beq 6f; cmpw 9,28; beq 5f; 4:; mr 11,9; lwz 0,0xa4(11); cmpwi 0,0; beq 6f; mr 9,0; cmpw 0,28; bne 4b; 5:; cmpwi 9,0; beq 6f; lwz 0,0xa4(28); stw 0,0xa4(11); 6:; mr 3,24; mr 4,28; bl _s800EFA48_5; 7:; li 3,0; lwz 0,0x3c(1); lwz 12,0x14(1); mtspr 8,0; lmw 24,0x18(1); mtcrf 8,12; addi 1,1,56"

extern "C" void _s800EFA48_0();
extern "C" void _s800EFA48_1();
extern "C" void _s800EFA48_2();
extern "C" void _s800EFA48_3();
extern "C" void _s800EFA48_4();
extern "C" void _s800EFA48_5();

struct ObjectFolderImpl {
    void RemoveSelector_ObjSelector();
};

void ObjectFolderImpl::RemoveSelector_ObjSelector() {
}
