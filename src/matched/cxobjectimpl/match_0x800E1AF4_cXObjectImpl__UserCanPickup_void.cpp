// 0x800E1AF4 cXObjectImpl::UserCanPickup(void) (452 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lwz 11,-21432(13); li 9,0; mr 30,3; stw 9,-31884(13); lwz 0,0x3dc(11); stw 9,-31888(13); cmpwi 0,0; bne 9f; addi 31,30,40; li 4,43; mr 3,31; bl _s800E1AF4_0; lhz 0,0x0(3); andi. 9,0,2; bne 0f; li 0,37; b 2f; 0:; mr 3,31; li 4,62; bl _s800E1AF4_1; lha 0,0x0(3); cmpwi 0,0; bgt 1f; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0x1e0(9); lwz 9,0x1e4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 3f; 1:; li 0,38; 2:; li 3,0; stw 0,-31888(13); b 10f; 3:; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0x2b0(9); lwz 9,0x2b4(9); add 3,3,0; mtspr 8,9; blrl; addic. 31,3,-1; blt 6f; 4:; lwz 3,0x4(30); mr 4,31; lwz 9,0x4(3); lha 0,0x2c0(9); lwz 9,0x2c4(9); add 3,3,0; mtspr 8,9; blrl; mr. 11,3; beq 5f; lwz 9,0x4(11); lha 3,0x158(9); lwz 0,0x15c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 7f; 5:; addic. 31,31,-1; bge 4b; 6:; lwz 11,0x4(30); addi 3,1,8; lwz 9,0x4(11); lwz 0,0x35c(9); lha 4,0x358(9); mtspr 8,0; add 4,11,4; blrl; lwz 11,-21488(13); addi 4,1,8; lwz 9,0x0(11); lha 3,0x60(9); lwz 0,0x64(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 8f; lwz 3,-21488(13); addi 4,1,8; lwz 9,0x0(3); lha 0,0x128(9); lwz 9,0x12c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 8f; li 0,39; addi 3,1,8; stw 0,-31888(13); li 4,2; bl _s800E1AF4_2; 7:; li 3,0; b 10f; 8:; addi 3,1,8; li 4,2; bl _s800E1AF4_3; 9:; li 3,1; 10:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s800E1AF4_0();
extern "C" void _s800E1AF4_1();
extern "C" void _s800E1AF4_2();
extern "C" void _s800E1AF4_3();

struct cXObjectImpl {
    void UserCanPickup();
};

void cXObjectImpl::UserCanPickup() {
}
