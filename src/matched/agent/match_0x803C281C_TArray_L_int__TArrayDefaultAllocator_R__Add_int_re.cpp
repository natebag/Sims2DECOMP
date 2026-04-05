/* TArray_L_int__TArrayDefaultAllocator_R__Add_int_ref at 0x803C281C (40B) — auto-matched [load_field_param_call] */

// FLAGS: -fno-elide-constructors
extern int tgt_803C281C(void *, int, int, int);
int func_803C281C(void *self, int a1) { return tgt_803C281C(self, a1, *(int*)((char*)self + 4), 1); }
