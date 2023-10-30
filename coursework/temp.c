    int buffer1 = 100, count1 = 0;
    char line1[buffer1];
    while (fgets(line1, buffer1, file) != NULL) {
        count1++;
    }

    printf("Number of records in file: %d\n", count1);