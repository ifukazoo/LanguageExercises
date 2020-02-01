use std::io;
use std::io::Write;

fn main() -> Result<(), std::io::Error> {
    let mut first_number = String::new();
    print!("What is the first number? ");
    io::stdout().flush()?;
    io::stdin().read_line(&mut first_number)?;
    let first_number: i32 = first_number.trim().parse().unwrap();

    let mut second_number = String::new();
    print!("What is the second number? ");
    io::stdout().flush()?;
    io::stdin().read_line(&mut second_number)?;
    let second_number: i32 = second_number.trim().parse().unwrap();

    println!(
        "{} + {} = {}",
        first_number,
        second_number,
        first_number + second_number
    );
    println!(
        "{} - {} = {}",
        first_number,
        second_number,
        first_number - second_number
    );
    println!(
        "{} * {} = {}",
        first_number,
        second_number,
        first_number * second_number
    );
    println!(
        "{} / {} = {}",
        first_number,
        second_number,
        first_number / second_number
    );

    Ok(())
}
