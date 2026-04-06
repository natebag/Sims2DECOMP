/* auto at 0x802E0744 (40B) [load_field_param_call] */

// FLAGS: -fno-elide-constructors
extern int tgt_802E0744(void *, int, int);
int func_802E0744(void *self) { return tgt_802E0744(self, *(int*)((char*)self + 4), 0); }
