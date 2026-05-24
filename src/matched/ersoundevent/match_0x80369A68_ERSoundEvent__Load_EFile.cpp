// 0x80369A68 ERSoundEvent::Load(EFile (888 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 25,0x34(1); stw 0,0x54(1); mr 27,3; mr. 31,4; beq 6f; addi 3,1,8; bl _s80369A68_0; lis 5,21317; addi 3,1,8; mr 4,31; ori 5,5,22100; li 6,1; li 7,1; bl _s80369A68_1; cmpwi 3,0; bne 0f; addi 3,1,8; li 4,2; bl _s80369A68_2; b 6f; 0:; addi 3,1,8; bl _s80369A68_3; lwz 9,0x18(1); addi 4,27,20; lwz 0,0x10(27); li 5,1; rlwimi 0,9,8,0,23; stw 0,0x10(27); lwz 9,0x28(31); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,1,32; li 5,1; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lbz 0,0x20(1); cmpwi 0,0; beq 5f; lwz 9,0x28(31); addi 4,27,21; li 5,1; addi 25,1,44; lwz 0,0x1c(9); li 30,0; lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,27,22; li 5,1; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,27,23; li 5,1; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,1,33; li 5,1; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,27,24; li 5,2; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,27,26; li 5,1; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,27,27; li 5,1; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,27,28; li 5,1; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,27,29; li 5,1; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,27,30; li 5,1; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,27,31; li 5,1; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,27,32; li 5,1; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,1,36; li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 4,0x24(1); addi 3,27,36; li 5,0; bl _s80369A68_4; lwz 0,0x24(1); cmplw 30,0; bge 4f; 1:; lwz 9,0x28(31); mulli 11,30,12; addi 4,1,40; lwz 0,0x24(27); lha 3,0x18(9); li 5,4; lwz 9,0x1c(9); li 29,0; add 3,31,3; add 28,0,11; mtspr 8,9; addi 26,30,1; blrl; lwz 4,0x28(1); mr 3,28; li 5,0; bl _s80369A68_5; lwz 0,0x28(1); cmplw 29,0; bge 3f; li 30,0; 2:; lwz 9,0x28(31); li 5,8; lwz 4,0x0(28); addi 29,29,1; lwz 0,0x1c(9); lha 3,0x18(9); add 4,4,30; mtspr 8,0; addi 30,30,8; add 3,31,3; blrl; lwz 0,0x28(1); cmplw 29,0; blt 2b; 3:; lwz 0,0x24(1); mr 30,26; cmplw 30,0; blt 1b; 4:; lwz 9,0x28(31); mr 4,25; li 5,4; lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; lis 3,-32692; lwz 4,0x2c(1); addi 3,3,-10724; li 5,0; li 6,0; bl _s80369A68_6; stw 3,0x30(27); 5:; addi 3,1,8; li 4,2; bl _s80369A68_7; 6:; lwz 0,0x54(1); mtspr 8,0; lmw 25,0x34(1); addi 1,1,80"

extern "C" void _s80369A68_0();
extern "C" void _s80369A68_1();
extern "C" void _s80369A68_2();
extern "C" void _s80369A68_3();
extern "C" void _s80369A68_4();
extern "C" void _s80369A68_5();
extern "C" void _s80369A68_6();
extern "C" void _s80369A68_7();

struct ERSoundEvent {
    void Load_EFile();
};

void ERSoundEvent::Load_EFile() {
}
