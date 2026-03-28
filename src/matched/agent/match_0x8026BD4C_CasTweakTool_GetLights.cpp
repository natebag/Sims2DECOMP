
void CasTweakTool_GetLightsInternal(void *, void *);

struct CasTweakTool {
    void GetLights(void* lights);
};

void CasTweakTool::GetLights(void* lights) {
    CasTweakTool_GetLightsInternal(this, lights);
}
