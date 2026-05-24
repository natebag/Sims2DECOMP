// 0x80363908 EFontPage::Read(EStream (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; bl _s80363908_0; lis 9,-32688; lhz 0,-10502(9); cmpwi 0,0; bne 0f; lwz 9,0x18(31); addi 4,30,4; li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x18(31); addi 4,30,12; li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x18(31); addi 4,30,16; li 5,4; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80363908_0();

struct EFontPage {
    void Read_EStream();
};

void EFontPage::Read_EStream() {
}
