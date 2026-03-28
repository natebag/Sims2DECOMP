/* FAMTarget::IsSelectedLotOccupied(void) at 0x802C8A1C (40B) */

struct FAMTarget;

extern int FAMTarget_helper(FAMTarget*, int, int*);

struct FAMTarget {
    int IsSelectedLotOccupied(int arg);
};

int FAMTarget::IsSelectedLotOccupied(int arg) {
    int result;
    FAMTarget_helper(this, arg, &result);
    return result;
}
