// 0x80190728 SerializeUIGameData::SaveComplete(NghResFile::SectionID, (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-31448(13); cmpwi 0,0; beq 0f; bl _s80190728_0; lwz 4,-31448(13); bl _s80190728_1; li 0,0; stw 0,-31448(13); 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80190728_0();
extern "C" void _s80190728_1();
extern "C" void f_80190728() {}
