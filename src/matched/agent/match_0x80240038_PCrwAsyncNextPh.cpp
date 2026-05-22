// 0x80240038 PCrwAsyncNextPh (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 3,3; beq 4f; cmplwi 3,3; bgt 0f; cmpwi 3,1; beq 1f; cmpwi 3,2; beq 2f; b 4f; 0:; cmpwi 3,4; beq 2f; cmpwi 3,5; beq 3f; b 4f; 1:; bl _s80240038_0; b 4f; 2:; lis 11,-32700; lwz 9,-23460(11); addi 9,9,1; stw 9,-23460(11); b 4f; 3:; bl _s80240038_1; 4:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80240038_0();
extern "C" void _s80240038_1();
extern "C" void f_80240038() {}
