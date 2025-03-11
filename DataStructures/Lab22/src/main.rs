use sortinglib;

fn main() {
    let mut arr = vec![3, 6, 8, 10, 1, 2, 1, 4]; // Приклад масиву
    let n = arr.len();

    // Знайти i-ту порядкову статистику
    let i = 3; // Приклад: знайти 3-тю найменшу порядкову статистику
    let ith_statistic = sortinglib::randomized_select(&mut arr, 0, n - 1, i);
    println!("{}-та порядкова статистика: {}", i, ith_statistic);

    // Знайти мінімальне значення (1-ша порядкова статистика)
    let min = sortinglib::randomized_select(&mut arr, 0, n - 1, 1);
    println!("Мінімальне значення: {}", min);

    // Знайти максимальне значення (n-та порядкова статистика)
    let max = sortinglib::randomized_select(&mut arr, 0, n - 1, n);
    println!("Максимальне значення: {}", max);

    // Знайти медіану
    if n % 2  == 0{
        let median1 = sortinglib::randomized_select(&mut arr, 0, n - 1, n/2);
        let median2 = sortinglib::randomized_select(&mut arr, 0, n - 1, (n/2)+1);
        //println!("{}, {}", median1, median2);
        println!("Медіана: {}", (median1+median2) as f32 / 2.0);
    }
    else {
        let median = sortinglib::randomized_select(&mut arr, 0, n - 1, n/2);
        println!("Медіана: {}", median);


   }}
