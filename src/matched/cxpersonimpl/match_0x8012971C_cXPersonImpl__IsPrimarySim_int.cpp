// 0x8012971C cXPersonImpl::IsPrimarySim(int) (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32697; mr 27,3; addi 31,9,23428; mr 30,4; addi 3,31,244; li 28,0; bl _s8012971C_0; lwz 0,0xec(31); mr 29,3; cmpwi 0,0; beq 0f; addi 3,31,260; bl _s8012971C_1; mr 28,3; 0:; addi 0,30,1; cmplwi 0,1; bgt 1f; cmpwi 29,0; beq 1f; lwz 11,0x4(27); lwz 9,0x4(11); lwz 0,0x1b4(9); lha 3,0x1b0(9); mtspr 8,0; add 3,11,3; blrl; lha 0,0x4(29); cmpw 3,0; bne 1f; li 3,1; b 4f; 1:; cmpwi 30,1; beq 2f; cmpwi 30,-1; bne 3f; 2:; cmpwi 28,0; beq 3f; lwz 11,0x4(27); lwz 9,0x4(11); lwz 0,0x1b4(9); lha 3,0x1b0(9); mtspr 8,0; add 3,11,3; blrl; lha 0,0x4(28); cmpw 3,0; li 3,1; beq 4f; 3:; li 3,0; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s8012971C_0();
extern "C" void _s8012971C_1();

struct cXPersonImpl {
    void IsPrimarySim();
};

void cXPersonImpl::IsPrimarySim() {
}
