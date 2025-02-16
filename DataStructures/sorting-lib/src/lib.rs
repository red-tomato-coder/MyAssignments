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

pub fn quick_sort(arr: &mut Vec<i32>, p: usize, r: usize) {
    if p < r {
        let mut q = partition(arr, p, r);
        quick_sort(arr, p, q-1);
        quick_sort(arr, q+1, r);
    }
}

pub fn partition(arr: &mut Vec<i32>, p: usize, r: usize) {
    let mut x = arr[r];
    let mut i = p - 1;
    let j = p;
    for p in 0..r-1{
        if arr[j] <= x{
            i+=1;
            let mut swap = arr[i];
            arr[i] = arr[j];
            arr[j] = swap;
        }
    }
    let mut swap = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = swap;
}
