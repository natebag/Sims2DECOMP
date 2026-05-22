// 0x801F5570 INVTarget::ClearAllObjectInfoData(void) (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 29,0x4c(1); stw 0,0x5c(1); mr 31,3; li 4,0; addi 3,1,8; li 5,64; crxor 6,6,6; bl _s801F5570_0; lwz 0,0x84(31); cmpwi 0,0; bne 0f; lis 9,-32704; addi 29,9,-23620; b 1f; 0:; lis 9,-32704; addi 29,9,-23604; 1:; lwz 0,0x84(31); mr 11,0; cmpwi 0,0; bne 2f; lis 9,-32704; addi 3,9,-23588; b 3f; 2:; lis 9,-32704; addi 3,9,-23576; 3:; cmpwi 11,0; bne 4f; lis 9,-32704; addi 30,9,-23560; b 5f; 4:; lis 9,-32704; addi 30,9,-23544; 5:; addi 4,1,8; bl _s801F5570_1; addi 4,1,8; mr 3,30; bl _s801F5570_2; mr 3,29; addi 4,1,8; bl _s801F5570_3; lwz 0,0x3258(31); cmpwi 0,0; beq 8f; lwz 0,0x84(31); addi 9,13,-28688; lwz 11,0x0(31); rlwinm 0,0,2,0,29; lwzx 4,9,0; cmpwi 11,0; beq 6f; lwz 3,0x20(31); cmpwi 3,0; beq 6f; bl _s801F5570_4; b 7f; 6:; li 3,0; 7:; xori 0,3,1; stw 0,0x3258(31); 8:; lwz 0,0x5c(1); mtspr 8,0; lmw 29,0x4c(1); addi 1,1,88"
extern "C" void _s801F5570_0();
extern "C" void _s801F5570_1();
extern "C" void _s801F5570_2();
extern "C" void _s801F5570_3();
extern "C" void _s801F5570_4();
extern "C" void f_801F5570() {}
