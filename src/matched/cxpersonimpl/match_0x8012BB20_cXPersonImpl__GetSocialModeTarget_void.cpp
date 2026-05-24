// 0x8012BB20 cXPersonImpl::GetSocialModeTarget(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lha 4,0x58(3); cmpwi 4,0; bne 0f; li 3,0; b 2f; 0:; lwz 11,0x0(3); lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x488(9); lwz 0,0x48c(9); add 3,10,3; mtspr 8,0; blrl; mr. 3,3; beq 1f; lwz 3,0x0(3); li 4,2; bl _s8012BB20_0; b 2f; 1:; li 3,0; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s8012BB20_0();

struct cXPersonImpl {
    void GetSocialModeTarget();
};

void cXPersonImpl::GetSocialModeTarget() {
}
