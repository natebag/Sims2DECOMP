void ConditionalCallTarget(void *);

struct ConditionalCaller {
    void MaybeCall(int flag);
};

void ConditionalCaller::MaybeCall(int flag) {
    if (flag & 1) {
        ConditionalCallTarget(this);
    }
}
