// FLAGS: -fno-elide-constructors
extern int g1_80030760[];
extern int g2_80030760[];
extern int g3_80030760[];
extern int g4_80030760[];
extern int g5_80030760[];
extern int g6_80030760[];
extern void target_80030760(void*, void*, void*, void*, void*, void*, void*);

void func_80030760(void *self) {
    target_80030760(g1_80030760, g2_80030760, g3_80030760, g4_80030760, self, g5_80030760, g6_80030760);
}
