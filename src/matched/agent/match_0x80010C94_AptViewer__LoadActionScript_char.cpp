// 0x80010C94 AptViewer::LoadActionScript(char (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,5; lis 4,-32707; li 5,0; addi 4,4,-9816; li 6,0; li 7,1; mr 8,31; crxor 6,6,6; bl _s80010C94_0; cmpwi 30,0; beq 0f; mr 3,31; bl _s80010C94_1; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80010C94_0();
extern "C" void _s80010C94_1();
extern "C" void f_80010C94() {}
