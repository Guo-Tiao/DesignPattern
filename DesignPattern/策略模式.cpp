#include "策略模式.h"

// 抽象策略类
class Strategy
{
public:
	Strategy() {}
	virtual void Sort(int arr[], int N) = 0;
};

// 具体策略：冒泡排序
class BubbleSort :public Strategy
{
public:
	BubbleSort() {
		printf("冒泡排序_构造\n");
	}
	void Sort(int arr[], int N) 
	{
		printf("进行冒泡排序:\n");
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N - i - 1; j++)
			{
				if (arr[j] > arr[j + 1]) {
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
	}
};

// 具体策略：选择排序
class SelectionSort :public Strategy
{
public:
	SelectionSort() {
		printf("选择排序_构造\n");
	}
	void Sort(int arr[], int N) 
	{
		printf("进行选择排序:\n");
		int i, j, k;
		for (i = 0; i < N; i++)
		{
			k = i;
			for (j = i + 1; j < N; j++)
			{
				if (arr[j] < arr[k]) {
					k = j;
				}
			}
			int temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
};

// 具体策略：插入排序
class InsertSort :public Strategy
{
public:
	InsertSort() {
		printf("插入排序_构造\n");
	}
	void Sort(int arr[], int N) 
	{
		printf("进行插入排序:\n");
		int i, j;
		for (i = 1; i < N; i++)
		{
			for (j = i - 1; j >= 0; j--)
			{
				if (arr[i] > arr[j]) {
					break;
				}
			}
			int temp = arr[i];
			for (int k = i - 1; k > j; k--) {
				arr[k + 1] = arr[k];
			}
			arr[j + 1] = temp;
		}
	}
};



// 上下文类
class Context
{
public:
	Context() {
		arr = NULL;
		N = 0;
	}
	Context(int iArr[], int iN) {
		this->arr = iArr;
		this->N = iN;
	}
	void SetSortStrategy(Strategy* iSortStrategy) {
		this->sortStrategy = iSortStrategy;
	}
	void Sort() {
		this->sortStrategy->Sort(arr, N);
		printf("输出：");
		this->Print();
	}
	void SetInput(int iArr[], int iN) {
		this->arr = iArr;
		this->N = iN;
	}
	void Print() {
		for (int i = 0; i < N; i++) {
			printf("%3d ", arr[i]);
		}
		printf("\n");
	}

private:
	Strategy* sortStrategy;
	int* arr;
	int N;
};

void 策略模式::运行()
{
	std::cout << "********************策略模式********************" << std::endl;

	Context* ctx = new Context();

	int arr[] = { 7, 3, 13, 0, 66, 17, 36, 77, -33, -1, 11 };
	ctx->SetInput(arr, sizeof(arr) / sizeof(int));
	printf("输入:");
	ctx->Print();

	// 冒泡排序
	ctx->SetSortStrategy(new BubbleSort());
	ctx->Sort();

	// 选择排序
	ctx->SetSortStrategy(new SelectionSort());
	ctx->Sort();

	// 插入排序
	ctx->SetSortStrategy(new InsertSort());
	ctx->Sort();

	std::cout << "************************************************" << std::endl;
}
