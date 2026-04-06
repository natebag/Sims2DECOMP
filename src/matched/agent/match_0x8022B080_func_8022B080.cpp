// FLAGS: -fno-elide-constructors
extern int g1_8022B080[];
extern int g2_8022B080[];
extern int g3_8022B080[];
extern int g4_8022B080[];
extern int g5_8022B080[];
extern int g6_8022B080[];
extern void target_8022B080(void*, void*, void*, void*, void*, void*, void*);

void func_8022B080(void *self) {
    target_8022B080(g1_8022B080, g2_8022B080, g3_8022B080, g4_8022B080, self, g5_8022B080, g6_8022B080);
}
