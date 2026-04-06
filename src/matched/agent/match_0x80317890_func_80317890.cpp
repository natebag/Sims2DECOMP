// FLAGS: -fno-elide-constructors
extern int g1_80317890[];
extern int g2_80317890[];
extern int g3_80317890[];
extern int g4_80317890[];
extern int g5_80317890[];
extern int g6_80317890[];
extern void target_80317890(void*, void*, void*, void*, void*, void*, void*);

void func_80317890(void *self) {
    target_80317890(g1_80317890, g2_80317890, g3_80317890, g4_80317890, self, g5_80317890, g6_80317890);
}
