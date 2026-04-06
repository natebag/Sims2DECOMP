struct CameraBlurData { float x, y, z, w; };
extern void* gCameraBlurTarget;
extern "C" void applyCameraBlur(void*, float, float, float, float);
void SAnimator2_triggerCameraBlur(void* self, CameraBlurData* data) {
    applyCameraBlur(gCameraBlurTarget, data->x, data->y, data->z, data->w);
}
