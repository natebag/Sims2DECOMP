// FLAGS: -fno-elide-constructors
extern int g1_80364760[];
extern int g2_80364760[];
extern int g3_80364760[];
extern int g4_80364760[];
extern int g5_80364760[];
extern int g6_80364760[];
extern void target_80364760(void*, void*, void*, void*, void*, void*, void*);

void func_80364760(void *self) {
    target_80364760(g1_80364760, g2_80364760, g3_80364760, g4_80364760, self, g5_80364760, g6_80364760);
}
