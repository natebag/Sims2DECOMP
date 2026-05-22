// 0x80129804 cXPersonImpl::AttachToHUD(bool) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32697; lwz 11,0x4(3); addi 9,9,24012; li 10,0; lwz 0,0xbc(9); cmpw 11,0; beq 1f; lwz 0,0xc0(9); cmpw 11,0; bne 0f; li 10,1; b 1f; 0:; li 4,0; 1:; cmpwi 4,0; beq 2f; addi 3,3,304; mr 4,10; bl _s80129804_0; b 3f; 2:; addi 3,3,304; mr 4,10; bl _s80129804_1; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80129804_0();
extern "C" void _s80129804_1();
extern "C" void f_80129804() {}
