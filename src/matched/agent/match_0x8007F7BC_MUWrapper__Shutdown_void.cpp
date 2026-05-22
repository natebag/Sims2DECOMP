// 0x8007F7BC MUWrapper::Shutdown(void) (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 30,-32697; mr 31,3; addi 30,30,24012; lis 4,-32707; lwz 3,0xb4(30); lis 8,-32707; addi 8,8,27520; addi 4,4,27500; li 5,0; li 6,0; li 7,1; lis 29,-32707; crxor 6,6,6; bl _s8007F7BC_0; lwz 3,0xb4(30); lis 8,-32707; addi 8,8,27540; addi 4,29,27600; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s8007F7BC_1; lwz 3,0xb4(30); lis 8,-32707; addi 8,8,27548; addi 4,29,27600; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s8007F7BC_2; lwz 3,0xb4(30); lis 8,-32707; addi 8,8,27556; addi 4,29,27600; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s8007F7BC_3; lwz 3,0xb4(30); lis 8,-32707; addi 8,8,27564; addi 4,29,27600; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s8007F7BC_4; lwz 3,0xb4(30); lis 4,-32707; addi 4,4,27616; li 5,0; li 6,0; li 7,0; crxor 6,6,6; bl _s8007F7BC_5; lis 4,-32707; mr 3,31; addi 4,4,27636; bl _s8007F7BC_6; lwz 3,0xa4(31); cmpwi 3,0; beq 0f; bl _s8007F7BC_7; li 0,0; stw 0,0xa4(31); 0:; mr 3,31; bl _s8007F7BC_8; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8007F7BC_0();
extern "C" void _s8007F7BC_1();
extern "C" void _s8007F7BC_2();
extern "C" void _s8007F7BC_3();
extern "C" void _s8007F7BC_4();
extern "C" void _s8007F7BC_5();
extern "C" void _s8007F7BC_6();
extern "C" void _s8007F7BC_7();
extern "C" void _s8007F7BC_8();
extern "C" void f_8007F7BC() {}
