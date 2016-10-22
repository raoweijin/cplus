//This can implement shift right or left
void shiftright(int* data, int offset, int len) {

	for (int i = 0; i < ((len - offset) / 2); i++) {
		swapdata(data[i], data[len - offset - i-1]);
	}
	for (int i = 0; i < offset / 2; i++) {
	swapdata(data[i + len - offset], data[len - i-1]);
		}
	for (int i = 0; i < len / 2; i++) {
			swapdata(data[i], data[len - i-1]);
		}
}

int main()
{

	printf("start right shift\n");
	int datasource[10] = { 1,2,3,4,5,6,7,8,9 };
	int datadestination[10] = { 7,8,9,1,2,3,4,5,6 };
	for (int i = 0; i < 9; i++) {
		printf(" %d ", datasource[i]);
	}
	printf("\n");

	shiftright(datasource, 3, 9);
	for (int i = 0; i < 9; i++) {
		printf(" %d ", datasource[i]);
	}
	printf("\n");

	return 1;
}