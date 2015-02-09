quick_sort_test.exe: quick_sort.o check_quick_sort.o
	gcc -o quick_sort_test quick_sort.o check_quick_sort.o
quick_sort.o:quick_sort.c
	gcc -c quick_sort.c
check_quick_sort.o:check_quick_sort.c
	gcc -c check_quick_sort.c
clean:
	rm quick_sort_test.exe quick_sort.o check_quick_sort.o
