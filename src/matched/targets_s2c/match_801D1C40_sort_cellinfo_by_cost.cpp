/* sort_cellinfo_by_cost(void *, void *) at 0x801D1C40 (100B) */

struct cCellInfo {
    int GetPrice() const;
};

int sort_cellinfo_by_cost(void* a, void* b) {
    if (a == b) return 0;
    int priceA = ((cCellInfo*)a)->GetPrice();
    int priceB = ((cCellInfo*)b)->GetPrice();
    if (priceA == priceB) return 0;
    return (priceA < priceB) ? -1 : 1;
}
