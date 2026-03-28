void ECheatsResetCodes(void* self);
void ECheatsResetFlags(void* self);

void ECheats_Reset(void* self) {
    ECheatsResetCodes(self);
    ECheatsResetFlags(self);
}
