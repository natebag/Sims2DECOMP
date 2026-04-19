// 0x803220D8 (60B) HDDThread::ArcIsOpen(int)
// Same pattern as ArcIsCurrent: pre-seed r3=0, bgt to shared epilogue.

extern int InnerArcOpen(void*);

class HDDThreadAO {
public:
    int ArcIsOpen(int);
};

int HDDThreadAO::ArcIsOpen(int idx) {
    int result = 0;
    if ((unsigned int)idx <= 31) {
        result = InnerArcOpen((char*)this + (idx * 20 + 0x340));
    }
    return result;
}
