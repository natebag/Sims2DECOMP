// FLAGS: -fno-elide-constructors
extern int g1_8036C230[];
extern int g2_8036C230[];
extern int g3_8036C230[];
extern int g4_8036C230[];
extern int g5_8036C230[];
extern int g6_8036C230[];
extern void target_8036C230(void*, void*, void*, void*, void*, void*, void*);

void func_8036C230(void *self) {
    target_8036C230(g1_8036C230, g2_8036C230, g3_8036C230, g4_8036C230, self, g5_8036C230, g6_8036C230);
}
