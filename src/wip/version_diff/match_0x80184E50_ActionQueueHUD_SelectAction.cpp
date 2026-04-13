// FLAGS: -fno-elide-constructors
// 0x80184E50 ActionQueueHUD::SelectAction (60b)

void SelectAction_test(char* self, int idx) {
    if (idx < 0 || idx >= *(int*)(self + 336)) {
        aqh_deactivate(self);
    } else {
        *(self + 793) = (char)idx;
    }
}
