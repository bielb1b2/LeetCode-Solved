#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main(void) {

  int case1_array1[2] = {1,2};
  int case1_array2[2] = {3,4};

  double resultCase1 = findMedianSortedArrays(case1_array1, 2, case1_array2, 2);
  printf("%f", resultCase1);

  return 0;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int total = nums1Size + nums2Size;
  int mid = total / 2;

  int i = 0;
  int j = 0;
  int count = 0;
  int prev = 0, curr = 0;
  
  while (count <= mid)
  {
    prev = curr;
    if(i < nums1Size && (j >= nums2Size || nums1[i] <= nums2[j])) {
      curr = nums1[i++];
    } else {
      curr = nums2[j++];
    }

    count++;
  }

  if(total % 2 == 1) {
    return (double)curr;
  } else {
    return ((double)prev + (double)curr) / 2.0;
  }
}