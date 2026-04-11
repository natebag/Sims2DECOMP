// FLAGS: -fno-elide-constructors
extern int g1_8030FBE8[];
extern int g2_8030FBE8[];
extern int g3_8030FBE8[];
extern int g4_8030FBE8[];
extern int g5_8030FBE8[];
extern int g6_8030FBE8[];
extern void target_8030FBE8(void*, void*, void*, void*, void*, void*, void*);

void func_8030FBE8(void *self) {
    target_8030FBE8(g1_8030FBE8, g2_8030FBE8, g3_8030FBE8, g4_8030FBE8, self, g5_8030FBE8, g6_8030FBE8);
}
