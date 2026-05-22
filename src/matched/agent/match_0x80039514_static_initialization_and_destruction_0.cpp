// 0x80039514 __static_initialization_and_destruction_0 (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; ori 0,0,65535; cmpw 4,0; bnelr; cmpwi 3,0; beqlr; lis 11,-32697; li 0,-1; stw 0,0x5a60(11); addi 8,11,23136; li 10,0; lis 9,-32697; stw 10,0x4(8); addi 9,9,23172; li 10,5; li 11,-1; mtspr 9,10; li 0,0; 0:; stw 11,0x0(9); stw 0,0x4(9); addi 9,9,36; bdnz 0b"
extern "C" void f_80039514() {}
