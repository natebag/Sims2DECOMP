// FLAGS: -fno-elide-constructors
extern int g1_800305A8[];
extern int g2_800305A8[];
extern int g3_800305A8[];
extern int g4_800305A8[];
extern int g5_800305A8[];
extern int g6_800305A8[];
extern void target_800305A8(void*, void*, void*, void*, void*, void*, void*);

void func_800305A8(void *self) {
    target_800305A8(g1_800305A8, g2_800305A8, g3_800305A8, g4_800305A8, self, g5_800305A8, g6_800305A8);
}
