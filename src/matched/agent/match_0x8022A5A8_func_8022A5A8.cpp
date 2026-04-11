// FLAGS: -fno-elide-constructors
extern int g1_8022A5A8[];
extern int g2_8022A5A8[];
extern int g3_8022A5A8[];
extern int g4_8022A5A8[];
extern int g5_8022A5A8[];
extern int g6_8022A5A8[];
extern void target_8022A5A8(void*, void*, void*, void*, void*, void*, void*);

void func_8022A5A8(void *self) {
    target_8022A5A8(g1_8022A5A8, g2_8022A5A8, g3_8022A5A8, g4_8022A5A8, self, g5_8022A5A8, g6_8022A5A8);
}
