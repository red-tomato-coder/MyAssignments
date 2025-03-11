use sortinglib;

fn main() {
    let mut vectors = vec![
        vec![6, 2, 5, 8, 1],
        vec![7, 2, 1, 9, 3],
        vec![12, 63, 23, 75]
    ];
        println!("Метод підрахунку");
    for i in 0..vectors.len() {
        println!("Оригінальний масив: {:?}", vectors[i]); 
        
        sortinglib::counting_sort(&mut vectors[i]); 
        
        println!("Відсортований масив: {:?}", vectors[i]);
    }
    let mut vectors = vec![
        vec![6, 2, 5, 8, 1],
        vec![7, 2, 1, 9, 3],
        vec![12, 63, 23, 75]
    ];
        println!("***********");
        println!("Radix метод");
        println!("***********");
    for i in 0..vectors.len() {
        println!("Оригінальний масив: {:?}", vectors[i]); 
        
        sortinglib::radix_sort(&mut vectors[i]); 
        
        println!("Відсортований масив: {:?}", vectors[i]);
    }
}
