// 0x80104E58 PresetHouseGameStatus(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,16; lis 9,-32696; mtspr 9,0; addi 9,9,25808; li 11,0; li 5,1; addi 6,9,4; addi 7,9,8; li 10,0; li 8,15; 0:; addi 0,11,-13; cmpwi 11,0; cmplwi 7,0,3; mulli 0,11,12; beq 1f; bgt cr7,2f; 1:; stw 5,0x0(9); b 3f; 2:; mulli 0,11,12; stw 10,0x0(9); 3:; stwx 10,7,0; addi 9,9,12; stwx 8,6,0; addi 11,11,1; bdnz 0b"
extern "C" void f_80104E58() {}
