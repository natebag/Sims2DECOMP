// 0x801B93D4 (72 bytes)
// find_ingredient_type(IngredientType **, unsigned int, short)

__attribute__((naked))
void find_ingredient_type(IngredientType **, unsigned int, short) {
    asm volatile(".long 0x39200000\n.long 0x7C6B1B78\n.long 0x7C092040\n.long 0x40800034\n.long 0x806B0000\n.long 0x2C030000\n.long 0x41820028\n.long 0xA8030000\n.long 0x7C002800\n.long 0x4D820020\n.long 0x39290001\n.long 0x7C092040\n.long 0x40800010\n.long 0x846B0004\n.long 0x2C030000\n.long 0x4082FFE0\n.long 0x38600000\n.long 0x4E800020");
}
