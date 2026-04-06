// FLAGS: -fno-elide-constructors
extern int g1_802C5D7C[];
extern int g2_802C5D7C[];
extern int g3_802C5D7C[];
extern int g4_802C5D7C[];
extern int g5_802C5D7C[];
extern int g6_802C5D7C[];
extern void target_802C5D7C(void*, void*, void*, void*, void*, void*, void*);

void func_802C5D7C(void *self) {
    target_802C5D7C(g1_802C5D7C, g2_802C5D7C, g3_802C5D7C, g4_802C5D7C, self, g5_802C5D7C, g6_802C5D7C);
}
