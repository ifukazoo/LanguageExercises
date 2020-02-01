extern crate chrono;
use chrono::prelude::*;
use std::io;
use std::io::Write;

fn main() -> Result<(), std::io::Error> {
    let mut age = String::new();
    print!("What is your current age? ");
    io::stdout().flush()?;
    io::stdin().read_line(&mut age)?;
    let age: i32 = age.trim().parse().unwrap();

    let mut retire_age = String::new();
    print!("At what age would you like to retire? ");
    io::stdout().flush()?;
    io::stdin().read_line(&mut retire_age)?;
    let retire_age: i32 = retire_age.trim().parse().unwrap();

    let this_year = Local::now().year();
    println!(
        "You have {} years left until you can retire.",
        retire_age - age
    );

    Ok(())
}
