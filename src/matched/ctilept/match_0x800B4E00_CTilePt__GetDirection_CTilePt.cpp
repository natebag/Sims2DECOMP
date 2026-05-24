// 0x800B4E00 CTilePt::GetDirection(CTilePt (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lbz 9,0x1(30); lbz 0,0x1(31); lbz 10,0x0(30); extsb 9,9; lbz 11,0x0(31); extsb 0,0; subf 9,0,9; cmpw 10,11; beq 0f; cmpwi 9,0; beq 1f; bl _s800B4E00_0; cmpwi 3,0; li 3,4; bne 4f; mr 3,31; mr 4,30; bl _s800B4E00_1; cmpwi 3,0; li 3,5; bne 4f; mr 3,31; mr 4,30; bl _s800B4E00_2; cmpwi 3,0; li 3,7; bne 4f; mr 3,31; mr 4,30; bl _s800B4E00_3; cmpwi 3,0; beq 3f; li 3,6; b 4f; 0:; cmpwi 9,0; bne 2f; 1:; li 3,2; blt 4f; li 3,3; b 4f; 2:; li 3,1; b 4f; 3:; li 3,8; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800B4E00_0();
extern "C" void _s800B4E00_1();
extern "C" void _s800B4E00_2();
extern "C" void _s800B4E00_3();

struct CTilePt {
    void GetDirection_CTilePt();
};

void CTilePt::GetDirection_CTilePt() {
}
