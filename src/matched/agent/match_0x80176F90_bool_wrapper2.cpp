struct BoolWrapper2 {
    int InternalCheck();
    int BoolCheck();
};

int BoolWrapper2::BoolCheck() {
    return InternalCheck() != 0;
}
