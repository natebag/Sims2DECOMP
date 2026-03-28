// 0x80074E20 (8 bytes) — li 3, 1; blr
// InvalidatePS2SavedGame(int)

__attribute__((naked))
void InvalidatePS2SavedGame(int) {
    asm volatile(
        "li 3, 1\n"
        "blr\n"
    );
}
