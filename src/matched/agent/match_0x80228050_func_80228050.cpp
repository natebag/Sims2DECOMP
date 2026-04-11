// FLAGS: -fno-elide-constructors
extern int g1_80228050[];
extern int g2_80228050[];
extern int g3_80228050[];
extern int g4_80228050[];
extern int g5_80228050[];
extern int g6_80228050[];
extern void target_80228050(void*, void*, void*, void*, void*, void*, void*);

void func_80228050(void *self) {
    target_80228050(g1_80228050, g2_80228050, g3_80228050, g4_80228050, self, g5_80228050, g6_80228050);
}
