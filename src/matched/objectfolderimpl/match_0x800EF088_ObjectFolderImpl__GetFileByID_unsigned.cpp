// 0x800EF088 ObjectFolderImpl::GetFileByID(unsigned (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 31,3; cmpwi 30,-1; bne 1f; 0:; li 3,0; b 4f; 1:; lwz 0,-31848(13); cmpw 30,0; bne 2f; lwz 3,0x440(31); b 4f; 2:; lwz 3,0x690(31); lis 4,-32706; addi 4,4,-19424; bl _s800EF088_0; mulli 9,30,72; lwz 0,0x4(3); lwz 29,0x3c(31); mr 3,29; add 30,0,9; mr 4,30; bl _s800EF088_1; mr. 31,3; bne 3f; li 3,16; bl _s800EF088_2; bl _s800EF088_3; mr 31,3; li 5,0; stw 30,0x8(31); li 4,0; bl _s800EF088_4; lwz 9,0xc(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 3f; cmpwi 31,0; beq 0b; lwz 9,0xc(31); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; b 0b; 3:; mr 3,29; mr 4,31; bl _s800EF088_5; mr 3,31; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s800EF088_0();
extern "C" void _s800EF088_1();
extern "C" void _s800EF088_2();
extern "C" void _s800EF088_3();
extern "C" void _s800EF088_4();
extern "C" void _s800EF088_5();

struct ObjectFolderImpl {
    void GetFileByID();
};

void ObjectFolderImpl::GetFileByID() {
}
