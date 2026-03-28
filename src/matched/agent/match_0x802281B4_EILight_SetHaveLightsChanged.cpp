extern int gEILight_SetHaveLightsChanged;

struct EILight {
    static void SetHaveLightsChanged(int val);
};
void EILight::SetHaveLightsChanged(int val) { gEILight_SetHaveLightsChanged = val; }
