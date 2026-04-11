// FLAGS: -fno-elide-constructors
// 0x80143438 SpriteSlot::ActivateForLoops (44b)

void ActivateForLoops_test(char* self, int loops) {
    int ticks = *(int*)(self + 44) * 12;
    slot_activate_ticks(self, ticks * loops);
}
