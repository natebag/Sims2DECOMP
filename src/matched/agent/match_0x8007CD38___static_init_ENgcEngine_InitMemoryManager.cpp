// 0x8007CD38 __static_initialization_and_destruction_0 (56B)

class ENgcEngine {
public:
    static void InitMemoryManager();
};

void __static_initialization_and_destruction_0(int __initialize_p, unsigned int __priority) {
    if (__priority != 0xFFFF) return;
    if (__initialize_p == 0) return;
    ENgcEngine::InitMemoryManager();
}
