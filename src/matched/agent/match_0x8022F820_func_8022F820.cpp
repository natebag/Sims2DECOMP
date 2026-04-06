// FLAGS: -fno-elide-constructors
extern int g1_8022F820[];
extern int g2_8022F820[];
extern int g3_8022F820[];
extern int g4_8022F820[];
extern int g5_8022F820[];
extern int g6_8022F820[];
extern void target_8022F820(void*, void*, void*, void*, void*, void*, void*);

void func_8022F820(void *self) {
    target_8022F820(g1_8022F820, g2_8022F820, g3_8022F820, g4_8022F820, self, g5_8022F820, g6_8022F820);
}
