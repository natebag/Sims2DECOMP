// 0x80134FCC RelMatrixImpl::GetValue(int, int) (60B)
// ASMPROC_swap_operands: match="lwzx 3,30,9" pos=1,2

class RelMatrixImpl {
public:
    int*** FindArray(int row);
    int GetValue(int row, int col);
};

int RelMatrixImpl::GetValue(int row, int col) {
    int*** p = FindArray(row);
    int** q = *p;
    int* arr = *q;
    return arr[col];
}
