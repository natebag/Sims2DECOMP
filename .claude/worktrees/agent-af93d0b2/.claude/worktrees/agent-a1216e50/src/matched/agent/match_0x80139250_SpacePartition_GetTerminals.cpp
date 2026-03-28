/* SpacePartition::GetTerminals(int *, int *) - 0x80139250 - 20 bytes */
/* li r0, 0; li r9, 1; stw r0, 0(r4); stw r9, 0(r5); blr */

class SpacePartition {
public:
    void GetTerminals(int *, int *);
};

void SpacePartition::GetTerminals(int *pFirst, int *pLast) {
    *pFirst = 0;
    *pLast = 1;
}
