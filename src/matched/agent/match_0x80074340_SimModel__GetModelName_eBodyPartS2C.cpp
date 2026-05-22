// 0x80074340 SimModel::GetModelName(eBodyPartS2C, (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); rlwinm 4,4,2,0,29; addi 3,3,104; lwzx 9,3,4; mr 31,5; cmpwi 9,0; beq 0f; lwz 0,0x120(9); cmpwi 0,0; bne 1f; 0:; lis 4,-32707; mr 3,31; addi 4,4,22044; bl _s80074340_0; b 2f; 1:; lis 4,-32707; mr 3,31; addi 4,4,21620; bl _s80074340_1; 2:; lwz 3,0x0(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80074340_0();
extern "C" void _s80074340_1();
extern "C" void f_80074340() {}
