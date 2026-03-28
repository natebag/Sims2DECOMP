extern int gEInstance_SetContext;

struct EInstance {
    static void SetContext(int val);
};
void EInstance::SetContext(int val) { gEInstance_SetContext = val; }
