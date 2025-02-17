use sortinglib;

fn main() {
    let mut vectors = vec![
        vec![6, 2, 5, 8, 1],
        vec![7, 2, 1, 9, 3],
        vec![12, 63, 23, 75]
    ];

    for i in 0..vectors.len() {
        println!("Оригінальний масив: {:?}", vectors[i]); 
        
        let len = vectors[i].len();
        sortinglib::quick_sort(&mut vectors[i]);
        
        println!("Відсортований масив: {:?}", vectors[i]);
    }
}
