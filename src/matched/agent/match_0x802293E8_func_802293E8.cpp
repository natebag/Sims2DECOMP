// FLAGS: -fno-elide-constructors
extern int g1_802293E8[];
extern int g2_802293E8[];
extern int g3_802293E8[];
extern int g4_802293E8[];
extern int g5_802293E8[];
extern int g6_802293E8[];
extern void target_802293E8(void*, void*, void*, void*, void*, void*, void*);

void func_802293E8(void *self) {
    target_802293E8(g1_802293E8, g2_802293E8, g3_802293E8, g4_802293E8, self, g5_802293E8, g6_802293E8);
}
