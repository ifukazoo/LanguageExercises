use std::io;

fn main() {
    println!("What is your name?");

    let mut name = String::new();
    io::stdin().read_line(&mut name).expect("err");
    let name = name.trim();

    println!("Helle, {}, nice to meet you!", name);
}
