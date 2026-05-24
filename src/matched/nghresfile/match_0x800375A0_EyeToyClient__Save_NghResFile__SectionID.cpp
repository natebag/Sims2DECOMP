// 0x800375A0 EyeToyClient::Save(NghResFile::SectionID, (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 0,17785; li 9,0; ori 0,0,25907; cmpw 3,0; beq 2f; bgt 0f; lis 0,17785; ori 0,0,25905; cmpw 3,0; beq 1f; lis 0,17785; ori 0,0,25906; cmpw 3,0; beq 6f; b 7f; 0:; lis 0,17785; ori 0,0,25909; cmpw 3,0; beq 4f; blt 3f; lis 0,17785; ori 0,0,25910; cmpw 3,0; beq 5f; b 7f; 1:; mr 3,4; bl _s800375A0_0; b 7f; 2:; li 9,1; b 6f; 3:; li 9,2; b 6f; 4:; li 9,3; b 6f; 5:; li 9,4; 6:; mr 3,9; bl _s800375A0_1; 7:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s800375A0_0();
extern "C" void _s800375A0_1();

struct NghResFile {
    void Save_NghResFile__SectionID();
};

void NghResFile::Save_NghResFile__SectionID() {
}
