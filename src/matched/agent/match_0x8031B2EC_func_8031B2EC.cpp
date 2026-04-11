// FLAGS: -fno-elide-constructors
extern int g1_8031B2EC[];
extern int g2_8031B2EC[];
extern int g3_8031B2EC[];
extern int g4_8031B2EC[];
extern int g5_8031B2EC[];
extern int g6_8031B2EC[];
extern void target_8031B2EC(void*, void*, void*, void*, void*, void*, void*);

void func_8031B2EC(void *self) {
    target_8031B2EC(g1_8031B2EC, g2_8031B2EC, g3_8031B2EC, g4_8031B2EC, self, g5_8031B2EC, g6_8031B2EC);
}
