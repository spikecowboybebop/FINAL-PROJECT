void staff_delete_record() {
    char del_data[2][50];
    printf("Enter the ID - ");
    gets(del_data[0]);
    printf("Enter Employee's Name - ");
    gets(del_data[1]);

    char fname[50] = "staff-";
    strcat(fname, del_data[0]);
    strcat(fname, del_data[1]);
    strcat(fname, ".txt");

    if(remove(fname) == 0) {
        printf("Record Deleted Successfully\n");
        FILE *fptr;
        fptr = fopen("staff-count.txt", "r");
        char count[10];
        fgets(count, sizeof(count), fptr);
        int c = atoi(count);
        c--;
        fclose(fptr);
        FILE *wfptr;
        wfptr = fopen("staff-count.txt", "w");
        fprintf(wfptr, "%d", c);

    }
    else {
        printf("Delete: Operation failed\n");
    }
}