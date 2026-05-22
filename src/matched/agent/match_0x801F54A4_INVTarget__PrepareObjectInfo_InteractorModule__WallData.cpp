// 0x801F54A4 INVTarget::PrepareObjectInfo(InteractorModule::WallData (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-544(1); mfspr 0,8; stmw 27,0x20c(1); stw 0,0x224(1); mr 31,3; mr 28,5; mr 29,6; mr. 30,4; li 3,0; beq 5f; mr 3,31; bl _s801F54A4_0; addi 3,1,8; li 4,0; li 5,512; crxor 6,6,6; bl _s801F54A4_1; lwz 0,0x84(31); cmpwi 0,0; bne 0f; lis 9,-32704; addi 27,9,-23620; b 1f; 0:; lis 9,-32704; addi 27,9,-23604; 1:; lwz 0,0x4(30); cmpwi 0,-1; bne 2f; li 3,20; b 3f; 2:; lwz 9,0x0(30); lwz 3,0x4(9); 3:; cmpwi 29,0; bne 4f; mr 5,28; li 4,20; bl _s801F54A4_2; 4:; mr 4,3; mr 5,29; addi 6,1,8; mr 3,31; bl _s801F54A4_3; mr 3,27; addi 4,1,8; bl _s801F54A4_4; li 3,1; 5:; lwz 0,0x224(1); mtspr 8,0; lmw 27,0x20c(1); addi 1,1,544"
extern "C" void _s801F54A4_0();
extern "C" void _s801F54A4_1();
extern "C" void _s801F54A4_2();
extern "C" void _s801F54A4_3();
extern "C" void _s801F54A4_4();
extern "C" void f_801F54A4() {}
