// CasTweakTool::GetLights(ELights &)
// Address: 0x8026BD4C | Size: 32 bytes
// Simple thunk: calls internal function with same args

extern void CasTweakTool_GetLights_impl(void* self, void* lights);

struct CasTweakTool {
    void GetLights(void* lights);
};

void CasTweakTool::GetLights(void* lights) {
    CasTweakTool_GetLights_impl(this, lights);
}
