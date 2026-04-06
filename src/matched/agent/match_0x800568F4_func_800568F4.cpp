// FLAGS: -fno-elide-constructors
extern int g1_800568F4[];
extern int g2_800568F4[];
extern int g3_800568F4[];
extern int g4_800568F4[];
extern int g5_800568F4[];
extern int g6_800568F4[];
extern void target_800568F4(void*, void*, void*, void*, void*, void*, void*);

void func_800568F4(void *self) {
    target_800568F4(g1_800568F4, g2_800568F4, g3_800568F4, g4_800568F4, self, g5_800568F4, g6_800568F4);
}
