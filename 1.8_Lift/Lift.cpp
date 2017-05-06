// #1 O(N^2)
int N;
int nPerson[];
int nFloor, nMinFloor, nTargetFloor = -1;
for (int i = 1; i <= N; i++) {
    nFloor = 0;
    for (int j = 1; j <= N; j++) {
        nFloor += nPerson[j] * abs(j - i);
    }
    if (nFloor < nMinFloor) {
        nMinFloor = nFloor;
        nTargetFloor = i;
    }
}
return (nTargetFloor, nMinFloor);

// #2 O(N)
int N;
int nPerson[];
int nMinFloor = 0, nTargetFloor = 1;
int N1, N2, N3;
for (N1 = 0, N2 = nPerson[1], N3 = 0, int i = 2; i <= N; i++) {
    N3 += nPerson[i];
    nMinFloor += nPerson[i] * (i - 1);
}
for (int i = 2; i <= N; i++) {
    if (N1 + N2 < N3) {
        nTargetFloor = i;
        nMinFloor += (N1 + N2 - N3);
        N1 += N2;
        N2 = nPerson[i];
        N3 -= nPerson[i];
    } else
        break;
}
return (nTargetFloor, nMinFloor);


// #3 Median
