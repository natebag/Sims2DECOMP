// 0x80142940 GoalUnlock::~GoalUnlock(void) (4B)
// dtor compiled to blr — avoid dtor syntax (triggers deleting-destructor expansion)
struct GoalUnlock { void _dtor(void); };
void GoalUnlock::_dtor(void) {}
