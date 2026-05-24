// 0x80200D30 RELTarget::SetVariable(char (876 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 29,0x34(1); stw 0,0x44(1); mr 30,4; mr 31,3; lbz 9,0x0(30); mr 29,5; addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 30,30,1; 0:; lis 3,-32704; mr 4,30; addi 3,3,-18248; bl _s80200D30_0; cmpwi 3,0; bne 1f; lwz 0,0x88(31); cmpwi 0,0; beq 17f; mr 3,29; bl _s80200D30_1; mr 0,3; mulli 4,0,6; mr 3,31; stw 0,0x8c(31); bl _s80200D30_2; b 17f; 1:; lis 3,-32704; mr 4,30; addi 3,3,-18236; bl _s80200D30_3; cmpwi 3,0; bne 16f; lwz 0,0x88(31); cmpwi 0,0; beq 17f; mr 3,29; bl _s80200D30_4; lwz 0,0x8c(31); mr 4,3; stw 4,0x90(31); mr 3,31; mulli 0,0,6; add 4,0,4; bl _s80200D30_5; mr. 29,3; beq 17f; addi 30,1,16; addi 3,1,8; bl _s80200D30_6; lwz 5,0x1c(29); lis 4,-32704; addi 4,4,-30836; mr 3,30; crxor 6,6,6; bl _s80200D30_7; mr 4,30; addi 3,1,8; bl _s80200D30_8; lwz 0,0x9c(31); cmpwi 0,0; bne 2f; addi 3,1,8; bl _s80200D30_9; mr 4,3; lis 3,-32704; addi 3,3,-23620; bl _s80200D30_10; b 3f; 2:; addi 3,1,8; bl _s80200D30_11; mr 4,3; lis 3,-32704; addi 3,3,-23604; bl _s80200D30_12; 3:; lis 3,-32697; lwz 4,0x8(29); addi 3,3,24012; bl _s80200D30_13; mr. 30,3; beq 5f; lwz 9,0xc(30); addi 3,31,148; li 4,0; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; bl _s80200D30_14; b 6f; 5:; lis 4,-32704; addi 3,31,148; addi 4,4,-30460; bl _s80200D30_15; 6:; cmpwi 30,0; beq 8f; lwz 5,0x8(30); cmpwi 5,0; beq 8f; lwz 0,0x9c(31); cmpwi 0,0; bne 7f; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-18504; cmpwi 0,0; beq 15f; lwz 3,0x1c(31); cmpwi 3,0; beq 15f; lwz 6,0x7c(31); b 13f; 7:; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-18488; cmpwi 0,0; beq 15f; lwz 3,0x1c(31); cmpwi 3,0; beq 15f; lwz 6,0x7c(31); b 13f; 8:; lwz 0,0xc(29); cmpwi 0,0; beq 11f; lwz 3,0x98(31); cmpwi 3,0; beq 9f; bl _s80200D30_16; li 0,0; stw 0,0x98(31); 9:; lwz 9,0xc(29); addi 4,31,152; lwz 3,0xc(9); bl _s80200D30_17; lwz 5,0x98(31); cmpwi 5,0; beq 12f; lwz 0,0x9c(31); cmpwi 0,0; bne 10f; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-18504; cmpwi 0,0; beq 11f; lwz 3,0x1c(31); cmpwi 3,0; beq 11f; lwz 6,0x7c(31); li 7,0; bl _s80200D30_18; b 11f; 10:; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-18488; cmpwi 0,0; beq 11f; lwz 3,0x1c(31); cmpwi 3,0; beq 11f; lwz 6,0x7c(31); li 7,0; bl _s80200D30_19; 11:; lwz 0,0x98(31); cmpwi 0,0; bne 15f; 12:; lwz 0,0x9c(31); cmpwi 0,0; bne 14f; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-18504; cmpwi 0,0; beq 15f; lwz 3,0x1c(31); cmpwi 3,0; beq 15f; lis 5,14705; lwz 6,0x7c(31); ori 5,5,38864; 13:; li 7,0; bl _s80200D30_20; b 15f; 14:; lwz 0,0x0(31); lis 9,-32704; addi 4,9,-18488; cmpwi 0,0; beq 15f; lwz 3,0x1c(31); cmpwi 3,0; beq 15f; lis 5,14705; lwz 6,0x7c(31); ori 5,5,38864; li 7,0; bl _s80200D30_21; 15:; addi 3,1,8; li 4,2; bl _s80200D30_22; b 17f; 16:; lis 3,-32704; mr 4,30; addi 3,3,-18216; bl _s80200D30_23; cmpwi 3,0; bne 17f; lwz 0,0x88(31); cmpwi 0,0; beq 17f; mr 3,29; bl _s80200D30_24; stw 3,0x90(31); 17:; lwz 0,0x44(1); mtspr 8,0; lmw 29,0x34(1); addi 1,1,64"

extern "C" void _s80200D30_0();
extern "C" void _s80200D30_1();
extern "C" void _s80200D30_2();
extern "C" void _s80200D30_3();
extern "C" void _s80200D30_4();
extern "C" void _s80200D30_5();
extern "C" void _s80200D30_6();
extern "C" void _s80200D30_7();
extern "C" void _s80200D30_8();
extern "C" void _s80200D30_9();
extern "C" void _s80200D30_10();
extern "C" void _s80200D30_11();
extern "C" void _s80200D30_12();
extern "C" void _s80200D30_13();
extern "C" void _s80200D30_14();
extern "C" void _s80200D30_15();
extern "C" void _s80200D30_16();
extern "C" void _s80200D30_17();
extern "C" void _s80200D30_18();
extern "C" void _s80200D30_19();
extern "C" void _s80200D30_20();
extern "C" void _s80200D30_21();
extern "C" void _s80200D30_22();
extern "C" void _s80200D30_23();
extern "C" void _s80200D30_24();

struct RELTarget {
    void SetVariable();
};

void RELTarget::SetVariable() {
}
