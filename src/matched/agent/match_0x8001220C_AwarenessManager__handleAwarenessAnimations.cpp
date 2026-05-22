// 0x8001220C AwarenessManager::handleAwarenessAnimations(unsigned int) (68B)
struct AwarenessManager {
    void handleAwarenessAnimations(unsigned int mask);
    void handleMemoryAwarenessAnimation(unsigned int mask);
    void handleAwarenessTurningAnimation(void);
    void handlePassiveInfluenceAnimation(unsigned int mask);
};

void AwarenessManager::handleAwarenessAnimations(unsigned int mask) {
    handleMemoryAwarenessAnimation(mask);
    handleAwarenessTurningAnimation();
    handlePassiveInfluenceAnimation(mask);
}
