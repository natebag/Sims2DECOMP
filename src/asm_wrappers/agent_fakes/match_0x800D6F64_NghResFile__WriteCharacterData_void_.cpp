/* NghResFile::WriteCharacterData(void) at 0x800D6F64 (144B) */

struct NghResFile { void WriteCharacterData(); };

__attribute__((naked))
void NghResFile::WriteCharacterData() {
    asm volatile(
        ".long 0x9421FFF0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFC10008\n"
        ".long 0x90010014\n"
        ".long 0x7C7E1B78\n"
        ".long 0x806DAC48\n"
        ".long 0x4BF6AB45\n"
        ".long 0x38000000\n"
        ".long 0x808D8350\n"
        ".long 0x38A00000\n"
        ".long 0x387E0028\n"
        ".long 0xB01E0184\n"
        ".long 0x4BFCFBE5\n"
        ".long 0x7FC3F378\n"
        ".long 0x38800000\n"
        ".long 0x4BFFE72D\n"
        ".long 0x7C7F1B78\n"
        ".long 0x2C1F0001\n"
        ".long 0x40820014\n"
        ".long 0x7FC3F378\n"
        ".long 0x38800000\n"
        ".long 0x4BFFEA89\n"
        ".long 0x7C7F1B78\n"
        ".long 0x806D9864\n"
        ".long 0x81230020\n"
        ".long 0xA8090028\n"
        ".long 0x8129002C\n"
        ".long 0x7C630214\n"
        ".long 0x7D2803A6\n"
        ".long 0x4E800021\n"
        ".long 0x7FE3FB78\n"
        ".long 0x80010014\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBC10008\n"
        ".long 0x38210010\n"
        ".long 0x4E800020\n"
    );
}
