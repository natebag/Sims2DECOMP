// 0x801F5334 INVTarget::PrepareObjectInfo(InteractorModule::WallPaperData (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-544(1); mfspr 0,8; stmw 27,0x20c(1); stw 0,0x224(1); mr 31,3; mr 27,5; mr 28,6; mr. 30,4; li 3,0; beq 3f; addi 29,1,8; mr 3,31; bl _s801F5334_0; mr 3,29; li 4,0; li 5,512; crxor 6,6,6; bl _s801F5334_1; lwz 9,0x0(30); cmpwi 28,0; lwz 3,0x0(9); bne 0f; mr 5,27; li 4,20; bl _s801F5334_2; 0:; mr 4,3; mr 5,28; mr 6,29; mr 3,31; bl _s801F5334_3; lwz 0,0x84(31); cmpwi 0,0; bne 1f; lis 9,-32704; addi 3,9,-23620; b 2f; 1:; lis 9,-32704; addi 3,9,-23604; 2:; addi 4,1,8; bl _s801F5334_4; li 3,1; 3:; lwz 0,0x224(1); mtspr 8,0; lmw 27,0x20c(1); addi 1,1,544"
extern "C" void _s801F5334_0();
extern "C" void _s801F5334_1();
extern "C" void _s801F5334_2();
extern "C" void _s801F5334_3();
extern "C" void _s801F5334_4();
extern "C" void f_801F5334() {}
