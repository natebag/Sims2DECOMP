extern int gEILight_HaveLightsChanged;

struct EILight {
    static int HaveLightsChanged();
};
int EILight::HaveLightsChanged() { return gEILight_HaveLightsChanged; }
