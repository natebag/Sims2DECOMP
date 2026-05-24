// 0x801905E8 SerializeUIGameData::Save(NghResFile::SectionID, (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s801905E8_0; li 4,1024; li 5,0; bl _s801905E8_1; lis 0,21865; stw 3,-31448(13); ori 0,0,30769; cmpw 31,0; bne 0f; mr 4,3; li 5,1; li 3,0; li 6,0; bl _s801905E8_2; b 6f; 0:; lis 0,21865; li 11,0; ori 0,0,30770; cmpw 31,0; beq 1f; ble 4f; lis 0,21865; ori 0,0,30771; cmpw 31,0; beq 2f; lis 0,21865; ori 0,0,30772; cmpw 31,0; beq 3f; b 4f; 1:; li 11,1; b 4f; 2:; li 11,2; b 4f; 3:; li 11,3; 4:; lis 9,-32701; rlwinm 0,11,2,0,29; addi 9,9,27664; lwz 11,-31448(13); lwzx 9,9,0; li 10,1008; 5:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 5b; lwz 0,0x0(9); stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); 6:; lwz 9,-31448(13); li 0,1024; stw 0,0x0(30); stw 9,0x4(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s801905E8_0();
extern "C" void _s801905E8_1();
extern "C" void _s801905E8_2();

struct NghResFile {
    void Save_NghResFile__SectionID();
};

void NghResFile::Save_NghResFile__SectionID() {
}
