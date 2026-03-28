/* 0x8039ba20 (80 bytes) */
/* __VMBASEDSIServiceExceptionPrep */

__attribute__((naked))
void _match_8039BA20(void) {
    asm volatile(".long 0x90030000
.long 0x90230004
.long 0x90430008
.long 0xBCC30018
.long 0x7C11E2A6
.long 0x900301A8
.long 0x7C12E2A6
.long 0x900301AC
.long 0x7C13E2A6
.long 0x900301B0
.long 0x7C14E2A6
.long 0x900301B4
.long 0x7C15E2A6
.long 0x900301B8
.long 0x7C16E2A6
.long 0x900301BC
.long 0x7C17E2A6
.long 0x900301C0
.long 0x7C9302A6
.long 0x48000004");
}
