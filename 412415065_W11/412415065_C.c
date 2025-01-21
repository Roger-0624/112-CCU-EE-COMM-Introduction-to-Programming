#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[11];
    int chinese;
    int english;
    int math;
    int society;
    int science;
    int total;
} Student;

// 定義比較函數，用於快速排序
int compare(const void *a, const void *b) {
    // 先比較總分，總分高者排前面
    int diff = ((Student *)b)->total - ((Student *)a)->total;
    if (diff != 0) return diff;
    
    // 如果總分相同，依次比較各科成績，國文 > 英文 > 數學 > 社會 > 自然
    if (((Student *)a)->chinese != ((Student *)b)->chinese) {
        return ((Student *)b)->chinese - ((Student *)a)->chinese;
    }
    if (((Student *)a)->english != ((Student *)b)->english) {
        return ((Student *)b)->english - ((Student *)a)->english;
    }
    if (((Student *)a)->math != ((Student *)b)->math) {
        return ((Student *)b)->math - ((Student *)a)->math;
    }
    if (((Student *)a)->society != ((Student *)b)->society) {
        return ((Student *)b)->society - ((Student *)a)->society;
    }
    if (((Student *)a)->science != ((Student *)b)->science) {
        return ((Student *)b)->science - ((Student *)a)->science;
    }
    
    // 如果各科成績也相同，依字典序排序名字
    return strcmp(((Student *)a)->name, ((Student *)b)->name);
}

int main() {
    int n;
    scanf("%d", &n);

    // 分配記憶體來存儲學生資料
    Student *students = (Student *)malloc(n * sizeof(Student));
    if (students == NULL) {
        fprintf(stderr, "記憶體分配失敗\n");
        return 1;
    }

    // 讀取學生資料並計算總分
    for (int i = 0; i < n; i++) 
    {
        scanf("%s %d %d %d %d %d", students[i].name, &students[i].chinese, &students[i].english, &students[i].math, &students[i].society, &students[i].science);
        students[i].total = students[i].chinese + students[i].english + students[i].math + students[i].society + students[i].science;
    }
    // 使用快速排序對學生進行排序
    qsort(students, n, sizeof(Student), compare);

    // 輸出排名
    for (int i = 0; i < n; i++) {
        printf("%s\n", students[i].name);
    }

    // 釋放記憶體
    free(students);

    return 0;
}