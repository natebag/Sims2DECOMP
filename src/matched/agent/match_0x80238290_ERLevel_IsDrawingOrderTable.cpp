extern int gERLevel_IsDrawingOrderTable;

struct ERLevel {
    static int IsDrawingOrderTable();
};
int ERLevel::IsDrawingOrderTable() { return gERLevel_IsDrawingOrderTable; }
