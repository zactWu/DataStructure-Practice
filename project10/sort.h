//
// Created by Zact on 2019/12/10.
//

#ifndef PROJECT10_SORT_H
#define PROJECT10_SORT_H

#include <iostream>
#include <ctime>
using namespace std;

void BubbleSort(int * ori_array, int len){
    int * array = new int[len];
    memcpy(array, ori_array, sizeof(int)*len);
    int compare_times = 0;
    int begin = clock();
    for (int i = 0; i < len-1; ++i) {
        for (int j = 0; j < len - i; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);//两两交换
                compare_times++;
            }
        }
    }
    int end = clock();
    cout << "冒泡排序交换次数:" << compare_times << endl;
    cout << "冒泡排序所用时间" << end - begin << endl;
}

void SelectionSort(int * ori_array, int len){
    int * array = new int[len];
    memcpy(array, ori_array, sizeof(int)*len);
    int compare_times = 0;
    int begin = clock();
    for (int i = 0; i < len; ++i) {
        int min_loc = i;
        for (int j = i + 1; j < len; ++j) {
            if(array[j] < array[min_loc]){
                min_loc = j;
            }
        }//选择最大关键码
        swap(array[i],array[min_loc]);
        compare_times++;
    }
    int end = clock();
    cout << "选择排序交换次数:" << compare_times << endl;
    cout << "选择排序所用时间" << end - begin << endl;
}

void InsertionSort(int * ori_array, int len){
    int * array = new int[len];
    memcpy(array, ori_array, sizeof(int)*len);
    int compare_times = 0;
    int begin = clock();
    int temp_num = 0;
    for (int i = 1; i < len; ++i) {
        temp_num = array[i];
        int j = i;
        while(j > 0 && temp_num < array[j-1]){
            array[j] = array[j-1];
            j--;
        }
        array[j] = temp_num;
        compare_times++;
    }
    int end = clock();
    cout << "直接插入排序交换次数:" << compare_times << endl;
    cout << "直接插入排序所用时间" << end - begin << endl;
}

