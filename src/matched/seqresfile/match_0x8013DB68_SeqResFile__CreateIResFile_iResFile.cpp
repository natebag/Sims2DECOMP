// 0x8013DB68 SeqResFile::CreateIResFile(iResFile (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-320(1); mfspr 0,8; stmw 23,0x11c(1); stw 0,0x144(1); mr 26,3; mr 28,5; mr 27,6; mr 24,7; mr 23,8; li 25,-250; mr. 30,4; beq 4f; addi 31,1,8; li 5,260; addi 4,31,8; mr 3,31; bl _s8013DB68_0; li 29,-250; mr 4,28; mr 3,31; bl _s8013DB68_1; mulli 9,27,20; mr 3,31; addi 9,9,208; add 28,26,9; mr 4,28; bl _s8013DB68_2; cmpwi 3,0; beq 0f; lwz 9,0xc(30); mr 4,31; lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; mr 29,3; 0:; cmpwi 29,0; beq 1f; mr 25,29; b 2f; 1:; lwz 9,0x0(24); addi 4,28,4; lwz 0,0x0(23); mulli 3,9,40; addi 9,9,1; stw 9,0x0(24); add 3,0,3; bl _s8013DB68_3; 2:; cmpwi 30,0; beq 3f; lwz 9,0xc(30); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,30,3; mtspr 8,0; blrl; 3:; cmpwi 25,-43; mr 3,25; beq 5f; 4:; mr 3,25; 5:; lwz 0,0x144(1); mtspr 8,0; lmw 23,0x11c(1); addi 1,1,320"

extern "C" void _s8013DB68_0();
extern "C" void _s8013DB68_1();
extern "C" void _s8013DB68_2();
extern "C" void _s8013DB68_3();

struct SeqResFile {
    void CreateIResFile_iResFile();
};

void SeqResFile::CreateIResFile_iResFile() {
}
