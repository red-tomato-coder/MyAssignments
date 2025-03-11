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
        let num: i32 = input.trim().parse().expect("Має бути цифра");
        vec.push(num);
    }

    let mut vec1 = vec.clone();
    let vecl = vec.len();
    let vec1l = vec1.len();

    println!("Оригінальний масив: {:?}", vec); 
        
    sortinglib::quick_sort(&mut vec, 0, vecl - 1);
    //let veclen = vec1.len() - 1; //Існує тільки тому, що не можна вносити двічі один елемент у аргументи   
    println!("Відсортований масив: {:?}", vec);
    //****
    println!("Оригінальний масив: {:?}", vec1);
    sortinglib::randomized_quick_sort(&mut vec1, 0, vec1l - 1);
    println!("Відсортований масив: {:?} (з випадковим опорним)", vec1);
}
