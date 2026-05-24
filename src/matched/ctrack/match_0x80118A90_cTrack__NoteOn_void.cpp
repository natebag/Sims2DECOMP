// 0x80118A90 cTrack::NoteOn(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 3,0x50(31); cmpwi 3,0; bne 0f; lis 4,-32706; mr 3,31; addi 4,4,-14664; b 2f; 0:; lwz 0,0xc(31); cmpwi 0,0; beq 1f; bl _s80118A90_0; mr 30,3; mr 3,31; bl _s80118A90_1; mr 3,30; b 3f; 1:; lis 4,-32706; mr 3,31; addi 4,4,-14624; 2:; bl _s80118A90_2; li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80118A90_0();
extern "C" void _s80118A90_1();
extern "C" void _s80118A90_2();

struct cTrack {
    void NoteOn();
};

void cTrack::NoteOn() {
}
