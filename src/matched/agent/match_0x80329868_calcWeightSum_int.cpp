// 0x80329868 calcWeightSum(int) (52 B)
// FLAGS: -fno-schedule-insns
// Pattern: li+cmpw guard; mtspr CTR; bdnz loop; cmpwi/li zero-guard on sum

int calcWeightSum(int* weights, int count) {
    int sum = 0;
    if (sum < count) {
        int n = count;
        do {
            sum += *weights++;
        } while (--n);
    }
    if (sum == 0) sum = 1;
    return sum;
}
