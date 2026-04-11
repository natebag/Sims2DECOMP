// FLAGS: -fno-elide-constructors
extern int g1_80322B00[];
extern int g2_80322B00[];
extern int g3_80322B00[];
extern int g4_80322B00[];
extern int g5_80322B00[];
extern int g6_80322B00[];
extern void target_80322B00(void*, void*, void*, void*, void*, void*, void*);

void func_80322B00(void *self) {
    target_80322B00(g1_80322B00, g2_80322B00, g3_80322B00, g4_80322B00, self, g5_80322B00, g6_80322B00);
}
