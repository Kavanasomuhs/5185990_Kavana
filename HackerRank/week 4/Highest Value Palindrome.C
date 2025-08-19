char* highestValuePalindrome(char* s, int n, int k) {

    char* result = (char*)malloc((n + 1) * sizeof(char));
    strcpy(result, s);

    int* changed = (int*)calloc(n, sizeof(int));
    int l = 0, r = n - 1;

    
    while (l < r) {
        if (result[l] != result[r]) {
            if (result[l] > result[r]) {
                result[r] = result[l];
            } else {
                result[l] = result[r];
            }
            changed[l] = changed[r] = 1;
            k--;
        }
        l++; r--;
    }

    if (k < 0) {
        free(changed);
        strcpy(result, "-1");
        return result;
    }

    
    l = 0; r = n - 1;
    while (l <= r) {
        if (l == r) { 
            if (k > 0) result[l] = '9';
        } else {
            if (result[l] != '9') {
                if (changed[l] && k >= 1) {
                    result[l] = result[r] = '9';
                    k -= 1;
                } else if (!changed[l] && k >= 2) {
                    result[l] = result[r] = '9';
                    k -= 2;
                }
            }
        }
        l++; r--;
    }

    free(changed);
    return result;
}
