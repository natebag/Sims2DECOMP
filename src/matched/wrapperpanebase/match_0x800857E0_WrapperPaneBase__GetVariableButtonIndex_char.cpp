// 0x800857E0 WrapperPaneBase::GetVariableButtonIndex(char (384 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 26,3; mr 31,4; lwz 4,0x38(26); mr 24,5; li 30,0; cmpwi 4,0; beq 0f; lwz 5,0x3c(26); cmpwi 5,0; beq 0f; mr 3,31; bl _s800857E0_0; cmpwi 3,0; bne 1f; 0:; li 30,1; 1:; cmpwi 30,0; beq 6f; lwz 0,0x3c(26); add 31,31,0; cmpwi 0,0; beq 2f; addi 31,31,1; 2:; lis 4,-32707; mr 3,31; addi 4,4,29360; li 5,7; bl _s800857E0_1; cmpwi 3,0; bne 6f; addi 28,31,7; li 4,95; mr 3,28; bl _s800857E0_2; mr. 27,3; beq 6f; addi 31,27,1; lis 4,-32707; addi 4,4,29368; mr 3,31; bl _s800857E0_3; cmpwi 3,0; beq 3f; lis 4,-32707; mr 3,31; addi 4,4,29372; bl _s800857E0_4; cmpwi 3,0; beq 3f; lis 4,-32707; mr 3,31; addi 4,4,29376; bl _s800857E0_5; cmpwi 3,0; bne 6f; 3:; lis 9,-32702; subf 29,28,27; addi 25,9,15952; li 30,0; li 31,0; b 5f; 4:; addi 31,9,4; addi 30,30,1; 5:; cmpwi 30,6; bgt 6f; lwzx 4,31,25; mr 3,28; mr 5,29; bl _s800857E0_6; lis 11,-32702; mr 9,31; cmpwi 3,0; bne 4b; lwz 9,0x4(26); li 0,256; slw 0,0,30; and. 10,9,0; beq 6f; addi 9,11,15952; lwzx 3,9,31; bl _s800857E0_7; cmpw 29,3; bne 6f; lbz 0,0x1(27); mr 3,30; stb 0,0x0(24); b 7f; 6:; li 3,-1; 7:; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"

extern "C" void _s800857E0_0();
extern "C" void _s800857E0_1();
extern "C" void _s800857E0_2();
extern "C" void _s800857E0_3();
extern "C" void _s800857E0_4();
extern "C" void _s800857E0_5();
extern "C" void _s800857E0_6();
extern "C" void _s800857E0_7();

struct WrapperPaneBase {
    void GetVariableButtonIndex();
};

void WrapperPaneBase::GetVariableButtonIndex() {
}
