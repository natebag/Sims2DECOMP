// FLAGS: -fno-schedule-insns
/* 0x80066054 (104 bytes) - SAnimator2::cleanupParticlesImmediate(TRedBlackTree<...> *) */
class SAnimator2 {
public:
    void cleanupParticlesImmediate(void* tree);
    void cleanupImmediateHelper(void* tree);
};

void SAnimator2::cleanupParticlesImmediate(void* tree) {
    char* root = *(char**)tree;
    if (root == 0) goto L_tail;
    do {
        char* innerTree = *(char**)(root + 28);
        char* node = *(char**)innerTree;
        if (node != 0) {
            int one = 1;
            int zero = 0;
            do {
                char* target = *(char**)(node + 28);
                *(int*)(target + 124) = zero;
                *(int*)(target + 120) = one;
                node = *(char**)(node + 16);
            } while (node != 0);
        }
        root = *(char**)(root + 16);
    } while (root != 0);
L_tail:
    cleanupImmediateHelper(tree);
}
