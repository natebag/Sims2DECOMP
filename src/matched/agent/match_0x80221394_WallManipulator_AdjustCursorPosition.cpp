// FLAGS: -fno-elide-constructors
// 0x80221394 WallManipulator::AdjustCursorPosition (44b)

void AdjustCursorPosition_test(char* self) {
    wm_adjust_func(self + 8, self + 32, 2);
}
