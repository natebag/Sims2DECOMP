// FLAGS: -fno-elide-constructors
extern int g1_8022E0B8[];
extern int g2_8022E0B8[];
extern int g3_8022E0B8[];
extern int g4_8022E0B8[];
extern int g5_8022E0B8[];
extern int g6_8022E0B8[];
extern void target_8022E0B8(void*, void*, void*, void*, void*, void*, void*);

void func_8022E0B8(void *self) {
    target_8022E0B8(g1_8022E0B8, g2_8022E0B8, g3_8022E0B8, g4_8022E0B8, self, g5_8022E0B8, g6_8022E0B8);
}
