// 0x8003038C __static_initialization_and_destruction_0 (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; lis 9,-32707; lis 11,-32707; lfs f1,0xebc(9); lis 3,-32697; lfs f2,0xec0(11); lis 4,-32707; addi 4,4,3720; li 5,0; addi 3,3,21628; lis 30,-32688; bl _s8003038C_0; lis 11,-32707; lis 9,-32707; lfs f1,0xec4(9); lis 3,-32697; lfs f2,0xec8(11); lis 4,-32707; addi 4,4,3744; li 5,0; addi 3,3,21676; bl _s8003038C_1; lis 3,-32688; lis 4,-32765; lis 5,-32765; lis 6,-32765; lis 8,-32707; addi 4,4,1632; addi 5,5,1672; addi 6,6,1716; addi 8,8,3176; addi 9,30,-19536; li 7,0; addi 3,3,-19496; bl _s8003038C_2; stw 3,-25112(13); lis 4,-32765; lis 5,-32765; lis 6,-32765; lis 8,-32707; lis 9,-32688; addi 3,30,-19536; addi 4,4,1192; addi 5,5,1232; addi 6,6,1276; addi 8,8,3164; addi 9,9,-19456; li 7,0; bl _s8003038C_3; stw 3,-25108(13); b 1f; 0:; lis 9,-32698; lis 10,-32697; addi 9,9,-19784; lis 11,-32697; stw 9,0x54a8(11); stw 9,0x54d8(10); 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8003038C_0();
extern "C" void _s8003038C_1();
extern "C" void _s8003038C_2();
extern "C" void _s8003038C_3();
extern "C" void f_8003038C() {}
