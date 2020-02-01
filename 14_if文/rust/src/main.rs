use std::io;
use std::io::Write;

const TAX_WI: f64 = 5.5;

fn main() -> Result<(), std::io::Error> {
    print!("What is the order amount? ");
    io::stdout().flush()?;

    let mut amount = String::new();
    io::stdin().read_line(&mut amount)?;
    let amount: f64 = amount.trim().parse().unwrap();

    print!("What is the state? ");
    io::stdout().flush()?;

    let mut state = String::new();
    io::stdin().read_line(&mut state)?;
    let state = state.trim();

    let tax = if state == "WI" {
        amount * (TAX_WI / 100.0)
    } else {
        0.0
    };
    if state == "WI" {
        println!("The subtotal is ${:.2}.", amount);
        println!("The tax is ${:.2}.", tax);
    }
    let total_amount = (((amount + tax) * 100.0) + 0.5).floor() / 100.0;
    println!("The total is ${:.2}.", total_amount);

    Ok(())
}
