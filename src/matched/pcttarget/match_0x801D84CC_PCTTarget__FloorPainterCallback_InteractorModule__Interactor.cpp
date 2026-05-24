// 0x801D84CC PCTTarget::FloorPainterCallback(InteractorModule::Interactor::CallbackData (400 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr. 30,4; beq 9f; lwz 0,0x0(30); cmpwi 0,3; beq 1f; bgt 0f; cmpwi 0,0; beq 4f; b 9f; 0:; cmpwi 0,4; beq 3f; cmpwi 0,5; beq 7f; b 9f; 1:; bl _s801D84CC_0; lwz 4,0x84(29); bl _s801D84CC_1; li 4,1; mr 3,29; bl _s801D84CC_2; li 3,0; crxor 6,6,6; bl _s801D84CC_3; lis 3,30424; ori 3,3,7210; bl _s801D84CC_4; 2:; li 3,1; b 10f; 3:; li 3,0; crxor 6,6,6; bl _s801D84CC_5; mr 3,29; li 4,0; li 5,0; bl _s801D84CC_6; b 2b; 4:; mr 3,29; mr 4,30; bl _s801D84CC_7; mr. 31,3; beq 2b; lwz 0,0xc(30); cmpwi 0,0; beq 5f; lis 3,30194; neg 31,31; ori 3,3,56718; bl _s801D84CC_8; b 6f; 5:; lis 3,-30726; ori 3,3,3858; bl _s801D84CC_9; 6:; li 3,0; bl _s801D84CC_10; subf 4,31,3; li 3,0; bl _s801D84CC_11; mr 3,29; bl _s801D84CC_12; lwz 0,0x214(29); stw 3,0x20c(29); cmpwi 0,0; beq 2b; mr 3,0; li 4,0; bl _s801D84CC_13; b 2b; 7:; mr 4,30; mr 3,29; bl _s801D84CC_14; mr 31,3; lwz 4,0x10(30); lis 3,-32705; mr 5,31; addi 3,3,18640; crxor 6,6,6; bl _s801D84CC_15; lwz 3,0x214(29); cmpwi 3,0; beq 2b; mr 4,31; bl _s801D84CC_16; lwz 3,0x214(29); cmpwi 31,0; li 4,1; bne 8f; li 4,0; 8:; bl _s801D84CC_17; b 2b; 9:; li 3,0; 10:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s801D84CC_0();
extern "C" void _s801D84CC_1();
extern "C" void _s801D84CC_2();
extern "C" void _s801D84CC_3();
extern "C" void _s801D84CC_4();
extern "C" void _s801D84CC_5();
extern "C" void _s801D84CC_6();
extern "C" void _s801D84CC_7();
extern "C" void _s801D84CC_8();
extern "C" void _s801D84CC_9();
extern "C" void _s801D84CC_10();
extern "C" void _s801D84CC_11();
extern "C" void _s801D84CC_12();
extern "C" void _s801D84CC_13();
extern "C" void _s801D84CC_14();
extern "C" void _s801D84CC_15();
extern "C" void _s801D84CC_16();
extern "C" void _s801D84CC_17();

struct PCTTarget {
    void FloorPainterCallback_InteractorModule__Interactor();
};

void PCTTarget::FloorPainterCallback_InteractorModule__Interactor() {
}
