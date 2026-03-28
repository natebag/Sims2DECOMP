struct BoolWrapper1 {
    int InternalCheck();
    int BoolCheck();
};

int BoolWrapper1::BoolCheck() {
    return InternalCheck() != 0;
}
