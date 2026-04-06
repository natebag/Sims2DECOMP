extern short gClipStackDepth;
extern "C" void pushUnitClip(void);
void AptMath_ClipStackPushUnit() {
    gClipStackDepth++;
    pushUnitClip();
}
