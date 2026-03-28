// 0x80139C04 (92 bytes)
// IsRectInside(IRect *, IRect *)

__attribute__((naked))
void IsRectInside(IRect *, IRect *) {
    asm volatile(".long 0x7C842379\n.long 0x4082000C\n.long 0x38600001\n.long 0x4E800020\n.long 0x81230004\n.long 0x80040004\n.long 0x7C090000\n.long 0x41800038\n.long 0x8123000C\n.long 0x8004000C\n.long 0x7C090000\n.long 0x41810028\n.long 0x81230000\n.long 0x80040000\n.long 0x7C090000\n.long 0x41800018\n.long 0x81230008\n.long 0x80040008\n.long 0x38600001\n.long 0x7C090000\n.long 0x4C810020\n.long 0x38600000\n.long 0x4E800020");
}
