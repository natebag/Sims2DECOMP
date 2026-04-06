// FLAGS: -fno-elide-constructors
extern int g1_803680D4[];
extern int g2_803680D4[];
extern int g3_803680D4[];
extern int g4_803680D4[];
extern int g5_803680D4[];
extern int g6_803680D4[];
extern void target_803680D4(void*, void*, void*, void*, void*, void*, void*);

void func_803680D4(void *self) {
    target_803680D4(g1_803680D4, g2_803680D4, g3_803680D4, g4_803680D4, self, g5_803680D4, g6_803680D4);
}
