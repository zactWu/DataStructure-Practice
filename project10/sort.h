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
                swap(array[j], array[j + 1]);//��������
                compare_times++;
            }
        }
    }
    int end = clock();
    cout << "ð�����򽻻�����:" << compare_times << endl;
    cout << "ð����������ʱ��" << end - begin << endl;
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
        }//ѡ�����ؼ���
        swap(array[i],array[min_loc]);
        compare_times++;
    }
    int end = clock();
    cout << "ѡ�����򽻻�����:" << compare_times << endl;
    cout << "ѡ����������ʱ��" << end - begin << endl;
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
    cout << "ֱ�Ӳ������򽻻�����:" << compare_times << endl;
    cout << "ֱ�Ӳ�����������ʱ��" << end - begin << endl;
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
    cout << "ϣ�����򽻻�����:" << compare_times << endl;
    cout << "ϣ����������ʱ��" << end - begin << endl;
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
                array[i++] = array[j];//�Ҳ��С��
                compare_times++;
            }
            while (i < j && array[i] < key) {
                i++;
            }
            if (i < j) {
                array[j--] = array[i];//���ϴ���
                compare_times++;
            }
        }
        array[i] = key;//����ؼ���
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
    cout << "�������򽻻�����:" << compare_times << endl;
    cout << "������������ʱ��" << end - begin << endl;
}

void HeapOpeartion(int * array, int i, int len, int &compare_times) {
    int temp = array[i];//��ȡ����ǰԪ��i
    for (int k = i * 2 + 1; k < len; k = k * 2 + 1) {//��i�������ӽ�㿪ʼ��Ҳ����2i+1����ʼ
        if (k + 1 < len && array[k] < array[k + 1]) {//������ӽ��С�����ӽ�㣬kָ�����ӽ��
            k++;
        }
        if (array[k] > temp) {//����ӽڵ���ڸ��ڵ㣬���ӽڵ�ֵ�������ڵ㣨���ý��н�����
            array[i] = array[k];
            i = k;
            compare_times++;
        }
        else {
            break;
        }
    }
    array[i] = temp;//��tempֵ�ŵ����յ�λ��
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
    cout << "�����򽻻�����:" << compare_times << endl;
    cout << "����������ʱ��:" << end - begin  << endl;
}

void merge(int* array, int mid, int len, int &compare_times){
    int * temp = new int[len];
    int i = 0;//������ָ��
    int j = mid + 1;//������ָ��
    int t = 0;//��ʱ����ָ��
    while (i <= mid && j < len) {
        if (array[i] <= array[j]) {
            temp[t++] = array[i++];
            compare_times++;
        }
        else {
            temp[t++] = array[j++];

        }
    }
    while (i <= mid) {//�����ʣ��Ԫ������temp��
        temp[t++] = array[i++];
    }
    while (j < len) {//��������ʣ��Ԫ������temp��
        temp[t++] = array[j++];
    }
    t = 0;
    //��temp�е�Ԫ��ȫ��������ԭ������
    memcpy(array, temp, sizeof(int) * len);
    delete[]temp;
}

void MSOperation(int * array, int len, int &compare_times) {
    if (len > 1) {
        int mid = (len - 1) / 2;//�м�Ԫ�ص��±�
        MSOperation(array, mid + 1, compare_times);//_size��mid+1
        MSOperation(array + mid + 1, len - mid - 1, compare_times);//�ұ߹鲢����ʹ��������������
        merge(array, mid, len, compare_times);//����������������ϲ�����
    }
}
void MergeSort(int * ori_array, int len) {
    int *array = new int[len];
    memcpy(array, ori_array, sizeof(int) * len);
    int compare_times = 0;
    int start = clock();
    MSOperation(array, len, compare_times);
    int end = clock();
    cout << "�鲢����Ƚϴ���:" << compare_times << endl;
    cout << "�鲢��������ʱ��" << end - start << endl;
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
    int exp;    // ָ�����������鰴��λ��������ʱ��exp=1����ʮλ��������ʱ��exp=10��...
    int max = ori_array[0];
    for (int i = 1; i < len; i++)
        if (ori_array[i] > max)
            max = ori_array[i];//�����е����ֵ
    int * array = new int[len];
    memcpy(array, ori_array, sizeof(int) * len);				   // �Ӹ�λ��ʼ��������a��"ָ��"��������
    for (exp = 1; max / exp > 0; exp *= 10) {
        RSOperation(array, len, exp);
    }
    int end = clock();
    cout << "��������Ƚϴ���:" << 0 << endl;
    cout << "������������ʱ��" << end - start << endl;
}

#endif //PROJECT10_SORT_H
