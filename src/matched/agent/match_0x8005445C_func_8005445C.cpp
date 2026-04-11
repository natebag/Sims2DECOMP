// FLAGS: -fno-elide-constructors
extern int g1_8005445C[];
extern int g2_8005445C[];
extern int g3_8005445C[];
extern int g4_8005445C[];
extern int g5_8005445C[];
extern int g6_8005445C[];
extern void target_8005445C(void*, void*, void*, void*, void*, void*, void*);

void func_8005445C(void *self) {
    target_8005445C(g1_8005445C, g2_8005445C, g3_8005445C, g4_8005445C, self, g5_8005445C, g6_8005445C);
}
