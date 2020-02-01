use std::io;
use std::io::Write;

fn main() -> Result<(), std::io::Error> {
    print!("What is the input string? ");
    io::stdout().flush()?;

    let mut text = String::new();
    io::stdin().read_line(&mut text)?;
    let text = text.trim();
    println!("{} {} {} {}", text, "has", text.len(), "characters.");

    Ok(())
}
