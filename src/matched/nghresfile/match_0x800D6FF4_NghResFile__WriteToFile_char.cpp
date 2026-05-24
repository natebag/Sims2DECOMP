// 0x800D6FF4 NghResFile::WriteToFile(char (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-304(1); mfspr 0,8; stmw 29,0x124(1); stw 0,0x134(1); addi 29,1,8; mr 30,4; mr 31,3; li 5,260; addi 4,29,8; mr 3,29; bl _s800D6FF4_0; mr 4,30; mr 5,29; mr 3,31; bl _s800D6FF4_1; mr 3,29; bl _s800D6FF4_2; lis 4,-32706; addi 4,4,-21636; bl _s800D6FF4_3; mr. 30,3; bne 0f; li 3,-42; b 1f; 0:; addi 4,1,280; addi 5,1,284; mr 3,31; bl _s800D6FF4_4; lwz 4,0x11c(1); mr 6,30; lwz 3,0x118(1); li 5,1; bl _s800D6FF4_5; bl _s800D6FF4_6; lwz 4,0x118(1); bl _s800D6FF4_7; mr 3,30; bl _s800D6FF4_8; li 3,0; 1:; lwz 0,0x134(1); mtspr 8,0; lmw 29,0x124(1); addi 1,1,304"

extern "C" void _s800D6FF4_0();
extern "C" void _s800D6FF4_1();
extern "C" void _s800D6FF4_2();
extern "C" void _s800D6FF4_3();
extern "C" void _s800D6FF4_4();
extern "C" void _s800D6FF4_5();
extern "C" void _s800D6FF4_6();
extern "C" void _s800D6FF4_7();
extern "C" void _s800D6FF4_8();

struct NghResFile {
    void WriteToFile();
};

void NghResFile::WriteToFile() {
}
