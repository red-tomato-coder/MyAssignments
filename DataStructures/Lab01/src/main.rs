use std::io;
use sortinglib;

fn main() {

    let mut vec = vec![];

    loop{
        let mut input = String::new();
        io::stdin().read_line(&mut input);
        if input.trim() == "run"{
            break;
        }
        let num: i32 = input.trim().parse().expect("Має бути число");
        vec.push(num);
    }
    let veclen = vec.len()-1;
    println!("Оригінальний масив: {:?}", vec); 
        
    sortinglib::merge_sort(&mut vec, 0, veclen);
        
    println!("Відсортований масив: {:?}", vec);
}
