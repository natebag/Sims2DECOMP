// 0x80356FB0 FrameEffect::Enable(bool) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; cmpwi 7,4,0; bne cr7,0f; lwz 0,0xc(31); cmpwi 0,1; beq 2f; 0:; li 4,8; beq cr7,1f; li 4,2; 1:; lwz 9,0x10(31); stw 4,0xc(31); lha 3,0x20(9); lwz 0,0x24(9); add 3,31,3; mtspr 8,0; blrl; lis 9,-32702; lfs f0,0x2ad8(9); stfs f0,0x8(31); 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_80356FB0() {}
