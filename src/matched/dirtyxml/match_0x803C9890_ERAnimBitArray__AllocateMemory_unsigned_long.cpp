/* ERAnimBitArray__AllocateMemory_unsigned_long at 0x803C9890 (44B) — auto-matched [load_addr_param_44B] */

// FLAGS: -fno-elide-constructors
extern int g_obj_803C9890[];
extern int func_803C9890(int, int, int);

int fwd_803C9890(void *self, int a0) {
    return func_803C9890((int)g_obj_803C9890, a0, 8);
}
