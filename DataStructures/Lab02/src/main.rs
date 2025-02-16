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
        sortinglib::squick_sort(&mut vectors[i], 0, len - 1);
        
        println!("Відсортований масив: {:?}", vectors[i]);
    }
}
