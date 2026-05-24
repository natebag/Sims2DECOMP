// 0x80126194 cXPersonImpl::CancelAllActions(void) (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 30,0x50(1); stw 0,0x5c(1); mr 30,3; li 4,0; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0xd8(9); lwz 9,0xdc(9); add 3,3,0; mtspr 8,9; blrl; addic. 31,3,-1; blt 1f; 0:; lwz 11,0x4(30); mr 4,31; li 5,0; lwz 9,0x4(11); lwz 0,0xe4(9); lha 3,0xe0(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x4(30); lwz 4,0x38(3); lwz 9,0x4(11); lha 3,0xb8(9); lwz 0,0xbc(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 3f; addic. 31,31,-1; bge 0b; 1:; lwz 11,0x4(30); addi 31,1,8; lwz 9,0x4(11); lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,11,3; blrl; mr 4,3; addi 3,1,8; bl _s80126194_0; lwz 11,0x4(30); lwz 4,0x38(31); lwz 9,0x4(11); lha 3,0xb8(9); lwz 0,0xbc(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 2f; mr 3,31; li 4,2; bl _s80126194_1; li 3,1; b 4f; 2:; mr 3,31; li 4,2; bl _s80126194_2; 3:; li 3,0; 4:; lwz 0,0x5c(1); mtspr 8,0; lmw 30,0x50(1); addi 1,1,88"

extern "C" void _s80126194_0();
extern "C" void _s80126194_1();
extern "C" void _s80126194_2();

struct cXPersonImpl {
    void CancelAllActions();
};

void cXPersonImpl::CancelAllActions() {
}
