struct EGraphicsGlobals {
    float farZ;
    float nearZ;
    float aspect;
};

extern EGraphicsGlobals g_graphicsGlobals;

float GetFarZVal(void) {
    return g_graphicsGlobals.farZ;
}

float GetNearZVal(void) {
    return g_graphicsGlobals.nearZ;
}

float GetScreenAspect(void) {
    return g_graphicsGlobals.aspect;
}
