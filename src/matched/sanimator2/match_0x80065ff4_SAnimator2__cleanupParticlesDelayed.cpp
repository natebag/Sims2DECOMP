/* 0x80065ff4 (96 bytes) - SAnimator2::cleanupParticlesDelayed(TRedBlackTree<...> *) */
class SAnimator2 {
public:
    void cleanupParticlesImmediate(void* tree);
    void cleanupParticlesDelayed(void* tree);
};

void SAnimator2::cleanupParticlesDelayed(void* tree) {
    char* root = *(char**)tree;
    if (root == 0) goto L_tail;
    do {
        char* innerTree = *(char**)(root + 28);
        char* node = *(char**)innerTree;
        if (node != 0) {
            do {
                char* target = *(char**)(node + 28);
                *(int*)(target + 120) = 0;
                node = *(char**)(node + 16);
            } while (node != 0);
        }
        root = *(char**)(root + 16);
    } while (root != 0);
L_tail:
    cleanupParticlesImmediate(tree);
}
