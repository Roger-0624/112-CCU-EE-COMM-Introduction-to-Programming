#include <stdio.h>
#include <math.h>

int ran_dateNum[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int notRan_dateNum[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_ran(int year) {
    if (year % 400 == 0) return 1;
    else if (year % 100 == 0) return 0;
    else if (year % 4 == 0) return 1;
    else return 0;
}

int cal_dates_of_that_year(int y, int m, int d) {
    int ans = 0;
    if (is_ran(y))
        for (int i = 1; i < m; i++)
            ans += ran_dateNum[i];
    else
        for (int i = 1; i < m; i++)
            ans += notRan_dateNum[i];
    return ans + d;
}

int cal_dates_from_1_to_that_year(int y) {
    int ran_days = y / 4 - y / 100 + y / 400;    // 算出閏年的天數
    return y * 365 + ran_days;
}

int main() {
    int t; scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int y1, m1, d1, y2, m2, d2;
        scanf("%d %d %d", &y1, &m1, &d1);
        scanf("%d %d %d", &y2, &m2, &d2);
        
        int sum1 = cal_dates_from_1_to_that_year(y1 - 1)
            + cal_dates_of_that_year(y1, m1, d1);
        int sum2 = cal_dates_from_1_to_that_year(y2 - 1)
            + cal_dates_of_that_year(y2, m2, d2);
        
        printf("%d\n", abs(sum1 - sum2));
    }

    return 0;
}