use std::io;
use std::io::Write;

fn main() -> Result<(), std::io::Error> {
    print!("Who said it? ");
    io::stdout().flush()?;

    let mut text = String::new();
    io::stdin().read_line(&mut text)?;
    let text = text.trim();
    println!(
        "{} {} {}",
        text, "says,", r#""These aren't the droids you're looking for.""#
    );

    Ok(())
}
