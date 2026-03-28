// 0x8004B5BC (124 bytes)
// get_ingredient_type_array(FoodResult *, short *)

__attribute__((naked))
void get_ingredient_type_array(FoodResult *, short *) {
    asm volatile(".long 0x38000000\n.long 0x7C631B79\n.long 0xB0040000\n.long 0xB0040006\n.long 0xB0040004\n.long 0xB0040002\n.long 0x4082000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x81230004\n.long 0x2C090000\n.long 0x4182000C\n.long 0xA0090000\n.long 0xB0040000\n.long 0x81230008\n.long 0x2C090000\n.long 0x4182000C\n.long 0xA0090000\n.long 0xB0040002\n.long 0x8123000C\n.long 0x2C090000\n.long 0x4182000C\n.long 0xA0090000\n.long 0xB0040004\n.long 0x80630010\n.long 0x2C030000\n.long 0x4182000C\n.long 0xA0030000\n.long 0xB0040006\n.long 0x38600001\n.long 0x4E800020");
}
