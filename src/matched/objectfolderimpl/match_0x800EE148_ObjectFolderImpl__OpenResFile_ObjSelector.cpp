// 0x800EE148 ObjectFolderImpl::OpenResFile(ObjSelector (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,4; lwz 29,0x3c(3); lwz 30,0x54(28); mr 3,29; mr 4,30; bl _s800EE148_0; mr. 31,3; bne 1f; li 3,16; bl _s800EE148_1; bl _s800EE148_2; mr 31,3; li 5,0; stw 30,0x8(31); li 4,0; bl _s800EE148_3; lwz 9,0xc(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; cmpwi 31,0; beq 0f; lwz 9,0xc(31); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; 0:; li 3,0; b 2f; 1:; mr 3,29; mr 4,31; bl _s800EE148_4; mr 3,31; 2:; stw 3,0x0(28); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s800EE148_0();
extern "C" void _s800EE148_1();
extern "C" void _s800EE148_2();
extern "C" void _s800EE148_3();
extern "C" void _s800EE148_4();

struct ObjectFolderImpl {
    void OpenResFile_ObjSelector();
};

void ObjectFolderImpl::OpenResFile_ObjSelector() {
}
