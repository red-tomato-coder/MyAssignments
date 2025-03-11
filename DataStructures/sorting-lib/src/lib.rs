use rand::Rng;

// Функція для об'єднання двох підмасивів у Merge Sort
pub fn merge(arr: &mut [i32], p: usize, q: usize, r: usize) {
    let left = arr[p..=q].to_vec(); // Лівий підмасив
    let right = arr[q + 1..=r].to_vec(); // Правий підмасив

    let mut left_vec = left.clone();
    let mut right_vec = right.clone();

    left_vec.push(i32::MAX); // Додаємо "нескінченність" для спрощення порівнянь
    right_vec.push(i32::MAX); // Те саме для правого підмасиву

    let (mut i, mut j) = (0, 0); // Індекси для лівої та правої частин

    // Об'єднуємо два підмасиви
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

// Функція Merge Sort
pub fn merge_sort(arr: &mut [i32], p: usize, r: usize) {
    if p < r {
        let q = (p + r) / 2; // Знаходимо середину масиву
        merge_sort(arr, p, q); // Сортуємо ліву частину
        merge_sort(arr, q + 1, r); // Сортуємо праву частину
        merge(arr, p, q, r); // Об'єднуємо дві відсортовані частини
    }
}

// Функція розбиття для QuickSort
pub fn partition(arr: &mut [i32], p: usize, r: usize) -> usize {
    let pivot = arr[r]; // Обираємо опорний елемент (останній елемент)
    let mut i = p as i32 - 1; // Індекс для менших елементів

    // Проходимо по масиву та переміщуємо елементи менші за опорний ліворуч
    for j in p..r {
        if arr[j] <= pivot {
            i += 1;
            arr.swap(i as usize, j); // Міняємо місцями
        }
    }
    arr.swap((i + 1) as usize, r); // Ставимо опорний елемент на правильну позицію
    (i + 1) as usize // Повертаємо індекс опорного елемента
}

// Функція рандомізованого розбиття
pub fn randomized_partition(arr: &mut [i32], p: usize, r: usize) -> usize {
    let i = rand::thread_rng().gen_range(p..=r); // Обираємо випадковий індекс для опорного елемента
    arr.swap(i, r); // Міняємо випадковий елемент з останнім
    partition(arr, p, r) // Викликаємо стандартне розбиття
}

// Функція QuickSort
pub fn quick_sort(arr: &mut [i32], p: usize, r: usize) {
    if p < r {
        let q = partition(arr, p, r); // Розбиваємо масив
        quick_sort(arr, p, q.saturating_sub(1)); // Сортуємо ліву частину
        quick_sort(arr, q + 1, r); // Сортуємо праву частину
    }
}

// Функція рандомізованого QuickSort
pub fn randomized_quick_sort(arr: &mut [i32], p: usize, r: usize) {
    if p < r {
        let q = randomized_partition(arr, p, r); // Розбиваємо масив з випадковим опорним елементом
        randomized_quick_sort(arr, p, q.saturating_sub(1)); // Сортуємо ліву частину
        randomized_quick_sort(arr, q + 1, r); // Сортуємо праву частину
    }
}

// Функція для знаходження i-тої порядкової статистики
pub fn randomized_select(arr: &mut [i32], p: usize, r: usize, i: usize) -> i32 {
    if p == r {
        return arr[p]; // Базовий випадок: масив має один елемент
    }

    // Розбиваємо масив навколо випадкового опорного елемента
    let q = randomized_partition(arr, p, r);

    // Кількість елементів у лівій частині (включаючи опорний)
    let k = q - p + 1;

    if i == k {
        // Опорний елемент є i-тою порядковою статистикою
        arr[q]
    } else if i < k {
        // i-та статистика знаходиться у лівій частині
        randomized_select(arr, p, q - 1, i)
    } else {
        // i-та статистика знаходиться у правій частині
        randomized_select(arr, q + 1, r, i - k)
    }
}

// Функція Counting Sort
pub fn counting_sort(arr: &mut Vec<i32>) {
    if arr.is_empty() {
        return;
    }

    let min = *arr.iter().min().unwrap(); // Знаходимо мінімальне значення
    let max = *arr.iter().max().unwrap(); // Знаходимо максимальне значення
    let range = (max - min + 1) as usize; // Обчислюємо діапазон

    let mut count = vec![0; range]; // Ініціалізуємо масив для підрахунку

    // Рахуємо кількість кожного елемента
    for &num in arr.iter() {
        count[(num - min) as usize] += 1;
    }

    // Відновлюємо відсортований масив
    let mut index = 0;
    for (i, &count) in count.iter().enumerate() {
        for _ in 0..count {
            arr[index] = (i as i32) + min;
            index += 1;
        }
    }
}

// Функція Radix Sort
pub fn radix_sort(arr: &mut Vec<i32>) {
    if arr.is_empty() {
        return;
    }

    let max = *arr.iter().max().unwrap(); // Знаходимо максимальне значення
    let mut exp = 1; // Початковий розряд (одиниці)

    // Сортуємо за кожним розрядом
    while max / exp > 0 {
        counting_sort_by_digit(arr, exp);
        exp *= 10; // Переходимо до наступного розряду
    }
}

// Допоміжна функція для сортування за розрядом у Radix Sort
pub fn counting_sort_by_digit(arr: &mut Vec<i32>, exp: i32) {
    let mut output = vec![0; arr.len()]; // Вихідний масив
    let mut count = vec![0; 10]; // Масив для підрахунку цифр (0-9)

    // Рахуємо кількість кожної цифри у поточному розряді
    for &num in arr.iter() {
        let digit = (num / exp) % 10;
        count[digit as usize] += 1;
    }

    // Обчислюємо кумулятивну кількість
    for i in 1..10 {
        count[i] += count[i - 1];
    }

    // Будуємо вихідний масив
    for &num in arr.iter().rev() {
        let digit = (num / exp) % 10;
        output[count[digit as usize] - 1] = num;
        count[digit as usize] -= 1;
    }

    // Копіюємо відсортовані елементи назад у вихідний масив
    arr.copy_from_slice(&output);
}