void ShellSort(int * ori_array, int len){
    int * array = new int[len];
    memcpy(array, ori_array, sizeof(int)*len);
    int compare_times = 0;
    int begin = clock();
    int gap = (int)(len/2);
    int temp_num = 0;
    while(gap){
        for (int i = gap; i < len; ++i) {
            temp_num = array[i];
            int j = i;
            while (j >= gap && temp_num < array[j - gap]) {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = temp_num;
            compare_times++;
        }
            gap = gap == 2 ? 1 : (int) (gap / 2.2);
    }
    int end = clock();
    cout << "希尔排序交换次数:" << compare_times << endl;
    cout << "希尔排序所用时间" << end - begin << endl;
}

void QSOperation(int *array, int left, int right, int &compare_times){
    if(left<right) {
        int i = left;
        int j = right;
        int key = array[i];
        while (i != j) {
            while (i < j && array[j] > key) {
                j--;
            }
            if (i < j) {
                array[i++] = array[j];//右侧较小数
                compare_times++;
            }
            while (i < j && array[i] < key) {
                i++;
            }
            if (i < j) {
                array[j--] = array[i];//左侧较大数
                compare_times++;
            }
        }
        array[i] = key;//放入关键数
        compare_times++;
        QSOperation(array, left, i - 1,compare_times);
        QSOperation(array, j + 1, right,compare_times);
    }
}

void QuickSort(int * ori_array, int len){
    int * array = new int[len];
    memcpy(array, ori_array, sizeof(int)*len);
    int compare_times = 0;
    int begin = clock();
    QSOperation(array, 0, len - 1,compare_times);
    int end = clock();
    cout << "快速排序交换次数:" << compare_times << endl;
    cout << "快速排序所用时间" << end - begin << endl;
}

void HeapOpeartion(int * array, int i, int len, int &compare_times) {
    int temp = array[i];//先取出当前元素i
    for (int k = i * 2 + 1; k < len; k = k * 2 + 1) {//从i结点的左子结点开始，也就是2i+1处开始
        if (k + 1 < len && array[k] < array[k + 1]) {//如果左子结点小于右子结点，k指向右子结点
            k++;
        }
        if (array[k] > temp) {//如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
            array[i] = array[k];
            i = k;
            compare_times++;
        }
        else {
            break;
        }
    }
    array[i] = temp;//将temp值放到最终的位置
}
void HeapSort(int * ori_array, int len){
    int * array = new int[len];
    memcpy(array, ori_array, sizeof(int)*len);
    int compare_times = 0;
    int begin = clock();
    for (int i = len / 2 - 1; i >= 0; --i) {
        HeapOpeartion(array, i, len, compare_times);
    }
    for (int i = len-1; i >= 0; --i) {
        compare_times++;
        swap(array[i],array[0]);
        HeapOpeartion(array,0,i, compare_times);
    }
    int end = clock();
    delete[]array;
    cout << "堆排序交换次数:" << compare_times << endl;
    cout << "堆排序所用时间:" << end - begin  << endl;
}

void merge(int* array, int mid, int len, int &compare_times){
    int * temp = new int[len];
    int i = 0;//左序列指针
    int j = mid + 1;//右序列指针
    int t = 0;//临时数组指针
    while (i <= mid && j < len) {
        if (array[i] <= array[j]) {
            temp[t++] = array[i++];
            compare_times++;
        }
        else {
            temp[t++] = array[j++];

        }
    }
    while (i <= mid) {//将左边剩余元素填充进temp中
        temp[t++] = array[i++];
    }
    while (j < len) {//将右序列剩余元素填充进temp中
        temp[t++] = array[j++];
    }
    t = 0;
    //将temp中的元素全部拷贝到原数组中
    memcpy(array, temp, sizeof(int) * len);
    delete[]temp;
}

void MSOperation(int * array, int len, int &compare_times) {
    if (len > 1) {
        int mid = (len - 1) / 2;//中间元素的下标
        MSOperation(array, mid + 1, compare_times);//_size是mid+1
        MSOperation(array + mid + 1, len - mid - 1, compare_times);//右边归并排序，使得右子序列有序
        merge(array, mid, len, compare_times);//将两个有序子数组合并操作
    }
}
void MergeSort(int * ori_array, int len) {
    int *array = new int[len];
    memcpy(array, ori_array, sizeof(int) * len);
    int compare_times = 0;
    int start = clock();
    MSOperation(array, len, compare_times);
    int end = clock();
    cout << "归并排序比较次数:" << compare_times << endl;
    cout << "归并排序所用时间" << end - start << endl;
}

void RSOperation(int * array, int len, int exp)
{
    int i, buckets[10] = { 0 };
    int * outputs = new int[len];

    for (i = 0; i < len; i++)
        buckets[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        buckets[i] += buckets[i - 1];

    for (i = len - 1; i >= 0; i--)
    {
        outputs[buckets[(array[i] / exp) % 10] - 1] = array[i];
        buckets[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < len; i++)
        array[i] = outputs[i];
}

void RadixSort(int * ori_array, int len)
{
    int start = clock();
    int exp;    // 指数。当对数组按各位进行排序时，exp=1；按十位进行排序时，exp=10；...
    int max = ori_array[0];
    for (int i = 1; i < len; i++)
        if (ori_array[i] > max)
            max = ori_array[i];//数组中的最大值
    int * array = new int[len];
    memcpy(array, ori_array, sizeof(int) * len);				   // 从个位开始，对数组a按"指数"进行排序
    for (exp = 1; max / exp > 0; exp *= 10) {
        RSOperation(array, len, exp);
    }
    int end = clock();
    cout << "基数排序比较次数:" << 0 << endl;
    cout << "基数排序所用时间" << end - start << endl;
}

#endif //PROJECT10_SORT_H
