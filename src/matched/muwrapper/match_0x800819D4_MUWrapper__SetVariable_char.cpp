// 0x800819D4 MUWrapper::SetVariable(char (532 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lis 3,-32707; mr 29,5; addi 3,3,28188; bl _s800819D4_0; cmpwi 3,0; bne 0f; lwz 0,0xa8(31); cmpwi 0,0; beq 7f; mr 3,29; bl _s800819D4_1; stw 3,0xcc(31); b 7f; 0:; lis 3,-32707; mr 4,30; addi 3,3,28208; bl _s800819D4_2; cmpwi 3,0; bne 1f; lwz 0,0xa8(31); cmpwi 0,0; beq 7f; mr 3,29; bl _s800819D4_3; stw 3,0xd0(31); li 4,0; mr 3,31; bl _s800819D4_4; lwz 5,0xd0(31); li 4,1; lwz 3,0xa8(31); addi 5,5,-1; bl _s800819D4_5; b 7f; 1:; lis 3,-32707; mr 4,30; addi 3,3,28228; bl _s800819D4_6; cmpwi 3,0; bne 2f; mr 3,29; bl _s800819D4_7; stfs f1,0xd4(31); b 7f; 2:; lis 3,-32707; mr 4,30; addi 3,3,28244; bl _s800819D4_8; cmpwi 3,0; bne 3f; mr 3,29; bl _s800819D4_9; stfs f1,0xd8(31); b 7f; 3:; lis 3,-32707; mr 4,30; addi 3,3,28260; bl _s800819D4_10; cmpwi 3,0; bne 4f; mr 3,29; bl _s800819D4_11; stfs f1,0xdc(31); b 7f; 4:; lis 3,-32707; mr 4,30; addi 3,3,28276; bl _s800819D4_12; cmpwi 3,0; bne 5f; mr 3,29; bl _s800819D4_13; stfs f1,0xe0(31); mr 3,31; li 4,0; bl _s800819D4_14; b 7f; 5:; lis 3,-32707; mr 4,30; addi 3,3,28292; bl _s800819D4_15; cmpwi 3,0; beq 7f; lis 3,-32707; mr 4,30; addi 3,3,28316; bl _s800819D4_16; cmpwi 3,0; bne 6f; lwz 0,0xa8(31); cmpwi 0,0; beq 7f; mr 3,29; bl _s800819D4_17; lwz 11,0xa8(31); lwz 10,0x60(11); lwz 9,0x1c(10); lha 3,0x48(9); lwz 0,0x4c(9); add 3,10,3; mtspr 8,0; blrl; b 7f; 6:; lis 3,-32707; mr 4,30; addi 3,3,28340; bl _s800819D4_18; cmpwi 3,0; bne 7f; lwz 0,0xa8(31); cmpwi 0,0; beq 7f; mr 3,29; bl _s800819D4_19; lwz 11,0xa8(31); lwz 10,0x60(11); lwz 9,0x1c(10); lha 3,0x58(9); lwz 0,0x5c(9); add 3,10,3; mtspr 8,0; blrl; 7:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s800819D4_0();
extern "C" void _s800819D4_1();
extern "C" void _s800819D4_2();
extern "C" void _s800819D4_3();
extern "C" void _s800819D4_4();
extern "C" void _s800819D4_5();
extern "C" void _s800819D4_6();
extern "C" void _s800819D4_7();
extern "C" void _s800819D4_8();
extern "C" void _s800819D4_9();
extern "C" void _s800819D4_10();
extern "C" void _s800819D4_11();
extern "C" void _s800819D4_12();
extern "C" void _s800819D4_13();
extern "C" void _s800819D4_14();
extern "C" void _s800819D4_15();
extern "C" void _s800819D4_16();
extern "C" void _s800819D4_17();
extern "C" void _s800819D4_18();
extern "C" void _s800819D4_19();

struct MUWrapper {
    void SetVariable();
};

void MUWrapper::SetVariable() {
}
