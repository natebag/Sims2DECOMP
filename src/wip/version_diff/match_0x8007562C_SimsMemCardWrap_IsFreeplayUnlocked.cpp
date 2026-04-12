// VERSION_DIFF: Absolute addressing vs SDA
// DOL uses lis/addi with fixed address (0x8047xxxx)
// Compiler generates SDA-relative (@sda21) for all extern patterns tried
// Cannot match without linker-level control or forbidden asm tricks
// 0x8007562C SimsMemCardWrap::IsFreeplayUnlocked (16b)

extern int* gSimsMemCardWrap;

int SimsMemCardWrap_IsFreeplayUnlocked() {
    return gSimsMemCardWrap[3];  // offset 0x0C / 4
}
