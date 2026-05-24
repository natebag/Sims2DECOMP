// 0x8007E184 DlgWrapper::SetVariable(char (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; mr 31,4; mr 29,5; lwz 3,0xac(28); bl _s8007E184_0; cmpwi 3,0; bne 3f; lis 4,-32707; lwz 30,0xac(28); addi 4,4,27096; mr 3,31; li 5,16; bl _s8007E184_1; cmpwi 3,0; bne 2f; lbz 0,0x11(31); mr 3,29; xori 31,0,120; subfic 9,31,0; adde 31,9,31; bl _s8007E184_2; cmpwi 30,0; beq 3f; cmpwi 31,0; beq 0f; lwz 3,0x60(30); lwz 9,0x1c(3); lha 0,0x48(9); lwz 9,0x4c(9); b 1f; 0:; lwz 3,0x60(30); lwz 9,0x1c(3); lha 0,0x58(9); lwz 9,0x5c(9); 1:; add 3,3,0; mtspr 8,9; blrl; b 3f; 2:; lis 4,-32707; mr 3,31; addi 4,4,27116; bl _s8007E184_3; cmpwi 3,0; bne 3f; lis 4,-32707; mr 3,29; addi 4,4,27132; bl _s8007E184_4; subfic 0,3,0; adde 3,0,3; stw 3,0xb4(28); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s8007E184_0();
extern "C" void _s8007E184_1();
extern "C" void _s8007E184_2();
extern "C" void _s8007E184_3();
extern "C" void _s8007E184_4();

struct DlgWrapper {
    void SetVariable();
};

void DlgWrapper::SetVariable() {
}
