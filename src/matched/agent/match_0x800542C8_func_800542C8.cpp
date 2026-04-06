// FLAGS: -fno-elide-constructors
extern int g1_800542C8[];
extern int g2_800542C8[];
extern int g3_800542C8[];
extern int g4_800542C8[];
extern int g5_800542C8[];
extern int g6_800542C8[];
extern void target_800542C8(void*, void*, void*, void*, void*, void*, void*);

void func_800542C8(void *self) {
    target_800542C8(g1_800542C8, g2_800542C8, g3_800542C8, g4_800542C8, self, g5_800542C8, g6_800542C8);
}
