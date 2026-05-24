// 0x8029B89C AptDisplayList::clear(bool) (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; mfcr 12; stmw 25,0xc(1); stw 0,0x2c(1); stw 12,0x8(1); mr 29,3; lwz 9,0x0(29); cmpwi 9,0; beq 3f; lwz 9,0x0(9); lwz 31,0x54(9); cmpwi 31,0; beq 3f; cmpwi 4,4,0; lis 27,-32704; lis 28,-32704; li 25,0; lis 26,-32694; 0:; lwz 9,0x8(31); addi 4,27,30180; addi 5,28,29796; li 6,1508; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; lwz 30,0x54(31); mtspr 8,0; blrl; mr 3,29; mr 4,31; bl _s8029B89C_0; beq cr4,1f; lwz 0,0x0(31); mr 3,31; li 4,1; rlwimi 0,25,8,18,23; stw 0,0x0(31); bl _s8029B89C_1; 1:; lwz 3,-27600(13); lwz 0,0x4(3); cmpwi 0,0; beq 2f; lwz 0,-16032(26); cmpwi 0,0; bne 2f; bl _s8029B89C_2; 2:; lwz 9,0x8(31); addi 4,27,30180; addi 5,28,29796; li 6,1522; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; mr. 31,30; bne 0b; 3:; lwz 0,0x2c(1); lwz 12,0x8(1); mtspr 8,0; lmw 25,0xc(1); mtcrf 8,12; addi 1,1,40"

extern "C" void _s8029B89C_0();
extern "C" void _s8029B89C_1();
extern "C" void _s8029B89C_2();

struct AptDisplayList {
    void clear();
};

void AptDisplayList::clear() {
}
