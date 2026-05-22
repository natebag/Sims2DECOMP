// 0x80132D3C SetReconDumpFile(char (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,-31684(13); mr 31,3; cmpwi 0,0; beq 0f; mr 3,0; bl _s80132D3C_0; li 0,0; stw 0,-31684(13); 0:; cmpwi 31,0; beq 1f; lis 4,-32706; mr 3,31; addi 4,4,-12212; bl _s80132D3C_1; stw 3,-31684(13); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80132D3C_0();
extern "C" void _s80132D3C_1();
extern "C" void f_80132D3C() {}
