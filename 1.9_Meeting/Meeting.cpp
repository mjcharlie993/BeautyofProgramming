// O(N)
int nMaxColors = 0;
for (int i = 0; i < N; i++) {
    for (int k = 0; k < nMaxColors; k++)
        isForbidden[k] = false;
    for (int j = 0; j < i; j++) 
        if (Overlap(b[j], e[j], b[i], e[i]))
            isForbidden[color[j]] = true;
    for (int k = 0; k < nMaxColors; k++) 
        if (!isForbidden[k]])
            break;
    if (k < nMaxColors)
        color[i] = k;
    else
        color[i] = nMaxColors++;
}
return nMaxColors;

// O(NlogN)
int nColorUsing = 0, MaxColor = 0;
for (int i = 0; i < 2 * N; i++) {
    if (TimePoints[i].type == "Begin") {
        nColorUsing++;
        if (nColorUsing > MaxColor)
            MaxColor = nColorUsing;
    } else
        nColorUsing--;
}