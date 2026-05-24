// 0x8012B978 cXPersonImpl::CheckSecondPlayerForFailedSocialModeEntry(void) (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 30,3; lwz 0,0x5c70(9); cmpwi 0,0; beq 2f; lis 31,-32697; li 4,0; addi 3,31,24012; bl _s8012B978_0; lwz 0,0x4(30); cmpw 0,3; bne 0f; addi 3,31,24012; li 4,1; b 1f; 0:; addi 3,31,24012; li 4,0; 1:; bl _s8012B978_1; mr 31,3; cmpwi 31,0; beq 2f; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0xf0(9); lwz 9,0xf4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 2f; lwz 11,0x4(30); li 4,0; lwz 9,0x4(11); lwz 0,0x364(9); lha 3,0x360(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x4(30); li 4,0; lwz 9,0x4(11); lwz 0,0x344(9); lha 3,0x340(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x3f4(30); lwz 9,0x0(11); lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x4(30); li 5,0; li 4,40; lwz 9,0x4(11); lwz 0,0x144(9); lha 3,0x140(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x4(31); lwz 0,0xcc(9); lha 3,0xc8(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x4(31); li 4,0; lwz 0,0x33c(9); lha 3,0x338(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x4(31); li 4,40; li 5,0; lwz 0,0x144(9); lha 3,0x140(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x4(31); lha 3,0x188(9); lwz 0,0x18c(9); add 3,31,3; mtspr 8,0; blrl; mr. 11,3; beq 2f; lwz 9,0x0(11); lha 3,0x138(9); lwz 0,0x13c(9); add 3,11,3; mtspr 8,0; blrl; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8012B978_0();
extern "C" void _s8012B978_1();

struct cXPersonImpl {
    void CheckSecondPlayerForFailedSocialModeEntry();
};

void cXPersonImpl::CheckSecondPlayerForFailedSocialModeEntry() {
}
