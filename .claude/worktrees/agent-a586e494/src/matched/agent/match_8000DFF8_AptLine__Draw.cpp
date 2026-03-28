// 0x8000DFF8 (116 bytes)
// AptLine::Draw(ERC *, EMat4 *, EVec4 *, EVec4 *)

class AptLine { public: void Draw(ERC *, EMat4 *, EVec4 *, EVec4 *); };

__attribute__((naked))
void AptLine::Draw(ERC *, EMat4 *, EVec4 *, EVec4 *) {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0xBF61000C\n.long 0x90010024\n.long 0x83C30004\n.long 0x7C9B2378\n.long 0x7CBC2B78\n.long 0x7CDD3378\n.long 0x7CFF3B78\n.long 0x2C1E0000\n.long 0x41820038\n.long 0x813E002C\n.long 0x7F64DB78\n.long 0x7F85E378\n.long 0x7FA6EB78\n.long 0xA8690010\n.long 0x7FE7FB78\n.long 0x80090014\n.long 0x7C7E1A14\n.long 0x7C0803A6\n.long 0x83DE0000\n.long 0x4E800021\n.long 0x7FDEF379\n.long 0x4082FFD0\n.long 0x80010024\n.long 0x7C0803A6\n.long 0xBB61000C\n.long 0x38210020\n.long 0x4E800020");
}
