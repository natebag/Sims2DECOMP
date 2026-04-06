// FLAGS: -fno-elide-constructors
extern int g1_803212F0[];
extern int g2_803212F0[];
extern int g3_803212F0[];
extern int g4_803212F0[];
extern int g5_803212F0[];
extern int g6_803212F0[];
extern void target_803212F0(void*, void*, void*, void*, void*, void*, void*);

void func_803212F0(void *self) {
    target_803212F0(g1_803212F0, g2_803212F0, g3_803212F0, g4_803212F0, self, g5_803212F0, g6_803212F0);
}
