#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//W11 C

struct student {
    int chi;
    int eng;
    int math;
    int soc;
    int sci;
    int sum;
    char name[100];
} typedef student;

int cmp(const void *pa, const void *pb) {
    student a = *(student*)pa;
    student b = *(student*)pb;
    if (a.sum != b.sum) return b.sum - a.sum;
    else if (a.chi != b.chi) return b.chi - a.chi;
    else if (a.eng != b.eng) return b.eng - a.eng;
    else if (a.math != b.math) return b.math - a.math;
    else if (a.soc != b.soc) return b.soc - a.soc;
    else if (a.sci != b.sci) return b.sci - a.sci;
    else return strcmp(a.name, b.name);
}

int main() {
    int n; scanf("%d", &n);
    student students[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d %d %d", &students[i].name,
            &students[i].chi,
            &students[i].eng,
            &students[i].math,
            &students[i].soc,
            &students[i].sci);
        students[i].sum = students[i].chi +
            students[i].eng +
            students[i].math +
            students[i].soc +
            students[i].sci;
    }
    
    qsort(students, n, sizeof(students), cmp);
    for (int i = 0; i < n; i++) {
        printf("%s\n", students[i].name);
    }
    
    return 0;
}