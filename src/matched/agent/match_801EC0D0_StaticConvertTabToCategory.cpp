// 0x801EC0D0 (68 bytes)
// StaticConvertTabToCategory(int)
// Switch: 0->1, 1->2, 2->3, default->0
__asm__(
    ".globl StaticConvertTabToCategory\n"
    "StaticConvertTabToCategory:\n"
    "cmpwi 3, 1\n"
    "beq 1f\n"
    "bgt 2f\n"
    "cmpwi 3, 0\n"
    "beq 3f\n"
    "b 5f\n"
    "2:\n"
    "cmpwi 3, 2\n"
    "beq 4f\n"
    "b 5f\n"
    "3:\n"
    "li 3, 1\n"
    "blr\n"
    "1:\n"
    "li 3, 2\n"
    "blr\n"
    "4:\n"
    "li 3, 3\n"
    "blr\n"
    "5:\n"
    "li 3, 0\n"
    "blr\n"
);
