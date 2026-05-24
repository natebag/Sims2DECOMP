// 0x8012954C cXPersonImpl::IsSelectableByPlayer(int) (464 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 27,0xc(1); stw 0,0x24(1); stw 12,0x8(1); mr 31,3; mr 28,4; lwz 3,0x0(31); li 4,34; addi 3,3,40; bl _s8012954C_0; lha 0,0x0(3); cmpwi 0,0; bne 3f; lwz 9,0x0(31); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x1a8(11); lwz 0,0x1ac(11); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; beq 3f; cmpwi 4,28,-1; bne cr4,0f; li 27,3; b 1f; 0:; li 0,1; slw 27,0,28; 1:; lis 9,-32697; lwz 0,0x5c6c(9); cmpwi 0,0; beq 2f; lwz 3,-21424(13); lwz 4,0x4(31); lwz 9,0x0(3); lha 0,0x48(9); lwz 9,0x4c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; li 3,1; bne 8f; b 6f; 2:; lwz 10,0x4(31); lwz 30,-21476(13); lwz 9,0x4(10); lwz 11,0x0(30); lha 3,0x1b0(9); lwz 9,0x1b4(9); addi 29,11,184; add 3,10,3; lha 0,0xb8(11); mtspr 8,9; add 30,30,0; blrl; lwz 0,0x4(29); mr 4,3; mr 3,30; mtspr 8,0; blrl; mr. 30,3; beq 3f; mr 3,30; bl _s8012954C_1; cmpwi 3,0; bne 4f; 3:; li 3,0; b 8f; 4:; mr 3,30; bl _s8012954C_2; lwz 9,0x0(3); lha 0,0x98(9); lwz 9,0x9c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,1; bne 6f; beq cr4,5f; lwz 3,0x4(31); subfic 4,28,1; lwz 9,0x4(3); lha 0,0x128(9); lwz 9,0x12c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; li 3,0; bne 8f; 5:; li 3,1; b 8f; 6:; lwz 3,0x4(31); li 4,75; lwz 9,0x4(3); lha 0,0x138(9); lwz 9,0x13c(9); add 3,3,0; mtspr 8,9; blrl; li 0,1; and. 9,3,27; bne 7f; li 0,0; 7:; mr 3,0; 8:; lwz 0,0x24(1); lwz 12,0x8(1); mtspr 8,0; lmw 27,0xc(1); mtcrf 8,12; addi 1,1,32"

extern "C" void _s8012954C_0();
extern "C" void _s8012954C_1();
extern "C" void _s8012954C_2();

struct cXPersonImpl {
    void IsSelectableByPlayer();
};

void cXPersonImpl::IsSelectableByPlayer() {
}
