// 0x80314034 ERFont::Load(EFile (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 29,0x3c(1); stw 0,0x4c(1); mr 31,3; mr 29,4; bl _s80314034_0; addi 3,1,8; bl _s80314034_1; lis 5,17999; addi 3,1,8; mr 4,29; ori 5,5,20052; li 6,10; li 7,10; bl _s80314034_2; cmpwi 3,0; beq 0f; addi 3,1,8; bl _s80314034_3; lwz 0,0x10(31); lwz 9,0x18(1); rlwimi 0,9,8,0,23; stw 0,0x10(31); b 1f; 0:; addi 3,1,32; mr 30,3; bl _s80314034_4; mr 4,30; mr 3,29; bl _s80314034_5; lwz 4,0x20(1); mr 3,30; bl _s80314034_6; 1:; mr 3,29; addi 4,31,20; bl _s80314034_7; lwz 10,0x18(31); cmpwi 10,0; beq 2f; lwz 10,0x0(10); lis 8,17200; lis 9,-32702; stw 10,0x54(31); lfd f13,0x6b8(9); lwz 0,0x4(10); xoris 0,0,32768; stw 0,0x34(1); stw 8,0x30(1); lfd f0,0x30(1); fsub f0,f0,f13; frsp f0,f0; stfs f0,0x4c(31); 2:; addi 3,1,8; li 4,2; bl _s80314034_8; lwz 0,0x4c(1); mtspr 8,0; lmw 29,0x3c(1); addi 1,1,72"

extern "C" void _s80314034_0();
extern "C" void _s80314034_1();
extern "C" void _s80314034_2();
extern "C" void _s80314034_3();
extern "C" void _s80314034_4();
extern "C" void _s80314034_5();
extern "C" void _s80314034_6();
extern "C" void _s80314034_7();
extern "C" void _s80314034_8();

struct ERFont {
    void Load_EFile();
};

void ERFont::Load_EFile() {
}
