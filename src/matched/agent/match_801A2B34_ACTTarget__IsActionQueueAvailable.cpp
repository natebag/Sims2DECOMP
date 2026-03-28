class ACTTarget {
public:
    int IsActionQueueAvailable(int) const;
};

int ACTTarget::IsActionQueueAvailable(int) const {
    return 1;
}
