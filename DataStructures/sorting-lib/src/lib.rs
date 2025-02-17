/*pub fn add(left: u64, right: u64) -> u64 {
    left + right
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }
}*/

use rand::Rng;

pub fn merge(arr: &mut Vec<i32>, p: usize, q: usize, r: usize) {
    let left = arr[p..=q].to_vec();
    let right = arr[q+1..=r].to_vec();

    let mut left_vec = left.clone();
    let mut right_vec = right.clone();

    left_vec.push(i32::MAX);  // Нескінченність
    right_vec.push(i32::MAX); // Також нескінченність

    let (mut i, mut j) = (0, 0);
    for k in p..=r {
        if left_vec[i] <= right_vec[j] {
            arr[k] = left_vec[i];
            i += 1;
        } else {
            arr[k] = right_vec[j];
            j += 1;
        }
    }
}

pub fn merge_sort(arr: &mut Vec<i32>, p: usize, r: usize) {
    if p < r {
        let q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);  // Fix: pass arr as mutable reference
    }
}
pub fn quick_sort(arr: &mut [i32]) {
    if arr.len() <= 1 {
        return;
    }

    let mut rng = rand::thread_rng();
    let n = rng.gen_range(0..arr.len());
    arr.swap(n, arr.len() - 1); // Random pivot at the end

    let q = partition(arr);
    quick_sort(&mut arr[..q]);    // Sort left subarray
    quick_sort(&mut arr[q+1..]);  // Sort right subarray
}

pub fn partition(arr: &mut [i32]) -> usize {
    let pivot = arr[arr.len() - 1];
    let mut i = 0;

    for j in 0..arr.len() - 1 {
        if arr[j] <= pivot {
            arr.swap(i, j);
            i += 1;
        }
    }
    arr.swap(i, arr.len() - 1); // Place pivot in final position
    i
}
