// 0x802B8B70 AptScriptFunctionBase::CreatingNestedFunction(void) (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 0,-26960(13); mr 30,3; cmpwi 0,0; bne 3f; lhz 0,0x30(30); cmpwi 0,0; beq 0f; lwz 3,-23016(13); li 4,36; bl _s802B8B70_0; mr 31,3; lwz 29,0x2c(30); lhz 30,0x30(30); li 4,20; bl _s802B8B70_1; lis 9,-32703; mr 4,30; addi 9,9,8984; addi 3,31,12; stw 9,0x8(31); bl _s802B8B70_2; lis 9,-32703; stw 29,0x20(31); addi 9,9,28232; cmpwi 29,0; stw 9,0x8(31); beq 2f; lwz 9,0x8(29); lis 4,-32703; lis 5,-32703; addi 4,4,26072; lha 3,0x8(9); addi 5,5,25984; lwz 0,0xc(9); li 6,56; add 3,29,3; b 1f; 0:; lwz 3,-23016(13); li 4,36; bl _s802B8B70_3; mr 31,3; lwz 30,0x2c(30); li 4,20; bl _s802B8B70_4; lis 9,-32703; addi 3,31,12; addi 9,9,8984; li 4,4; stw 9,0x8(31); bl _s802B8B70_5; lis 9,-32703; stw 30,0x20(31); addi 9,9,28232; cmpwi 30,0; stw 9,0x8(31); beq 2f; lwz 9,0x8(30); lis 4,-32703; lis 5,-32703; addi 4,4,25936; lha 3,0x8(9); addi 5,5,25984; lwz 0,0xc(9); li 6,48; add 3,30,3; 1:; mtspr 8,0; blrl; 2:; stw 31,-26960(13); lwz 11,-26960(13); lis 4,-32703; lis 5,-32703; addi 4,4,26176; lwz 9,0x8(11); addi 5,5,26224; li 6,214; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s802B8B70_0();
extern "C" void _s802B8B70_1();
extern "C" void _s802B8B70_2();
extern "C" void _s802B8B70_3();
extern "C" void _s802B8B70_4();
extern "C" void _s802B8B70_5();

struct AptScriptFunctionBase {
    void CreatingNestedFunction();
};

void AptScriptFunctionBase::CreatingNestedFunction() {
}
